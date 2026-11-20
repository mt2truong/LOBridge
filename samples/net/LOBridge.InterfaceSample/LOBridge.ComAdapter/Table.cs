using LOBridge.Abstractions;
using Com = Interop.LOBridge;

namespace LOBridge.ComAdapter;

/// <summary>Table backed by a native WriterTable COM object.</summary>
internal sealed class Table : ITable
{
    private Com.IWriterTable? _table;

    internal Table(Com.IWriterTable table)
    {
        _table = table;
    }

    public int RowCount => Live().RowCount;

    public int ColumnCount => Live().ColumnCount;

    public ITableRow GetRow(int index) => new TableRow(Live().GetRow(index));

    public void Dispose()
    {
        if (_table is null) return;
        ComRelease.Release(_table);
        _table = null;
    }

    private Com.IWriterTable Live() =>
        _table ?? throw new ObjectDisposedException(nameof(Table));
}
