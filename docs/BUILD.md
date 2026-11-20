# Build, register and run

## Prerequisites

| Component | Version used | Notes |
| --- | --- | --- |
| Windows | 10 / 11 x64 | The COM server is x64 only |
| Visual Studio with C++ tools | 2022 or newer (MSVC 14.5x) | `vswhere` must be able to find it |
| LibreOffice SDK | 26.8.x | Build machine only (`sdk\include`, `sdk\lib`, `sdk\bin\cppumaker.exe`) |
| LibreOffice | 26.8.x | Build and run machines. Provides `program\sal3.dll`, `cppu3.dll`, `cppuhelper3MSC.dll` |
| .NET SDK | 10.0 | Only for the sample and tests |

The LibreOffice SDK is not part of this repository. Its default location is `C:\Program Files\LibreOffice\sdk`; pass `-SdkDir` to `build.ps1` if yours is elsewhere.

### Build machine and run machine

The SDK is needed only to build the DLL. It provides the headers, the import libraries and `cppumaker`, none of which are used at run time.

| Task | LibreOffice | LibreOffice SDK |
| --- | --- | --- |
| Build `LOBridge.dll` | Yes | Yes |
| Run the COM server, the sample or the tests | Yes | No |

The built DLL imports only Windows and VC runtime DLLs, plus `sal3.dll`, `cppu3.dll` and `cppuhelper3MSC.dll`. The last three are delay-loaded from the LibreOffice `program` folder. The DLL does not reference the SDK. To deploy to a machine without the SDK:

1. Copy `LOBridge.dll` and its `.config` file.
2. Install the Visual C++ 2022 x64 redistributable if the VC runtime is missing.
3. Install LibreOffice 26.8.x. The DLL finds it through `LIBREOFFICE_PROGRAM`, the `HKLM\SOFTWARE\LibreOffice\UNO\InstallPath` registry value, or `C:\Program Files\LibreOffice\program`, in that order.
4. Register the DLL from an elevated prompt with `regsvr32`.

Removing the SDK from a machine that has already built the DLL does not affect the registered server. This has been checked from the DLL's imports, not by running a machine without the SDK; that test is still open.

## Build the native library

From `native\`:

```powershell
powershell -ExecutionPolicy Bypass -File build.ps1
```

The script does the following:

1. Loads the x64 developer environment (`vcvars64.bat`).
2. Generates the UNO C++ headers into `native\generated\include` with `cppumaker`, on the first build only.
3. Compiles the IDL with `midl` (`LOBridge.h`, `LOBridge_i.c`, `LOBridge.tlb`).
4. Embeds the type library with `rc`, compiles and links `LOBridge.dll`.

Add `-Test` to also build and run `SmokeTest.exe`, which drives both the Writer and Calc paths. The smoke test expects a LibreOffice office listening on port 2083. It also tries to start one itself, but that path is not yet verified (see [TROUBLESHOOTING.md](TROUBLESHOOTING.md) §5), so start the office first if the test hangs.

## Register the COM server

Registration writes to `HKEY_CLASSES_ROOT` and needs an elevated prompt:

```bash
regsvr32 "C:\LOBridge\native\bin\LOBridge.dll"
```

To remove it:

```bash
regsvr32 /u "C:\LOBridge\native\bin\LOBridge.dll"
```

Registration registers two ProgIDs:

- `LOBridge.Writer.App` (CLSID `{596EF499-A61F-4977-A257-D06A8C8D8E03}`)
- `LOBridge.Calc.App` (CLSID `{65ED3120-936C-4BEA-996E-C6C9CF35B179}`)

These are the same identifiers as the .NET Framework server, so existing callers keep working.

## Generate the .NET interop assembly

The .NET sample uses early-bound interop types. Generate the assembly from the type library after the native DLL is built:

```powershell
powershell -ExecutionPolicy Bypass -File samples\net\tools\Generate-Interop.ps1
```

The script runs the x64 `TlbImp.exe` from the Windows SDK NETFX tools and writes `samples\net\LOBridge.Sample\lib\Interop.LOBridge.dll`. Regenerate it whenever `LOBridge.idl` changes.

Callers then create objects with `new WriterAppClass()`, `new CalcAppClass()` and use the `IWriterDocument`, `ICalcWorkbook`, and other interfaces. No `Activator.CreateInstance` is needed.

## Run the .NET sample

```powershell
cd samples\net\LOBridge.Sample
dotnet run -c Release -- C:\temp\lobridge-out sample.csv
```

The sample writes `sample.docx` and `sample.pdf` into the output folder and prints the contents of the CSV.

## Run the .NET tests

```powershell
powershell -ExecutionPolicy Bypass -File tests\net\tools\Run-Tests.ps1
```

The script regenerates the interop DLL for the test project, then runs `dotnet test -c Release`. The 15 tests cover Writer (create, text and font, `.docx` save, PDF export, open, missing file), Calc (`.xlsx` and `.csv` open, cells, used range) and the ProgID and CLSID registration. Fixtures are in `tests\net\LOBridge.Tests\Fixtures` and are described in [tests/net/README.md](../tests/net/README.md).

## Clean up

- Stop the office used by the bridge (port 2083) when you are done:

  ```powershell
  Get-NetTCPConnection -LocalPort 2083 -State Listen | ForEach-Object { Stop-Process -Id $_.OwningProcess -Force }
  ```

- `native\generated\` and the build outputs are safe to delete. They are rebuilt on the next run.
