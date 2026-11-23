# LOBridge

A native C++ COM server that exposes LibreOffice's UNO API to .NET 10 through COM. It replaces the .NET Framework library it was ported from and keeps the same COM contract (interface IDs and ProgIDs), so existing callers keep working.

> **Status: experimental.** The Writer and Calc smoke test passes end to end. Automatic start of the office and registration on other machines are not yet verified. See [Known issues](#known-issues).

## Why native C++

A COM component integrates the LibreOffice SDK with .NET. The SDK's managed UNO bridge (`cli_*` assemblies) does not work with .NET 5 and later, so this project talks to LibreOffice from native code and gives .NET callers a COM surface they can use from any version of .NET.

## Features

- **Writer (Word-compatible API):** create and open documents, paragraphs, fonts, styles, page setup, tables, rows, columns, cells, text boxes and shapes.
- **Export:** save as `.docx`, `.doc`, `.rtf`, `.pdf`, and a `word/document.xml` extract (`xml`), read with a built-in ZIP and DEFLATE reader.
- **Calc (Excel-compatible API):** open workbooks, worksheets, used ranges, cells and values.
- **Dual interfaces:** usable from late-bound (`dynamic`), early-bound, and C++ callers.

## Repository layout

| Path | Contents |
| --- | --- |
| [`native/`](native/) | C++ COM server, IDL, build script, smoke test |
| [`package/`](package/) | NuGet package `LOBridge.Net`: interfaces, COM adapter, interop types, native DLL |
| [`samples/net/`](samples/net/) | Two .NET 10 samples: direct use of `LOBridge.dll`, and use through the package |
| [`docs/`](docs/) | Architecture, API reference, build guide, troubleshooting |

## Requirements

- Windows 10 or 11, x64
- Visual Studio 2022 or newer with the C++ tools (x64)
- LibreOffice 26.8.x with its SDK at `C:\Program Files\LibreOffice\sdk`
- .NET SDK 10.0 (only for the sample)

## Quick start

1. Build the native library:

   ```powershell
   cd native
   powershell -ExecutionPolicy Bypass -File build.ps1
   ```

2. Register the COM server from an elevated prompt:

   ```bash
   regsvr32 "C:\LOBridge\native\bin\LOBridge.dll"
   ```

3. Generate the .NET interop assembly from the type library:

   ```powershell
   powershell -ExecutionPolicy Bypass -File tools\Generate-Interop.ps1
   ```

4. Run the .NET sample:

   ```powershell
   cd samples\net\LOBridge.Sample.Direct
   dotnet run -c Release -- C:\temp\lobridge-out sample.csv
   ```

A minimal example in C# (early-bound, like the `PdfCom` interop):

```csharp
using Interop.LOBridge;

var app = new WriterAppClass();
IWriterDocument doc = app.NewDoc(false, 842f, 595f);   // A4 portrait, in points
IWriterParagraph paragraph = doc.AddNewParagraph();
paragraph.Text = "Hello from .NET 10";
doc.SaveAs(@"C:\temp\hello.docx");
doc.Close();
app.Dispose();
```

## Documentation

- [Understanding LOBridge](docs/UNDERSTANDING.md): a step-by-step guide for readers new to C++, covering COM, UNO, the Session and the build
- [Architecture](docs/ARCHITECTURE.md): layers, object model, office session
- [API reference](docs/API.md): every interface, and the differences from the .NET version
- [Build, register and run](docs/BUILD.md)
- [Troubleshooting and known issues](docs/TROUBLESHOOTING.md)

## Known issues

- The office runs out of process on port 2083. Starting it automatically is implemented but not yet verified from a clean state.
- The in-process Desktop crashes in this environment, so the bridge does not use it.
- `WordTable.SetTabStops` writes positions in points; LibreOffice expects 1/100 mm.
- `CreateShape` and `GetRangeHeight` are not implemented.

Details and workarounds are in [TROUBLESHOOTING.md](docs/TROUBLESHOOTING.md).

## Testing

- `native\build.ps1 -Test` builds and runs the C++ smoke test, which covers Writer and Calc.
- `tests\net\LOBridge.Tests` is an xUnit project for .NET 10 with 15 tests: Writer, Calc and registration. Run it with `powershell -ExecutionPolicy Bypass -File tests\net\tools\Run-Tests.ps1`. See [tests/net/README.md](tests/net/README.md).
- `samples\net\LOBridge.Sample.Direct` exercises the COM surface from .NET 10 (early-bound, `LOBridge.dll` directly).
- `samples\net\LOBridge.Sample.Package` does the same through the `LOBridge.Net` package (`package\Pack.ps1` first).

## Contributing

Issues and pull requests are welcome. Before opening a pull request:

1. Build with `native\build.ps1 -Test` and confirm `ALL OK`.
2. Keep the interface IDs and ProgIDs unchanged; they are part of the compatibility contract.
3. Update [`docs/API.md`](docs/API.md) when the IDL changes.

## License

Released under the [MIT License](LICENSE).
