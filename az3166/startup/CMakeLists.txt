# Copyright (c) Microsoft Corporation.
# Licensed under the MIT License.

set(SOURCES
  system_stm32f4xx.c
  startup_stm32f412rx.s
  tx_initialize_low_level.S
)

target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC .)

target_link_directories(${PROJECT_NAME} PUBLIC ./)