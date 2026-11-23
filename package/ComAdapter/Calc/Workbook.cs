using LOBridge.Abstractions.Calc;
using Com = Interop.LOBridge;

namespace LOBridge.ComAdapter.Calc;

/// <summary>Workbook backed by a native CalcWorkbook COM object.</summary>
internal sealed class Workbook : IWorkbook
{
    private Com.ICalcWorkbook? _workbook;

    internal Workbook(Com.ICalcWorkbook workbook)
    {
        _workbook = workbook;
    }

    public int WorksheetCount => Live().WorksheetCount;

    public IWorksheet GetWorksheet(int index)
    {
        return new Worksheet(Live().GetWorksheet(index));
    }

    public void Close()
    {
        if (_workbook is null) return;
        _workbook.Close();
    }

    public void Dispose()
    {
        if (_workbook is null) return;
        Close();
        ComRelease.Release(_workbook);
        _workbook = null;
    }

    private Com.ICalcWorkbook Live() =>
        _workbook ?? throw new ObjectDisposedException(nameof(Workbook));
}
