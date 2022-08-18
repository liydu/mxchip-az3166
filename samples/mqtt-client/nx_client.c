/* Copyright (c) Microsoft Corporation.
   Licensed under the MIT License. */

#include "nx_client.h"
#include "nxd_dhcp_client.h"
#include "nxd_sntp_client.h"
#include "nxd_dns.h"

#include "wiced_sdk.h"

// WiFi configurations
typedef enum
{
    None = 0,
    WEP = 1,
    WPA_PSK_TKIP = 2,
    WPA2_PSK_AES = 3
} WiFi_Mode;

#define DEFAULT_MEMORY_SIZE 1024
#define IP_STACK_MEMORY_SIZE 2 * DEFAULT_MEMORY_SIZE
#define ARP_MEMORY_SIZE 512

// IP instance configurations
#define NX_TX_PACKET_COUNT 16
#define NX_RX_PACKET_COUNT 12
#define NX_PACKET_SIZE (WICED_LINK_MTU)
#define NX_TX_PACKET_POOL_SIZE ((NX_PACKET_SIZE + sizeof(NX_PACKET)) * NX_TX_PACKET_COUNT)
#define NX_RX_PACKET_POOL_SIZE ((NX_PACKET_SIZE + sizeof(NX_PACKET)) * NX_RX_PACKET_COUNT)

#define NULL_ADDRESS IP_ADDRESS(0, 0, 0, 0)
#define NULL_MASK IP_ADDRESS(255, 255, 255, 0)
#define USER_DNS_ADDRESS IP_ADDRESS(1, 1, 1, 1)

// Winced WiFi configurations
#define WIFI_COUNTRY WICED_COUNTRY_UNITED_STATES

// Threads configurations
#define DEFAULT_THREAD_MEMORY_SIZE 4 * DEFAULT_MEMORY_SIZE
#define DEFAULT_MAIN_PRIORITY 10

#define SNTP_CLIENT_THREAD_MEMORY_SIZE 6 * DEFAULT_MEMORY_SIZE
#define SNTP_PRIORITY 5

#define MQTT_PRIORITY 3

#define APP_QUEUE_SIZE 10

// SNTP client configurations
#define SNTP_SERVER_NAME "time1.google.com"
#define SNTP_UPDATE_EVENT 1
// Define how often the demo checks for SNTP updates
#define PERIODIC_CHECK_INTERVAL (60 * NX_IP_PERIODIC_RATE)

#define DEFAULT_TIMEOUT 10 * NX_IP_PERIODIC_RATE
// Is equivalent to 70 years in sec calculated with www.epochconverter.com/date-difference
#define EPOCH_TIME_DIFF 2208988800

TX_THREAD AppMainThread;
TX_THREAD AppSNTPThread;
TX_THREAD AppMQTTThread;

TX_QUEUE MsgQueueOne;

TX_SEMAPHORE Semaphore;

NX_PACKET_POOL AppPool[2]; // 0=TX, 1=RX.
NX_IP IpInstance;
NX_DHCP DhcpClient;
NX_SNTP_CLIENT SntpClient;
// TODO: Why we put static for the DnsClient?
NX_DNS DnsClient;

TX_EVENT_FLAGS_GROUP SntpFlags;

ULONG IpAddress;
ULONG NetMask;

ULONG current_time;

static CHAR *wifi_ssid;
static CHAR *wifi_password;
static wiced_security_t wifi_mode;

static UCHAR ip_stack[IP_STACK_MEMORY_SIZE];
static UCHAR tx_pool_stack[NX_TX_PACKET_POOL_SIZE];
static UCHAR rx_pool_stack[NX_RX_PACKET_POOL_SIZE];
// static UCHAR arp_cache_stack[ARP_MEMORY_SIZE];

static VOID app_main_thread_entry(ULONG thread_input);
static VOID app_sntp_thread_entry(ULONG thread_input);
static VOID app_mqtt_thread_entry(ULONG thread_input);

