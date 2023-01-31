#include "pch.h"

#include "stringhelper.h"
#include "stringbuilder.h"
using namespace Spire::Common;

using namespace Spire::Pdf;
using namespace std;

int main()
{
	wstring outputFile = OUTPUTPATH + L"SpecifyPageToView.pdf";
	wstring inputFile = DATAPATH + L"Sample.pdf";
	//Create a pdf document
	PdfDocument* doc = new PdfDocument();

	//Load an existing pdf from disk
	doc->LoadFromFile(inputFile.c_str());

	//Create a PdfDestination with specific page, location and 50% zoom factor
	PdfDestination* dest = new PdfDestination(2, new PointF(0, 100), 0.5f);

	//Create GoToAction with dest
	PdfGoToAction* action = new PdfGoToAction(dest);

	//Set open action
	doc->SetAfterOpenAction(action);
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();
	delete doc;
}
