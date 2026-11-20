# Understanding LOBridge

This guide explains, step by step, what LOBridge does when your .NET code calls it, and what happens when the native DLL is built. It is written for someone who knows C# and .NET but has little or no C++ experience. Each C++ construct is explained where it first appears.

If you only want to build or run the project, see [BUILD.md](BUILD.md). For the list of methods, see [API.md](API.md).

## Contents

1. [The big picture](#1-the-big-picture)
2. [Vocabulary](#2-vocabulary)
3. [What comes from LibreOffice and what we wrote](#3-what-comes-from-libreoffice-and-what-we-wrote)
4. [The Session: what it is and where it comes from](#4-the-session-what-it-is-and-where-it-comes-from)
5. [Following one call from C# to LibreOffice](#5-following-one-call-from-c-to-libreoffice)
6. [Reading the C++ code](#6-reading-the-c-code)
7. [How the DLL is built](#7-how-the-dll-is-built)
8. [What runs where](#8-what-runs-where)
9. [Known weak points](#9-known-weak-points)
10. [Checking it yourself](#10-checking-it-yourself)

---

## 1. The big picture

```text
 Your C# code (.NET 10)
    var app = new WriterAppClass();          <- a COM object, created by the Windows COM system
    app.NewDoc(...)                        <- a method call on that COM object
        │
        │  COM: Windows looks up the CLSID in the registry, loads our DLL,
        │  and asks it for an object that implements IWriterApp.
        ▼
 LOBridge.dll      (our code, written in C++)
    WriterApp::NewDoc(...)                   <- our C++ function, the one that runs
    - turns the call into UNO requests
        │
        │  UNO: LibreOffice's own API, talked to over a local socket (port 2083)
        ▼
 soffice.exe  (LibreOffice, a separate process)
    - creates the Writer document, lays out pages, saves files, exports PDF
```

Two things are important:

- **Your C# code never talks to LibreOffice directly.** It calls our COM object. Our DLL talks to LibreOffice.
- **LibreOffice runs in its own process.** Our DLL starts it if needed, and connects to it through a socket. The office is not loaded inside your program.

---

## 2. Vocabulary

Terms are listed in the order they tend to come up. You don't need to memorise them; come back here when a word is unfamiliar.

| Term | Meaning | Analogy for a .NET developer |
| --- | --- | --- |
| **COM** | Component Object Model, Windows' binary standard for objects that can be used from any language. | A cross-language interface contract, like a COM-visible .NET class, but at the binary level. |
| **DLL** | A compiled library loaded into a process at run time. | A .NET assembly, but native code. |
| **Interface** | A named list of methods that an object promises to implement. | A .NET `interface`. |
| **IID** | A GUID that identifies an interface. | The identity of a .NET interface, as a GUID. |
| **CLSID** | A GUID that identifies a class (the thing you create). | The class identity used by `Activator`. |
| **ProgID** | A readable name for a CLSID, such as `...COM.Word.App`. | An alias for the class GUID. |
| **Registry** | Windows' settings database. COM stores CLSID-to-DLL mappings here. | Where `regsvr32` writes the mapping that `new WriterAppClass()` reads. |
| **regsvr32** | The Windows tool that writes the registry entries for a DLL. | `RegAsm.exe` for managed COM servers. |
| **IDL** | Interface Definition Language. A text file that describes the interfaces. | Roughly a C# interface file, but COM-specific. |
| **midl** | Microsoft's IDL compiler. Turns the IDL file into C++ headers and a type library. | Roughly the compiler step that produces metadata for a .NET assembly. |
| **Type library (.tlb)** | A binary description of the interfaces: method names, parameters, types, IDs. | The metadata in a .NET assembly. |
| **tlbimp** | Reads a type library and writes a .NET assembly with matching C# interfaces. | Same as `Add Reference > COM` in Visual Studio. |
| **Vtable** | A table of function pointers that a C++ object uses to find its methods. | The method table behind a .NET interface call. |
| **IDispatch** | A standard COM interface that lets callers find methods by name at run time (used by `dynamic`). | Reflection, but for COM objects. |
| **HRESULT** | A 32-bit status code. `S_OK` (0) means success, negative values mean failure. | An exception, but returned as a value. |
| **Reference count** | COM objects count their users. When the count reaches zero, the object is deleted. | Like a manual GC: `AddRef` and `Release` keep it alive. |
| **UNO** | Universal Network Objects. LibreOffice's API for everything (documents, text, cells, settings). | The API that LibreOffice exposes, like the object model of Word or Excel. |
| **Service** | A named UNO component, such as `com.sun.star.frame.Desktop`. You ask for one by name. | A type you create by name, through a factory. |
| **Component context** | UNO's root object. It knows all services and the settings of the running process. | A dependency-injection container. |
| **Service manager** | The object inside a context that creates services by name. | The DI container's `GetService` method. |
| **Desktop** | The UNO service that opens, tracks and closes documents. | The application object of Word or Excel. |
| **URP / socket** | The protocol and transport used to talk to a remote office. | A remoting channel, similar to a WCF binding. |
| **Session** | Our wrapper for one connection to LibreOffice: context, desktop and loader. See [section 4](#4-the-session-what-it-is-and-where-it-comes-from). | `new App()` / `Dispose()` in the old .NET library. |
| **Reference<T>** | A C++ smart pointer to a UNO object. It counts references, like a COM pointer. | A .NET reference, with a manual `Release`. |
| **.def file** | A list of functions the DLL exports, such as `DllRegisterServer`. | The public entry points of the assembly. |
| **.lib file** | An import library. It tells the linker which DLL provides a function. | Similar to a reference assembly. |
| **Header (.h / .hpp / .hxx)** | A C++ file that declares types and functions, without the implementation. | A C# interface or a public signature list. |
| **Compile, link** | Compile turns each `.cpp` into an object file (`.obj`). Link combines the object files and libraries into a DLL or EXE. | Compile is like building a project; link is like producing the final assembly. |

---

## 3. What comes from LibreOffice and what we wrote

This table is the most useful one to keep open.

| Piece | Source | Used at | Where in the repo |
| --- | --- | --- | --- |
| UNO API types (`XTextDocument`, `XSpreadsheet`, ...) | Generated by `cppumaker` from LibreOffice's type registry | Build | `native/generated/` (not committed) |
| UNO runtime (`sal3.dll`, `cppu3.dll`, `cppuhelper3MSC.dll`) | LibreOffice `program` folder | Run | Not in repo |
| `soffice.exe` | LibreOffice installation | Run (started by us if needed) | Not in repo |
| `defaultBootstrap_InitialComponentContext` | UNO C++ library (`cppuhelper`) | Run | Called in `native/src/uno/Uno.cpp` |
| `UnoUrlResolver`, `Desktop`, `XComponentLoader` | UNO services | Run | Called in `native/src/uno/Uno.cpp` and the `writer/` and `calc/` sources |
| **`Session` (struct)** | **We wrote it** | Run | `native/src/uno/Uno.h` |
| **`StartSession`, `EndSession`** | **We wrote them** | Run | `native/src/uno/Uno.cpp` |
| **COM classes `WriterApp`, `writer::Document`, ...** | **We wrote them** | Run | `native/src/writer/`, `native/src/calc/*.cpp` |
| **IDL contract (interfaces, GUIDs)** | **We wrote it** | Build | `native/idl/LOBridge.idl` |
| **COM plumbing (`IUnknown`, `IDispatch`, registration)** | **We wrote it** | Run | `native/src/common/Common.h`, `native/src/com/Dll.cpp` |
| **ZIP and DEFLATE reader** | **We wrote it** (no zip library used) | Run | `native/src/common/Zip.cpp` |
| **Build script** | **We wrote it** | Build | `native/build.ps1` |

Short version: LibreOffice gives us the office and its API. We wrote the COM layer that exposes that API to .NET, the connection code, and the build.

---

## 4. The Session: what it is and where it comes from

### It is not a built-in UNO type

**`Session` is our own C++ struct.** It is declared in `native/src/uno/Uno.h`:

```cpp
struct Session
{
    Reference<css::uno::XComponentContext> ctx;
    Reference<css::frame::XDesktop>        desktop;
    Reference<css::frame::XComponentLoader> loader;
};
```

It holds three things that UNO provides:

| Field | What it is | Built into UNO? |
| --- | --- | --- |
| `ctx` | The component context of the office process. It gives access to all services. | Yes. The office creates it. |
| `desktop` | The `com.sun.star.frame.Desktop` service. It opens and tracks documents. | Yes. It is a UNO service. |
| `loader` | The same Desktop, viewed through the `XComponentLoader` interface. It opens files. | Yes. It is an interface of the Desktop. |

So the **Session groups three UNO objects** that every method needs. It exists to avoid repeating the same three lines in each class. It does the same job as the .NET `App` class (constructor starts, `Dispose` ends).

### How it is created

`StartSession()` in `native/src/uno/Uno.cpp` builds it. Here is what it does, in order.

1. **Start Winsock once.** Winsock is the Windows networking library. The socket connection needs it. A `static` variable makes sure this runs only once per process.
2. **Bootstrap a local UNO context.** `Bootstrap()` (in `Uno.cpp`) finds the LibreOffice folder, points the Windows loader at it, and sets `URE_BOOTSTRAP` to the short path of `fundamental.ini`. Then it calls `cppu::defaultBootstrap_InitialComponentContext()`, a UNO function that builds the local context. This local context is only a starting point. It is not the office.
3. **Ask for a connector.** The local service manager creates `com.sun.star.bridge.UnoUrlResolver`. This service connects to remote offices by URL.
4. **Connect to the office.** The resolver is given `uno:socket,host=localhost,port=2083;urp;StarOffice.ComponentContext`. This means: connect over a socket on port 2083, using the URP protocol, and ask the office for its component context.
   - If nothing answers, we start `soffice.exe --headless ... --accept=socket,...` with a private profile in `%TEMP%\LOBridge\profile`, then retry every 0.5 seconds for about 60 seconds.
5. **Create the Desktop inside the office.** The remote context gives us the office's service manager. We ask it for `com.sun.star.frame.Desktop`. Now the Desktop lives in the office process, and our Session points at it.
6. **Store the three references** in the struct and return it.

The result is `Session`. `WriterApp` and `CalcApp` each hold one as a member (`m_session` in `writer/App.h` and `calc/App.h`).

### How it ends

`EndSession()` clears the three references. It does **not** close the office. The office may be used by other callers, so we leave it running. This is why a `soffice.exe` process can still be running after your program exits.

### Lifetime in practice

```text
C#:  var app = new WriterAppClass();   -> WriterApp constructor -> StartSession()   (session created)
C#:  app.NewDoc(...)                 -> uses m_session.loader, m_session.desktop
C#:  app.Dispose();                  -> WriterApp::Dispose() -> EndSession()       (references cleared)
C#:  Marshal.FinalReleaseComObject(app) -> COM count reaches 0 -> ~WriterApp(),
     which calls EndSession only if Dispose was not already called (m_disposed guards it)
```

---

## 5. Following one call from C# to LibreOffice

Take `IWriterDocument doc = app.NewDoc(false, 842f, 595f);` from the sample. Here is what happens.

1. **C# asks COM for the object.** `new WriterAppClass()` tells the .NET runtime to create the COM class with CLSID `{596EF499-...}`. The runtime looks it up in the registry, finds `LOBridge.dll`, loads it, and calls `DllGetClassObject` (exported in `Dll.cpp`). That returns a class factory, which creates a `WriterApp` object.
2. **The constructor starts the Session** (section 4). This is where the office connection is made, the first time only (about a few seconds if the office has to start).
3. **C# calls `NewDoc` through IDispatch or the vtable.** The sample is early-bound, so C# calls the vtable slot for `NewDoc` directly. The vtable is the table of function pointers generated by midl from `LOBridge.idl`.
4. **Our C++ `WriterApp::NewDoc` runs** (`native/src/writer/`). It does three things:
   - asks the Desktop to open a new Writer document: `OpenInternal(Ascii("private:factory/swriter"), ...)`. `private:factory/swriter` is the UNO URL for "a new empty Writer document".
   - wraps the document in a `writer::Document` COM object and sets the page size and orientation through the page style (`writer::PageSetup`).
   - returns the object through `*ppDoc` with a reference count of 1. The caller owns that reference.
5. **Errors.** Any UNO exception is caught by `LO_COM_TRY` / `LO_COM_CATCH` (in `Common.h`). It is logged with the prefix `[LOBridge]`, and the method returns `E_FAIL`. .NET turns that into a `COMException`.
6. **C# releases the object** with `Marshal.FinalReleaseComObject(doc)`. The reference count drops, and when it reaches zero, C++ deletes the `writer::Document` object. That object releases its UNO references too, but the document stays open in the office until `Close()` is called.

---

## 6. Reading the C++ code

You don't need to write C++ to follow the flow. These are the patterns that appear most often.

| You see | It means |
| --- | --- |
| `STDMETHODIMP WriterApp::NewDoc(...)` | A COM method implemented by the class `WriterApp`. `STDMETHODIMP` means it returns an `HRESULT`. |
| `HRESULT` | A status code. `S_OK` is success, `E_FAIL` is failure, `E_POINTER` means a null pointer was passed. |
| `if (!ppDoc) return E_POINTER;` | Guard: the caller passed a null output pointer. |
| `Reference<css::text::XText>` | A UNO object reference (a smart pointer). It keeps the object alive while it exists. `css` is an alias for `com::sun::star`. |
| `text->createTextCursor()` | A method call. `->` is like `.` in C# when calling through a pointer or reference. |
| `ToUrl(...)`, `ToOUString(...)` | Our helper functions that convert between Windows strings, UNO strings (`OUString`), and file URLs. |
| `Ascii("Standard")` | Converts a plain C string to a UNO string. |
| `LO_COM_TRY` ... `LO_COM_CATCH` | A macro (text substitution) that wraps a body in `try { } catch`, so that UNO exceptions become `E_FAIL`. |
| `ReturnNew<IWriterDocument>(obj, out)` | Hands a newly created object to the caller with a reference count of 1. |
| `Release()` / `AddRef()` | Manual reference counting, as COM requires. Our classes do this through `LO_COM_IUNKNOWN_AND_DISPATCH` (in `Common.h`). |
| `m_session.loader->loadComponentFromURL(...)` | Calls the UNO method `loadComponentFromURL` on the loader. Opens or creates a document. |
| `#include "..."` | Copies another file's declarations in at that point. Like a `using` in C#, but it pastes text. |
| `namespace lo_uno { ... }` | A namespace, as in C#. `lo_uno::Session` is `Session` inside `namespace lo_uno`. |
| `static` inside a function | A variable that is created once and kept between calls. |

Two rules of thumb:

- **Every `.h` file declares, every `.cpp` file defines.** When you see a function in a `.h`, its body is in the matching `.cpp`.
- **Each COM class is one `.cpp` section.** `writer/App.cpp` and its sibling files hold `WriterApp`, `writer::Document`, `writer::Paragraph`, and the rest of the Writer classes. `Excel.cpp` holds the Calc classes.

---

## 7. How the DLL is built

`native/build.ps1` runs these steps in order. Each step explains one tool, and why it is needed.

### Step 0: set up the compiler environment

`vcvars64.bat` (from Visual Studio) puts the x64 compiler, linker and Windows tools on the path. The script finds Visual Studio with `vswhere.exe`.

### Step 1: generate UNO headers (`cppumaker`, first build only)

LibreOffice describes its whole API in type-registry files (`program\types\offapi.rdb`). `cppumaker` reads them and writes one C++ header per API type into `native/generated/include/`. Example: `XTextDocument` becomes `com/sun/star/text/XTextDocument.hpp`. Our code `#include`s these headers.

This step needs the SDK. Once the headers exist, the step is skipped.

### Step 2: compile the IDL (`midl`)

`midl` reads `native/idl/LOBridge.idl`, our contract, and produces three files:

| Output | What it is |
| --- | --- |
| `LOBridge.h` | C++ declarations of our interfaces (`IWriterApp`, `IWriterDocument`, ...). Our classes inherit from these. |
| `LOBridge_i.c` | The GUID values for the IIDs and CLSIDs, as real data. |
| `LOBridge.tlb` | The binary type library. Windows uses it for `IDispatch` (by name), and `tlbimp` uses it for .NET. |

### Step 3: embed the type library (`rc`)

`rc` compiles `LOBridge.rc`, which contains one line: resource 1 is `LOBridge.tlb`. The type library is now stored inside the DLL, so only the DLL needs to be deployed.

### Step 4: compile the C++ files (`cl`)

`cl` compiles each `.cpp` file into an object file (`.obj`). Each object file contains machine code for its functions, plus a list of the functions it needs from other places. Compiler flags used:

| Flag | Meaning |
| --- | --- |
| `/c` | Compile only, do not link yet. |
| `/EHsc` | Enable C++ exceptions (UNO uses them). |
| `/MD` | Use the shared (DLL) version of the C runtime. |
| `/std:c++17` | Language version. |
| `/I` | Where to look for headers (`generated`, and the SDK's `include`). |
| `/DCPPU_ENV=msci` | Tells UNO headers which C++ ABI to use (MSVC on Windows). |

### Step 5: link the DLL (`link`)

`link` joins the object files and the libraries into `LOBridge.dll` (named `LOBridge.dll` in the build). Important inputs:

| Input | What it does |
| --- | --- |
| `LOBridge.def` | The list of exported functions that COM and `regsvr32` call (`DllGetClassObject`, `DllRegisterServer`, ...). |
| `icppu.lib`, `icppuhelper.lib`, `isal.lib` | Import libraries from the SDK. They tell the linker about the UNO functions we call. The SDK is used only here. |
| `/DELAYLOAD:sal3.dll`, `/DELAYLOAD:cppu3.dll`, `/DELAYLOAD:cppuhelper3MSC.dll` | The UNO runtime DLLs are loaded when first used, not at start-up. The `SetDllDirectoryW` call in `Bootstrap()` makes sure they are found in the LibreOffice folder. |
| `ole32.lib`, `oleaut32.lib`, `advapi32.lib`, ... | Windows libraries for COM, registry, and strings. |
| `ws2_32.lib` | Winsock, for the socket connection. |

### Step 6 (optional): smoke test (`-Test`)

The smoke test is a separate program. It links the same objects, but without `Dll.obj`. It calls our C++ functions directly, without COM, and checks Writer and Calc. Use it to check the C++ code before registering the DLL.

### After the DLL is built: the .NET side

- `samples/net/tools/Generate-Interop.ps1` runs `tlbimp` on `LOBridge.tlb`. The result is `Interop.LOBridge.dll`, a .NET assembly with `WriterAppClass`, `IWriterDocument`, and the other types the C# code uses.
- `regsvr32` (run by you, as administrator) writes the CLSID and ProgID entries into the registry, and registers the type library.

### Why the SDK is not needed to run

The SDK provides headers, import libraries and `cppumaker`. None of these are used after the DLL is linked. The linked DLL needs only the three UNO DLLs from the LibreOffice folder. See [BUILD.md](BUILD.md#build-machine-and-run-machine).

---

## 8. What runs where

| Part | Process | Lifetime |
| --- | --- | --- |
| Your C# program (sample or tests) | Your process | Until your program exits |
| `LOBridge.dll` (our COM server) | Loaded into your process | Until your process exits |
| `soffice.exe` | Separate process, started by us if needed | Keeps running after your program exits (we never stop it) |
| UNO runtime DLLs | Loaded into your process by `LOBridge.dll` | Same as `LOBridge.dll` |

Two consequences:

- **Documents open in the office stay open** until closed. `Close()` on a document is important.
- **The office is shared.** It listens on port 2083 and remains running. The tests and the sample use the same office. To stop it, use the command in [BUILD.md](BUILD.md#clean-up).

---

## 9. Known weak points

These are real issues in the current code. Each one is also listed in [TROUBLESHOOTING.md](TROUBLESHOOTING.md) or [API.md](API.md).

| Point | Detail |
| --- | --- |
| Out-of-process only | An office started inside our DLL crashed in this environment. We therefore always use the separate `soffice.exe` on port 2083. |
| Auto-start is untested from a clean state | The code starts `soffice.exe` if nothing listens on port 2083. This path has not been verified from a machine with no office running. |
| Office is never stopped | `EndSession` releases references only. If you want the office gone, stop it yourself. |
| Stale comment in `Bootstrap()` | The comment in `native/src/uno/Uno.cpp` says `URE_BOOTSTRAP` is left to the default. The code sets it to the short path of `fundamental.ini`, which is what works. The comment needs to be corrected. |
| Known recursion in `Desktop` query | A remote `Desktop` query can recurse. This is recorded in `StartSession`'s comment and in TROUBLESHOOTING. |
| Partial API | `CreateShape` and `GetRangeHeight` are not implemented. `SetTabStops` may use points where LibreOffice expects 1/100 mm. |

---

## 10. Checking it yourself

These steps show each layer working on your machine. Run them from the repository root in PowerShell.

1. **Check the DLL's dependencies.** Shows that the DLL needs only Windows and the three UNO DLLs.

   ```powershell
   & "C:\Program Files\Microsoft Visual Studio\18\Enterprise\VC\Tools\MSVC\14.44.35207\bin\Hostx64\x64\dumpbin.exe" /dependents native\bin\LOBridge.dll
   ```

   The version folder differs by machine; `dumpbin` is in the "x64 Native Tools" folder of Visual Studio.

2. **Check the registration.** Shows the ProgID points to our DLL.

   ```powershell
   Get-ItemProperty "Registry::HKEY_CLASSES_ROOT\CLSID\{596EF499-A61F-4977-A257-D06A8C8D8E03}\InprocServer32"
   ```

3. **Check the office is listening.** Shows the socket that the Session connects to.

   ```powershell
   Get-NetTCPConnection -LocalPort 2083 -State Listen
   ```

4. **Run the C++ smoke test.** Calls our C++ code directly, without COM.

   ```powershell
   powershell -ExecutionPolicy Bypass -File native\build.ps1 -Test
   ```

5. **Run the .NET tests.** Calls our COM server from C#.

   ```powershell
   powershell -ExecutionPolicy Bypass -File tests\net\tools\Run-Tests.ps1
   ```

6. **Watch the log.** Our code writes `[LOBridge] ...` messages to the error stream and the debugger. In the test output, lines such as `URE_BOOTSTRAP set` come from `StartSession`.

If step 5 passes, every layer in section 1 has worked at least once on your machine.
