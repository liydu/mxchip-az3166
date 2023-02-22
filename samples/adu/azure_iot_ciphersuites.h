/* Copyright (c) Microsoft Corporation.
   Licensed under the MIT License. */

#ifndef NX_AZURE_IOT_CIPHERSUITES_H
#define NX_AZURE_IOT_CIPHERSUITES_H

#include "nx_secure_tls_api.h"

// Users can use these ciphersuites as sample, and also can build their own ciphersuite
// referring to nx_secure/nx_crypto_generic_ciphersuites.c.
extern const NX_CRYPTO_METHOD *_nx_azure_iot_tls_supported_crypto[];
extern const UINT _nx_azure_iot_tls_supported_crypto_size;
extern const NX_CRYPTO_CIPHERSUITE *_nx_azure_iot_tls_ciphersuite_map[];
extern const UINT _nx_azure_iot_tls_ciphersuite_map_size;

// Define the metadata size for _nx_azure_iot_tls_ciphers.
#define NX_AZURE_IOT_TLS_METADATA_BUFFER_SIZE (9 * 1024)

#endif /* NX_AZURE_IOT_CIPHERSUITES_H */