using Microsoft.Win32;
using Xunit;

namespace LOBridge.Tests;

/// <summary>Checks that the native server is registered under the same identifiers as the .NET Framework library.</summary>
public class RegistrationTests
{
    public static IEnumerable<object[]> ProgIds() =>
    [
        ["LOBridge.Writer.App", "{596EF499-A61F-4977-A257-D06A8C8D8E03}"],
        ["LOBridge.Calc.App", "{65ED3120-936C-4BEA-996E-C6C9CF35B179}"],
    ];

    [Theory]
    [MemberData(nameof(ProgIds))]
    public void ProgId_ResolvesToExpectedClsid(string progId, string clsid)
    {
        // Fails with a clear message if regsvr32 has not been run on this machine.
        using var key = Registry.ClassesRoot.OpenSubKey($@"{progId}\CLSID");
        Assert.NotNull(key);
        Assert.Equal(clsid, key!.GetValue(null) as string, ignoreCase: true);
    }

    [Theory]
    [MemberData(nameof(ProgIds))]
    public void Clsid_PointsToExistingInprocServer(string progId, string clsid)
    {
        using var key = Registry.ClassesRoot.OpenSubKey($@"CLSID\{clsid}\InprocServer32");
        Assert.NotNull(key);
        var path = key!.GetValue(null) as string;
        Assert.True(File.Exists(path), $"InprocServer32 for {progId} points to a missing file: {path}");
    }
}
