/* Copyright (c) Microsoft Corporation.
   Licensed under the MIT License. */

#ifndef _NX_CLIENT_H
#define _NX_CLIENT_H

#include "nx_api.h"
#include "nxd_dns.h"
#include "tx_api.h"

UINT mqtt_client_entry(NX_IP *ip_ptr, NX_PACKET_POOL *pool_ptr, NX_DNS *dns_ptr);

#endif // _NX_CLIENT_H