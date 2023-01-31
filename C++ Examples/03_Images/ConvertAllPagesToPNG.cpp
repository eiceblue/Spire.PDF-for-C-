#include "pch.h"

using namespace std;
using namespace Spire::Pdf;

int main() {
	wstring inputFile = DATAPATH+L"ToImage.pdf";
	wstring outputFile = OUTPUTPATH+L"ConvertAllPagesToPNG\\";

	//Open pdf document   Load an Pdf file      
	Spire::Common::Stream* image = new Spire::Common::Stream();
	PdfDocument* pdf = new PdfDocument();
	pdf->LoadFromFile(inputFile.c_str());
	//Save to images
	for (int i = 0; i < pdf->GetPages()->GetCount(); i++)
	{
		wstring s = to_wstring(i);
		wstring filename = OUTPUTPATH + L"ToPNG-img-" + s + L".png";
		//var image
		image = pdf->SaveAsImage(i, Spire::Pdf::PdfImageType::Bitmap);
		image->Save(filename.c_str());
	}

	pdf->Close();
	delete pdf;
}







