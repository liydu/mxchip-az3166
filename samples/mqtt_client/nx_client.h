/* Copyright (c) Microsoft Corporation.
   Licensed under the MIT License. */

#ifndef _NX_CLIENT_H
#define _NX_CLIENT_H

#include "nx_api.h"

#define WIFI_SSID "BabyAvocado"
#define WIFI_PASSWORD "yjy64161551"
#define WIFI_MODE WPA2_PSK_AES

#define PRINT_IP_ADDRESS(addr)                      \
   do                                               \
   {                                                \
      printf("STM32 %s: %lu.%lu.%lu.%lu \n", #addr, \
             (addr >> 24) & 0xff,                   \
             (addr >> 16) & 0xff,                   \
             (addr >> 8) & 0xff,                    \
             (addr & 0xff));                        \
   } while (0)

// Export functions prototypes
UINT nx_client_init(VOID *memory_ptr);

#endif // _NX_CLIENT_H