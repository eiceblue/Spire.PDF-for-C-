#include "pch.h"

using namespace std;
using namespace Spire::Pdf;
using namespace Spire::Common;

int main()
{
	wstring outputFile = OUTPUTPATH + L"ImageWatermarkFirst.pdf";
	wstring inputFile = DATAPATH + L"ImageWaterMark.pdf";

	//Load the Pdf from disk
	PdfDocument* document = new PdfDocument();
	document->LoadFromFile(inputFile.c_str());
	//Get the first page
	PdfPageBase* page = document->GetPages()->GetItem(0);
	//Load image          
	wstring inputFile_i = DATAPATH + L"Background.png";
	Stream* img = new Stream(inputFile_i.c_str());
	//Set background image

	page->SetBackgroundImage(img);

	//Save the document
	document->SaveToFile(outputFile.c_str());
	document->Close();

	delete document;
}
