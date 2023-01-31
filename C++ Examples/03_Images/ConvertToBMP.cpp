#include "pch.h"

using namespace std;
using namespace Spire::Pdf;

int main() {
	wstring outputFile = OUTPUTPATH+L"ConvertToBMP\\";
	wstring fn1 = DATAPATH;

	//Open pdf document
	PdfDocument* pdf = new PdfDocument();
	pdf->LoadFromFile((fn1 + L"ToImage.pdf").c_str());
	//Save to images
	Spire::Common::Stream* image = new Spire::Common::Stream();
	for (int i = 0; i < pdf->GetPages()->GetCount(); i++)
	{
		wstring s = to_wstring(i);
		wstring filename = outputFile +  L"ToBMP-img-" + s + L".bmp";
		//var image
		image = pdf->SaveAsImage(i, Spire::Pdf::PdfImageType::Bitmap);
		image->Save(filename.c_str());
	}

	pdf->Close();
	delete pdf;
}









