/* Copyright (c) Microsoft Corporation.
   Licensed under the MIT License. */

#include "nx_client.h"

#include <stdio.h>

#include "stm32f4xx_hal.h"

#include "nx_api.h"

#include "azure_config.h"
#include "wwd_networking.h"

UINT mqtt_client_entry(NX_IP* ip_ptr, NX_PACKET_POOL* pool_ptr, NX_DNS* dns_ptr, UINT (*unix_time_callback)(ULONG* unix_time))
{
    UINT status;

    
}