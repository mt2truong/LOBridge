# Direct sample

`LOBridge.Sample.Direct` is a console application that references the native COM server through early-bound interop types. It shows the two main paths:

- **Writer:** creates a document, sets paragraph text and font size, reads page and paper information, saves a `.docx` and exports a `.pdf`.
- **Calc:** opens a CSV file as a workbook and prints the used range.

## Prerequisites

- The native DLL is built and registered (see [../../../docs/BUILD.md](../../../docs/BUILD.md)).
- `lib\Interop.LOBridge.dll` exists (run `tools\Generate-Interop.ps1`).
- LibreOffice 26.8.x is installed.
- .NET SDK 10.0.

## Run

From this folder:

```powershell
dotnet run -c Release -- C:\temp\lobridge-out sample.csv
```

Arguments:

1. Output folder. Created if missing.
2. CSV file to open in Calc.

Expected output (abbreviated):

```text
== Writer
  paragraphs: 3, characters: 98
  paper: A4, width 594.9921 pt
  saved: C:\temp\lobridge-out\sample.docx
  exported: C:\temp\lobridge-out\sample.pdf
== Calc
  sheet: sample
  used range: 3 x 2
  Name | Value
  Alpha | 1.5
  Beta | 42
```

## How it calls COM

The sample is early-bound. It references `lib\Interop.LOBridge.dll`, generated from the native type library by [../../../tools/Generate-Interop.ps1](../../../tools/Generate-Interop.ps1). Objects are created with `new WriterAppClass()` or `new CalcAppClass()`, not `Activator.CreateInstance`. Each COM object is released with `Marshal.FinalReleaseComObject` once it is no longer needed.

The first call starts the bridge, which connects to LibreOffice (see [../../../docs/ARCHITECTURE.md](../../../docs/ARCHITECTURE.md#office-session)).

## Files

| Path | Purpose |
| --- | --- |
| `Program.cs` | Writer and Calc sample |
| `sample.csv` | Input for the Calc part |
| `lib/` | Generated interop DLL (not committed) |
