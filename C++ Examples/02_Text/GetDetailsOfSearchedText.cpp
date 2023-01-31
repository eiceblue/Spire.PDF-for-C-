#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring outputFile= OUTPUTPATH+L"GetDetailsOfSearchedText.txt";
	wstring inputFile =DATAPATH+L"SearchReplaceTemplate.pdf";

	// Read a pdf file
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	// Get the first page of pdf file
	PdfPageBase* page = doc->GetPages()->GetItem(0);
	// Create PdfTextFindCollection object to find all the matched phrases
	PdfTextFindCollection* collection = page->FindText(L"Spire.PDF for .NET", Find_TextFindParameter::IgnoreCase);
	wstring str = L"";
	for each (PdfTextFind * find in collection->GetFinds())
	{
	str += L"==================================================================================";
	str += L"\nMatch Text: ";
	str += find->GetMatchText();
	str += L"\nText:";
	str += find->GetSearchText();
	str += L"\nSize:";
	str += find->GetSize()->ToString();
	str += L"\nPosition:";
	str += find->GetPosition()->ToString();
	str += L"\nThe index of page which is including the searched text : ";
	str += find->GetSearchPageIndex();
	str += L"\nThe line that contains the searched text : ";
	str += find->GetLineText();
	str += L"\nMatch Text: ";
	str += find->GetMatchText();
	str += L"\n";
	}
	wofstream os;
	os.open(outputFile, ios::trunc);
	os << str;
	os.close();
	doc->Close();

	delete doc;
}


