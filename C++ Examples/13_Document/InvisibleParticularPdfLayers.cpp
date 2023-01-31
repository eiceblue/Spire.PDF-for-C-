#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main(){
	wstring inputFile = DATAPATH+L"Template_Pdf_5.pdf";
	wstring outputFile = OUTPUTPATH+L"InvisibleParticularPdfLayers.pdf";
	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());

	//Set the first layer invisible.
	doc->GetLayers()->GetItem(0)->SetVisibility(PdfVisibility::Off);

	//Set the layer named "blue line" invisible.
	doc->GetLayers()->GetItem(L"blue line")->SetVisibility(PdfVisibility::Off);
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete doc;
}
