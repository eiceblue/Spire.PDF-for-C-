#include "pch.h"


using namespace Spire::Pdf;
using namespace std;

int main()
{
	wstring outputFile = OUTPUTPATH + L"SelectRadioButtonItem.pdf";
	wstring inputFile = DATAPATH + L"RadioButton.pdf";
	PdfDocument* pdf = new PdfDocument();
	//Load a pdf document
	pdf->LoadFromFile(inputFile.c_str());

	//Get pdf forms
	PdfFormWidget* formWidget = Object::Convert<PdfFormWidget>(pdf->GetForm());

	//Find the radio button field and select the second item
	for (int i = 0; i < formWidget->GetFieldsWidget()->GetCount(); i++)
	{
		PdfField* field = formWidget->GetFieldsWidget()->GetItem(i);

		wchar_t nm_w[100];
		swprintf(nm_w, 100, L"%hs", typeid(PdfRadioButtonListFieldWidget).name());
		LPCWSTR_S newName = nm_w;
		if (wcscmp(newName, field->GetInstanceTypeName()) == 0)
		{
			PdfRadioButtonListFieldWidget* radioButton = Object::Convert<PdfRadioButtonListFieldWidget>(field);
			wstring str = radioButton->GetName();
			if (str == L"RadioButton")
			{
				radioButton->SetSelectedIndex(1);
			}
		}
	}
	//Save the document
	pdf->SaveToFile(outputFile.c_str());
	pdf->Close();
	delete pdf;
}
