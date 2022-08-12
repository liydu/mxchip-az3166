/* Copyright (c) Microsoft Corporation.
   Licensed under the MIT License. */

#include "nx_client.h"

static VOID App_Main_Thread_Entry(ULONG thread_input);
static VOID App_MQTT_Client_Thread_Entry(ULONG thread_input);
static VOID App_SNTP_Thread_Entry(ULONG thread_input);
static VOID ip_address_change_notify_callback(NX_IP *ip_instance, VOID *ptr);
static VOID time_update_callback(NX_SNTP_TIME_MESSAGE *time_update_ptr, NX_SNTP_TIME *local_time);
static ULONG nx_secure_tls_session_time_function(void);
static UINT dns_create(NX_DNS *dns_ptr);

/**
  * @brief  Application NetXDuo Initialization.
  * @param memory_ptr: memory pointer
  * @retval int
  */
 UINT nx_client_init(VOID *memory_ptr)
 {
    UNIT status = NX_SUCCESS;
 }