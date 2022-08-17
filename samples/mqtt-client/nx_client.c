/* Copyright (c) Microsoft Corporation.
   Licensed under the MIT License. */

#include "nx_client.h"

#include "wiced_sdk.h"

#define NULL_ADDRESS IP_ADDRESS(0, 0, 0, 0)
#define NULL_MASK IP_ADDRESS(255, 255, 255, 0)

#define IP_STACK_MEMORY_SIZE 1024

#define WIFI_COUNTRY WICED_COUNTRY_UNITED_STATES

TX_THREAD AppMainThread;

NX_IP nx_ip;
NX_PACKET_POOL AppPool[2]; // 0=TX, 1=RX.

static CHAR *wifi_ssid;
static CHAR *wifi_password;
static wiced_security_t wifi_mode;

static VOID app_main_thread_entry(ULONG thread_input);
static VOID app_sntp_thread_entry(ULONG thread_input);
// static VOID App_MQTT_Client_Thread_Entry(ULONG thread_input);

// static VOID ip_address_change_notify_callback(NX_IP *ip_instance, VOID *ptr);
// static VOID time_update_callback(NX_SNTP_TIME_MESSAGE *time_update_ptr, NX_SNTP_TIME *local_time);
// static ULONG nx_secure_tls_session_time_function(void);
// static UINT dns_create(NX_DNS *dns_ptr);

/**
 * @brief Join WiFi.
 * @retval int
 */
static UINT wifi_init()
{
    wiced_mac_t mac;

    printf("\r\nInitializing WiFi...\r\n");

    if (wifi_ssid[0] == 0)
    {
        printf("ERROR: wifi_ssid is empty\r\n");
        return NX_NOT_SUCCESSFUL;
    }

    // Set pools for wifi
    if (wwd_buffer_init(AppPool) != WWD_SUCCESS)
    {
        printf("ERROR: wwd_buffer_init\r\n");
        return NX_NOT_SUCCESSFUL;
    }

    // Set country
    if (wwd_management_wifi_on(WIFI_COUNTRY) != WWD_SUCCESS)
    {
        printf("ERROR: wwd_management_wifi_on\r\n");
        return NX_NOT_SUCCESSFUL;
    }

    wwd_wifi_get_mac_address(&mac, WWD_STA_INTERFACE);
    printf("\tMAC address: %02X:%02X:%02X:%02X:%02X:%02X\r\n",
           mac.octet[0],
           mac.octet[1],
           mac.octet[2],
           mac.octet[3],
           mac.octet[4],
           mac.octet[5]);

    printf("SUCCESS: WiFi initialized\r\n");

    return NX_SUCCESS;
}

/**
 * @brief Application NetXDuo Initialization.
 * @param memory_ptr: memory pointer
 * @retval int
 */
