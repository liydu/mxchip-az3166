:: Copyright (c) Microsoft Corporation.
:: Licensed under the MIT License.

setlocal
cd /d %~dp0\..

openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c "program build/mxchip_mqtt_client.elf verify" -c "reset halt" -c "shutdown"