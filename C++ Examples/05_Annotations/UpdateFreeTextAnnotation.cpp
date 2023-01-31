#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring outputFile = OUTPUTPATH+L"UpdateFreeTextAnnotation.pdf";
	wstring inputFile = DATAPATH+L"UpdateFreeTextAnnotation.pdf";
	
	//Create a new PDF document.
	PdfDocument* doc = new PdfDocument();
	//Load the file from disk.
	doc->LoadFromFile(inputFile.c_str());
	//Get the annotation Collection from the document.
	PdfAnnotationCollection* annotations = doc->GetPages()->GetItem(0)->GetAnnotationsWidget();
	//Update free text annotation.
	for (int i = 0; i < annotations->GetCount(); i++) {
	PdfFreeTextAnnotationWidget* annotaion = Object::Convert<PdfFreeTextAnnotationWidget>(annotations->GetItem(i));
	annotaion->SetColor(new PdfRGBColor(Spire::Common::Color::GetYellowGreen()));
	}
	//Save the document
	doc->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	doc->Close();

	delete doc;
}


