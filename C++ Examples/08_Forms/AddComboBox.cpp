#include "pch.h"

using namespace Spire::Pdf;
using namespace std;


int main()
{
	wstring outputFile = OUTPUTPATH + L"AddComboBox.pdf";
	wstring inputFile = DATAPATH + L"SampleB_1.pdf";
	//Open pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	doc->SetAllowCreateForm(true);
	//Create comboBox
	PdfComboBoxField* comboBoxField = new PdfComboBoxField(doc->GetPages()->GetItem(0), L"Combox1");
	comboBoxField->SetBounds(new RectangleF(60, 300, 70, 30));
	comboBoxField->SetBorderWidth(0.75f);
	comboBoxField->SetFont(new PdfFont(PdfFontFamily::Helvetica, 9.f));
	comboBoxField->SetRequired(true);
	//Add items in comboBox
	comboBoxField->GetItems()->Add(new PdfListFieldItem(L"Apple", L"itme1"));
	comboBoxField->GetItems()->Add(new PdfListFieldItem(L"Banana", L"itme2"));
	comboBoxField->GetItems()->Add(new PdfListFieldItem(L"Pear", L"itme3"));
	comboBoxField->GetItems()->Add(new PdfListFieldItem(L"Peach", L"itme4"));
	comboBoxField->GetItems()->Add(new PdfListFieldItem(L"Grape", L"itme5"));
	//Add in form
	doc->GetForm()->GetFields()->Add(comboBoxField);
	//Save to file
	doc->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	doc->Close();

	delete doc;
}
