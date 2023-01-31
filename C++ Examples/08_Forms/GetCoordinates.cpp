#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main()
{
	wstring outputFile = OUTPUTPATH + L"GetCoordinates.txt";
	wstring inputFile = DATAPATH + L"TextBoxSampleB.pdf";

	//Create a pdf document
	PdfDocument* doc = new PdfDocument();

	//Load from file
	doc->LoadFromFile(inputFile.c_str());

	//Get form fields
	PdfFormWidget* formWidget = Object::Convert<PdfFormWidget>(doc->GetForm());

	//Get textbox
	PdfTextBoxFieldWidget* textbox = Object::Convert<PdfTextBoxFieldWidget>(formWidget->GetFieldsWidget()->GetItem(L"Text1"));

	//Get the location of the textbox
	PointF* location = textbox->GetLocation();
	//Save to file.
	wofstream os;
	os.open(outputFile, ios::trunc);
	os << L"The location of the field named ";
	os << textbox->GetName();
	os << L" is\n X:";
	os << to_wstring(location->GetX());
	os << L"  Y:";
	os << to_wstring(location->GetY());
	os.close();

	doc->Close();
	delete doc;
}
