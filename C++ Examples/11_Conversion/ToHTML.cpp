#include "pch.h"
using namespace Spire::Pdf;
using namespace std;

int main(){
	//Input and output files path
	wstring inputFile = DATAPATH+L"ToHTML.pdf";
	wstring outputFile = OUTPUTPATH+"ToHTML.html";
	//Create a new PDF document.
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//save to file
	doc->SaveToFile(outputFile.c_str(), FileFormat::HTML);
	doc->Close();
	delete doc;
			
}
