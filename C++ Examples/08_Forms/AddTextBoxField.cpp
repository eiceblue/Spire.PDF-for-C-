#include "pch.h"


using namespace Spire::Pdf;
using namespace std;


int main()
{
	wstring outputFile = OUTPUTPATH + L"AddTextBoxField.pdf";
	wstring inputFile = DATAPATH + L"FormFieldTemplate.pdf";
	//Open pdf document
	PdfDocument* pdf = new PdfDocument();
	pdf->LoadFromFile(inputFile.c_str());

	//Get the first page
	PdfPageBase* page = pdf->GetPages()->GetItem(0);

	//As for existing pdf, the property needs to be set as true
	pdf->SetAllowCreateForm(true);

	//Create a new pdf font
	PdfFont* font = new PdfFont(PdfFontFamily::Helvetica, 12.0f, PdfFontStyle::Bold);

	//Create a pdf brush
	PdfBrush* brush = PdfBrushes::GetBlack();

	float x = 50;
	float y = 550;
	float tempX = 0;

	std::wstring text = L"TexBox: ";

	//Draw a text into page
	page->GetCanvas()->DrawString(text.c_str(), font, brush, x, y);

	//Add a textBox field
	tempX = font->MeasureString(text.c_str())->GetWidth() + x + 15;
	PdfTextBoxField* textbox = new PdfTextBoxField(page, L"TextBox");
	textbox->SetBounds(new RectangleF(tempX, y, 100, 15));
	textbox->SetBorderWidth(0.75f);
	textbox->SetBorderStyle(PdfBorderStyle::Solid);
	pdf->GetForm()->GetFields()->Add(textbox);
	//Save the document
	pdf->SaveToFile(outputFile.c_str());
	pdf->Close();
	delete pdf;
}
