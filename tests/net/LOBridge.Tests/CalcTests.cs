using System.Runtime.InteropServices;
using Interop.LOBridge;
using Xunit;

namespace LOBridge.Tests;

/// <summary>Calc (Excel-compatible) API: workbooks, worksheets, used ranges, cells and values.</summary>
public class CalcTests
{
    [Fact]
    public void Open_XlsxFixture_ReadsSheetNameAndUsedRange()
    {
        var app = new CalcAppClass();
        try
        {
            ICalcWorkbook workbook = app.Open(TestSupport.FixturePath("sample.xlsx"), true);
            try
            {
                Assert.Equal(1, workbook.WorksheetCount);

                ICalcWorksheet sheet = workbook.GetWorksheet(0);
                Assert.Equal("Data", sheet.Name);

                ICalcRange used = sheet.UsedRange;
                Assert.Equal(3, used.RowCount);
                Assert.Equal(2, used.ColumnCount);

                TestSupport.Release(used);
                TestSupport.Release(sheet);
            }
            finally
            {
                workbook.Close();
                TestSupport.Release(workbook);
            }
        }
        finally
        {
            app.Dispose();
            TestSupport.Release(app);
        }
    }

    [Fact]
    public void Cells_ReturnTextAndNumericValues()
    {
        var app = new CalcAppClass();
        try
        {
            ICalcWorkbook workbook = app.Open(TestSupport.FixturePath("sample.xlsx"), true);
            try
            {
                ICalcWorksheet sheet = workbook.GetWorksheet(0);
                ICalcRange used = sheet.UsedRange;

                ICalcCell header = used.GetCell(0, 0);
                Assert.Equal("Name", header.Text);
                TestSupport.Release(header);

                ICalcCell alpha = used.GetCell(1, 1);
                Assert.Equal("1.5", alpha.Text);
                Assert.Equal(1.5, Convert.ToDouble(alpha.value));
                TestSupport.Release(alpha);

                ICalcCell beta = used.GetCell(2, 1);
                Assert.Equal(42d, Convert.ToDouble(beta.value));
                TestSupport.Release(beta);

                TestSupport.Release(used);
                TestSupport.Release(sheet);
            }
            finally
            {
                workbook.Close();
                TestSupport.Release(workbook);
            }
        }
        finally
        {
            app.Dispose();
            TestSupport.Release(app);
        }
    }

    [Fact]
    public void Open_CsvFixture_ReadsRows()
    {
        var app = new CalcAppClass();
        try
        {
            ICalcWorkbook workbook = app.Open(TestSupport.FixturePath("sample.csv"), true);
            try
            {
                ICalcWorksheet sheet = workbook.GetWorksheet(0);
                ICalcRange used = sheet.UsedRange;
                Assert.Equal(3, used.RowCount);
                Assert.Equal(2, used.ColumnCount);

                ICalcCell cell = used.GetCell(2, 0);
                Assert.Equal("Beta", cell.Text);
                TestSupport.Release(cell);

                TestSupport.Release(used);
                TestSupport.Release(sheet);
            }
            finally
            {
                workbook.Close();
                TestSupport.Release(workbook);
            }
        }
        finally
        {
            app.Dispose();
            TestSupport.Release(app);
        }
    }

    [Fact]
    public void Open_MissingFile_ThrowsCOMException()
    {
        var app = new CalcAppClass();
        try
        {
            var missing = Path.Combine(TestSupport.NewScratchDir(), "does-not-exist.xlsx");
            Assert.Throws<COMException>(() => app.Open(missing, true));
        }
        finally
        {
            app.Dispose();
            TestSupport.Release(app);
        }
    }
}
