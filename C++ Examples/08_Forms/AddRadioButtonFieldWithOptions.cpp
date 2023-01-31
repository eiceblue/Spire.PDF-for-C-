#include "pch.h"

#include "stringhelper.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;


int main()
{
	wstring outputFile = OUTPUTPATH + L"AddRadioButtonFieldWithOptions.pdf";
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

	float x = 150;
	float y = 550;
	float temX = 0;
	//Create a pdf radio button list
	PdfRadioButtonListField* radioButton = new PdfRadioButtonListField(page, L"RadioButton");
	radioButton->SetRequired(true);
	//Add items into radio button list.
	for (int i = 0; i < 3; i++)
	{
		PdfRadioButtonListItem* item = new PdfRadioButtonListItem(StringHelper::formatSimple(L"item{0}", i).c_str());
		item->SetBorderWidth(0.75f);
		item->SetBounds(new RectangleF(x, y, 15, 15));
		item->SetBorderColor(new PdfRGBColor(Color::GetRed()));
		item->SetForeColor(new PdfRGBColor(Color::GetRed()));
		radioButton->GetItems()->Add(item);
		temX = x + 20;
		page->GetCanvas()->DrawString(StringHelper::formatSimple(L"Item{0}", i).c_str(), font, brush, temX, y);
		x = temX + 100;

	}

	//Add the radio button list field into pdf document
	pdf->GetForm()->GetFields()->Add(radioButton);
	//Save the document
	pdf->SaveToFile(outputFile.c_str());
	pdf->Close();
	delete pdf;
}