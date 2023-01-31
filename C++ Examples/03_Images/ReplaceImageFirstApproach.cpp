#include "pch.h"

using namespace std;
using namespace Spire::Pdf;

int main() {
	wstring inputFile = DATAPATH+L"ReplaceImage.pdf";
	wstring inputImg = DATAPATH+L"E-iceblueLogo.png";
	wstring outputFile= OUTPUTPATH+L"ReplaceImageFirstApproach.pdf";

	//Create a pdf document
	PdfDocument* pdf = new PdfDocument();
	pdf->LoadFromFile(inputFile.c_str());
	//Get the first page.
	PdfPageBase* page = pdf->GetPages()->GetItem(0);
	//Get images of the first page.
	std::vector<PdfImageInfo*> imageInfo = page->GetImagesInfo();
	PdfImage* image = new PdfImage();
	image = image->FromFile(inputImg.c_str());
	page->ReplaceImage(0, image);
	 //Save the document
	pdf->SaveToFile(outputFile.c_str());

	pdf->Close();
	delete pdf;
}









