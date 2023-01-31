#include "pch.h"


using namespace Spire::Pdf;
using namespace std;


int main()
{
	wstring outputFile = OUTPUTPATH + L"AddTooltipForFormField.pdf";
	wstring inputFile = DATAPATH + L"AddTooltipForFormField.pdf";

	//Open pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());

	//Get the first page
	PdfPageBase* page = doc->GetPages()->GetItem(0);

	//As for existing pdf, the property needs to be set as true
	doc->SetAllowCreateForm(true);

	//Create a new pdf font
	PdfFont* font = new PdfFont(PdfFontFamily::Helvetica, 12.0f, PdfFontStyle::Bold);

	//Create a pdf brush
	PdfBrush* brush = PdfBrushes::GetBlack();

	float x = 50;
	float y = 590;
	float tempX = 0;

	std::wstring text = L"E-mail: ";

	//Draw a text into page
	page->GetCanvas()->DrawString(text.c_str(), font, brush, x, y);

	tempX = font->MeasureString(text.c_str())->GetWidth() + x + 15;

	//Create a pdf textbox field
	PdfTextBoxField* textbox = new PdfTextBoxField(page, L"TextBox");

	//Set the bounds of textbox field
	textbox->SetBounds(new RectangleF(tempX, y, 100, 15));

	//Set the border width of textbox field
	textbox->SetBorderWidth(0.75f);

	//Set the border style of textbox field
	textbox->SetBorderStyle(PdfBorderStyle::Solid);

	//Add the textbox field into pdf document
	doc->GetForm()->GetFields()->Add(textbox);

	//Add a tooltip for the textbox field
	doc->GetForm()->GetFields()->GetItem(L"TextBox")->SetToolTip(L"Please insert a valid email address");
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();
	delete doc;
}