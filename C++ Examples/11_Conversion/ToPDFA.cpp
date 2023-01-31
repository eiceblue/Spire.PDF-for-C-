#include "pch.h"
using namespace Spire::Pdf;
using namespace std;

int main(){
	//Input and output files path
	wstring outputFile = OUTPUTPATH+L"ToPDFA.pdf";
	wstring inputFile = DATAPATH+L"ToPDFA.pdf";
             
	PdfStandardsConverter* converter_1 = new PdfStandardsConverter(inputFile.c_str());
	converter_1->ToPdfA1B(outputFile.c_str());
	delete converter_1;
}
