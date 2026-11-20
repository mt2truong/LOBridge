// Smoke test for the native library without COM registration: drives App/App through their C++ vtables.
#include "Common.h"
#include "writer/App.h"
#include "calc/App.h"

#include <cstdio>
#include <string>

HINSTANCE g_hModule = nullptr;
LONG g_objectCount = 0;

static int g_failures = 0;

static void Check(const char* what, HRESULT hr)
{
    if (FAILED(hr))
    {
        ++g_failures;
        std::printf("FAIL %-40s hr=0x%08lX\n", what, (unsigned long)hr);
    }
    else
    {
        std::printf("ok   %s\n", what);
    }
}

static void PrintBstr(const char* label, BSTR b)
{
    std::wstring w = b ? std::wstring(b) : std::wstring(L"<null>");
    std::printf("     %s = %ls\n", label, w.c_str());
    if (b) SysFreeString(b);
}

static void Diagnose()
{
    std::printf("  diag: StartSession\n");
    lo_uno::Session diag = lo_uno::StartSession();
    std::printf("  diag: context valid=%d\n", (int)diag.ctx.is());
    if (!diag.ctx.is()) { std::printf("diag: no context\n"); return; }
    std::printf("  diag: getServiceManager\n");
    auto smgr = diag.ctx->getServiceManager();
    std::printf("  diag: smgr valid=%d, listing services\n", (int)smgr.is());
    auto names = smgr->getAvailableServiceNames();
    std::printf("  diag: listed\n");
    int hits = 0;
    for (const auto& n : names)
    {
        if (n.indexOf(OUString::createFromAscii("UnoUrlResolver")) >= 0 || n.indexOf(OUString::createFromAscii("Desktop")) >= 0)
        {
            ++hits;
            std::printf("  service: %s\n", rtl::OUStringToOString(n, RTL_TEXTENCODING_UTF8).getStr());
        }
    }
    std::printf("  %d services available, %d mention Desktop, loader=%s\n",
                (int)names.getLength(), hits, diag.loader.is() ? "yes" : "no");
    std::printf("  diag: before EndSession\n");
    lo_uno::EndSession(diag);
    std::printf("  diag: after EndSession\n");
}

