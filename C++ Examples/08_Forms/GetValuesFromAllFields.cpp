#include "pch.h"

#include "stringhelper.h"
using namespace Spire::Pdf;
using namespace std;


int main()
{
	wstring outputFile = OUTPUTPATH + L"GetValuesFromAllFields.txt";
	wstring inputFile = DATAPATH + L"AllFields.pdf";
	wstring sb = L"";

	//Load a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());

	//Get pdf forms
	PdfFormWidget* formWidget = Object::Convert<PdfFormWidget>(doc->GetForm());

	//Find pdf form fields
	for (int i = 0; i < formWidget->GetFieldsWidget()->GetCount(); i++)
	{
		PdfField* field = formWidget->GetFieldsWidget()->GetItem(i);

		wchar_t nm_w1[100];
		swprintf(nm_w1, 100, L"%hs", typeid(PdfTextBoxFieldWidget).name());
		LPCWSTR_S newName1 = nm_w1;
		if (wcscmp(newName1, field->GetInstanceTypeName()) == 0)
		{
			PdfTextBoxFieldWidget* textBoxField = Object::Convert<PdfTextBoxFieldWidget>(field);
			//Get text of textbox
			std::wstring text = textBoxField->GetText();
			sb.append(L"The text in textbox is " + text + L"\r\n");
		}

		wchar_t nm_w2[100];
		swprintf(nm_w2, 100, L"%hs", typeid(PdfListBoxWidgetFieldWidget).name());
		LPCWSTR_S newName2 = nm_w2;
		if (wcscmp(newName2, field->GetInstanceTypeName()) == 0)
		{
			PdfListBoxWidgetFieldWidget* listBoxField = Object::Convert<PdfListBoxWidgetFieldWidget>(field);
			sb.append(L"Listbox items are \r\n");
			//Get values of listbox
			PdfListWidgetItemCollection* items = listBoxField->GetValues();
			for (int j = 0; j < items->GetCount(); j++)
			{
				auto item = items->GetItem(j);
				sb.append(item->GetValue());
				sb.append(L"\r\n");
			}
			//Get selected value
			std::wstring selectedValue = listBoxField->GetSelectedValue();
			sb.append(L"The selected value in the listbox is " + selectedValue + L"\r\n");

		}

		wchar_t nm_w3[100];
		swprintf(nm_w3, 100, L"%hs", typeid(PdfComboBoxWidgetFieldWidget).name());
		LPCWSTR_S newName3 = nm_w3;
		if (wcscmp(newName3, field->GetInstanceTypeName()) == 0)
		{
			PdfComboBoxWidgetFieldWidget* comBoxField = Object::Convert<PdfComboBoxWidgetFieldWidget>(field);
			sb.append(L"comBoxField items are \r\n");
			//Get values of comboBox
			PdfListWidgetItemCollection* items = comBoxField->GetValues();

			for (int j = 0; j < items->GetCount(); j++)
			{
				auto item = items->GetItem(j);
				sb.append(item->GetValue());
				sb.append(L"\r\n");
			}
			//Get selected value
			std::wstring selectedValue = comBoxField->GetSelectedValue();
			sb.append(L"The selected value in the comBoxField is " + selectedValue + L"\r\n");

		}

		wchar_t nm_w4[100];
		swprintf(nm_w4, 100, L"%hs", typeid(PdfRadioButtonListFieldWidget).name());
		LPCWSTR_S newName4 = nm_w4;
		if (wcscmp(newName4, field->GetInstanceTypeName()) == 0)
		{
			PdfRadioButtonListFieldWidget* radioBtnField = Object::Convert<PdfRadioButtonListFieldWidget>(field);
			//Get value of radio button
			std::wstring value = radioBtnField->GetValue();

			sb.append(L"The text in radioButtonField is " + value + L"\r\n");
		}

		wchar_t nm_w5[100];
		swprintf(nm_w5, 100, L"%hs", typeid(PdfCheckBoxWidgetFieldWidget).name());
		LPCWSTR_S newName5 = nm_w5;
		if (wcscmp(newName5, field->GetInstanceTypeName()) == 0)
		{
			PdfCheckBoxWidgetFieldWidget* checkBoxField = Object::Convert<PdfCheckBoxWidgetFieldWidget>(field);
			//Get the checked state of the checkbox
			bool state = checkBoxField->GetChecked();
			wstring stateValue = state ? L"True" : L"False";
			sb.append(L"If the checkBox is checked: " + stateValue + L"\r\n");
		}
	}
	//Save to file.
	wofstream os;
	os.open(outputFile, ios::trunc);
	os << sb;
	os.close();

	doc->Close();
	delete doc;
}
