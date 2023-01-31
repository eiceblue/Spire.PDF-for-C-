#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring inputFile = DATAPATH+L"FreeTextAnnotation.pdf";
	wstring outputFile = OUTPUTPATH+L"TextAnnotationProperties.pdf";
	//Load old PDF from disk.
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//Get the first page.
	PdfPageBase* page = doc->GetPages()->GetItem(0);
	//Create a new PDF document.
	PdfDocument* newDoc = new PdfDocument();
	//Traverse the annotations of the first page of old PDF
	for (int i = 0; i < page->GetAnnotationsWidget()->GetCount(); i++) {
		PdfAnnotation* annotation = page->GetAnnotationsWidget()->GetItem(i);
		wchar_t nm_w[100];
		swprintf(nm_w, 100, L"%hs", typeid(PdfFreeTextAnnotationWidget).name());
		LPCWSTR_S newName = nm_w;
		//If it is FreeTextAnnotation
		if (wcscmp(newName, annotation->GetInstanceTypeName()) == 0) {
		PdfFreeTextAnnotationWidget* textAnnotation = Object::Convert<PdfFreeTextAnnotationWidget>(annotation);
		//Get its bounds and text
		RectangleF* rect = textAnnotation->GetBounds();
		wstring text = textAnnotation->GetText();
		//Add new page for newPdf
		PdfPageBase* newPage = newDoc->GetPages()->Add(page->GetSize());
		//Add annotation with the same settings as the annotation of old PDF
		PdfFreeTextAnnotation* newAnnotation = new PdfFreeTextAnnotation(rect);
		newAnnotation->SetText(text.c_str());
		newAnnotation->SetCalloutLines(textAnnotation->GetCalloutLines());
		newAnnotation->SetLineEndingStyle(textAnnotation->GetLineEndingStyle());
		newAnnotation->SetRectangleDifferences(textAnnotation->GetRectangularDifferenceArray());
		newAnnotation->SetColor(textAnnotation->GetColor());
		newAnnotation->SetAnnotationIntent(PdfAnnotationIntent::FreeTextCallout);
		newPage->GetAnnotationsWidget()->Add(newAnnotation);
		}
	}
	//Save the file
	newDoc->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	doc->Close();
	newDoc->Close();

	delete newDoc;
	delete doc;
}

