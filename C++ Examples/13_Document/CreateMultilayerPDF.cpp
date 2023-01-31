#include "pch.h"
using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main()
{
	wstring outputFile = OUTPUTPATH+L"CreateMultilayerPDF.pdf";
	//Create a new pdf document
	PdfDocument* doc = new PdfDocument();
	// Creates a page
	PdfPageBase* page = doc->GetPages()->Add();

	//Create text
	LPCWSTR_S text = L"Welcome to evaluate Spire.PDF for .NET !";

	PdfStringFormat* format = new PdfStringFormat(PdfTextAlignment::Left);

	PdfTrueTypeFont* font = new PdfTrueTypeFont(L"Calibri", 15.0f, PdfFontStyle::Regular, true);
	PdfBrush* brush = new PdfSolidBrush(new PdfRGBColor(Color::GetBlack()));

	float x = 50;
	float y = 50;
	PointF* pf = new PointF(x, y);
	// Draw text layer
	page->GetCanvas()->DrawString(text, font, brush, pf, format);

	SizeF* size = font->MeasureString(L"Welcome to  evaluate", format);

	SizeF* size2 = font->MeasureString(L"Spire.PDF for .NET", format);

	// Loads an image 
	wstring inputFile = DATAPATH+L"MultilayerImage.png";
	PdfImage* image = PdfImage::FromFile(inputFile.c_str());
	pf = new PointF(x + size->GetWidth(), y);
	// Draw image layer
	page->GetCanvas()->DrawImage(image, pf, size2);
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();
	delete doc;
}
