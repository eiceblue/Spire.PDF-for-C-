#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring outputFile = OUTPUTPATH+L"RearrangePageOrder.pdf";
	wstring inputFile = DATAPATH+L"SampleB_3.pdf";

	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());

	//Rearrange the page order
	doc->GetPages()->ReArrange(std::vector<int> {1, 0});

	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete doc;
}

