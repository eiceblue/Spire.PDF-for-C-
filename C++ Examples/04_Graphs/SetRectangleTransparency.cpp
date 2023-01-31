#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring outputFile = OUTPUTPATH+L"SetRectangleTransparency.pdf";

	wstring inputFile = DATAPATH+L"DrawingTemplate.pdf";
	//Create one page
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	PdfPageBase* page = doc->GetPages()->GetItem(0);
	//Save graphics state
	PdfGraphicsState* state = page->GetCanvas()->Save();
	//Draw rectangles
	int x = 200;
	int y = 300;
	int width = 200;
	int height = 100;
	PdfPen* pen = new PdfPen(new PdfRGBColor(Spire::Common::Color::GetBlack()), 1.f);
	PdfBrush* brush = new PdfSolidBrush(new PdfRGBColor(Spire::Common::Color::GetRed()));
	page->GetCanvas()->SetTransparency(0.5f, 0.5f);
	page->GetCanvas()->DrawRectangle(pen, brush, new RectangleF(new PointF(x, y), new SizeF(width, height)));
	x = x + width / 2;
	y = y - height / 2;
	page->GetCanvas()->SetTransparency(0.2f, 0.2f);
	page->GetCanvas()->DrawRectangle(pen, brush, new RectangleF(new PointF(x, y), new SizeF(width, height)));
	//Restore graphics
	page->GetCanvas()->Restore(state);
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete doc;
}

