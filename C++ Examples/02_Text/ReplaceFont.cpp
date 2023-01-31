#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring inputFile = DATAPATH+L"ReplaceFont.pdf";
	wstring outputFile= OUTPUTPATH+L"ReplaceFont.pdf";

	//Load the document from disk 
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//Create a new font 
	PdfTrueTypeFont* newFont = new PdfTrueTypeFont(L"Arial", 13.f, PdfFontStyle::Regular, true);
	for each (PdfUsedFont * font in doc->GetUsedFonts())
	{
	//Replace the font with new font
	font->Replace(newFont);
	}
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete doc;
}

