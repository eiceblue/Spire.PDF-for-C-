#include "pch.h"


using namespace Spire::Pdf;
using namespace std;

int main()
{
	wstring outputFile = OUTPUTPATH + L"GetFieldValue.txt";
	wstring inputFile = DATAPATH + L"TextBoxSampleB_1.pdf";

	//Create a pdf document
	PdfDocument* doc = new PdfDocument();

	//Load from file
	doc->LoadFromFile(inputFile.c_str());

	//Get form fields
	PdfFormWidget* formWidget = Object::Convert<PdfFormWidget>(doc->GetForm());

	//Get textbox
	PdfTextBoxFieldWidget* textbox = Object::Convert<PdfTextBoxFieldWidget>(formWidget->GetFieldsWidget()->GetItem(L"Text1"));

	//Get the text of the textbox
	std::wstring text = textbox->GetText();

	//Save to file.
	wofstream os;
	os.open(outputFile, ios::trunc);
	os << L"The value of the field named ";
	os << textbox->GetName();
	os << L" is " + text;
	os.close();

	doc->Close();
	delete doc;
}
