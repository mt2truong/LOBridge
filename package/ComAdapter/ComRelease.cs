using System.Runtime.InteropServices;

namespace LOBridge.ComAdapter;

/// <summary>Releases a COM object once the adapter no longer needs it. Ignores null.</summary>
internal static class ComRelease
{
    public static void Release(object? comObject)
    {
        if (comObject is not null && Marshal.IsComObject(comObject))
        {
            Marshal.FinalReleaseComObject(comObject);
        }
    }
}
