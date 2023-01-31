#include "pch.h"

using namespace std;
using namespace Spire::Pdf;

int main() {
	wstring outputFile = OUTPUTPATH+L"DeleteImageFirstApproach.pdf";
	wstring fn1 = DATAPATH;

	//Open pdf document
	PdfDocument* pdf = new PdfDocument();
	pdf->LoadFromFile((fn1 + L"DeleteImage.pdf").c_str());
	//Get the first page
	PdfPageBase* page = pdf->GetPages()->GetItem(0);

	std::vector<PdfImageInfo*> imageInfo = page->GetImagesInfo();
	//first method
	page->DeleteImage(imageInfo[0]->GetIndex());
	//Save the document
	pdf->SaveToFile(outputFile.c_str());

	pdf->Close();
	delete pdf;
}







