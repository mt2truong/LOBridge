using LOBridge.Abstractions.Writer;
using Com = Interop.LOBridge;

namespace LOBridge.ComAdapter.Writer;

/// <summary>Table cell backed by a native WriterTableCell COM object.</summary>
internal sealed class TableCell : ITableCell
{
    private Com.IWriterTableCell? _cell;

    internal TableCell(Com.IWriterTableCell cell)
    {
        _cell = cell;
    }

    public string Text => (_cell ?? throw new ObjectDisposedException(nameof(TableCell))).Text;

    public void Dispose()
    {
        if (_cell is null) return;
        ComRelease.Release(_cell);
        _cell = null;
    }
}
