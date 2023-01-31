#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring outputFile = OUTPUTPATH+L"ExpandBookmarks.pdf";
	wstring inputFile = DATAPATH+L"Template_Pdf_1.pdf";
	//Create a new PDF document.
	PdfDocument* doc = new PdfDocument();
	//Load the file from disk.
	doc->LoadFromFile(inputFile.c_str());

	//Set BookMarkExpandOrCollapse as true to expand the bookmarks.
	doc->GetViewerPreferences()->SetBookMarkExpandOrCollapse(true);

	//Save the document
	doc->SaveToFile(outputFile.c_str());

	delete doc;
}

