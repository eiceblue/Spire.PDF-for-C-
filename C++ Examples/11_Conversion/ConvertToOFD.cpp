#include "pch.h"
using namespace Spire::Pdf;
using namespace std;

int main(){
	//Input and output files path
	wstring outputFile = OUTPUTPATH+L"ConvertToOFD.ofd";
	wstring inputFile = DATAPATH+L"ConvertToOFD.pdf";
	//Create pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//Convert pdf to ofd
	doc->SaveToFile(outputFile.c_str(), FileFormat::OFD);

	delete doc;
}

