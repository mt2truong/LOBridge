using LOBridge.Abstractions.Calc;
using Com = Interop.LOBridge;

namespace LOBridge.ComAdapter.Calc;

/// <summary>Calc application backed by the native CalcApp COM object.</summary>
internal sealed class CalcApplication : ICalcApplication
{
    private Com.CalcAppClass? _app = new();

    public IWorkbook Open(string filePath, bool readOnly)
    {
        var app = _app ?? throw new ObjectDisposedException(nameof(CalcApplication));
        return new Workbook(app.Open(filePath, readOnly));
    }

    public void Dispose()
    {
        if (_app is null) return;
        _app.Dispose();
        ComRelease.Release(_app);
        _app = null;
    }
}