UINT nx_client_init(VOID *memory_ptr)
{
    UINT status = NX_SUCCESS;
    TX_BYTE_POOL *byte_pool = (TX_BYTE_POOL *)memory_ptr;

    printf("Nx_MQTT_Client application started...\r\n");

    CHAR *pointer;

    // Allocate the memory for packet_pool
    if ((status = tx_byte_allocate(byte_pool, (VOID **)&pointer, NX_PACKET_POOL_SIZE, TX_NO_WAIT)))
    {
        printf("ERROR: tx_byte_allocate for packet pool (0x%08x)\r\n", status);
        return TX_POOL_ERROR;
    }

    // Create the Main TX Packet pool to be used for packet allocation
    status = nx_packet_pool_create(&AppPool[0], "Main TX Packet Pool", PAYLOAD_SIZE, pointer, NX_PACKET_POOL_SIZE);
    if (status != NX_SUCCESS)
    {
        printf("ERROR: nx_packet_pool_create for Main TX (0x%08x)\r\n", status);
        return NX_NOT_ENABLED;
    }

    // Create the Main RX Packet pool to be used for packet allocation
    status = nx_packet_pool_create(&AppPool[1], "Main RX Packet Pool", PAYLOAD_SIZE, pointer, NX_PACKET_POOL_SIZE);
    if (status != NX_SUCCESS)
    {
        nx_packet_pool_delete(&AppPool[0]);
        printf("ERROR: nx_packet_pool_create for Main RX (0x%08x)\r\n", status);
        return NX_NOT_ENABLED;
    }

    // Initialize WiFi
    status = wifi_init();
    if (status != NX_SUCCESS)
    {
        nx_packet_pool_delete(&AppPool[0]);
        nx_packet_pool_delete(&AppPool[1]);
        printf("ERROR: wifi_init (0x%08x)\r\n", status);
        return NX_NOT_ENABLED;
    }

    // Allocate the memory for NX_IP instance
    if ((status = tx_byte_allocate(byte_pool, (VOID **)&pointer, NX_PACKET_POOL_SIZE, TX_NO_WAIT)))
    {
        printf("ERROR: tx_byte_allocate for packet pool (0x%08x)\r\n", status);
        return TX_POOL_ERROR;
    }

    // Create the main NX_IP instance
    status = nx_ip_create(
        &IpInstance, "Main Ip Instance",
        NULL_ADDRESS, NULL_MASK,
        &AppPool[0],
        wiced_sta_netx_duo_driver_entry,
        pointer,
        2 * IP_STACK_MEMORY_SIZE,
        TX_NO_WAIT);
    if (status != NX_SUCCESS)
    {
        nx_packet_pool_delete(&AppPool[0]);
        nx_packet_pool_delete(&AppPool[1]);
        printf("ERROR: nx_ip_create (0x%08x)\r\n", status);
        return NX_NOT_ENABLED;
    }

    // Create the DHCP client

    // Allocate the memory for ARP

    // Enable the ARP protocol and provide the ARP cache size for the IP instance

    // Enable the ICMP

    // Enable the UDP protocol required for DHCP communication

    // Enable the TCP protocol required for DNS, MQTT..

    // Allocate the memory for Main thread
    if ((status = tx_byte_allocate(byte_pool, (VOID **)&pointer, DEFAULT_THREAD_MEMORY_SIZE, TX_NO_WAIT)))
    {
        printf("ERROR: tx_byte_allocate for main thread (0x%08x)\r\n", status);
        return TX_POOL_ERROR;
    }

    // Create the main thread
    status = tx_thread_create(
        &AppMainThread, "App Main Thread", app_main_thread_entry,
        0,
        pointer,
        DEFAULT_THREAD_MEMORY_SIZE,
        DEFAULT_MAIN_PRIORITY, DEFAULT_MAIN_PRIORITY,
        TX_NO_TIME_SLICE,
        TX_AUTO_START);
    if (status != TX_SUCCESS)
    {
        printf("ERROR: App Main Thread creation failed!\r\n");
        return NX_NOT_ENABLED;
    }

    // Allocate the memory for SNTP client thread
    if ((status = tx_byte_allocate(byte_pool, (VOID **)&pointer, SNTP_CLIENT_THREAD_MEMORY_SIZE, TX_NO_WAIT)))
    {
        printf("ERROR: tx_byte_allocate for SNTP client thread (0x%08x)\r\n", status);
        return TX_POOL_ERROR;
    }

    // Create the SNTP client thread
    status = tx_thread_create(
        &AppSNTPThread, "App SNTP Thread", app_sntp_thread_entry,
        0,
        pointer,
        SNTP_CLIENT_THREAD_MEMORY_SIZE,
        SNTP_PRIORITY, SNTP_PRIORITY,
        TX_NO_TIME_SLICE,
        TX_DONT_START);
    if (status != TX_SUCCESS)
    {
        printf("ERROR: App SNTP Thread creation failed!\r\n");
        return NX_NOT_ENABLED;
    }

    // Create the SNTP event flags
    status = tx_event_flags_create(&SntpFlags, "SNTP Event Flags");
    if (status != NX_SUCCESS)
    {
        printf("ERROR: tx_event_flags_create for SNTP (0x%08x)\r\n", status);
        return NX_NOT_ENABLED;
    }

    // Allocate the memory for Main thread
    if ((status = tx_byte_allocate(byte_pool, (VOID **)&pointer, DEFAULT_THREAD_MEMORY_SIZE, TX_NO_WAIT)))
    {
        printf("ERROR: tx_byte_allocate for MQTT client thread (0x%08x)\r\n", status);
        return TX_POOL_ERROR;
    }

    // Create the MQTT client thread
    status = tx_thread_create(
        &AppMQTTThread, "App MQTT Thread", app_mqtt_thread_entry,
        0,
        pointer,
        DEFAULT_THREAD_MEMORY_SIZE,
        MQTT_PRIORITY, MQTT_PRIORITY,
        TX_NO_TIME_SLICE,
        TX_DONT_START);

    if (status != TX_SUCCESS)
    {
        printf("ERROR: App MQTT Thread creation failed!\r\n");
        return NX_NOT_ENABLED;
    }

    // Allocate the MsgQueueOne
    if ((status = tx_byte_allocate(byte_pool, (VOID **)&pointer, APP_QUEUE_SIZE * sizeof(ULONG), TX_NO_WAIT)))
    {
        printf("ERROR: tx_byte_allocate for MsgQueueOne (0x%08x)\r\n", status);
        return TX_POOL_ERROR;
    }

    // Create the MsgQueueOne shared by MsgSenderThreadOne and MsgReceiverThread
    if ((status = tx_queue_create(&MsgQueueOne, "Message Queue One", TX_1_ULONG, pointer, APP_QUEUE_SIZE * sizeof(ULONG))))
    {
        printf("ERROR: tx_queue_create for MsgQueueOne (0x%08x)\r\n", status);
        return TX_QUEUE_ERROR;
    }

    // Set DHCP notification callback
    tx_semaphore_create(&Semaphore, "DHCP Semaphore", 0);

    return status;
}