int main()
{
    std::setvbuf(stdout, nullptr, _IONBF, 0);
    const wchar_t* dir = L"C:\\Users\\ttran329\\AppData\\Local\\Temp\\lo-native-test";
    CreateDirectoryW(dir, nullptr);
    std::wstring base = dir;
    CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);

    std::printf("LibreOffice program: %ls\n", lo_uno::LibreOfficeProgramDir().c_str());
    Diagnose();

    // ---- Writer ----
    {
        IWriterApp* app = new writer::App();   // refcount 1
        IWriterDocument* doc = nullptr;
        Check("App.NewDoc", app->NewDoc(VARIANT_FALSE, 842.0f, 595.0f, &doc));
        if (!doc) { std::printf("no document\n"); app->Release(); return 1; }

        IWriterParagraph* p1 = nullptr;
        Check("Document.AddNewParagraph (1)", doc->AddNewParagraph(&p1));
        Check("Paragraph.put_Text", p1->put_Text(SysAllocString(L"Hello from the native LibreOffice COM bridge.")));

        IWriterParagraph* p2 = nullptr;
        Check("Document.AddNewParagraph (2)", doc->AddNewParagraph(&p2));
        Check("Paragraph.put_Text (2)", p2->put_Text(SysAllocString(L"Second paragraph, Vietnamese: Xin chào.")));

        IWriterFont* font = nullptr;
        Check("Paragraph.get_Font", p1->get_Font(&font));
        Check("Font.put_Size", font->put_Size(18.0f));
        float size = 0;
        font->get_Size(&size);
        std::printf("     font size = %.1f\n", size);
        font->Release();

        long paragraphs = 0, chars = 0;
        Check("Document.get_ParagraphCount", doc->get_ParagraphCount(&paragraphs));
        Check("Document.get_CharacterCount", doc->get_CharacterCount(&chars));
        std::printf("     paragraphs=%ld characters=%ld\n", paragraphs, chars);

        IWriterPageSetup* ps = nullptr;
        Check("Document.get_PageSetup", doc->get_PageSetup(&ps));
        float w = 0, h = 0, lm = 0;
        BSTR paper = nullptr;
        ps->get_PageWidth(&w);
        ps->get_PageHeight(&h);
        ps->get_LeftMargin(&lm);
        ps->get_PaperSize(&paper);
        std::printf("     page %.1f x %.1f pt, left margin %.1f pt\n", w, h, lm);
        PrintBstr("paper size", paper);
        ps->Release();

        std::wstring docx = base + L"\\writer-test.docx";
        std::wstring pdf = base + L"\\writer-test.pdf";
        std::wstring xml = base + L"\\writer-test.xml";
        Check("Document.SaveAs(docx)", doc->SaveAs(SysAllocString(docx.c_str())));
        Check("Document.Export(pdf)", doc->Export(SysAllocString(pdf.c_str()), SysAllocString(L"pdf")));
        Check("Document.Export(xml)", doc->Export(SysAllocString(xml.c_str()), SysAllocString(L"xml")));

        BSTR tmpl = nullptr;
        Check("Document.GetTemplateName", doc->GetTemplateName(SysAllocString(docx.c_str()), &tmpl));
        PrintBstr("template", tmpl);

        IWriterStyle* style = nullptr;
        Check("Document.GetStyleByName(Standard)", doc->GetStyleByName(SysAllocString(L"Standard"), &style));
        if (style) { BSTR n = nullptr; style->get_Name(&n); PrintBstr("style", n); style->Release(); }

        p1->Release();
        p2->Release();
        Check("Document.Close", doc->Close());
        doc->Release();
        Check("App.Dispose", app->Dispose());
        app->Release();

        IWriterApp* app2 = new writer::App();
        IWriterDocument* doc2 = nullptr;
        Check("App.Open(docx)", app2->Open(SysAllocString(docx.c_str()), VARIANT_TRUE, &doc2));
        if (doc2)
        {
            IWriterParagraph* para = nullptr;
            Check("Document.GetParagraph(0)", doc2->GetParagraph(0, &para));
            if (para) { BSTR t = nullptr; para->get_Text(&t); PrintBstr("paragraph 0", t); para->Release(); }
            long pages = 0;
            doc2->get_PageCount(&pages);
            std::printf("     pages = %ld\n", pages);
            doc2->Close();
            doc2->Release();
        }
        app2->Dispose();
        app2->Release();
    }

    // ---- Calc ----
    {
        std::wstring csv = base + L"\\calc-test.csv";
        if (FILE* f = _wfopen(csv.c_str(), L"w"))
        {
            // Text mode already writes CRLF on Windows: use plain \n to avoid blank rows.
            std::fputs("Name,Value\nAlpha,1.5\nBeta,42\n", f);
            std::fclose(f);
        }

        ICalcApp* xapp = new calc::App();
        ICalcWorkbook* wb = nullptr;
        Check("App.Open(csv)", xapp->Open(SysAllocString(csv.c_str()), VARIANT_TRUE, &wb));
        if (wb)
        {
            long sheets = 0;
            wb->get_WorksheetCount(&sheets);
            std::printf("     worksheets = %ld\n", sheets);
            ICalcWorksheet* sheet = nullptr;
            wb->GetWorksheet(0, &sheet);
            if (sheet)
            {
                BSTR name = nullptr;
                sheet->get_Name(&name);
                PrintBstr("sheet name", name);
                ICalcRange* used = nullptr;
                Check("Worksheet.UsedRange", sheet->get_UsedRange(&used));
                if (used)
                {
                    long rows = 0, cols = 0;
                    used->get_RowCount(&rows);
                    used->get_ColumnCount(&cols);
                    std::printf("     used range %ld x %ld\n", rows, cols);
                    for (long r = 0; r < rows && r < 4; ++r)
                    {
                        for (long c = 0; c < cols; ++c)
                        {
                            ICalcCell* dump = nullptr;
                            used->GetCell(r, c, &dump);
                            BSTR t = nullptr;
                            if (dump) { dump->get_Text(&t); dump->Release(); }
                            std::printf("     cell[%ld,%ld] = %ls\n", r, c, t ? t : L"<null>");
                            if (t) SysFreeString(t);
                        }
                    }
                    ICalcCell* cell = nullptr;
                    used->GetCell(1, 1, &cell);   // B2 = 1.5
                    if (cell)
                    {
                        VARIANT v;
                        VariantInit(&v);
                        cell->get_Value(&v);
                        std::printf("     B2 vt=%d", v.vt);
                        if (v.vt == VT_R8) std::printf(" value=%g", v.dblVal);
                        std::printf("\n");
                        VariantClear(&v);
                        BSTR text = nullptr;
                        cell->get_Text(&text);
                        PrintBstr("B2 text", text);
                        cell->Release();
                    }
                    used->Release();
                }
                sheet->Release();
            }
            wb->Close();
            wb->Release();
        }
        xapp->Dispose();
        xapp->Release();
    }

    std::printf("\n%s (%d failure(s))\n", g_failures ? "FAILED" : "ALL OK", g_failures);
    CoUninitialize();
    return g_failures ? 1 : 0;
}