static VOID ip_address_change_notify_callback(NX_IP *ip_instance, VOID *ptr);
static VOID time_update_callback(NX_SNTP_TIME_MESSAGE *time_update_ptr, NX_SNTP_TIME *local_time);
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
    // TODO: this will cause error
    // if (wwd_management_wifi_on(WIFI_COUNTRY) != WWD_SUCCESS)
    // {
    //     printf("ERROR: wwd_management_wifi_on\r\n");
    //     return NX_NOT_SUCCESSFUL;
    // }

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

    // Set WiFi crendentials from config file
    wifi_ssid = WIFI_SSID;
    wifi_password = WIFI_PASSWORD;
    WiFi_Mode mode = WIFI_MODE;

    switch (mode)
    {
    case None:
        wifi_mode = WICED_SECURITY_OPEN;
        break;
    case WEP:
        wifi_mode = WICED_SECURITY_WEP_SHARED;
        break;
    case WPA_PSK_TKIP:
        wifi_mode = WICED_SECURITY_WPA_TKIP_PSK;
        break;
    case WPA2_PSK_AES:
        wifi_mode = WICED_SECURITY_WPA2_AES_PSK;
        break;
    }

    // Allocate the memory for packet_pool
    // if ((status = tx_byte_allocate(byte_pool, (VOID **)&pointer, NX_PACKET_POOL_SIZE, TX_NO_WAIT)))
    // {
    //     printf("ERROR: tx_byte_allocate for packet pool (0x%08x)\r\n", status);
    //     return TX_POOL_ERROR;
    // }

    // Initialize the NetX system
    nx_system_initialize();

    // Create the Main TX Packet pool to be used for packet allocation
    status = nx_packet_pool_create(&AppPool[0], "Main TX Packet Pool", NX_PACKET_SIZE, tx_pool_stack, NX_TX_PACKET_POOL_SIZE);
    if (status != NX_SUCCESS)
    {
        printf("ERROR: nx_packet_pool_create for Main TX (0x%08x)\r\n", status);
        return NX_NOT_ENABLED;
    }

    // Create the Main RX Packet pool to be used for packet allocation
    status = nx_packet_pool_create(&AppPool[1], "Main RX Packet Pool", NX_PACKET_SIZE, rx_pool_stack, NX_RX_PACKET_POOL_SIZE);
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
    // if ((status = tx_byte_allocate(byte_pool, (VOID **)&pointer, NX_PACKET_POOL_SIZE, TX_NO_WAIT)))
    // {
    //     printf("ERROR: tx_byte_allocate for packet pool (0x%08x)\r\n", status);
    //     return TX_POOL_ERROR;
    // }

    // Create the main NX_IP instance
    status = nx_ip_create(
        &IpInstance, "Main Ip Instance",
        NULL_ADDRESS, NULL_MASK,
        &AppPool[0],
        wiced_sta_netx_duo_driver_entry,
        (UCHAR *)ip_stack,
        IP_STACK_MEMORY_SIZE,
        TX_NO_WAIT);
    if (status != NX_SUCCESS)
    {
        nx_packet_pool_delete(&AppPool[0]);
        nx_packet_pool_delete(&AppPool[1]);
        printf("ERROR: nx_ip_create (0x%08x)\r\n", status);
        return NX_NOT_ENABLED;
    }

    // Create the DHCP client
    status = nx_dhcp_create(&DhcpClient, &IpInstance, "DHCP Client");
    if (status != NX_SUCCESS)
    {
        nx_ip_delete(&IpInstance);
        nx_packet_pool_delete(&AppPool[0]);
        nx_packet_pool_delete(&AppPool[1]);
        printf("ERROR: nx_dhcp_create (0x%08x)\r\n", status);
        return NX_NOT_ENABLED;
    }

    // Allocate the memory for ARP
    if ((status = tx_byte_allocate(byte_pool, (VOID **)&pointer, ARP_MEMORY_SIZE, TX_NO_WAIT)))
    {
        printf("ERROR: tx_byte_allocate for main thread (0x%08x)\r\n", status);
        return TX_POOL_ERROR;
    }

    // Enable the ARP protocol and provide the ARP cache size for the IP instance
    status = nx_arp_enable(&IpInstance, (VOID *)pointer, ARP_MEMORY_SIZE);
    if (status != NX_SUCCESS)
    {
        nx_ip_delete(&IpInstance);
        nx_packet_pool_delete(&AppPool[0]);
        nx_packet_pool_delete(&AppPool[1]);
        printf("ERROR: nx_arp_enable (0x%08x)\r\n", status);
        return NX_NOT_ENABLED;
    }

    // Enable the ICMP
    status = nx_icmp_enable(&IpInstance);
    if (status != NX_SUCCESS)
    {
        nx_ip_delete(&IpInstance);
        nx_packet_pool_delete(&AppPool[0]);
        nx_packet_pool_delete(&AppPool[1]);
        printf("ERROR: nx_icmp_enable (0x%08x)\r\n", status);
        return NX_NOT_ENABLED;
    }

    // Enable the UDP protocol required for DHCP communication
    status = nx_udp_enable(&IpInstance);
    if (status != NX_SUCCESS)
    {
        nx_ip_delete(&IpInstance);
        nx_packet_pool_delete(&AppPool[0]);
        nx_packet_pool_delete(&AppPool[1]);
        printf("ERROR: nx_udp_enable (0x%08x)\r\n", status);
        return NX_NOT_ENABLED;
    }

    // Enable the TCP protocol required for DNS, MQTT..
    status = nx_tcp_enable(&IpInstance);
    if (status != NX_SUCCESS)
    {
        nx_ip_delete(&IpInstance);
        nx_packet_pool_delete(&AppPool[0]);
        nx_packet_pool_delete(&AppPool[1]);
        printf("ERROR: nx_tcp_enable (0x%08x)\r\n", status);
        return status;
    }

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

    // Allocate the memory for MQTT client thread
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

    // Allocate the memory for MsgQueueOne
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

