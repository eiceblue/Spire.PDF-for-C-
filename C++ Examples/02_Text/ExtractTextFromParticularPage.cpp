#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring inputFile = DATAPATH+L"PDFTemplate-Az.pdf";
	wstring outputFile = OUTPUTPATH+L"ExtractTextFromParticularPage.txt";

	// Read a pdf file
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	// Get the first page
	PdfPageBase* page = doc->GetPages()->GetItem(0);
	// Extract text from page keeping white space
	wstring text = page->ExtractText(true);
	// Write a line of text to the file
	wofstream os;
	os.open(outputFile, ios::trunc);
	os << text;
	os.close();
	doc->Close();

	delete doc;
}

