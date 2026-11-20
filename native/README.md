# Native COM server (C++)

The C++ COM server that replaces the .NET Framework LibreOffice library (see `../reference-dotnet`). For a step-by-step explanation of what the code does, read [../docs/UNDERSTANDING.md](../docs/UNDERSTANDING.md).

## Prerequisites

- Visual Studio with the C++ tools (x64).
- LibreOffice 26.8.x. The LibreOffice SDK is needed only to build (headers, import libraries, `cppumaker`), not to run. Default SDK location: `C:\Program Files\LibreOffice\sdk`.

## Build

```powershell
powershell -ExecutionPolicy Bypass -File build.ps1          # builds bin\LOBridge.dll
powershell -ExecutionPolicy Bypass -File build.ps1 -Test    # also builds and runs the smoke test (ALL OK)
```

## Layout

| Folder | Contents |
| --- | --- |
| `idl/` | `LOBridge.idl` (the COM contract), `LOBridge.def` (exports), `LOBridge.rc` (embeds the type library) |
| `src/common/` | COM plumbing (`Common`), appSettings (`Config`), ZIP and DEFLATE reader (`Zip`) |
| `src/uno/` | Office connection: `Uno.h` declares `Session`, `StartSession`, `EndSession`; `Uno.cpp` implements them |
| `src/com/` | `Dll.cpp`: class factories, `DllRegisterServer`, `DllUnregisterServer` |
| `src/writer/` | Writer classes, one `.h` and `.cpp` per class: `App`, `Document`, `Paragraph`, `Range`, `Font`, `Style`, `PageSetup`, `Shape`, `Table`, `TableRow`, `TableColumn`, `TableCell`. `Helpers.h` holds the shared helpers. |
| `src/calc/` | Calc classes, one `.h` and `.cpp` per class: `App`, `Workbook`, `Worksheet`, `Range`, `Cell`. `Helpers.h` holds the shared helpers. |
| `tests/native/` | `SmokeTest.cpp`, which calls the C++ classes directly (no registration) |
| `generated/` | Created by the build: UNO headers (`include/`), `LOBridge.h`, `LOBridge_i.c`, `LOBridge.tlb`, `LOBridge.res` |
| `build/` | Created by the build: object files |
| `bin/` | Created by the build: the DLL and `SmokeTest.exe` |

## Names

- C++ classes live in namespaces named after the LibreOffice applications: `writer::App`, `calc::Cell`, and so on.
- COM interfaces are `IWriterApp`, `ICalcCell`, and so on. The coclasses are `WriterApp` and `CalcApp`.
- The CLSIDs and IIDs are unchanged from the .NET Framework library. The ProgIDs are `LOBridge.Writer.App` and `LOBridge.Calc.App`, so callers that create objects by ProgID must use the new names.

## Register

Registration needs an elevated prompt. See [../docs/BUILD.md](../docs/BUILD.md).

## Visual Studio and MSBuild

- `LOBridge.vcxproj`: the DLL (x64, Debug and Release).
- `tests/native/SmokeTest.vcxproj`: the C++ smoke test.
- `LOBridge.props`: settings shared by both native projects (SDK location, include paths, compiler and linker options) and the step that generates the UNO headers.
- `..\LOBridge.sln`: the solution for both native projects and the .NET projects.

Open the solution in Visual Studio, or build from the command line:

```powershell
msbuild ..\LOBridge.sln /p:Configuration=Release /p:Platform=x64
```

`build.ps1` calls MSBuild for the same projects, so both routes produce the same output. Override the SDK location with `/p:LibreOfficeSdkDir="D:\path	o\LibreOffice\sdk"`.
