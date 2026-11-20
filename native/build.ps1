# Builds the native COM server (x64) with MSBuild, using the projects in this folder.
# The LibreOffice SDK is needed here only: headers, import libraries and cppumaker.
#
# Usage: powershell -ExecutionPolicy Bypass -File build.ps1 [-Configuration Debug|Release] [-Test]
#   -Test  also builds and runs SmokeTest.exe (no COM registration needed)
#
# Output: bin\LOBridge.dll
# The same build works from Visual Studio: open ..\LOBridge.sln or native\LOBridge.vcxproj.
param(
    [string]$SdkDir = "C:\Program Files\LibreOffice\sdk",
    [ValidateSet("Debug", "Release")][string]$Configuration = "Release",
    [switch]$Test
)

$ErrorActionPreference = "Stop"
$dir = Split-Path -Parent $MyInvocation.MyCommand.Path

# 1. Find MSBuild from the Visual Studio installation (with the C++ tools).
$vswhere = Join-Path ${env:ProgramFiles(x86)} "Microsoft Visual Studio\Installer\vswhere.exe"
$msbuild = & $vswhere -latest -products * -requires Microsoft.Component.MSBuild `
    -find "MSBuild\**\Bin\MSBuild.exe" | Select-Object -First 1
if (-not $msbuild) { throw "MSBuild not found. Install Visual Studio with the C++ tools." }

if (-not (Test-Path (Join-Path $SdkDir "include\com\sun\star\uno\Any.hxx"))) {
    throw "LibreOffice SDK headers not found under $SdkDir"
}

function Invoke-MSBuild([string]$project) {
    Write-Host "== msbuild $project ($Configuration|x64)" -ForegroundColor Cyan
    & $msbuild $project /nologo /m /p:Configuration=$Configuration /p:Platform=x64 "/p:LibreOfficeSdkDir=$SdkDir"
    if ($LASTEXITCODE -ne 0) { throw "msbuild failed for $project with exit code $LASTEXITCODE" }
}

# 2. Build the DLL.
Invoke-MSBuild (Join-Path $dir "LOBridge.vcxproj")
$dll = Join-Path $dir "bin\LOBridge.dll"
Write-Host "Built $dll" -ForegroundColor Green

# 3. Optional smoke test: links the same implementation without Dll.cpp, so no registration is needed.
if ($Test) {
    Invoke-MSBuild (Join-Path $dir "tests\native\SmokeTest.vcxproj")
    $testExe = Join-Path $dir "bin\SmokeTest.exe"
    & $testExe
    if ($LASTEXITCODE -ne 0) { throw "smoke test failed" }
}
