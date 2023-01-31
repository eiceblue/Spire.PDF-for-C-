#include "pch.h"

using namespace Spire::Pdf;
using namespace std;;
using namespace Spire::Common;

int main() {
	wstring outputFile = OUTPUTPATH+L"DrawRotatedText.pdf";

	PdfDocument* doc = new PdfDocument();
	PdfPageBase* page = doc->GetPages()->Add();
	PdfTrueTypeFont* font = new PdfTrueTypeFont(L"Arial", 12.f, PdfFontStyle::Regular, true);
	PdfRGBColor* color = new PdfRGBColor(Color::GetBlue());
	PdfSolidBrush* brush = new PdfSolidBrush(color);
	LPCWSTR_S text = L"This is a text";
	page->GetCanvas()->DrawString(text, font, brush, 20, 30);
	page->GetCanvas()->DrawString(text, font, brush, 20, 150);
	PdfGraphicsState* state = page->GetCanvas()->Save();
	PointF* point1 = new PointF(20, 30);
	page->GetCanvas()->RotateTransform(90, point1);
	page->GetCanvas()->DrawString(text, font, brush, point1);
	page->GetCanvas()->Restore(state);

	PdfGraphicsState* state2 = page->GetCanvas()->Save();
	PointF* point2 = new PointF(20, 150);
	page->GetCanvas()->RotateTransform(-90, point2);
	page->GetCanvas()->DrawString(text, font, brush, point2);
	page->GetCanvas()->Restore(state2);

	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete doc;
}

