# Copyright (c) Microsoft Corporation.
# Licensed under the MIT License.

set(SOURCES
    board_init.c
    console.c
    screen.c
    sntp_client.c
    wwd_networking.c
    stm32f4xx_hal_msp.c
)

# Allow to disable the newlib stubbing
if(NOT DEFINED DISABLE_NEWLIB_STUB)
    list(APPEND SOURCES
        newlib_nano.c
    )
endif()

target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC .)