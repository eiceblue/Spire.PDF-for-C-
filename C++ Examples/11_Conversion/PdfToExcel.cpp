#include "pch.h"
using namespace Spire::Pdf;
using namespace std;

int main(){
	//Input and output files path
	wstring outputFile=OUTPUTPATH+L"PdfToExcel.xlsx";
	wstring inputFile=DATAPATH+L"PdfToExcel.pdf";
	//Load a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//Save the pdf file to excel
	doc->SaveToFile(outputFile.c_str(), FileFormat::XLSX);
	doc->Close();

	delete doc;
}
