using LOBridge.Abstractions;
using Com = Interop.LOBridge;

namespace LOBridge.ComAdapter;

/// <summary>Worksheet backed by a native CalcWorksheet COM object. Reads go through the used range.</summary>
internal sealed class Worksheet : IWorksheet
{
    private readonly Com.ICalcWorksheet _sheet;
    private readonly Com.ICalcRange _used;

    internal Worksheet(Com.ICalcWorksheet sheet)
    {
        _sheet = sheet;
        _used = sheet.UsedRange;
    }

    public string Name => _sheet.Name;

    public int RowCount => _used.RowCount;

    public int ColumnCount => _used.ColumnCount;

    public string GetText(int row, int column)
    {
        var cell = _used.GetCell(row, column);
        try
        {
            return cell.Text;
        }
        finally
        {
            ComRelease.Release(cell);
        }
    }
}
