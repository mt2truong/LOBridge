namespace LOBridge.Abstractions;

/// <summary>A Calc workbook. Dispose releases the workbook and its COM references.</summary>
public interface IWorkbook : IDisposable
{
    int WorksheetCount { get; }

    IWorksheet GetWorksheet(int index);

    void Close();
}
