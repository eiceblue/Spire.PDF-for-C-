#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main(){
				
	//Output file path
	wstring inputFile = DATAPATH+L"ConvertToGrayPdf.pdf";
	wstring outputFile = OUTPUTPATH+L"ConvertToGrayPdf.pdf";
	//Create a PdfGrayConverter with an pdf file
	PdfGrayConverter* converter = new PdfGrayConverter(inputFile.c_str());
	//Convert the file to gray pdf
	converter->ToGrayPdf(outputFile.c_str());

	delete converter;			
}
