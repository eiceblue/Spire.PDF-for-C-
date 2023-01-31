#include "pch.h"
using namespace Spire::Pdf;
using namespace std;

int main(){
	//Input and output files path
	wstring inputFile =DATAPATH+L"ChartSample.pdf";
	wstring outputFile = OUTPUTPATH+L"ToXLSX.xlsx";
	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//Save to XLSX
	doc->SaveToFile(outputFile.c_str(), FileFormat::XLSX);
}
