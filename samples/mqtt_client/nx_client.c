/* Copyright (c) Microsoft Corporation.
   Licensed under the MIT License. */

#include "nx_client.h"

#include <stdio.h>

#include "stm32f4xx_hal.h"

#include "nx_api.h"
#include "nx_secure_tls_api.h"
#include "nxd_mqtt_client.h"

#include "mqtt_config.h"
#include "wwd_networking.h"

#include "sensor.h"

#include "mosquitto.cert.h"

#define DEFAULT_TIMEOUT 10 * NX_IP_PERIODIC_RATE

#define MQTT_CLIENT_ID          "MQTT_Client_ID"
#define MQTT_CLIENT_STACK_SIZE  1024 * 3
#define MQTT_THREAD_PRIORTY     2
#define MQTT_BROKER_SERVER_PORT NXD_MQTT_TLS_PORT
#define MQTT_KEEP_ALIVE_TIMER   60
#define MQTT_CLEAN_SESSION      NX_TRUE
#define QOS0                    0
#define QOS1                    1
#define DEMO_ALL_EVENTS         3
#define DEMO_MESSAGE_EVENT      1

TX_EVENT_FLAGS_GROUP mqtt_client_flags;

NXD_MQTT_CLIENT mqtt_client;
ULONG mqtt_client_stack[MQTT_CLIENT_STACK_SIZE];

// TLS buffers and certificate containers
extern const NX_SECURE_TLS_CRYPTO nx_crypto_tls_ciphers;

// Calculated with nx_secure_tls_metadata_size_calculate
static CHAR crypto_metadata_client[11600];

// Define the TLS packet reassembly buffer
UCHAR tls_packet_buffer[4000];

// Declare buffers to hold message and topic
static char message[NXD_MQTT_MAX_MESSAGE_LENGTH];
static UCHAR message_buffer[NXD_MQTT_MAX_MESSAGE_LENGTH];
static UCHAR topic_buffer[NXD_MQTT_MAX_TOPIC_NAME_LENGTH];

// static ULONG nx_secure_tls_session_time_func(VOID)
// {
//     // TODO: get the time
//     return (current_time);
// }

/**
 * @brief Callback to setup TLS parameters for secure MQTT connection.
 * @param memory_ptr: memory pointer
 * @retval int
 */
static UINT tls_setup_callback(NXD_MQTT_CLIENT *mqtt_client_ptr, NX_SECURE_TLS_SESSION *tls_session_ptr,
                               NX_SECURE_X509_CERT *certificate_ptr, NX_SECURE_X509_CERT *trusted_certificate_ptr)
{
    UINT status = NX_SUCCESS;
    NX_PARAMETER_NOT_USED(mqtt_client_ptr);

    // Initialize TLS module
    nx_secure_tls_initialize();

    // Create a TLS session
    status = nx_secure_tls_session_create(tls_session_ptr, &nx_crypto_tls_ciphers, crypto_metadata_client,
                                          sizeof(crypto_metadata_client));
    if (status != NX_SUCCESS)
    {
        printf("ERROR: nx_secure_tls_session_create (0x%08x)\r\n", status);
        return status;
    }

    // Allocate space for the certificate coming in from the broker
    memset((certificate_ptr), 0, sizeof(NX_SECURE_X509_CERT));

    // Setup the callback function used by checking certificate valid date
    // status = nx_secure_tls_session_time_function_set(tls_session_ptr, nx_secure_tls_session_time_func);
    // if (status != NX_SUCCESS)
    // {
    //     printf("ERROR: nx_secure_tls_session_time_function_set (0x%08x)\r\n", status);
    //     return status;
    // }

    // Allocate space for packet reassembly
    status = nx_secure_tls_session_packet_buffer_set(tls_session_ptr, tls_packet_buffer, sizeof(tls_packet_buffer));
    if (status != NX_SUCCESS)
    {
        printf("ERROR: nx_secure_tls_session_packet_buffer_set (0x%08x)\r\n", status);
        return status;
    }

    // Allocate space for the certificate coming in from the remote host
    status = nx_secure_tls_remote_certificate_allocate(tls_session_ptr, certificate_ptr, tls_packet_buffer,
                                                       sizeof(tls_packet_buffer));
    if (status != NX_SUCCESS)
    {
        printf("ERROR: nx_secure_tls_remote_certificate_allocate (0x%08x)\r\n", status);
        return status;
    }

    // Initialize Certificate to verify incoming server certificates
    status =
        nx_secure_x509_certificate_initialize(trusted_certificate_ptr, (UCHAR *)mosquitto_org_der,
                                              mosquitto_org_der_len, NX_NULL, 0, NULL, 0, NX_SECURE_X509_KEY_TYPE_NONE);
    if (status != NX_SUCCESS)
    {
        printf("ERROR: nx_secure_x509_certificate_initialize (0x%08x)\r\n", status);
        return status;
    }

    // Add a CA Certificate to our trusted store
    status = nx_secure_tls_trusted_certificate_add(tls_session_ptr, trusted_certificate_ptr);
    if (status != NX_SUCCESS)
    {
        printf("ERROR: nx_secure_tls_trusted_certificate_add (0x%08x)\r\n", status);
        return status;
    }

    return status;
}

