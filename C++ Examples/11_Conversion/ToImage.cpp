#include "pch.h"
using namespace Spire::Pdf;
using namespace std;

int main(){
	//Input and output files path
	wstring outputFile = OUTPUTPATH+L"ToImage\\";
	wstring inputFile = DATAPATH+L"ToImage.pdf";
	//Create a new PDF document.
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//Save to images
	for (int i = 0; i < doc->GetPages()->GetCount(); i++) {
		Stream* image = doc->SaveAsImage(i);
		wstring fileName = outputFile + to_wstring(i) + L".bmp";
		image->Save(fileName.c_str());
	}
	doc->Close();
	delete doc;
}
