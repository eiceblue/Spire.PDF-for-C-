#include "pch.h"
#include "stringbuilder.h"
using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main(){
				
	wstring outputFile = OUTPUTPATH+L"GetPageLabel.txt";
	wstring inputFile = DATAPATH+L"PageLabel.pdf";
	
	//Create a pdf document
	PdfDocument* pdf = new PdfDocument();
	pdf->LoadFromFile(inputFile.c_str());

	//Create a StringBuilder instance
	StringBuilder* sb = new StringBuilder();

	//Get the lables of the pages in the PDF file
	for (int i = 0; i < pdf->GetPages()->GetCount(); i++)
	{
		sb->appendLine(L"The page lable of page " + std::to_wstring(i + 1) + L" is \"" + pdf->GetPages()->GetItem(i)->GetPageLabel() + L"\"");
	}

	//Save to file
	wofstream os;
	os.open(outputFile, ios::trunc);
	os << sb->toString();
	os.close();

	delete sb;
	delete pdf;
}
