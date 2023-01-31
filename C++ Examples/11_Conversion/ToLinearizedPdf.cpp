#include "pch.h"
using namespace Spire::Pdf;
using namespace std;

int main(){
	//Input and output files path
	wstring inputFile = DATAPATH+L"PDFTemplate_N.pdf";
	wstring outputFile = OUTPUTPATH+L"ToLinearizedPdf.pdf";
	 //Convert to linearized Pdf
	PdfToLinearizedPdfConverter* converter = new PdfToLinearizedPdfConverter(inputFile.c_str());
	converter->ToLinearizedPdf(outputFile.c_str());
	delete converter;
}
		
	
