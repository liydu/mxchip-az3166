/* Copyright (c) Microsoft Corporation.
   Licensed under the MIT License. */

#include <stdio.h>

#include "tx_api.h"
#include "nx_api.h"

#include "main.h"
#include "board_init.h"
#include "cmsis_utils.h"

static TX_BYTE_POOL tx_app_byte_pool;
static UCHAR tx_byte_pool_buffer[TX_APP_MEM_POOL_SIZE];

static TX_BYTE_POOL nx_app_byte_pool;
static UCHAR nx_byte_pool_buffer[NX_APP_MEM_POOL_SIZE];

/**
 * @brief  Application ThreadX Initialization.
 * @param memory_ptr: memory pointer
 * @retval int
 */
UINT app_thread_init(VOID *memory_ptr)
{
    UINT status = TX_SUCCESS;
    TX_BYTE_POOL *byte_pool = (TX_BYTE_POOL *)memory_ptr;

    (void)byte_pool;

    return status;
}

void tx_application_define(void *first_unused_memory)
{
    systick_interval_set(TX_TIMER_TICKS_PER_SECOND);

    UINT status = TX_SUCCESS;
    VOID *memory_ptr;

    if ((status = tx_byte_pool_create(&tx_app_byte_pool, "Tx App Memory Pool", tx_byte_pool_buffer, TX_APP_MEM_POOL_SIZE)))
    {
        printf("ERROR: Tx pool creation failed.\r\n");
    }
    else
    {
        memory_ptr = (VOID *)&tx_app_byte_pool;
        status = app_thread_init(memory_ptr);

        if (status != TX_SUCCESS)
        {
            printf("ERROR: Failed to run app_thread_init (0x%08x)\r\n", status);
        }
    }

    if ((status = tx_byte_pool_create(&nx_app_byte_pool, "Nx App Memory Pool", nx_byte_pool_buffer, NX_APP_MEM_POOL_SIZE)))
    {
        printf("ERROR: Nx pool creation failed.\r\n");
    }
    else
    {
        memory_ptr = (VOID *)&nx_app_byte_pool;

        status = nx_client_init(memory_ptr);
        if (status != NX_SUCCESS)
        {
            printf("ERROR: Failed to run nx_client_init (0x%08x)\r\n", status);
        }
    }
}

int main(void)
{
    // Initialize the board
    board_init();

    // Enter the ThreadX kernel
    tx_kernel_enter();

    return 0;
}