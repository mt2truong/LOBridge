# Regenerates the interop assembly for the tests and runs them.
# Usage: powershell -ExecutionPolicy Bypass -File Run-Tests.ps1
$ErrorActionPreference = "Stop"
$root = Join-Path $PSScriptRoot "..\..\.."
& (Join-Path $root "tools\Generate-Interop.ps1") -Out (Join-Path $PSScriptRoot "..\LOBridge.Tests\lib\Interop.LOBridge.dll")
if ($LASTEXITCODE -ne 0) { throw "Generate-Interop failed" }
Push-Location (Join-Path $PSScriptRoot "..\LOBridge.Tests")
try {
    dotnet test -c Release --logger "console;verbosity=normal"
    if ($LASTEXITCODE -ne 0) { throw "dotnet test failed with exit code $LASTEXITCODE" }
} finally { Pop-Location }
