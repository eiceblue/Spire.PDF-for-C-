#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring outputFile = OUTPUTPATH+L"CreatePolylineAnnotation.pdf";

	//Create a Pdf document.
	PdfDocument* doc = new PdfDocument();
	//Add a new page to it.
	PdfPageBase* page = doc->GetPages()->Add();
	// create a polyline Annotation
	vector<PointF*> vec{ new PointF(0, 60), new PointF(30, 45), new PointF(60, 90), new PointF(90, 80) };
	PdfPolyLineAnnotation* polyline = new PdfPolyLineAnnotation(page, vec);
	//Set the border color, text, border effect and other properties of polyline annotation.
	polyline->SetColor(new PdfRGBColor(Spire::Common::Color::GetPaleVioletRed()));
	polyline->SetText(L"This is a polygon annotation");
	polyline->SetAuthor(L"E-ICEBLUE");
	polyline->SetSubject(L"polygon annotation demo");
	polyline->SetBorder(new PdfAnnotationBorder(1.f));
	polyline->SetModifiedDate(DateTime::GetNow());
	//Add the annotation to Pdf page and save the document.
	page->GetAnnotationsWidget()->Add(polyline);

	//Save the document
	doc->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	doc->Close();

	delete doc;
}

