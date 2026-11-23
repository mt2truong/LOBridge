namespace LOBridge.Abstractions.Writer;

/// <summary>One row of a table. Dispose releases its COM reference.</summary>
public interface ITableRow : IDisposable
{
    int CellCount { get; }

    /// <summary>Returns a cell by zero-based index. Dispose the cell when finished with it.</summary>
    ITableCell GetCell(int index);
}
