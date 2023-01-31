#include "pch.h"
using namespace Spire::Pdf;
using namespace std;

int main(){
	//Input and output files path
	wstring inputFile = DATAPATH+L"ToSVG.pdf";
	wstring outputFile = OUTPUTPATH+L"ToSVG.svg";
	//Load a PDF document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//Convert to svg file
	doc->SaveToFile(outputFile.c_str(), FileFormat::SVG);
	doc->Close();
	delete doc;
}
