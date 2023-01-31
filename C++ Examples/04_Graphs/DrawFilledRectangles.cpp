#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring outputFile = OUTPUTPATH +L"DrawFilledRectangles.pdf";
	wstring inputFile = DATAPATH +L"DrawingTemplate.pdf";

	//Create one page
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	PdfPageBase* page = doc->GetPages()->GetItem(0);
	//save graphics state
	PdfGraphicsState* state = page->GetCanvas()->Save();
	//Set rectangle display location and size
	int x = 200;
	int y = 300;
	int width = 200;
	int height = 120;
	//Create one page and brush
	PdfPen* pen = new PdfPen(new PdfRGBColor(Spire::Common::Color::GetBlack()), 1.f);
	PdfBrush* brush = new PdfSolidBrush(new PdfRGBColor(Spire::Common::Color::GetOrangeRed()));
	//Draw a filled rectangle
	page->GetCanvas()->DrawRectangle(pen, brush, new RectangleF(new PointF(x, y), new SizeF(width, height)));
	//restore graphics
	page->GetCanvas()->Restore(state);

	//Save the document
	doc->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	doc->Close();

	delete doc;
}

