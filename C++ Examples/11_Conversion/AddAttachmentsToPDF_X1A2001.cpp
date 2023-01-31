#include "pch.h"
using namespace Spire::Pdf;
using namespace std;
int main(){			
	wstring outputFile =OUTPUTPATH+L"AddAttachmentsToPDF_X1A2001.pdf";
	wstring inputFile = DATAPATH+L"AddAttachmentsToPDF_Temp.pdf";
	PdfStandardsConverter* converter = new PdfStandardsConverter(inputFile.c_str());
	converter->ToPdfX1A2001(outputFile.c_str());
	converter->Dispose();
	delete converter;	
}
