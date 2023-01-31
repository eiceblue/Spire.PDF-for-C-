#include "pch.h"
using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main()
{
	wstring outputFile = OUTPUTPATH+L"DeleteLayer.pdf";
	// Creates a pdf document
	PdfDocument* doc = new PdfDocument();
	wstring inputFile =DATAPATH+L"DeleteLayer.pdf";
	doc->LoadFromFile(inputFile.c_str());

	//Delete the "red line" layer
	doc->GetLayers()->RemoveLayer(L"red line");
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete doc;
			
}

