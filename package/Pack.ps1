# Builds the native DLL, generates the interop assembly and packs LOBridge.Net into .\nupkg.
#
# Usage: powershell -ExecutionPolicy Bypass -File Pack.ps1 [-Configuration Debug|Release]
#
# Prerequisites: the LibreOffice SDK (for the native build, see native\README.md) and the .NET SDK 10.
param(
    [ValidateSet("Debug", "Release")][string]$Configuration = "Release"
)

$ErrorActionPreference = "Stop"
$root = Join-Path $PSScriptRoot ".."

& (Join-Path $root "native\build.ps1") -Configuration $Configuration
if ($LASTEXITCODE -ne 0) { throw "native build failed" }

& (Join-Path $root "tools\Generate-Interop.ps1") -Out (Join-Path $PSScriptRoot "lib\Interop.LOBridge.dll")
if ($LASTEXITCODE -ne 0) { throw "Generate-Interop failed" }

Push-Location $PSScriptRoot
try {
    dotnet pack LOBridge.Net.csproj -c $Configuration -o nupkg
    if ($LASTEXITCODE -ne 0) { throw "dotnet pack failed with exit code $LASTEXITCODE" }
} finally { Pop-Location }

Get-ChildItem (Join-Path $PSScriptRoot "nupkg") -Filter *.nupkg | ForEach-Object { "Packed $($_.FullName)" }
