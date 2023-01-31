#include "pch.h"
using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main()
{
	wstring outputFile = OUTPUTPATH+L"CustomDocumentProperties.pdf";
	// Creates a pdf document
	PdfDocument* doc = new PdfDocument();

	wstring inputFile =DATAPATH+L"CustomDocumentProperties.pdf";
	//Load a pdf file from disk
	doc->LoadFromFile(inputFile.c_str());

	//Custom document properties
	doc->GetDocumentInformation()->SetCustomProperty(L"Company", L"E-iceblue");
	doc->GetDocumentInformation()->SetCustomProperty(L"Component", L"Spire.PDF for .NET");
	doc->GetDocumentInformation()->SetCustomProperty(L"Name", L"Daisy");
	doc->GetDocumentInformation()->SetCustomProperty(L"Team", L"SalesTeam");
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();
	
	delete doc;
}