/**
 * @brief  ip address change callback.
 * @param ip_instance: NX_IP instance
 * @param ptr: user data
 * @retval none
 */
static VOID ip_address_change_notify_callback(NX_IP *ip_instance, VOID *ptr)
{
    /* release the semaphore as soon as an IP address is available */
    tx_semaphore_put(&Semaphore);
}

/**
 * @brief  Main thread entry.
 * @param thread_input: ULONG user argument used by the thread entry
 * @retval none
 */
static VOID app_main_thread_entry(ULONG thread_input)
{
    UINT status = NX_SUCCESS;

    // Create a DNS client
    status = nx_dns_create(&DnsClient, &IpInstance, (UCHAR *)"DNS Client");
    if (status != NX_SUCCESS)
    {
        nx_dhcp_delete(&DhcpClient);
        nx_ip_delete(&IpInstance);
        nx_packet_pool_delete(&AppPool[0]);
        nx_packet_pool_delete(&AppPool[1]);
        printf("ERROR: nx_dns_create (0x%08x)\r\n", status);
    }

    // Initialize DNS instance with a dummy server
    // TODO: use nx_dhcp_interface_user_option_retrieve to get the DNS server address
    status = nx_dns_server_add(&DnsClient, USER_DNS_ADDRESS);
    if (status != NX_SUCCESS)
    {
        printf("ERROR: nx_dns_server_add (0x%08x)\r\n", status);
    }

    status = nx_ip_address_change_notify(&IpInstance, ip_address_change_notify_callback, NULL);
    if (status != NX_SUCCESS)
    {
        printf("ERROR: nx_ip_address_change_notify (0x%08x)\r\n", status);
    }

    // Start DHCP client
    status = nx_dhcp_start(&DhcpClient);
    if (status != NX_SUCCESS)
    {
        nx_dhcp_delete(&DhcpClient);
        nx_ip_delete(&IpInstance);
        nx_packet_pool_delete(&AppPool[0]);
        nx_packet_pool_delete(&AppPool[1]);
        printf("ERROR: nx_dhcp_start (0x%08x)\r\n", status);
    }

    // Wait until an IP address is ready
    status = tx_semaphore_get(&Semaphore, TX_WAIT_FOREVER);
    if (status != TX_SUCCESS)
    {
        printf("ERROR: tx_semaphore_get (0x%08x)\r\n", status);
    }

    // Get IP address
    status = nx_ip_address_get(&IpInstance, &IpAddress, &NetMask);
    if (status != NX_SUCCESS)
    {
        nx_ip_delete(&IpInstance);
        printf("ERROR: nx_ip_address_get (0x%08x)\r\n", status);
    }

    PRINT_IP_ADDRESS(IpAddress);

    // Start the SNTP client thread
    tx_thread_resume(&AppSNTPThread);

    // This thread is not needed any more, we relinquish it
    tx_thread_relinquish();

    return;
}

