#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring outputFile = OUTPUTPATH+L"GetBookmarkPageNumber.txt";
	wstring inputFile = DATAPATH+L"Template_Pdf_1.pdf";

	//Create a new PDF document.
	PdfDocument* doc = new PdfDocument();
	//Load the file from disk.
	doc->LoadFromFile(inputFile.c_str());

	//Get bookmarks collections of the PDF file.
	PdfBookmarkCollection* bookmarks = doc->GetBookmarks();
	//Get the page number of the first bookmark.
	PdfBookmark* bookmark = bookmarks->GetItem(0);
	
	//Save to file.
	int pageNumber = doc->GetPages()->IndexOf(bookmark->GetDestination()->GetPage()) + 1;
	wstring showPageNumber = to_wstring(pageNumber);
	wstring text = L"The page number of the first bookmark is: " + showPageNumber;
	wofstream os;
	os.open(outputFile, ios::trunc);
	os << text;
	os.close();

	delete doc;
}


