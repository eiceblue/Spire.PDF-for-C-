#include "pch.h"
using namespace Spire::Pdf;
using namespace std;

int main(){
	//Input and output files path			
	wstring inputFile = DATAPATH+L"ToPostScript.pdf";
	wstring outputFile = OUTPUTPATH+L"ToPostScript.ps";
     //Load a PDF document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
    //Save to PostScript
	doc->SaveToFile(outputFile.c_str(), FileFormat::POSTSCRIPT);
	doc->Close();
	delete doc;
}

