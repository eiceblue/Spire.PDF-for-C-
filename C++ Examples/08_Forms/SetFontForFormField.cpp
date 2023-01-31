#include "pch.h"


using namespace Spire::Pdf;
using namespace std;

int main()
{
	wstring outputFile = OUTPUTPATH + L"SetFontForFormField.pdf";
	wstring inputFile = DATAPATH + L"TextBoxSampleB.pdf";
	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	//Load from file
	doc->LoadFromFile(inputFile.c_str());

	//Get form fields
	PdfFormWidget* formWidget = Object::Convert<PdfFormWidget>(doc->GetForm());

	//Get textbox
	PdfTextBoxFieldWidget* textbox = Object::Convert<PdfTextBoxFieldWidget>(formWidget->GetFieldsWidget()->GetItem(L"Text1"));

	//Set the font for textbox

	textbox->SetFont(new PdfTrueTypeFont(L"Tahoma", 12, PdfFontStyle::Regular, true));
	//Set text
	textbox->SetText(L"Hello World");
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();
	delete doc;
}
