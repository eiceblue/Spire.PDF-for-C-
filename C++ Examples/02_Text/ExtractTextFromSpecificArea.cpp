#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring inputFile =DATAPATH+L"ExtractTextFromSpecificArea.pdf";
	wstring outputFile= OUTPUTPATH+L"ExtractTextFromSpecificArea.txt";

	//Load the PDF file
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//Get the first page
	PdfPageBase* page = doc->GetPages()->GetItem(0);
	//Extract text from a specific rectangular area within the page
	wstring text = page->ExtractText(new RectangleF(80, 180, 500, 200));
	//Save the text to a .txt file
	wofstream os;
	os.open(outputFile, ios::trunc);
	os << text;
	os.close();
	doc->Close();

	delete doc;
}

