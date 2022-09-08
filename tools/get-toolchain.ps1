# Copyright (c) Microsoft Corporation.
# Licensed under the MIT License.

[System.Net.ServicePointManager]::SecurityProtocol = [System.Net.SecurityProtocolType]::Tls12;

echo "`nInstalling prerequisites. Please leave the window open until the installation completes."

$gccarm_path = 'https://developer.arm.com/-/media/Files/downloads/gnu/11.3.rel1/binrel/'
$gccarm_file = 'arm-gnu-toolchain-11.3.rel1-mingw-w64-i686-arm-none-eabi.exe'
$gccarm_name = 'GCC-ARM 11.3.rel1'
$gccarm_hash = 'C0B213A93CBBC354C5A05F5C162094E25643890C68F126959AF29E33FD22711C'

$cmake_path = 'https://github.com/Kitware/CMake/releases/download/v3.24.1/'
$cmake_file = 'cmake-3.24.1-windows-x86_64.msi'
$cmake_name = 'CMake v3.24.1'
$cmake_hash = '04F1D47172B69D39CF178D0E7D9100B536C2B4B5F3C7302C7140800D9C2FA220'

$termite_path = 'https://www.compuphase.com/software'
$termite_file = 'termite-3.4.exe'
$termite_name = 'Termite v3.4'
$termite_hash = 'CA440B6C7F6EAA812BA5F8BF42AED86E02022CA50A1C72585168C9B671D0FE19'

$openocd_path = 'https://github.com/xpack-dev-tools/openocd-xpack/releases/download/v0.11.0-5/'
$openocd_file = 'xpack-openocd-0.11.0-5-win32-x64.zip'
$openocd_name = 'OpenOCD v0.11.0'
$openocd_hash = '1D062E422E71F56BB490A4713440B8A6DA09E25E314C39ED63A66BD6E7A62EF4'

echo "`nDownloading packages..."

$wc = New-Object System.Net.WebClient
$wc.Headers['User-Agent'] = "Mozilla/4.0"

echo "(1/4) $gccarm_name"
if ( -not (Test-Path "$env:TEMP\$gccarm_file") -Or ((Get-FileHash "$env:TEMP\$gccarm_file").Hash -ne $gccarm_hash))
{
    $wc.DownloadFile("$gccarm_path\$gccarm_file", "$env:TEMP\$gccarm_file")
}

echo "(2/4) $cmake_name"
if ( -not (Test-Path "$env:TEMP\$cmake_file") -Or ((Get-FileHash "$env:TEMP\$cmake_file").Hash -ne $cmake_hash))
{
    $wc.DownloadFile("$cmake_path\$cmake_file", "$env:TEMP\$cmake_file")
}

echo "(3/4) $termite_name"
if ( -not (Test-Path "$env:TEMP\$termite_file") -Or ((Get-FileHash "$env:TEMP\$termite_file").Hash -ne $termite_hash))
{
    $wc.DownloadFile("$termite_path\$termite_file", "$env:TEMP\$termite_file")
}

echo "(4/4) $openocd_name"
if ( -not (Test-Path "$env:TEMP\$openocd_file") -Or ((Get-FileHash "$env:TEMP\$openocd_file").Hash -ne $openocd_hash))
{
    $wc.DownloadFile("$openocd_path\$openocd_file", "$env:TEMP\$openocd_file")
}

echo "`nInstalling packages..."

echo "(1/4) $gccarm_name"
Start-Process -FilePath "$env:TEMP\$gccarm_file" -ArgumentList "/S /P /R" -Wait

echo "(2/4) $cmake_name"
Start-Process -FilePath "$env:TEMP\$cmake_file" -ArgumentList "ADD_CMAKE_TO_PATH=System /passive" -Wait

echo "(3/4) $termite_name"
Start-Process -FilePath "$env:TEMP\$termite_file" -ArgumentList "/S" -Wait

echo "(4/4) $openocd_name"
Expand-Archive "$env:TEMP\$openocd_file" -DestinationPath "C:\OpenOCD"
$env:PATH += ";C:\OpenOCD\xpack-openocd-0.11.0-5\bin"

echo "`nInstallation complete!"

echo "`nPress any key to continue..."
Read-Host