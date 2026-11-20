# Troubleshooting and known issues

This page records what was found while bringing the native bridge up. Each entry has the symptom, what was tried, and the current state.

## 1. Bootstrap fails or the `Desktop` service is missing

**Symptom:** `StartSession: Desktop service returned null`, or the context exposes only about 37 services and none of them is `com.sun.star.frame.Desktop`.

**Cause:** the UNO bootstrap did not load LibreOffice's `fundamental.ini`, so the service and type registries were never read.

**Fix that works:** set the `URE_BOOTSTRAP` environment variable to the **8.3 short path** of `fundamental.ini`, using the `vnd.sun.star.pathname:` prefix. The 8.3 form has no spaces. After that the context exposes about 1000 services, including `Desktop`.

```text
URE_BOOTSTRAP=vnd.sun.star.pathname:C:\PROGRA~1\LIBREO~1\program\FUNDAM~1.INI
```

`native/src/uno/Uno.cpp` (`Bootstrap`) computes this value with `GetShortPathNameW`.

**Failed attempts (do not repeat):**

| Attempt | Result |
| --- | --- |
| `URE_BOOTSTRAP` with the long path (`C:\Program Files\...`) | Crash (access violation) |
| `URE_BOOTSTRAP` as `file:///` URL, with or without `%20` encoding | Crash, or `Cannot obtain UNO_SERVICES from uno ini` |
| Passing `fundamental.ini` to `defaultBootstrap_InitialComponentContext(ini)` | `Cannot open uno ini` / `Cannot obtain UNO_SERVICES` |
| `UNO_TYPES` / `UNO_SERVICES` environment variables | Crash with `0xC0000409` |
| Changing the working directory to the program folder | No change (still 37 services) |

Space-separated list variables such as `UNO_TYPES` must also use the short path, because the spaces in `Program Files` split the value.

## 2. Process crashes inside the bootstrap or on first interface query

**Symptom:** the process exits with `0xC0000409` (fast-fail) or `0xC00000FD` (stack overflow) while querying a remote object for an interface.

**Cause (working theory):** the local UNO runtime does not know LibreOffice's API types, so describing remote objects recurses. The short-path `URE_BOOTSTRAP` fix (section 1) avoids this in the tests that pass.

**Current state:** the crash did not reproduce after section 1 was applied.

## 3. In-process Desktop creation crashes

**Symptom:** `createInstanceWithContext("com.sun.star.frame.Desktop")` inside the calling process terminates it silently, right after the diagnostic line.

**Current state:** not solved. `StartSession` therefore connects to a separate LibreOffice process over a private socket (port 2083, profile in `%TEMP%\LOBridge\profile`) instead of running the office in-process.

## 4. Office shut down by the first session

**Symptom:** the second session fails with `Binary URP bridge disposed during call`.

**Cause:** `EndSession` called `desktop->terminate()`, which stops the office that other sessions share.

**Fix:** `EndSession` only releases references now. Stop the office yourself, for example:

```powershell
Get-NetTCPConnection -LocalPort 2083 -State Listen | ForEach-Object { Stop-Process -Id $_.OwningProcess -Force }
```

## 5. Automatic launch of the office is not verified

`StartSession` starts `soffice.exe --headless ... --accept=socket,host=localhost,port=2083;urp;StarOffice.ServiceManager` when nothing listens on port 2083, then retries for about 60 seconds. The launch path has been exercised only while a listener was already running, so treat automatic start as unverified until a run starts from a clean state.

## 6. COM registration requires administrator rights

`regsvr32` writes to `HKEY_CLASSES_ROOT`. Run it from an elevated prompt:

```bash
regsvr32 "C:\LOBridge\native\bin\LOBridge.dll"
```

Unregister with `regsvr32 /u` and the same path.

## 7. Empty or wrong results in Calc

**Symptom:** cells read as empty, and the used range has extra rows.

**Cause:** CSV files written with `\r\n` in text mode on Windows contain `\r\r\n`, which LibreOffice reads as blank lines. Write CSV test data with `\n` in text mode.

## 8. Known behaviour differences from the .NET version

- `TableCell.Width` setter and `ScrollIntoView` are no-ops (they were not implemented in .NET either).
- `WordTable.SetTabStops` writes tab positions in points. The .NET code did the same, but LibreOffice expects 1/100 mm, so the tab stop may land in the wrong place. Keep this in mind before relying on it.

See [API.md](API.md) for the full list of differences.
