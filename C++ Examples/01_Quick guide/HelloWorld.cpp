#include "pch.h"
using namespace Spire::Pdf;

int main() {
	std::wstring output_path = OUTPUTPATH;
	std::wstring outputFile = output_path + L"HelloWorld.pdf";
	
	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	
	//Create one page
	PdfPageBase* page = doc->GetPages()->Add();
	
	//Draw the text
	std::wstring s = L"Hello, World!";
	float x = 10;
	float y = 10;
	PdfFontBase* font = new PdfFont(PdfFontFamily::Helvetica, 30.f);
	PdfRGBColor* color = new PdfRGBColor(Spire::Common::Color::GetBlack());
	PdfBrush* textBrush = new PdfSolidBrush(color);
	page->GetCanvas()->DrawString(s.c_str(), font, textBrush, x, y);
	
	//Save the document
	doc->SaveToFile((outputFile).c_str());
	doc->Dispose();
	delete doc;
}


