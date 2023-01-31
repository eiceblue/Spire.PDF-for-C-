#include "pch.h"
using namespace Spire::Pdf;
using namespace std;
int main(){							
	wstring outputFile = OUTPUTPATH+L"AddAttachmentsToPDF_A1A.pdf";
	wstring inputFile = DATAPATH+L"AddAttachmentsToPDF_Temp.pdf";
	PdfStandardsConverter* converter = new PdfStandardsConverter(inputFile.c_str());
	converter->ToPdfA1A(outputFile.c_str());
	delete converter;	
}
