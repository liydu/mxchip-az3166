# Copyright (c) Microsoft Corporation.
# Licensed under the MIT License.

set(CMAKE_C_STANDARD 99)

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

# Disable common networking component, MXCHIP has it's own
set(DISABLE_COMMON_NETWORK true)