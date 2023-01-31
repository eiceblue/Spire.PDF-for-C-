#include "pch.h"
using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main()
{
	wstring outputFile = OUTPUTPATH+L"CreateTwoColumnPDF.pdf";

	// Creates a pdf document
	PdfDocument* doc = new PdfDocument();

	// Creates a new page
	PdfPageBase* page = doc->GetPages()->Add();

	wstring s1 = L"Spire.PDF for .NET is a professional PDF component applied to creating, writing, ";
		s1 += L"editing, handling and reading PDF files without any external dependencies within ";
		s1 += L".NET application. Using this .NET PDF library, you can implement rich capabilities ";
		s1 += L"to create PDF files from scratch or process existing PDF documents entirely through ";
		s1 += L"C#/VB.NET without installing Adobe Acrobat.";
	wstring s2 = L"Many rich features can be supported by the .NET PDF API, such as security setting ";
		s2 += L"(including digital signature), PDF text/attachment/image extract, PDF merge/split ";
		s2 += L", metadata update, section, graph/image drawing and inserting, table creation and ";
		s2 += L"processing, and importing data etc.Besides, Spire.PDF for .NET can be applied to easily ";
		s2 += L"converting Text, Image and HTML to PDF with C#/VB.NET in high quality.";

	// Get width and height of page
	float pageWidth = page->GetClientSize()->GetWidth();
	float pageHeight = page->GetClientSize()->GetHeight();

	PdfBrush* brush = PdfBrushes::GetBlack();
	//PdfBrush* brush = new PdfSolidBrush(new PdfRGBColor(Color::GetBlack()));
	PdfFont* font = new PdfFont(PdfFontFamily::TimesRoman, 12.0f);
	//PdfTrueTypeFont* font = new PdfTrueTypeFont(L"Calibri", 15.0f, PdfFontStyle::Regular, true);
	PdfStringFormat* format = new PdfStringFormat(PdfTextAlignment::Justify);

	// Draw text
	page->GetCanvas()->DrawString(s1.c_str(), font, brush, new RectangleF(0, 20, pageWidth / 2 - 8.0f, pageHeight), format);
	page->GetCanvas()->DrawString(s2.c_str(), font, brush, new RectangleF(pageWidth / 2 + 8.0f, 20, pageWidth / 2 - 8.0f, pageHeight), format);
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();
	
	delete doc;
}
