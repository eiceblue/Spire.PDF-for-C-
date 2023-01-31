#include "pch.h"
#include "stringhelper.h"
#include "stringbuilder.h"
using namespace std;
using namespace Spire::Pdf;
using namespace Spire::Common;
int main() {
                    
    wstring inputFile = DATAPATH+L"EmbedImagesInHTML.pdf";
					
    wstring outputFile = OUTPUTPATH+L"EmbedImages.html";
	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
    //Load an existing PDF
	doc->LoadFromFile(inputFile.c_str());

	//Set the convertion option to embed image in html
	doc->GetConvertOptions()->SetPdfToHtmlOptions(true, true);

	//Save the document
	doc->SaveToFile(outputFile.c_str(), FileFormat::HTML);
	doc->Close();
	delete doc;
}

