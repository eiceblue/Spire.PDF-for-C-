#include "pch.h"
#include "stringhelper.h"
#include "stringbuilder.h"
using namespace Spire::Common;
using namespace Spire::Pdf;
using namespace std;

int main(){
					
	wstring inputFile = DATAPATH+L"SampleB_3.pdf";
	wstring outputFile = OUTPUTPATH+L"ToHTMLFilesSplittedByPages.html";

	//Create a pdf document
	PdfDocument* doc = new PdfDocument();

	//Load an xisting pdf from disk
	doc->LoadFromFile(inputFile.c_str());

	//Split to HTML file according to pages, here one page will convert to a HTML file.
	doc->GetConvertOptions()->SetPdfToHtmlOptions(false, true, 1);

	//Save the document
	doc->SaveToFile(outputFile.c_str(), FileFormat::HTML);
	doc->Close();

	delete doc;
}

