# LOBridge.Net

.NET 10 access to LibreOffice Writer and Calc. The package contains:

| Item | Where in the package | Purpose |
| --- | --- | --- |
| `LOBridge.Net.dll` | `lib/net10.0-windows7.0` | Interfaces (`LOBridge.Abstractions.Writer`, `LOBridge.Abstractions.Calc`) and the COM adapter (`LOBridge.ComAdapter`, `.Writer`, `.Calc`) |
| `Interop.LOBridge.dll` | `lib/net10.0-windows7.0` | COM interop types generated from the native type library |
| `LOBridge.dll` | `build/native` | Native COM server (C++). Copied next to your program at build time |

Your code uses the interfaces and `OfficeFactory` only. It never references the COM interop types.

## Install

```powershell
dotnet add package LOBridge.Net --version 1.0.0
```

Requirements: .NET SDK 10, Windows x64, LibreOffice 26.8.x (the program folder only, no SDK).

## Register the native server once

The native DLL is a COM server, so it must be registered before `OfficeFactory` can create objects. Registration writes to `HKEY_CLASSES_ROOT` and needs administrator rights. Run this from an administrator prompt, using the copy in your program's output folder:

```powershell
regsvr32 "C:\path\to\your\bin\Release\net10.0-windows\LOBridge.dll"
```

COM loads the DLL that was registered, not the copy next to your program. If you register a different copy, COM uses that one. Register again whenever the file moves.

## Use it

```csharp
using LOBridge.Abstractions.Writer;
using LOBridge.ComAdapter;

using IWriterApplication writer = OfficeFactory.CreateWriterApplication();
using IDocument document = writer.NewDocument(false, 595f, 842f);
document.AddParagraph("Hello from LOBridge.Net", 14f);
document.SaveAs(@"C:\temp\hello.docx");
document.Export(@"C:\temp\hello.pdf", "pdf");
```

See the interface sample at `samples/net/LOBridge.Sample.Package` in the repository for tables, rows, cells and CSV output.

## Links

- Repository and documentation: https://github.com/mt2truong/LOBridge
- Build the package yourself: `package\Pack.ps1` in the repository.
