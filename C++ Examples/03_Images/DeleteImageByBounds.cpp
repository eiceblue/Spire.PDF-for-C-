#include "pch.h"

using namespace std;
using namespace Spire::Pdf;

int main() {
	wstring outputFile = OUTPUTPATH+L"DeleteImageByBounds.pdf";
	wstring fn1 = DATAPATH;

	//Open pdf document
	PdfDocument* pdf = new PdfDocument();
	pdf->LoadFromFile((fn1 + L"DeleteImageByBounds.pdf").c_str());

	//Get the first page
	PdfPageBase* page = pdf->GetPages()->GetItem(0);
	//Get the information of all images in this page 
	vector<PdfImageInfo*> imageInfo = page->GetImagesInfo();
	for (int i = 0; i < imageInfo.size(); i++)
	{

		if (imageInfo[i]->GetBounds()->Contains(49.68f, 73.1f))
		{
			page->DeleteImage(imageInfo[i]);
		}

		//Case 2: delete the image if it's bounds intersects with a certain rectangle
		if (imageInfo[i]->GetBounds()->IntersectsWith(new RectangleF(100.0f, 500.0f, 30.0f, 40.0f))) {
			page->DeleteImage(imageInfo[i]);
		}
	}
	//save to file
	pdf->SaveToFile(outputFile.c_str());

	pdf->Close();
	delete pdf;
}









