# MXChip AZ3166 Azure RTOS Samples

A collection of samples using Azure RTOS on MXChip AZ3166 DevKit. Please follow the link below for the detailed documentation of each sample.

## Prerequisites

All samples rely on Arm GCC toolchain, CMake and OpenOCD to compile and debug. Follow the platform instrucitons below to install them

### Linux or WSL2

1. Download **x86_64 Linux hosted cross toolchains - AArch32 bare-metal target (arm-none-eabi)** from https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads. The one tested with the samples are `11.3.rel1`.

1. Extract it to local folder and copy it to the path you want to put the toolchain. We will use `/opt` as an example.

```bash
tar xv ./arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-eabi.tar.xz

sudo mv arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-eabi /opt/
```

1. Add the Arm GCC binary path to your `PATH` environment variable by updating our `.bashrc` or `.zshrc`.

```bash
# Add this path to the PATH environment variable
export PATH="...:/opt/arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-eabi/bin:$PATH"
```

1. Restart or use `source` to make your updated `.bashrc` or `.zshrc` reloaded.

```bash
source ~/.zshrc
```

1. You can verify it by view the version number of GCC.

```bash
arm-none-eabi-gcc --version

arm-none-eabi-gcc (Arm GNU Toolchain 11.3.Rel1) 11.3.1 20220712
```

1. Install `CMake`, `Ninja` and `Git` if you have not.

```bash
sudo apt update && sudo apt install -y cmake ninja-build git
```

1. Also verify the installation by issuing the commands.

Now you have your toolchain installed on your Linux.

### macOS

**[TBD]**

## Samples

-   [MQTT_Client](./samples/mqtt_client/): Data exchange with a MQTT broker with TSL v1.2 enabled
