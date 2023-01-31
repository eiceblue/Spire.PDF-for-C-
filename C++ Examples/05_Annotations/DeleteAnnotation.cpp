#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring outputFile = OUTPUTPATH+L"DeleteAnnotation.pdf";
	wstring inputFile = DATAPATH+L"DeleteAnnotation.pdf";
	
	//Open pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//Remove the first annotation
	doc->GetPages()->GetItem(0)->GetAnnotationsWidget()->RemoveAt(0);
    //Save pdf document
	doc->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	doc->Close();

	delete doc;
}

