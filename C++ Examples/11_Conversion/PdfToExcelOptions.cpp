#include "pch.h"
using namespace Spire::Pdf;
using namespace std;

int main(){
	//Input and output files path
	wstring outputFile =OUTPUTPATH+L"PdfToExcelOptions.xlsx";
	wstring inputFile = DATAPATH+L"PdfToXlsxOptions.pdf";
	//Create a new PDF document.
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//set options
	doc->GetConvertOptions()->SetPdfToXlsxOptions(new XlsxLineLayoutOptions(false, true, true));
	//Save the pdf file to excel
	doc->SaveToFile(outputFile.c_str(), FileFormat::XLSX);
	doc->Close();
	delete doc;		
}
