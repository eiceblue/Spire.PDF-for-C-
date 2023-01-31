#include "pch.h"
using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main()
{
	wstring outputFile = OUTPUTPATH+L"ChangePdfVersion.pdf";
	wstring inputFile = DATAPATH+L"ChangePdfVersion.pdf";
	
	//Create a new pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());

	//Change the pdf version
	doc->GetFileInfo()->SetVersion(PdfVersion::Version1_6);
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();
	
	delete doc;
}
