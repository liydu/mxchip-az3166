# Copyright (c) Microsoft Corporation.
# Licensed under the MIT License.

# Define ThreadX user configuration
set(TX_USER_FILE "${CMAKE_CURRENT_LIST_DIR}/threadx/tx_user.h" CACHE STRING "Enable TX user configuration")

# Define NetXDuo user configuration
set(NX_USER_FILE "${CMAKE_CURRENT_LIST_DIR}/netxduo/nx_user.h" CACHE STRING "Enable NX user configuration")
set(NXD_ENABLE_AZURE_IOT OFF CACHE BOOL "Disable Azure IoT")
set(NXD_ENABLE_FILE_SERVERS OFF CACHE BOOL "Disable fileX dependency by netxduo")

# Azure security module
set(NX_AZURE_DISABLE_IOT_SECURITY_MODULE ON CACHE BOOL "Security Module")

# Core libraries
add_subdirectory(threadx)
add_subdirectory(netxduo)

add_subdirectory(stm32cubef4)
add_subdirectory(mxchip_bsp)
add_subdirectory(wiced_sdk)
