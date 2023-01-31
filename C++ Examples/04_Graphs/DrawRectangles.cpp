#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring outputFile = OUTPUTPATH +L"DrawRectangles.pdf";
    wstring inputFile = DATAPATH +L"DrawingTemplate.pdf";

	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//Create one page
	PdfPageBase* page = doc->GetPages()->GetItem(0);
	PdfGraphicsState* state = page->GetCanvas()->Save();
	//Draw rectangles
	//Set rectangle display location and size
	int x = 130;
	int y = 100;
	int width = 300;
	int height = 400;
	//Create one page
	PdfPen* pen = new PdfPen(new PdfRGBColor(Spire::Common::Color::GetBlack()), 0.1f);
	page->GetCanvas()->DrawRectangle(pen, new RectangleF(new PointF(x, y), new SizeF(width, height)));
	y = y + height - 50;
	width = 100;
	height = 50;
	//Initialize an instance of PdfSeparationColorSpace
	PdfSeparationColorSpace* cs = new PdfSeparationColorSpace(L"MyColor", new PdfRGBColor(Spire::Common::Color::FromArgb(0, 100, 0, 0)));
	PdfPen* pen1 = new PdfPen(new PdfRGBColor(Spire::Common::Color::GetRed()), 1.f);
	//Create a brush with spot color
	PdfBrush* brush = new PdfSolidBrush(new PdfSeparationColor(cs, 0.1f));
	page->GetCanvas()->DrawRectangle(pen1, brush, new RectangleF(new PointF(x, y), new SizeF(width, height)));
	page->GetCanvas()->Restore(state);

	//Save the document
	doc->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	doc->Close();

	delete doc;
}

