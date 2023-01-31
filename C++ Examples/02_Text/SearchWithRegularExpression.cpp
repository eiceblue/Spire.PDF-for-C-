#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring inputFile = DATAPATH+L"SearchReplaceTemplate.pdf";
	wstring outputFile= OUTPUTPATH+L"SearchWithRegularExpression.pdf";

	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	// Get the first page of pdf file
	PdfPageBase* page = doc->GetPages()->GetItem(0);
	// Create PdfTextFindCollection object to find all the phrases matching the regular expression
	PdfTextFindCollection* collection = page->FindText(L"\\d{4}", Find_TextFindParameter::Regex);
	wstring newText = L"New Year";
	// Creates a brush
	PdfBrush* brush = new PdfSolidBrush(new PdfRGBColor(Color::GetDarkBlue()));
	// Defines a font
	PdfTrueTypeFont* font = new PdfTrueTypeFont(L"Arial", 7.f, PdfFontStyle::Bold, true);
	// Defines text horizontal/vertical center format
	PdfStringFormat* centerAlign = new PdfStringFormat(PdfTextAlignment::Center, PdfVerticalAlignment::Middle);
	RectangleF* rec;
	for each (PdfTextFind * find in collection->GetFinds())
	{
		// Gets the bound of the found text in page
		rec = find->GetBounds();

		page->GetCanvas()->DrawRectangle(PdfBrushes::GetGreenYellow(), rec);
		// Draws new text as defined font and color
		page->GetCanvas()->DrawString(newText.c_str(), font, brush, rec, centerAlign);

		// This method can directly replace old text with newText,but it just can set the background color, can not set font/forecolor
		// find->ApplyRecoverString(newText.c_str(), Color::GetGray());
	}
	
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete doc;
}


