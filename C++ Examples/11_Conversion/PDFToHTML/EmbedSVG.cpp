#include "pch.h"
#include "stringhelper.h"
#include "stringbuilder.h"
using namespace Spire::Common;
using namespace Spire::Pdf;
using namespace std;
int main() {
	
	wstring inputFile = DATAPATH+L"SampleB_1.pdf";
	wstring outputFile = OUTPUTPATH+L"EmbedSVG.html";
	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	//Load an existing pdf from disk
	doc->LoadFromFile(inputFile.c_str());
	//Set the bool useEmbeddedSvg as true to convert to HTML with embeding SVG
	doc->GetConvertOptions()->SetPdfToHtmlOptions(true);
	//Save the document
	doc->SaveToFile(outputFile.c_str(), FileFormat::HTML);
	doc->Close();
	delete doc;
}

