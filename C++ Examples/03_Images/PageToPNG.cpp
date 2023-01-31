#include "pch.h"

using namespace std;
using namespace Spire::Pdf;

int main() {
	wstring inputFile = DATAPATH+L"PageToImage.pdf";
	wstring outputFile = OUTPUTPATH+L"PageToPNG\\PageToPNG.png";

	//Create a pdf document
	PdfDocument* pdf = new PdfDocument();
	pdf->LoadFromFile(inputFile.c_str());
	//Convert a particular page to emf
	//Set page index and image name
	int pageIndex = 1;
	//Save page to image in matefile type
	Spire::Common::Stream* image = new Spire::Common::Stream();
	//var image
	image = pdf->SaveAsImage(pageIndex, Spire::Pdf::PdfImageType::Bitmap);
	image->Save(outputFile.c_str());

	pdf->Close();
	delete pdf;
}









