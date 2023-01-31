#include "pch.h"


using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring outputFile = OUTPUTPATH + L"AddCheckBox.pdf";
	wstring inputFile = DATAPATH + L"SampleB_1.pdf";

	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	doc->SetAllowCreateForm(true);
	//Create checkbox
	PdfCheckBoxField* checkboxField = new PdfCheckBoxField(doc->GetPages()->GetItem(0), L"fieldID");
	float checkboxWidth = 40;
	float checkboxHeight = 40;
	checkboxField->SetBounds(new RectangleF(60, 300, checkboxWidth, checkboxHeight));
	checkboxField->SetBorderWidth(0.75f);
	checkboxField->SetChecked(true);
	checkboxField->SetStyle(PdfCheckBoxStyle::Check);
	checkboxField->SetRequired(true);
	//Add in form
	doc->GetForm()->GetFields()->Add(checkboxField);
	//Save to file
	doc->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	doc->Close();
	delete doc;
}
