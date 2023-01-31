#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring inputFile = DATAPATH+L"FindAndHighlightText.pdf";
	wstring outputFile= OUTPUTPATH+L"FindAndHighlightText.pdf";
	//Load the document from disk
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	for (int i = 0; i < doc->GetPages()->GetCount(); i++) {
		PdfPageBase* page = doc->GetPages()->GetItem(i);
		//Find text
		for each (PdfTextFind * find in page->FindText(L"science", Find_TextFindParameter::None)->GetFinds())
		{
			//Highlight searched text
			find->ApplyHighLight();
		}
	}
	//Save the document
	doc->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	doc->Close();

	delete doc;
}

