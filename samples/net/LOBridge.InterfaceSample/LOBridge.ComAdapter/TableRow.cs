using LOBridge.Abstractions;
using Com = Interop.LOBridge;

namespace LOBridge.ComAdapter;

/// <summary>Table row backed by a native WriterTableRow COM object.</summary>
internal sealed class TableRow : ITableRow
{
    private Com.IWriterTableRow? _row;

    internal TableRow(Com.IWriterTableRow row)
    {
        _row = row;
    }

    public int CellCount => Live().CellCount;

    public ITableCell GetCell(int index) => new TableCell(Live().GetCell(index));

    public void Dispose()
    {
        if (_row is null) return;
        ComRelease.Release(_row);
        _row = null;
    }

    private Com.IWriterTableRow Live() =>
        _row ?? throw new ObjectDisposedException(nameof(TableRow));
}
