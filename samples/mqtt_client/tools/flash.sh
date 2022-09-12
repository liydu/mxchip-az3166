# Copyright (c) Microsoft Corporation.
# Licensed under the MIT License.

#!/bin/bash

openocd_param="-f interface/stlink.cfg -f target/stm32f4x.cfg -c \"program build/mxchip_mqtt_client.elf verify\" -c \"reset halt\" -c \"shutdown\""

# Use Windows version of OpenOCD under WSL
set -e
if grep -qEi "(Microsoft|WSL)" /proc/version &> /dev/null ; then
  echo "Windows Subsystem for Linux"
  openocd.exe $openocd_param
else
  echo "Anything else"
  openocd $openocd_param
fi