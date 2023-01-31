#include "pch.h"
#include "stringbuilder.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main(){
				
	wstring outputFile = OUTPUTPATH+L"InsertEmptyPage.pdf";
	wstring inputFile = DATAPATH+L"Sample.pdf";
	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());

	//insert a blank page as the second page
	doc->GetPages()->Insert(1);
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete doc;
}