/** @brief  Handler for notifying SNTP time update event
 * @param thread_input: ULONG user argument used by the thread entry
 * @retval none
 */
static VOID time_update_callback(NX_SNTP_TIME_MESSAGE *time_update_ptr, NX_SNTP_TIME *local_time)
{
    NX_PARAMETER_NOT_USED(time_update_ptr);
    NX_PARAMETER_NOT_USED(local_time);

    tx_event_flags_set(&SntpFlags, SNTP_UPDATE_EVENT, TX_OR);
}

/** @brief  SNTP Client thread entry.
 * @param thread_input: ULONG user argument used by the thread entry
 * @retval none
 */
static VOID app_sntp_thread_entry(ULONG thread_input)
{
    UINT status;
    ULONG fraction;
    ULONG events = 0;
    UINT server_status;
    NXD_ADDRESS sntp_server_ip;

    sntp_server_ip.nxd_ip_version = 4;

    // Look up SNTP Server address
    status = nx_dns_host_by_name_get(&DnsClient, (UCHAR *)SNTP_SERVER_NAME, &sntp_server_ip.nxd_ip_address.v4, DEFAULT_TIMEOUT);
    if (status != NX_SUCCESS)
    {
        printf("ERROR: nx_dns_host_by_name_get (0x%08x)\r\n", status);
    }

    // Create the SNTP client
    status = nx_sntp_client_create(&SntpClient, &IpInstance, 0, &AppPool[0], NULL, NULL, NULL);
    if (status != NX_SUCCESS)
    {
        printf("ERROR: nx_sntp_client_create (0x%08x)\r\n", status);
    }

    // Setup time update callback function
    nx_sntp_client_set_time_update_notify(&SntpClient, time_update_callback);

    // Use the IPv4 service to set up the Client and set the IPv4 SNTP server
    status = nx_sntp_client_initialize_unicast(&SntpClient, sntp_server_ip.nxd_ip_address.v4);
    if (status != NX_SUCCESS)
    {
        printf("ERROR: nx_sntp_client_initialize_unicast (0x%08x)\r\n", status);
    }

    // Run whichever service the client is configured for
    status = nx_sntp_client_run_unicast(&SntpClient);
    if (status != NX_SUCCESS)
    {
        printf("ERROR: nx_sntp_client_run_unicast (0x%08x)\r\n", status);
    }

    // Wait for a server update event
    tx_event_flags_get(&SntpFlags, SNTP_UPDATE_EVENT, TX_OR_CLEAR, &events, PERIODIC_CHECK_INTERVAL);

    if (events == SNTP_UPDATE_EVENT)
    {
        // Check for valid SNTP server status
        status = nx_sntp_client_receiving_updates(&SntpClient, &server_status);
        if ((status != NX_SUCCESS) || (server_status == NX_FALSE))
        {
            // We do not have a valid update
            printf("ERROR: nx_sntp_client_receiving_updates (0x%08x)\r\n", status);
        }

        // We have a valid update.  Get the SNTP client time
        status = nx_sntp_client_get_local_time_extended(&SntpClient, &current_time, &fraction, NX_NULL, 0);
        if ((status != NX_SUCCESS) || (server_status == NX_FALSE))
        {
            // We do not have a valid update
            printf("ERROR: nx_sntp_client_receiving_updates (0x%08x)\r\n", status);
        }

        // TODO: Why?
        // take off 70 years difference
        current_time -= EPOCH_TIME_DIFF;
    }
    else
    {
        printf("ERROR: not SNTP_UPDATE_EVENT");
        // TODO: Error handler
    }

    // Start the MQTT client thread
    tx_thread_resume(&AppMQTTThread);
}

/**
 * @brief  MQTT Client thread entry.
 * @param thread_input: ULONG user argument used by the thread entry
 * @retval none
 */
static VOID app_mqtt_thread_entry(ULONG thread_input)
{
    printf("Do fancy MQTT things here.\r\n");

    return;
}