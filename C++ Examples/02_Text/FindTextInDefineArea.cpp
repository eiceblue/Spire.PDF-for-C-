#include "pch.h"

using namespace Spire::Pdf;
using namespace std; 
using namespace Spire::Common;

int main() {
	wstring inputFile = DATAPATH+L"SampleB_1.pdf";
	wstring outputFile= OUTPUTPATH+L"FindTextInDefineArea.pdf";

	//load document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//define a rectangle
	RectangleF* rectg = new RectangleF(0, 0, 300, 300);
	//find text in the rectangle
	PdfTextFindCollection* findCollection = doc->GetPages()->GetItem(0)
	->FindText(rectg, L"Spire", Find_TextFindParameter::WholeWord);
	PdfTextFindCollection* findCollectionOut = doc->GetPages()->GetItem(0)
	->FindText(rectg, L"PDF", Find_TextFindParameter::WholeWord);
	//highlight the found text
	for each (PdfTextFind * find in findCollection->GetFinds())
	{
	find->ApplyHighLight(Color::GetGreen());
	}
	for each (PdfTextFind * findOut in findCollectionOut->GetFinds())
	{
	findOut->ApplyHighLight(Color::GetYellow());
	}
	//save the document
	doc->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	doc->Close();

	delete doc;
}


