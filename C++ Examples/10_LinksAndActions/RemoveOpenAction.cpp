#include "pch.h"

#include "stringhelper.h"
#include "stringbuilder.h"
using namespace Spire::Common;

using namespace Spire::Pdf;
using namespace std;


int main()
{
	wstring outputFile = OUTPUTPATH + L"RemoveOpenAction.pdf";
	wstring inputFile = DATAPATH + L"OpenAction.pdf";
	//Create a pdf document
	PdfDocument* document = new PdfDocument();

	//Load an existing pdf from disk
	document->LoadFromFile(inputFile.c_str());

	//Remove action
	document->SetAfterOpenAction();

	//Save the document
	document->SaveToFile(outputFile.c_str());
	document->Close();
	delete document;
}
