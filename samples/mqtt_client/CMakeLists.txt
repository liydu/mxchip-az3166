# Copyright (c) Microsoft Corporation.
# Licensed under the MIT License.

cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

set(ROOT_DIR ${CMAKE_SOURCE_DIR}/../..)

list(APPEND CMAKE_MODULE_PATH ${ROOT_DIR}/cmake)

include(variables)
include(utilities)

# Define the Project
# CXX enables IntelliSense only. Sources are still compiled as C.
project(mxchip_mqtt_client C CXX ASM)

set(AZURE_RTOS_USER_FILES ${SAMPLES_DIR}/mqtt_client/config)

set(SOURCES
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