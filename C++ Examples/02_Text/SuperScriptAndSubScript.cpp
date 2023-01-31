#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring outputFile= OUTPUTPATH+L"SuperScriptAndSubScript.pdf";
	
	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	PdfPageBase* page = doc->GetPages()->Add();
	PdfTrueTypeFont* font = new PdfTrueTypeFont(L"Arial", 20.f, PdfFontStyle::Regular, true);
	PdfSolidBrush* brush = new PdfSolidBrush(new PdfRGBColor(Color::GetBlack()));
	wstring text = L"Spire.PDF for .CPP";

	//Draw Superscript
	DrawSuperscript(page, text, font, brush);

	//Draw Subscript
	DrawSubscript(page, text, font, brush);
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete doc;
}

void DrawSuperscript(PdfPageBase* page, const std::wstring& text, PdfTrueTypeFont* font, PdfSolidBrush* brush)
{
	float x1 = 120;
	float y1 = 100;
	page->GetCanvas()->DrawString(text.c_str(), font, brush, new PointF(x1, y1));
	SizeF* size1 = font->MeasureString(text.c_str());
	x1 += size1->GetWidth();
	PdfStringFormat* format1 = new PdfStringFormat();
	format1->SetSubSuperScript(PdfSubSuperScript::SuperScript);
	page->GetCanvas()->DrawString(L"Superscript", font, brush, new PointF(x1, y1), format1);
}

void DrawSubscript(PdfPageBase* page, const std::wstring& text, PdfTrueTypeFont* font, PdfSolidBrush* brush)
{
	float x2 = 120;
	float y2 = 150;
	page->GetCanvas()->DrawString(text.c_str(), font, brush, new PointF(x2, y2));
	SizeF* size2 = font->MeasureString(text.c_str());
	x2 += size2->GetWidth();
	PdfStringFormat* format2 = new PdfStringFormat();
	format2->SetSubSuperScript(PdfSubSuperScript::SubScript);
	page->GetCanvas()->DrawString(L"SubScript", font, brush, new PointF(x2, y2), format2);
 }
