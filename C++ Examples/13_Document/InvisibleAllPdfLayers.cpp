#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main()
{
	wstring outputFile = OUTPUTPATH+L"InvisibleAllPdfLayers.pdf";
	wstring inputFile =DATAPATH+L"Template_Pdf_5.pdf";
	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	//Load the file from disk.
	doc->LoadFromFile(inputFile.c_str());

	for (int i = 0; i < doc->GetLayers()->GetCount(); i++)
	{      
		//Show all the Pdf layers.
		//doc.Layers[i].Visibility = PdfVisibility.On;
		//Set all the Pdf layers invisible.
		doc->GetLayers()->GetItem(i)->SetVisibility(PdfVisibility::Off);
	}
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();
	
	delete doc;
}
