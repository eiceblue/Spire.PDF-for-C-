#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring inputFile = DATAPATH +L"DrawingTemplate.pdf";
	wstring outputFile = OUTPUTPATH +L"DrawDashedLine.pdf";

	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//Create one page
	PdfPageBase* page = doc->GetPages()->GetItem(0);
	//Save graphics state
	PdfGraphicsState* state = page->GetCanvas()->Save();
	//Draw line
    //Set location and size
	float x = 150;
	float y = 200;
	float width = 300;
	//Create pens
	PdfPen* pen = new PdfPen(new PdfRGBColor(Spire::Common::Color::GetRed()), 3.f);
	//Set dash style and pattern
	pen->SetDashStyle(PdfDashStyle::Dash);
	float flo[] = { 1,4,1 };
	vector<float> vec;
	vec.insert(vec.begin(), flo, flo + 3);
	pen->SetDashPattern(vec);
	//Draw a rectangle
	//Draw two crossed lines	
	page->GetCanvas()->DrawLine(pen, x, y, x + width, y);
	//Restore graphics
	page->GetCanvas()->Restore(state);

	//Save the document
	doc->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	doc->Close();

	delete doc;
}

