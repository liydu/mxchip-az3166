# MXChip AZ3166 Azure RTOS Samples

A collection of samples using Azure RTOS on MXChip AZ3166 DevKit. Please follow the link below for the detailed documentation of each sample.

## Prerequisites

All samples rely on Arm GCC toolchain, CMake and OpenOCD to compile and debug. Follow the platform instrucitons below to install them.

### Windows

1. From File Explorer, navigate to the following path in the repo and run the setup script named `get-toolchain.bat`:

```ps
.\tools\get-toolchain.bat
```

1. After the installation, open a new console window to recognize the configuration changes made by the setup script. Use this console to complete the remaining programming tasks in the quickstart. You can use Windows CMD, PowerShell, or Git Bash for Windows.

1. Run the following code to confirm that CMake version 3.16 or later is installed.

```ps
cmake --version
```

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

1. Run the following code to confirm that CMake version 3.16 or later is installed.

```bash
cmake --version
```

Now you have your toolchain installed on your Linux.

### macOS

**[TBD]**

## Clone the repository

Recursively clone this repository so you have all dependent submodules

```bash
git clone --recursive https://github.com/liydu/mxchip-az3166.git
```

## Samples

Now follow the instruction for each sample to build and run it.

- [MQTT_Client](./samples/mqtt_client/): Data exchange with a MQTT broker with TSL v1.2 enabled
