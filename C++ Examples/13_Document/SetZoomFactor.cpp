#include "pch.h"
#include "stringbuilder.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring outputFile = OUTPUTPATH+L"SetZoomFactor.pdf";
	wstring inputFile = DATAPATH+L"SetZoomFactor.pdf";

	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());

	//Get the first page
	PdfPageBase* page = doc->GetPages()->GetItem(0);

	//Set pdf destination
	PdfDestination* dest = new PdfDestination(page);
	dest->SetMode(PdfDestinationMode::Location);
	dest->SetLocation(new PointF(-40.0f, -40.0f));
	dest->SetZoom(0.6f);

	//Set action
	PdfGoToAction* gotoAction = new PdfGoToAction(dest);
	doc->SetAfterOpenAction(gotoAction);
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete doc;
}

