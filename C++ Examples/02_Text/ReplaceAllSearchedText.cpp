#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring inputFile = DATAPATH+L"SearchReplaceTemplate.pdf";
	wstring outputFile= OUTPUTPATH+L"ReplaceAllSearchedText.pdf";

	// Read a pdf file
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	// Get the first page of pdf file
	PdfPageBase* page = doc->GetPages()->GetItem(0);
	// Searches "Spire.PDF for .NET" by ignoring case
	PdfTextFindCollection* collection = page->FindText(L"Spire.PDF for .NET", Find_TextFindParameter::IgnoreCase);
	wstring newText = L"E-iceblue Spire.PDF";
	// Creates a brush
	PdfBrush* brush = new PdfSolidBrush(new PdfRGBColor(Color::GetDarkBlue()));
	// Defines a font
	PdfTrueTypeFont* font = new PdfTrueTypeFont(L"Arial", 12.f, PdfFontStyle::Regular, true);
	RectangleF* rec;
	for each (PdfTextFind * find in collection->GetFinds())
	{
	// Gets the bound of the found text in page
		rec = find->GetBounds();
		page->GetCanvas()->DrawRectangle(PdfBrushes::GetWhite(), rec);
		// Draws new text as defined font and color
		page->GetCanvas()->DrawString(newText.c_str(), font, brush, rec);
	}
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete doc;
}

