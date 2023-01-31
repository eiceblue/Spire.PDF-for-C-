#include "pch.h"
#include "stringhelper.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring outputFile = OUTPUTPATH+L"GetPdfChildBookmarks.txt";
	wstring inputFile = DATAPATH+L"Template_Pdf_1.pdf";

	//Create a new Pdf document.
	PdfDocument* doc = new PdfDocument();
	//Load the file from disk.
	doc->LoadFromFile(inputFile.c_str());

	//Get bookmarks collections of the PDF file.
	PdfBookmarkCollection* bookmarks = doc->GetBookmarks();
	//Get Pdf child Bookmarks.
	GetChildBookmarks(bookmarks, outputFile);

	delete doc;
}

const wstring ChildToString(PdfTextStyle style) {
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

void GetChildBookmarks(PdfBookmarkCollection* bookmarks, std::wstring result)
{
	//Declare a new StringBuilder content
	wstring content;

	//Get Pdf bookmarks information.
	if (bookmarks->GetCount() > 0)
	{
		for (int i = 0; i < bookmarks->GetCount(); i++)
		{
			if (bookmarks->GetItem(i)->GetCount() > 0)
			{
				content += L"Child Bookmarks: \n";
				for (int j = 0; j < bookmarks->GetItem(i)->GetCount(); j++)
				{
					//Get the title ,color ,textStyle. 
					content += bookmarks->GetItem(i)->GetItem(j)->GetTitle();
					content += L"\n";
					wchar_t nm_w[100];
					swprintf(nm_w, 100, L"%hs", typeid(bookmarks->GetItem(i)->GetItem(j)->GetColor()).name());
					LPCWSTR_S newName = nm_w;
					wstring tName = newName;
					tName = StringHelper::split(tName,L' ')[1];
					content += tName + L"\n";
					wstring textStyle = ChildToString(bookmarks->GetItem(i)->GetItem(j)->GetDisplayStyle());
					content += textStyle + L"\n";
				}
			}
		}
	}

	//Save to file.
	wofstream os;
	os.open(result, ios::trunc);
	os << content;
	os.close();
}
