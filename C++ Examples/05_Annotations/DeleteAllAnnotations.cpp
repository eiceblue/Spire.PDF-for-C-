#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring outputFile = OUTPUTPATH+L"DeleteAllAnnotations.pdf";

	wstring inputFile = DATAPATH+L"Template_Pdf_3.pdf";
	//Create a new PDF document.
	PdfDocument* doc = new PdfDocument();
	//Load the file from disk
	doc->LoadFromFile(inputFile.c_str());
	//Remove all annotations
	doc->GetPages()->GetItem(0)->GetAnnotationsWidget()->Clear();
	//Save the document
	doc->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	doc->Close();

	delete doc;
}

