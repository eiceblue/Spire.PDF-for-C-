#include "pch.h"

using namespace std;
using namespace Spire::Pdf;

int main() {
	wstring outputFile = OUTPUTPATH+L"DeleteImageSecondApproach.pdf";
	wstring fn1 = DATAPATH;

	//Create a pdf document
	PdfDocument* pdf = new PdfDocument();
	//Load the document from disk
	pdf->LoadFromFile((fn1+ L"DeleteImage.pdf").c_str());
	//Get the first page
	PdfPageBase* page = pdf->GetPages()->GetItem(0);
	//Delete the first image on the page  second method
	page->DeleteImage(0);
	//Save the document
	pdf->SaveToFile(outputFile.c_str());

	pdf->Close();
	delete pdf;
}







