/* Copyright (c) Microsoft Corporation.
   Licensed under the MIT License. */

#ifndef _WWD_NETWORKING_H
#define _WWD_NETWORKING_H

#include "nx_api.h"
#include "nxd_dns.h"

#include "azure_config.h"

#define MAC_ADDRESS_SIZE 18

extern NX_PACKET_POOL nx_pool[2]; // 0=TX, 1=RX.
extern NX_IP nx_ip;
extern NX_DNS nx_dns_client;
extern CHAR mac_address[MAC_ADDRESS_SIZE];

UINT wwd_network_init(CHAR *ssid, CHAR *password, WiFi_Mode mode);
UINT wwd_network_connect();

#endif
