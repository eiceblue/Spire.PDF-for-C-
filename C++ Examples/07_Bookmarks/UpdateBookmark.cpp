#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring outputFile = OUTPUTPATH+L"UpdateBookmark.pdf";
	wstring inputFile = DATAPATH+L"UpdateBookmark.pdf";

	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());

	//Get the first bookmark
	PdfBookmark* bookMark = doc->GetBookmarks()->GetItem(0);

	//Change the title of the bookmark
	bookMark->SetTitle(L"Modified BookMark");

	//Set the color of the bookmark
	bookMark->SetColor(new PdfRGBColor(Spire::Common::Color::GetBlack()));

	//Set the outline text style of the bookmark
	bookMark->SetDisplayStyle(PdfTextStyle::Bold);

	//Edit child bookmarks of the parent bookmark
	EditChildBookmark(bookMark);

	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();
	delete doc;
}

void EditChildBookmark(PdfBookmark* parentBookmark)
{
	for (int i = 0; i < parentBookmark->GetCount(); i++)
	{
		PdfBookmark* childbookmark = parentBookmark->GetItem(i);
		childbookmark->SetColor(new PdfRGBColor(Spire::Common::Color::GetBlue()));
		childbookmark->SetDisplayStyle(PdfTextStyle::Regular);
		EditChild2Bookmark(childbookmark);

	}
}

void EditChild2Bookmark(PdfBookmark* childBookmark)
{
	for (int i = 0; i < childBookmark->GetCount(); i++)
	{
		PdfBookmark* childbookmark = childBookmark->GetItem(i);
		childbookmark->SetColor(new PdfRGBColor(Spire::Common::Color::GetLightSalmon()));
		childbookmark->SetDisplayStyle(PdfTextStyle::Italic);
	}
}
