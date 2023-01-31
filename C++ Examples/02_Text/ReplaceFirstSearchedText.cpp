#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring inputFile = DATAPATH+L"SearchReplaceTemplate.pdf";
	wstring outputFile= OUTPUTPATH+L"ReplaceFirstSearchedText.pdf";

	// Read a pdf file
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	// Get the first page of pdf file
	PdfPageBase* page = doc->GetPages()->GetItem(0);
	// Searches "Spire.PDF for .NET" by ignoring case
	PdfTextFindCollection* collection = page->FindText(L"Spire.PDF for .NET", Find_TextFindParameter::IgnoreCase);
	wstring newText = L"Spire.PDF API";
	// Gets the first found object
	PdfTextFind* find = collection->GetFinds()[0];
	// Creates a brush
	PdfBrush* brush = new PdfSolidBrush(new PdfRGBColor(Color::GetDarkBlue()));
	// Defines a font
	PdfTrueTypeFont* font = new PdfTrueTypeFont(L"Arial", 15.f, PdfFontStyle::Bold, true);
	// Gets the bound of the first found text in page
	RectangleF* rec = find->GetBounds();
	page->GetCanvas()->DrawRectangle(PdfBrushes::GetWhite(), rec);
	// Draws new text as defined font and color
	page->GetCanvas()->DrawString(newText.c_str(), font, brush, rec);
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete doc;
}
