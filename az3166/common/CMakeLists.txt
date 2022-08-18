# Copyright (c) Microsoft Corporation.
# Licensed under the MIT License.

set(TARGET common)

set(SOURCES
    board_init.c
    console.c
    screen.c
    stm32f4xx_hal_msp.c
)

# Allow to disable the newlib stubbing
if(NOT DEFINED DISABLE_NEWLIB_STUB)
    list(APPEND SOURCES
        newlib_nano.c
    )
endif()

add_library(${TARGET} OBJECT
    ${SOURCES}
)

target_include_directories(${TARGET}
    PUBLIC
    .
)

target_link_libraries(${TARGET}
    azrtos::threadx
    azrtos::netxduo
    stm32cubef4
    mxchip_bsp
)