/* Copyright (c) Microsoft Corporation.
   Licensed under the MIT License. */

#include "nx_client.h"

#include <stdio.h>

#include "stm32f4xx_hal.h"

#include "nx_api.h"
#include "nx_azure_iot_hub_client.h"
#include "nx_azure_iot_provisioning_client.h"

#include "azure_iot_nx_client.h"

#include "azure_config.h"

#include "screen.h"
#include "sensor.h"
#include "wwd_networking.h"

#define DEFAULT_TIMEOUT 10 * NX_IP_PERIODIC_RATE

// Device telemetry names
#define TELEMETRY_HUMIDITY    "humidity"
#define TELEMETRY_TEMPERATURE "temperature"
#define TELEMETRY_PRESSURE    "pressure"

typedef enum TELEMETRY_STATE_ENUM
{
    TELEMETRY_STATE_TEMPERATURE,
    TELEMETRY_STATE_END
} TELEMETRY_STATE;

static AZURE_IOT_NX_CONTEXT azure_iot_nx_client;

static int32_t telemetry_interval = 10;

// static ULONG nx_secure_tls_session_time_func(VOID)
// {
//     // TODO: get the time
//     return (current_time);
// }

/**
 * @brief Construct the temperature telemetry JSON
 * @param json_writer: NX_AZURE_IOT_JSON_WRITER pointer
 * @retval success status
 */
static UINT append_device_telemetry_temperature(NX_AZURE_IOT_JSON_WRITER *json_writer)
{
    lps22hb_t lps22hb_data    = lps22hb_data_read();
    hts221_data_t hts221_data = hts221_data_read();

    if (nx_azure_iot_json_writer_append_property_with_double_value(
            json_writer, (UCHAR *)TELEMETRY_HUMIDITY, sizeof(TELEMETRY_HUMIDITY) - 1, hts221_data.humidity_perc, 2) ||

        nx_azure_iot_json_writer_append_property_with_double_value(json_writer, (UCHAR *)TELEMETRY_TEMPERATURE,
                                                                   sizeof(TELEMETRY_TEMPERATURE) - 1,
                                                                   lps22hb_data.temperature_degC, 2) ||

        nx_azure_iot_json_writer_append_property_with_double_value(
            json_writer, (UCHAR *)TELEMETRY_PRESSURE, sizeof(TELEMETRY_PRESSURE) - 1, lps22hb_data.pressure_hPa, 2))
    {
        return NX_NOT_SUCCESSFUL;
    }

    return NX_AZURE_IOT_SUCCESS;
}

/**
 * @brief Telemetry publishing callback
 * @param nx_context: AZURE_IOT struct
 * @retval none
 */
static void telemetry_cb(AZURE_IOT_NX_CONTEXT *nx_context)
{
    static TELEMETRY_STATE telemetry_state = TELEMETRY_STATE_TEMPERATURE;

    switch (telemetry_state)
    {
        case TELEMETRY_STATE_TEMPERATURE:
            azure_iot_nx_client_publish_telemetry(&azure_iot_nx_client, NULL, append_device_telemetry_temperature);
            break;

        default: break;
    }

    telemetry_state = (telemetry_state + 1) % TELEMETRY_STATE_END;
}

/**
 * @brief Azure IoT thread entry point
 * @param nx_context: AZURE_IOT struct
 * @retval status
 */
UINT azure_iot_nx_client_entry(NX_IP *ip_ptr, NX_PACKET_POOL *pool_ptr, NX_DNS *dns_ptr,
                               UINT (*unix_time_callback)(ULONG *unix_time))
{
    UINT status;

    if ((status = azure_iot_nx_client_create(&azure_iot_nx_client, ip_ptr, pool_ptr, dns_ptr, unix_time_callback)))
    {
        printf("ERROR: azure_iot_nx_client_create failed (0x%08x)\r\n", status);
        return status;
    }

    // Register the callbacks
    azure_iot_nx_client_register_timer_callback(&azure_iot_nx_client, telemetry_cb, telemetry_interval);

    // Setup authentication
#ifdef ENABLE_X509
    if ((status =
             azure_iot_nx_client_cert_set(&azure_iot_nx_client, (UCHAR *)iot_x509_device_cert, iot_x509_device_cert_len,
                                          (UCHAR *)iot_x509_private_key, iot_x509_private_key_len)))
    {
        printf("ERROR: azure_iot_nx_client_cert_set (0x%08x)\r\n", status);
        return status;
    }
#else
    if ((status = azure_iot_nx_client_sas_set(&azure_iot_nx_client, IOT_DEVICE_SAS_KEY)))
    {
        printf("ERROR: azure_iot_nx_client_sas_set (0x%08x)\r\n", status);
        return status;
    }
#endif

    // Enter the main loop
#ifdef ENABLE_DPS
    azure_iot_nx_client_dps_run(&azure_iot_nx_client, IOT_DPS_ID_SCOPE, IOT_DPS_REGISTRATION_ID, wwd_network_connect);
#else
    azure_iot_nx_client_hub_run(&azure_iot_nx_client, IOT_HUB_HOSTNAME, IOT_HUB_DEVICE_ID, wwd_network_connect);
#endif

    return NX_SUCCESS;
}