/**
 * @brief Declare the disconnect notify function
 * @param mqtt_client_ptr: MQTT client pointer
 * @retval none
 */
static VOID mqtt_disconnect_func(NXD_MQTT_CLIENT *mqtt_client_ptr)
{
    NX_PARAMETER_NOT_USED(mqtt_client_ptr);

    printf("INFO: MQTT client disconnected from broker '%s'\r\n", MQTT_BROKER_SERVER);
}

/**
 * @brief Declare the notify function
 * @param mqtt_client_ptr: MQTT client pointer
 * @param number_of_messages: Number of messages
 * @retval none
 */
static VOID mqtt_notify_func(NXD_MQTT_CLIENT *mqtt_client_ptr, UINT number_of_messages)
{
    NX_PARAMETER_NOT_USED(mqtt_client_ptr);
    NX_PARAMETER_NOT_USED(number_of_messages);

    tx_event_flags_set(&mqtt_client_flags, DEMO_MESSAGE_EVENT, TX_OR);
    return;
}

UINT mqtt_client_entry(NX_IP *ip_ptr, NX_PACKET_POOL *pool_ptr, NX_DNS *dns_ptr)
{
    UINT status;
    NXD_ADDRESS mqtt_server_ip;
    ULONG events;
    UINT topic_length, message_length;
    UINT remaining_messages = MQTT_NB_MESSAGE;
    UINT message_count      = 0;
    UINT unlimited_publish  = NX_FALSE;

    lps22hb_t lps22hb_data;

    mqtt_server_ip.nxd_ip_version = 4;

    printf("MAC Address string is %s", mac_address);

    // Connect WiFi
    status = wwd_network_connect();
    if (status != NX_SUCCESS)
    {
        tx_thread_sleep(5 * TX_TIMER_TICKS_PER_SECOND);
    }

    // Get MQTT borker server IP
    status = nx_dns_host_by_name_get(dns_ptr, (UCHAR *)MQTT_BROKER_SERVER, &mqtt_server_ip.nxd_ip_address.v4,
                                     DEFAULT_TIMEOUT);
    if (status != NX_SUCCESS)
    {
        printf("ERROR: nxd_dns_host_by_name_get for MQTT broker server failed (0x%08x)\r\n", status);
        return status;
    }

    // Create MQTT client instance
    status =
        nxd_mqtt_client_create(&mqtt_client, "MQTT Client", MQTT_CLIENT_ID, strlen(MQTT_CLIENT_ID), ip_ptr, pool_ptr,
                               (VOID *)mqtt_client_stack, MQTT_CLIENT_STACK_SIZE, MQTT_THREAD_PRIORTY, NX_NULL, 0);
    if (status != NX_SUCCESS)
    {
        printf("ERROR: nxd_mqtt_client_create failed (0x%08x)\r\n", status);
        return status;
    }

    // Register the disconnect notification callback
    nxd_mqtt_client_disconnect_notify_set(&mqtt_client, mqtt_disconnect_func);

    // Set the receive notify callback
    nxd_mqtt_client_receive_notify_set(&mqtt_client, mqtt_notify_func);

    // Create a MQTT flag
    status = tx_event_flags_create(&mqtt_client_flags, "MQTT Client Flags");
    if (status != TX_SUCCESS)
    {
        printf("FAIL: Unable to create mqtt_client event flags (0x%02x)\r\n", status);
        return status;
    }

    // Start a secure connection to the MQTT broker
    status = nxd_mqtt_client_secure_connect(&mqtt_client, &mqtt_server_ip, MQTT_BROKER_SERVER_PORT, tls_setup_callback,
                                            MQTT_KEEP_ALIVE_TIMER, MQTT_CLEAN_SESSION, NX_WAIT_FOREVER);
    if (status != NX_SUCCESS)
    {
        printf("ERROR: nxd_mqtt_client_secure_connect failed (0x%08x)\r\n", status);
        return status;
    }
    else
    {
        printf("SUCCESS: MQTT client connected to broker.\r\n");
        printf("\tMQTT Broker server '%s':'%d'\r\n", MQTT_BROKER_SERVER, MQTT_BROKER_SERVER_PORT);
    }

    // Subscribe to the topic with QoS level 1
    status = nxd_mqtt_client_subscribe(&mqtt_client, MQTT_TOPIC_NAME, strlen(MQTT_TOPIC_NAME), QOS1);
    if (status != NX_SUCCESS)
    {
        printf("ERROR: nxd_mqtt_client_subscribe failed (0x%08x)\r\n", status);
        return status;
    }

    // Publish messages
    if (MQTT_NB_MESSAGE == 0) unlimited_publish = NX_TRUE;

    while (unlimited_publish || remaining_messages)
    {
        lps22hb_data = lps22hb_data_read();
        snprintf(message, sizeof(message), "%f", (double)lps22hb_data.temperature_degC);

        // Publish a message with QoS Level 1
        status = nxd_mqtt_client_publish(&mqtt_client, MQTT_TOPIC_NAME, strlen(MQTT_TOPIC_NAME), (CHAR *)message,
                                         strlen(message), NX_TRUE, QOS1, NX_WAIT_FOREVER);
        if (status != NX_SUCCESS)
        {
            printf("ERROR: nxd_mqtt_client_publish failed (0x%08x)\r\n", status);
            return status;
        }

        // Wait for the broker to publish the message
        tx_event_flags_get(&mqtt_client_flags, DEMO_ALL_EVENTS, TX_OR_CLEAR, &events, TX_WAIT_FOREVER);

        // Check if event received
        if (events & DEMO_MESSAGE_EVENT)
        {
            // Get message from the broker
            status = nxd_mqtt_client_message_get(&mqtt_client, topic_buffer, sizeof(topic_buffer), &topic_length,
                                                 message_buffer, sizeof(message_buffer), &message_length);
            if (status != NXD_MQTT_SUCCESS)
            {
                printf("ERROR: nxd_mqtt_client_message_get failed (0x%08x)\r\n", status);
                return status;
            }
            else
            {
                printf("SUCCESS: Message '%d' received: TOPIC = '%s', MESSAGE = '%s'\r\n", message_count + 1,
                       topic_buffer, message_buffer);
            }
        }

        // Decrease message count
        remaining_messages--;
        message_count++;

        // Delay 1s between each pub
        tx_thread_sleep(100);
    }

    // Unsubscribe the topic
    status = nxd_mqtt_client_unsubscribe(&mqtt_client, MQTT_TOPIC_NAME, strlen(MQTT_TOPIC_NAME));
    if (status != NX_SUCCESS)
    {
        printf("ERROR: nxd_mqtt_client_unsubscribe failed (0x%08x)\r\n", status);
        return status;
    }

    // Disconnect from the broker
    status = nxd_mqtt_client_disconnect(&mqtt_client);
    if (status != NX_SUCCESS)
    {
        printf("ERROR: nxd_mqtt_client_disconnect failed (0x%08x)\r\n", status);
        return status;
    }

    // Delete the client instance, release all the resources
    status = nxd_mqtt_client_delete(&mqtt_client);
    if (status != NX_SUCCESS)
    {
        printf("ERROR: nxd_mqtt_client_delete failed (0x%08x)\r\n", status);
        return status;
    }

    return status;
}