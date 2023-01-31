#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring inputFile =DATAPATH+L"SampleB_1.pdf";
	wstring outputFile = OUTPUTPATH+L"AddBorderForText.pdf";

	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile((inputFile).c_str());
	//Get the first page
	PdfPageBase* page = doc->GetPages()->GetItem(0);
	LPCWSTR_S text = L"Hello, World!";
	PdfTrueTypeFont* font = new PdfTrueTypeFont(L"Times New Roman", 11, PdfFontStyle::Regular, true);
	SizeF* size = font->MeasureString(text);
	PdfRGBColor* color = new PdfRGBColor(Color::GetBlack());
	PdfSolidBrush* brush = new PdfSolidBrush(color);
	int x = 60;
	int y = 300;
	//Draw the text on page
	page->GetCanvas()->DrawString(text, font, brush, x, y);
	//Draw border for text     
	page->GetCanvas()->DrawRectangle(new PdfPen(brush, 0.5f), new Spire::Common::RectangleF(
		x, y, (int)size->GetWidth(), (int)size->GetHeight()));
	//save to file
	doc->SaveToFile((outputFile).c_str(), FileFormat::PDF);
	doc->Close();

	delete doc;
}

