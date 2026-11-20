using System.IO.Compression;
using System.Runtime.InteropServices;

namespace LOBridge.Tests;

/// <summary>Shared helpers: fixture paths, a per-test scratch folder and a reader for OOXML package parts.</summary>
internal static class TestSupport
{
    public static string FixturePath(string name) =>
        Path.Combine(AppContext.BaseDirectory, "Fixtures", name);

    /// <summary>Creates an empty scratch folder for one test. The caller deletes it.</summary>
    public static string NewScratchDir()
    {
        var dir = Path.Combine(Path.GetTempPath(), "LOBridge.Tests", Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(dir);
        return dir;
    }

    public static void DeleteScratchDir(string dir)
    {
        try
        {
            Directory.Delete(dir, recursive: true);
        }
        catch (IOException)
        {
            // LibreOffice may still hold a file open; the temp folder is cleaned up later.
        }
        catch (UnauthorizedAccessException)
        {
        }
    }

    /// <summary>Returns the text of one part inside an OOXML package.</summary>
    public static string ReadPart(string packagePath, string partName)
    {
        using var zip = ZipFile.OpenRead(packagePath);
        var entry = zip.GetEntry(partName)
            ?? throw new InvalidDataException($"{partName} is missing from {packagePath}");
        using var reader = new StreamReader(entry.Open());
        return reader.ReadToEnd();
    }

    /// <summary>Releases a COM object. Ignores null and managed objects.</summary>
    public static void Release(object? comObject)
    {
        if (comObject is not null && Marshal.IsComObject(comObject))
        {
            Marshal.FinalReleaseComObject(comObject);
        }
    }
}
