#include "pch.h"
using namespace Spire::Pdf;
using namespace std;

int main(){
	wstring outputFile = OUTPUTPATH+L"ToXPS.xps";
	wstring inputFile =DATAPATH+L"ToXPS.pdf";
	//Open pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//Convert to xps file.
	doc->SaveToFile(outputFile.c_str(), FileFormat::XPS);
	doc->Close();

	delete doc;
}
