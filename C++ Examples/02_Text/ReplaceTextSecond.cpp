#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring inputFile = DATAPATH+L"ReplaceTextInPage.pdf";
	wstring outputFile= OUTPUTPATH+L"ReplaceTextSecond.pdf";

	// Read a pdf file
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	
	//Get the first page of pdf file
	PdfPageBase* page = doc->GetPages()->GetItem(0);
	
	// create a PdfTextReplacer using the first page
	PdfTextReplacer* replacer = new PdfTextReplacer(page);
	
	//replace all texts in this page
	replacer->ReplaceAllText(L"Spire.PDF", L"E-iceblue");
	//replace all texts in this page
	replacer->ReplaceAllText(L"Adobe Acrobat", L"PDF editors");
	
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

    delete replacer;
	delete doc;
}

