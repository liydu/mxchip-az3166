# Copyright (c) Microsoft Corporation.
# Licensed under the MIT License.

cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
set(CMAKE_C_STANDARD 99)

set(ROOT_DIR ${CMAKE_SOURCE_DIR}/../..)

# Path of static libs
set(LIB_DIR ${ROOT_DIR}/lib)

# Path of common code for AZ3166
set(AZ3166_DIR ${ROOT_DIR}/az3166)

# Path of acutal sample codes
set(SAMPLES_DIR ${ROOT_DIR}/samples)

# use the repo version of ninja on Windows as there is no Ninja installer
if(WIN32)
    set(CMAKE_MAKE_PROGRAM ${ROOT_DIR}/cmake/ninja CACHE STRING "Ninja location")
endif()

# Set the toolchain if not defined
if(NOT CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "${ROOT_DIR}/cmake/arm-gcc-cortex-m4.cmake")
endif()

list(APPEND CMAKE_MODULE_PATH ${ROOT_DIR}/cmake)

include(utilities)

# Define the Project
# CXX enables IntelliSense only. Sources are still compiled as C.
project(azure_iot_hub C CXX ASM)

# Disable common networking component, MXCHIP has it's own
set(DISABLE_COMMON_NETWORK true)

set(AZURE_RTOS_USER_FILES ${SAMPLES_DIR}/iot_hub/config)

set(SOURCES
    azure_iot_cert.c
    azure_iot_ciphersuites.c
    azure_iot_connect.c
    azure_iot_nx_client.c
    main.c
    nx_client.c
)

add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(${LIB_DIR} lib)
add_subdirectory(${AZ3166_DIR}/common common)
add_subdirectory(${AZ3166_DIR}/startup startup)

target_link_libraries(${PROJECT_NAME}
    azrtos::threadx
    azrtos::netxduo

    stm32cubef4
    mxchip_bsp
    wiced_sdk
)

target_include_directories(${PROJECT_NAME} PUBLIC
    .
    config
)

if(CMAKE_C_COMPILER_ID STREQUAL "IAR")
    message(FATAL_ERROR, "IAR is not currently implemented for this device")
else()
    set_target_linker(${PROJECT_NAME} ${AZ3166_DIR}/startup/MXChip_AZ3166.ld)
endif()

post_build(${PROJECT_NAME})