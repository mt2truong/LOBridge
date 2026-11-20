# .NET 10 tests

`LOBridge.Tests` is an xUnit project that drives the native COM server from .NET 10 and checks the results against real files. It covers:

- **Writer:** page setup, paragraphs and fonts (including Unicode), `SaveAs` to `.docx`, `Export` to PDF, opening a `.docx` fixture, and error handling for a missing file.
- **Calc:** opening `.xlsx` and `.csv` fixtures, sheet names, used ranges, cell text and numeric values.
- **Registration:** the two ProgIDs and CLSIDs resolve to the native DLL, with the same identifiers as the .NET Framework library.

The tests use a real LibreOffice, so they are integration tests. They run one at a time.

## Prerequisites

- The native DLL is built and registered (see [../../docs/BUILD.md](../../docs/BUILD.md)).
- LibreOffice 26.8.x is installed, and an office is listening on port 2083, or the bridge can start one (see [Known issues](../../README.md#known-issues)).
- .NET SDK 10.0.

## Run

From the repository root:

```powershell
powershell -ExecutionPolicy Bypass -File tests\net\tools\Run-Tests.ps1
```

The script regenerates `LOBridge.Tests\lib\Interop.LOBridge.dll` from the type library, then runs `dotnet test -c Release`.

Expected result: `Total tests: 15, Passed: 15`.

## Fixtures

The files in `LOBridge.Tests\Fixtures` are committed, so the tests need no internet access and no Office install to create them:

| File | Contents |
| --- | --- |
| `sample.docx` | Three paragraphs: a heading, a Unicode body line, and a plain line. A4 page. |
| `sample.xlsx` | One sheet named `Data`: a header row, then `Alpha` = 1.5 and `Beta` = 42. |
| `sample.csv` | The same table as CSV, with `\n` line endings. |

To regenerate the two OOXML files, run `tests\net\tools\New-Fixtures.ps1`. It writes minimal OOXML packages with `System.IO.Compression`.

## Files

| Path | Purpose |
| --- | --- |
| `LOBridge.Tests/WriterTests.cs` | Writer (Word-compatible) tests |
| `LOBridge.Tests/CalcTests.cs` | Calc (Excel-compatible) tests |
| `LOBridge.Tests/RegistrationTests.cs` | ProgID and CLSID checks |
| `LOBridge.Tests/TestSupport.cs` | Scratch folders, fixture paths, OOXML part reader |
| `LOBridge.Tests/Fixtures/` | Test documents |
| `tools/Run-Tests.ps1` | Generates the interop DLL and runs the tests |
| `tools/New-Fixtures.ps1` | Recreates the `.docx` and `.xlsx` fixtures |

## Notes

- Each test creates its own COM objects and releases them with `Marshal.FinalReleaseComObject`. Temporary files go to `%TEMP%\LOBridge.Tests`.
- `AddNewParagraph` on a new document adds a paragraph break after the existing empty paragraph. This matches the .NET Framework version, and the Writer test checks the count relative to the starting count.
- The generated interop names the cell value property `value` (lowercase), not `Value`. The tests use that name.
- The registration tests fail with a clear message on a machine where `regsvr32` has not been run.
