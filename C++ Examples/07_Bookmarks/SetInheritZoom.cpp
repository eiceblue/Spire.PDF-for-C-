#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring outputFile = OUTPUTPATH+L"SetInheritZoom.pdf";
	wstring inputFile = DATAPATH+L"Template_Pdf_1.pdf";

	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());

	PdfBookmarkCollection* bookmarks = doc->GetBookmarks();
	//Set Zoom level as 0, which the value is inherit zoom
	for (int i = 0; i < doc->GetBookmarks()->GetCount(); i++)
	{
		doc->GetBookmarks()->GetItem(i)->GetDestination()->SetZoom(0.5f);
	}
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	delete doc;
}

