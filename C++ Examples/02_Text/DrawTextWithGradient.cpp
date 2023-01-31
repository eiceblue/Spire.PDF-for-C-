#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring outputFile = OUTPUTPATH+L"DrawTextWithGradient.pdf";

	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	//Add a new page
	PdfPageBase* page = doc->GetPages()->Add();
	//Create a rectangle
	RectangleF* rect = new RectangleF(new PointF(0, 0), new SizeF(300.f, 100.f));
	//Create a brush with gradient
	PdfLinearGradientBrush* brush = new PdfLinearGradientBrush(rect, new PdfRGBColor(Color::GetRed()), new PdfRGBColor(Color::GetBlue()),
		PdfLinearGradientMode::Horizontal);
	//Create a true type font with size 20f, underline style
	PdfTrueTypeFont* font = new PdfTrueTypeFont(L"Arial", 20.f, PdfFontStyle::Underline, true);
	//Draw text
	page->GetCanvas()->DrawString(L"Welcome to E-iceblue!", font, brush, new PointF(1, 100));
	//Save to file
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete doc;
}

