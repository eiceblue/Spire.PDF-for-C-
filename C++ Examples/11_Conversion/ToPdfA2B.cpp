#include "pch.h"
using namespace Spire::Pdf;
using namespace std;
int main(){
	//Input and output files path
	wstring outputFile = OUTPUTPATH+L"ToPdfA2B.pdf";
	wstring inputFile = DATAPATH+L"ToPdfA2B.pdf";
    //Convert Pdf to PdfA2B 
	PdfStandardsConverter* converter_1 = new PdfStandardsConverter(inputFile.c_str());
	converter_1->ToPdfA2B(outputFile.c_str());
	delete converter_1;

}
