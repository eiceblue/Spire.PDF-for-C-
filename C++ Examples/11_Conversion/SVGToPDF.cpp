#include "pch.h"
using namespace Spire::Pdf;
using namespace std;

int main(){
	//Input and output files path
	wstring outputFile =OUTPUTPATH+L"SVGToPDF.pdf";
	wstring inputFile = DATAPATH+L"template.svg";
	//Create a new PDF document.
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromSvg(inputFile.c_str());

	doc->SaveToFile(outputFile.c_str());
	doc->Close();
	
	delete doc;
}
