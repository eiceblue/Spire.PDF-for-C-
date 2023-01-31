#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring inputFile = DATAPATH+L"Template_Pdf_1.pdf";
	wstring outputFile = OUTPUTPATH+L"DeleteAllBookmarks.pdf";

	//Create a new Pdf document.
	PdfDocument* doc = new PdfDocument();
	//Load the file from disk.
	doc->LoadFromFile(inputFile.c_str());

	//Remove all bookmarks.
	doc->GetBookmarks()->Clear();

	//Save the document
	doc->SaveToFile(outputFile.c_str());

	delete doc;
}


