#include "pch.h"
#include "stringhelper.h"
#include "stringbuilder.h"
using namespace Spire::Common;
using namespace Spire::Pdf;
using namespace std;

int main(){
					
	wstring inputFile = DATAPATH+L"SampleB_1.pdf";
	wstring outputFile = OUTPUTPATH+L"ToHTMLStream.html";
	
	//Create a pdf document
	PdfDocument* pdf = new PdfDocument();
	//Load an existing pdf from disk
	pdf->LoadFromFile(inputFile.c_str());
	//Save to HTML stream
	Stream* ms = new Stream();
	pdf->SaveToStream(ms, FileFormat::HTML);
	ms->Save(outputFile.c_str());

	delete pdf;
				
}
