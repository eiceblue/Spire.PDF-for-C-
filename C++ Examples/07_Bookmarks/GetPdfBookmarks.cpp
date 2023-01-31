#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	std::wstring outputFile = DATAPATH+L"GetPdfBookmarks.txt";
	//Create a new Pdf document.
	PdfDocument *doc = new PdfDocument();

	//Load the file from disk.
	doc->LoadFromFile(DATAPATH+L"Template_Pdf_1.pdf)");

	//Get bookmarks collection of the Pdf file.
	PdfBookmarkCollection *bookmarks = doc->Bookmarks;

	//Get Pdf Bookmarks.
	GetBookmarks(bookmarks, outputFile);

	delete doc;
}
void GetBookmarks(PdfBookmarkCollection *bookmarks, const std::wstring &result)
{
	//Declare a new StringBuilder content
	StringBuilder *content = new StringBuilder();

	//Get Pdf bookmarks information.
	if (bookmarks->Count > 0)
	{
		content->appendLine(L"Pdf bookmarks:");
		for (auto parentBookmark : *bookmarks)
		{
			//Get the title.
			content->appendLine(parentBookmark->Title);

			//Get the text style.
			std::wstring textStyle = parentBookmark->DisplayStyle.ToString();
			content->appendLine(textStyle);
			GetChildBookmark(parentBookmark,content);
		}
	}

	//Save to file.
	File::WriteAllText(result, content->toString());
}

void GetChildBookmark(PdfBookmark *parentBookmark, StringBuilder *content)
{
	if (parentBookmark->Count > 0)
	{
		for (auto childBookmark : *parentBookmark)
		{
			//Get the title.
			content->appendLine(childBookmark->Title);

			//Get the text style.
			std::wstring textStyle = childBookmark->DisplayStyle.ToString();
			content->appendLine(textStyle);
			GetChildBookmark(childBookmark, content);
		}
	}
}
