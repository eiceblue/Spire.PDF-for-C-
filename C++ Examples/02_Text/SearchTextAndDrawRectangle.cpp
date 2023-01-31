#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
int main() {
	wstring inputFile = DATAPATH+L"SearchReplaceTemplate.pdf";
	wstring outputFile= OUTPUTPATH+L"earchTextAndDrawRectangle.pdf";

	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	PdfPageBase* page = doc->GetPages()->GetItem(0);
	PdfTextFindCollection* collection = page->FindText(L"Spire.PDF for .NET", Find_TextFindParameter::IgnoreCase);
	for each (PdfTextFind * find in collection->GetFinds())
	{
		// Draw a rectangle with red pen
		page->GetCanvas()->DrawRectangle(new PdfPen(PdfBrushes::GetRed(), 0.9f), find->GetBounds());
	}
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete doc;
}

