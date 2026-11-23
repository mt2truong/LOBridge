# Package sample

`LOBridge.Sample.Package` is a console application that uses the `LOBridge.Net` NuGet package. Its code uses interfaces only. It never references the COM interop types, so the application does not depend on COM.

It does the same work as the Direct sample, plus table reading:

- **Writer:** creates a document, adds paragraphs, saves a `.docx` and exports a `.pdf`.
- **Tables:** opens an existing `.docx`, loops through its tables, rows and cells, and prints the cell text.
- **Calc:** opens a CSV file and prints it through `IWorksheet.GetText`.

## Layers

```text
LOBridge.Sample.Package  --->  LOBridge.Abstractions.*  <---  LOBridge.ComAdapter.*  --->  Interop.LOBridge  --->  LOBridge.dll
     (application)                (interfaces)                 (COM adapter)            (generated)          (native)
```

All of the first three layers ship in the `LOBridge.Net` package. The sample only sees the interfaces and `OfficeFactory`.

| Assembly | Role |
| --- | --- |
| `LOBridge.Abstractions.Writer` | Interfaces: `IWriterApplication`, `IDocument`, `IParagraph`, `ITable`, `ITableRow`, `ITableCell` |
| `LOBridge.Abstractions.Calc` | Interfaces: `ICalcApplication`, `IWorkbook`, `IWorksheet` |
| `LOBridge.ComAdapter` | `OfficeFactory`, the only public entry point. Shared COM release helper |
| `LOBridge.ComAdapter.Writer` / `.Calc` | Implement the interfaces over `Interop.LOBridge`. Internal |

## Why this layering

- **The application stays independent of COM.** Its code compiles without the interop assembly, and it can be tested with a fake implementation of the interfaces.
- **COM details are in one place.** Object release, `Dispose` ordering, and the mapping between property names and COM members live in the adapter.
- **Disposal is explicit.** Each adapter object releases its COM reference once, and using a disposed object throws `ObjectDisposedException`.

## Prerequisites

- `package\Pack.ps1` has run, so `package\nupkg\LOBridge.Net.1.0.0.nupkg` exists. The `nuget.config` in this folder reads that folder.
- The native DLL is registered with `regsvr32` (see [../../../docs/BUILD.md](../../../docs/BUILD.md)).
- LibreOffice 26.8.x is installed. The .NET SDK 10 is installed.

## Run

From this folder:

```powershell
dotnet run -c Release -- C:\temp\lobridge-package ..\LOBridge.Sample.Direct\sample.csv ..\..\..\tests\net\LOBridge.Tests\Fixtures\tables.docx
```

Arguments: the output folder, the CSV file, and the DOCX file whose tables you want to list.

Expected output: `interface-sample.docx` and `interface-sample.pdf` in the output folder. Then every table of the DOCX, row by row and cell by cell, and finally the CSV rows.

## Reading tables

`IDocument.TableCount` and `GetTable` return `ITable`. Each table gives `ITableRow` through `GetRow`, and each row gives `ITableCell` through `GetCell`. Each of these is `IDisposable`, so the sample wraps them in `using` to release the COM reference at the end of each loop.

## Adding a method

1. Add the member to the interface in `package\Abstractions\Writer` or `package\Abstractions\Calc`.
2. Implement it in the matching adapter class in `package\ComAdapter\Writer` or `package\ComAdapter\Calc`.
3. Run `package\Pack.ps1` again, then use the member from the application through the interface only.
