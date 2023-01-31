#include "pch.h"
using namespace Spire::Pdf;
using namespace std;

int main(){
	//Input and output files path
	wstring inputFile = DATAPATH+L"ToDoc.pdf";
	wstring outputFile = OUTPUTPATH+L"ToDoc.doc";
    //Create a new PDF document.
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
    //save to file
	doc->SaveToFile(outputFile.c_str(), FileFormat::DOC);
	doc->Close();
	delete doc;

}
