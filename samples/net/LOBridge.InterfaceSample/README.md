# Interface sample

This sample shows the layering used by the TRS `PdfCom` wrapper, applied to LOBridge. The application codes against .NET interfaces, and a separate assembly implements those interfaces over the COM interop types. The application never references the interop types directly.

## Layout

| Project | Role | References |
| --- | --- | --- |
| `LOBridge.Abstractions` | Interfaces only: `IWriterApplication`, `IDocument`, `IParagraph`, `ICalcApplication`, `IWorkbook`, `IWorksheet` | Nothing |
| `LOBridge.ComAdapter` | Implements the interfaces over `Interop.LOBridge`. `OfficeFactory` is the only public entry point. | `LOBridge.Abstractions`, `Interop.LOBridge` |
| `LOBridge.InterfaceSample` | Console app that writes a DOCX and PDF, opens an existing DOCX and prints its tables, and reads a CSV | `LOBridge.Abstractions`, `LOBridge.ComAdapter` |

```text
LOBridge.InterfaceSample  --->  LOBridge.Abstractions  <---  LOBridge.ComAdapter  --->  Interop.LOBridge  --->  LOBridge.dll
        (application)              (interfaces)                 (COM adapter)                (generated)          (native)
```

## Why this layering

- **The application stays independent of COM.** Its code compiles without the interop assembly, and it can be tested with a fake implementation of the interfaces.
- **COM details are in one place.** Object release, `Dispose` ordering, and the mapping between property names and COM members live in the adapter.
- **Disposal is explicit.** Each adapter object releases its COM reference once, and using a disposed object throws `ObjectDisposedException`.

## Prerequisites

- The native DLL is built and registered (see [../../../docs/BUILD.md](../../../docs/BUILD.md)).
- `samples\net\LOBridge.Sample\lib\Interop.LOBridge.dll` exists (run `samples\net\tools\Generate-Interop.ps1`).
- LibreOffice 26.8.x and the .NET SDK 10.0.

## Run

From this folder:

```powershell
cd LOBridge.InterfaceSample
dotnet run -c Release -- C:\temp\lobridge-interface ..\LOBridge.Sample\sample.csv ..\..\..\tests\net\LOBridge.Tests\Fixtures\tables.docx
```

Arguments: the output folder, the CSV file, and the DOCX file whose tables you want to list.

Expected output: `interface-sample.docx` and `interface-sample.pdf` in the output folder. Then every table of the DOCX, row by row and cell by cell, and finally the CSV rows printed through `IWorksheet.GetText`.

## Reading tables

`IDocument.TableCount` and `GetTable` return `ITable`. Each table gives `ITableRow` through `GetRow`, and each row gives `ITableCell` through `GetCell`. Each of these is `IDisposable`, so the sample wraps them in `using` to release the COM reference at the end of each loop.

## Adding a method

1. Add the member to the interface in `LOBridge.Abstractions`.
2. Implement it in the matching adapter class in `LOBridge.ComAdapter`.
3. Use it from the application through the interface only.
