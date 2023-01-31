#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring outputFile = OUTPUTPATH+L"DeleteBookmark.pdf";
	wstring inputFile = DATAPATH+L"DeleteBookmark.pdf";

	//Load a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());

	//Delete the first bookmark
	doc->GetBookmarks()->RemoveAt(0);

	//Save the pdf document
	doc->SaveToFile(outputFile.c_str());

	delete doc;
}


