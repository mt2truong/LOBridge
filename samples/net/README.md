# .NET 10 samples

Two console applications show the two ways to use LOBridge from .NET 10. Both write the same kind of output: a `.docx`, a `.pdf`, and the contents of a CSV.

| Sample | Uses | Code style | Read this when |
| --- | --- | --- | --- |
| [`LOBridge.Sample.Direct`](LOBridge.Sample.Direct/) | `LOBridge.dll` directly, through generated interop types | Early-bound: `new WriterAppClass()`, `IWriterDocument` | You reference the native COM server yourself |
| [`LOBridge.Sample.Package`](LOBridge.Sample.Package/) | The `LOBridge.Net` NuGet package from [`package/`](../../package/) | Interfaces: `OfficeFactory`, `IDocument`, `IWorksheet` | You want the application to depend on interfaces only |

Both samples need the same setup:

1. The native DLL is built (`native\build.ps1`).
2. The native DLL is registered once with `regsvr32` (see [docs/BUILD.md](../../docs/BUILD.md)).
3. LibreOffice 26.8.x is installed, and the .NET SDK 10 is available.

The Package sample also needs `package\Pack.ps1` run once, so that the local feed `package\nupkg` exists.

Shared files:

| Path | Purpose |
| --- | --- |
| [`tools/Generate-Interop.ps1`](../../tools/Generate-Interop.ps1) | Runs `TlbImp.exe` on `native/generated/LOBridge.tlb`. Used by the Direct sample, the tests and the package |
