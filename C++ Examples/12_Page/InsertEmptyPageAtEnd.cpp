#include "pch.h"
#include "stringbuilder.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main(){
				
	wstring outputFile = OUTPUTPATH+L"InsertEmptyPageAtEnd.pdf";
	wstring inputFile = DATAPATH+L"MultipagePDF.pdf";

	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//Add an empty page at the end 
	PdfMargins tempVar(0, 0);
	doc->GetPages()->Add(new SizeF(PdfPageSize::A4()), &tempVar);

	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();
	
	delete doc;
}
