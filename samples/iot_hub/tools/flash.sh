# Copyright (c) Microsoft Corporation.
# Licensed under the MIT License.

#!/bin/bash

# Use paths relative to this script's location
SCRIPT=$(readlink -f "$0")
SCRIPTDIR=$(dirname "$SCRIPT")
BASEDIR=$(dirname "$SCRIPTDIR")

# OPENOCD_PARAM="-f interface/stlink.cfg -f target/stm32f4x.cfg -c \"program build/azure_iot_hub.elf verify\" -c \"reset halt\" -c \"shutdown\""

# Use Windows version of OpenOCD under WSL
set -e
if grep -qEi "(Microsoft|WSL)" /proc/version &> /dev/null ; then
  echo "Windows Subsystem for Linux"
  openocd.exe -f interface/stlink.cfg -f target/stm32f4x.cfg -c "program build/azure_iot_hub.elf verify" -c "reset halt" -c "shutdown"
else
  echo "Any Linux else"
  openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c "program build/azure_iot_hub.elf verify" -c "reset halt" -c "shutdown"
fi