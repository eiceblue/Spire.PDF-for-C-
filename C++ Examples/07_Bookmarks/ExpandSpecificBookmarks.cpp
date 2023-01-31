#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring outputFile = OUTPUTPATH+L"ExpandSpecificBookmarks.pdf";
	wstring inputFile = DATAPATH+L"ExpandSpecificBookmarks.pdf";

	//Load old PDF from disk.
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());

	//Set BookMarkExpandOrCollapse as "true" for the first bookmarks and "false" for the first level of the second bookmarks  
	doc->GetBookmarks()->GetItem(0)->SetExpandBookmark(true);
	PdfBookmarkCollection* bookMarkCo = Object::Convert<PdfBookmarkCollection>(doc->GetBookmarks()->GetItem(1));
	bookMarkCo->GetItem(0)->SetExpandBookmark(true);

	//Save the file
	doc->SaveToFile(outputFile.c_str());

	delete doc;
}


