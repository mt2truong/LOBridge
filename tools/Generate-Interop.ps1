# Generates the early-bound .NET interop assembly for the native LibreOffice COM server
# (tlbimp on the type library, no Activator.CreateInstance needed).
#
# Usage: powershell -ExecutionPolicy Bypass -File tools\Generate-Interop.ps1 [-Tlb <path>] [-Out <path>]
param(
    [string]$Tlb = (Join-Path $PSScriptRoot "..\native\generated\LOBridge.tlb"),
    [string]$Out = (Join-Path $PSScriptRoot "..\samples\net\LOBridge.Sample.Direct\lib\Interop.LOBridge.dll")
)

$ErrorActionPreference = "Stop"
$tlbimp = Get-ChildItem "C:\Program Files (x86)\Microsoft SDKs\Windows" -Recurse -Filter TlbImp.exe -ErrorAction SilentlyContinue |
    Where-Object { $_.FullName -match "x64" } | Select-Object -First 1
if (-not $tlbimp) { throw "TlbImp.exe (x64) not found. Install the Windows SDK NETFX tools." }

$Tlb = (Resolve-Path $Tlb).Path
New-Item -ItemType Directory -Force -Path (Split-Path -Parent $Out) | Out-Null

& $tlbimp.FullName $Tlb /out:$Out /namespace:Interop.LOBridge /machine:X64 /nologo
if ($LASTEXITCODE -ne 0) { throw "tlbimp failed with exit code $LASTEXITCODE" }
"Generated $Out"
