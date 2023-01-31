#include "pch.h"
using namespace Spire::Pdf;
using namespace std;
int main(){
	//Input and output files path
	wstring outputFile =OUTPUTPATH+L"ToTransparentBackgroundImages.png";
	wstring inputFile =DATAPATH+L"ToTransparentBackgroundImages.pdf";
	 //Load a PDF document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	doc->GetConvertOptions()->SetPdfToImageOptions(0);
	//Convert Pdf to image
	Stream* image = doc->SaveAsImage(0, PdfImageType::Bitmap);
	//Write image to file
	image->Save(outputFile.c_str());
	delete doc;
}
