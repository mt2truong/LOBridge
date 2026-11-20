using LOBridge.Abstractions;

namespace LOBridge.ComAdapter;

/// <summary>
/// Creates the COM-backed implementations. Callers hold only the interfaces, so the COM
/// registration and the interop types stay inside this assembly.
/// </summary>
public static class OfficeFactory
{
    public static IWriterApplication CreateWriterApplication() => new WriterApplication();

    public static ICalcApplication CreateCalcApplication() => new CalcApplication();
}
