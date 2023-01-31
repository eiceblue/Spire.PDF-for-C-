#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring outputFile = OUTPUTPATH+L"CreatePdfPolygonAnnotation.pdf";

	//Create a Pdf document.
	PdfDocument* doc = new PdfDocument();
	//Add a new page to it.
	PdfPageBase* page = doc->GetPages()->Add();
	//Initialize an instance of PdfPolygonAnnotation, specifying all vertex coordinates which can form a complete shape.
	vector<PointF*> vec{ new PointF(0, 30), new PointF(30, 15), new PointF(60, 30),
	new PointF(45, 50), new PointF(15, 50), new PointF(0, 30) };
	PdfPolygonAnnotation* polygon = new PdfPolygonAnnotation(page, vec);
	//Set the border color, text, border effect and other properties of polygon annotation.
	polygon->SetColor(new PdfRGBColor(Spire::Common::Color::GetPaleVioletRed()));
	polygon->SetText(L"This is a polygon annotation");
	polygon->SetAuthor(L"E-ICEBLUE");
	polygon->SetSubject(L"polygon annotation demo");
	polygon->SetBorderEffect(PdfBorderEffect::BigCloud);
	polygon->SetModifiedDate(DateTime::GetNow());
	//Add the annotation to Pdf page and save the document.
	page->GetAnnotationsWidget()->Add(polygon);

	//Save the document
	doc->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	doc->Close();

	delete doc;
}

