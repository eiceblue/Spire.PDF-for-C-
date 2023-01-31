#include "pch.h"

using namespace std;
using namespace Spire::Pdf;

int main() {
	wstring inputFile = DATAPATH+L"ReplaceImage.pdf";
	wstring inputImg = DATAPATH+L"E-iceblueLogo.png";
	wstring outputFile = OUTPUTPATH+L"ReplaceImageSecondApproach.pdf";

	PdfDocument* pdf = new PdfDocument();
	pdf->LoadFromFile(inputFile.c_str());
	//Get the first page.
	PdfPageBase* page = pdf->GetPages()->GetItem(0);
	//Get images of the first page.
	std::vector<PdfImageInfo*> imageInfo = page->GetImagesInfo();
	//Load a image
	PdfImage* image = new PdfImage();
	image = image->FromFile(inputImg.c_str());

	//Replace the second image on the page.
	page->ReplaceImage(imageInfo[0]->GetIndex(), image);
	//Save the document
	pdf->SaveToFile(outputFile.c_str());

	pdf->Close();
	delete pdf;
}









