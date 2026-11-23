namespace LOBridge.Abstractions.Calc;

/// <summary>One worksheet of a workbook.</summary>
public interface IWorksheet
{
    string Name { get; }

    int RowCount { get; }

    int ColumnCount { get; }

    /// <summary>Returns the displayed text of a cell. Indexes are zero-based, relative to the used range.</summary>
    string GetText(int row, int column);
}
