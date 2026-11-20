namespace LOBridge.Abstractions;

/// <summary>A table in a Writer document. Dispose releases its COM reference.</summary>
public interface ITable : IDisposable
{
    int RowCount { get; }

    int ColumnCount { get; }

    /// <summary>Returns a row by zero-based index. Dispose the row when finished with it.</summary>
    ITableRow GetRow(int index);
}
