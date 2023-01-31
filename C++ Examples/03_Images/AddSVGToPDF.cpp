#include "pch.h"

using namespace std;
using namespace Spire::Pdf;

int main() {
	wstring outputFile = OUTPUTPATH+L"AddSVGToPDF.pdf";
	wstring fn1 = DATAPATH;

	//Create a new PDF document.
	PdfDocument* existingPDF = new PdfDocument();
	
	//Load an existing PDF
	existingPDF->LoadFromFile((fn1 + L"SampleB_1.pdf").c_str());
	//Create a new PDF document.
	PdfDocument* doc = new PdfDocument();
	//Load the SVG file
	doc->LoadFromSvg((fn1 + L"template.svg").c_str());
	//Create template
	PdfTemplate* pdftemplate = doc->GetPages()->GetItem(0)->CreateTemplate();
	//Draw template on existing PDF
	float x = 50;
	float y = 250;

	PointF* pf = new PointF(x, y);

	existingPDF->GetPages()->GetItem(0)->GetCanvas()->DrawTemplate(doc->GetPages()->GetItem(0)->CreateTemplate(),
		pf, new Spire::Common::SizeF(200, 200));
	
	//save to file
	existingPDF->SaveToFile((outputFile ).c_str(), FileFormat::PDF);

	delete doc;
}




