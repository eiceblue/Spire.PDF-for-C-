#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring outputFile = OUTPUTPATH +L"DrawLine.pdf";
	wstring inputFile = DATAPATH +L"DrawingTemplate.pdf";

	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//Create one page
	PdfPageBase* page = doc->GetPages()->GetItem(0);
	//Save graphics state
	PdfGraphicsState* state = page->GetCanvas()->Save();
	//Draw line
	//Set location and size	
	float x = 95;
	float y = 95;
	float width = 400;
	float height = 500;
	//Create pens
	PdfPen* pen = new PdfPen(new PdfRGBColor(Spire::Common::Color::GetBlack()), 0.1f);
	PdfPen* pen1 = new PdfPen(new PdfRGBColor(Spire::Common::Color::GetRed()), 0.1f);
	//Draw a rectangle
	page->GetCanvas()->DrawRectangle(pen, x, y, width, height);
	//Draw two crossed lines
	page->GetCanvas()->DrawLine(pen1, x, y, x + width, y + height);
	page->GetCanvas()->DrawLine(pen1, x + width, y, x, y + height);
	//Restore graphics
	page->GetCanvas()->Restore(state);

	//Save the document
	doc->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	doc->Close();

	delete doc;
}

