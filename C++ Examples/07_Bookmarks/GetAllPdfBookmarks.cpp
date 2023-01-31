#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring outputFile = OUTPUTPATH+L"GetAllPdfBookmarks.txt";
	wstring inputFile = DATAPATH+L"Template_Pdf_1.pdf";

	//Create a new Pdf document.
	PdfDocument* doc = new PdfDocument();
	//Load the file from disk.
	doc->LoadFromFile(inputFile.c_str());

	//Get bookmarks collection of the Pdf file.
	PdfBookmarkCollection* bookmarks = doc->GetBookmarks();
	//Get Pdf Bookmarks.
	GetBookmarks(bookmarks, outputFile);

	delete doc;
}
const wstring ToString(PdfTextStyle style) {
	switch (style)
	{
	case Spire::Pdf::PdfTextStyle::Regular:
		return L"Regular";
		break;
	case Spire::Pdf::PdfTextStyle::Italic:
		return L"Italic";
		break;
	case Spire::Pdf::PdfTextStyle::Bold:
		return L"Bold";
		break;
	default:
		break;
	}
}
void GetBookmarks(PdfBookmarkCollection* bookmarks, std::wstring result)
{
	//Declare a new StringBuilder content
	wstring content;

	//Get Pdf bookmarks information.
	if (bookmarks->GetCount() > 0)
	{
		content += L"Pdf bookmarks: \n";
		for (int i = 0; i < bookmarks->GetCount(); i++)
		{
			content += bookmarks->GetItem(i)->GetTitle();
			content += L"\n";
			//Get the text style.
			wstring textStyle = ToString(bookmarks->GetItem(i)->GetDisplayStyle());
			content +=  textStyle + L"\n";

			GetChildBookmark(bookmarks->GetItem(i), content);
		}
	}

	//Save to file.
	wofstream os;
	os.open(result, ios::trunc);
	os << content;
	os.close();

}

void GetChildBookmark(PdfBookmark* parentBookmark, wstring& content)
{
	if (parentBookmark->GetCount() > 0)
	{
		for (int i = 0; i < parentBookmark->GetCount(); i++)
		{
			//Get the title.
			content += parentBookmark->GetItem(i)->GetTitle();
			//Get the text style.
			wstring textStyle = ToString(parentBookmark->GetItem(i)->GetDisplayStyle());
			content += L"\n"+ textStyle + L"\n";
			GetChildBookmark(parentBookmark->GetItem(i), content);
		}
	}

}

