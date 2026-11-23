namespace LOBridge.Abstractions.Calc;

/// <summary>Entry point for Calc (Excel-compatible) workbooks.</summary>
public interface ICalcApplication : IDisposable
{
    /// <summary>Opens a spreadsheet or CSV file.</summary>
    IWorkbook Open(string filePath, bool readOnly);
}
