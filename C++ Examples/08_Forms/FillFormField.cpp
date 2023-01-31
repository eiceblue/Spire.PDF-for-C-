#include "pch.h"


using namespace Spire::Pdf;
using namespace std;

int main()
{
	wstring outputFile = OUTPUTPATH + L"FillFormField.pdf";
	wstring inputFile = DATAPATH + L"FillFormField.pdf";
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//Get pdf forms
	PdfFormWidget* formWidget = Object::Convert<PdfFormWidget>(doc->GetForm());

	//Fill pdf form fields
	for (int i = 0; i < formWidget->GetFieldsWidget()->GetCount(); i++)
	{
		PdfField* field = formWidget->GetFieldsWidget()->GetItem(i);
		wchar_t nm_w1[100];
		swprintf(nm_w1, 100, L"%hs", typeid(PdfTextBoxFieldWidget).name());
		LPCWSTR_S newName1 = nm_w1;
		if (wcscmp(newName1, field->GetInstanceTypeName()) == 0)
		{
			PdfTextBoxFieldWidget* textBoxField = Object::Convert<PdfTextBoxFieldWidget>(field);
			wstring str = textBoxField->GetName();
			if (str == L"email")
			{
				textBoxField->SetText(L"support@e-iceblue.com");

			}
			else if (str == L"username")
			{
				textBoxField->SetText(L"E-iceblue");

			}
			else if (str == L"password")
			{
				textBoxField->SetPassword(true);
				textBoxField->SetText(L"e-iceblue");

			}
			else if (str == L"password2")
			{
				textBoxField->SetPassword(true);
				textBoxField->SetText(L"e-iceblue");

			}
			else if (str == L"company_name ")
			{
				textBoxField->SetText(L"E-iceblue");

			}
			else if (str == L"first_name")
			{
				textBoxField->SetText(L"James");

			}
			else if (str == L"last_name")
			{
				textBoxField->SetText(L"Chen");

			}
			else if (str == L"middle_name")
			{
				textBoxField->SetText(L"J");

			}
			else if (str == L"address1")
			{
				textBoxField->SetText(L"Chengdu");

			}
			else if (str == L"address2")
			{
				textBoxField->SetText(L"Beijing");

			}
			else if (str == L"city")
			{
				textBoxField->SetText(L"Shanghai");

			}
			else if (str == L"postal_code")
			{
				textBoxField->SetText(L"11111");

			}
			else if (str == L"state")
			{
				textBoxField->SetText(L"Shanghai");

			}
			else if (str == L"phone")
			{
				textBoxField->SetText(L"1234567901");

			}
			else if (str == L"mobile_phone")
			{
				textBoxField->SetText(L"123456789");

			}
			else if (str == L"fax")
			{
				textBoxField->SetText(L"12121212");
			}
		}

		wchar_t nm_w2[100];
		swprintf(nm_w2, 100, L"%hs", typeid(PdfListBoxWidgetFieldWidget).name());
		LPCWSTR_S newName2 = nm_w2;
		if (wcscmp(newName2, field->GetInstanceTypeName()) == 0)
		{
			PdfListBoxWidgetFieldWidget* listBoxField = Object::Convert<PdfListBoxWidgetFieldWidget>(field);
			wstring str = listBoxField->GetName();
			if (str == L"email_format")
			{
				std::vector<int> index = { 1 };
				listBoxField->SetSelectedIndex(index);
			}
		}

		wchar_t nm_w3[100];
		swprintf(nm_w3, 100, L"%hs", typeid(PdfComboBoxWidgetFieldWidget).name());
		LPCWSTR_S newName3 = nm_w3;
		if (wcscmp(newName3, field->GetInstanceTypeName()) == 0)
		{
			PdfComboBoxWidgetFieldWidget* comBoxField = Object::Convert<PdfComboBoxWidgetFieldWidget>(field);
			wstring str = comBoxField->GetName();
			if (str == L"title")
			{
				std::vector<int> items = { 0 };
				comBoxField->SetSelectedIndex(items);
			}
		}

		wchar_t nm_w4[100];
		swprintf(nm_w4, 100, L"%hs", typeid(PdfRadioButtonListFieldWidget).name());
		LPCWSTR_S newName4 = nm_w4;
		if (wcscmp(newName4, field->GetInstanceTypeName()) == 0)
		{
			PdfRadioButtonListFieldWidget* radioBtnField = Object::Convert<PdfRadioButtonListFieldWidget>(field);
			wstring str = radioBtnField->GetName();
			if (str == L"country")
			{
				radioBtnField->SetSelectedIndex(1);
			}
		}
		wchar_t nm_w5[100];
		swprintf(nm_w5, 100, L"%hs", typeid(PdfCheckBoxWidgetFieldWidget).name());
		LPCWSTR_S newName5 = nm_w5;
		if (wcscmp(newName5, field->GetInstanceTypeName()) == 0)
		{
			PdfCheckBoxWidgetFieldWidget* checkBoxField = Object::Convert<PdfCheckBoxWidgetFieldWidget>(field);
			wstring str = checkBoxField->GetName();
			if (str == L"agreement_of_terms")
			{
				checkBoxField->SetChecked(true);
			}
		}

		wchar_t nm_w6[100];
		swprintf(nm_w6, 100, L"%hs", typeid(PdfButtonWidgetFieldWidget).name());
		LPCWSTR_S newName6 = nm_w6;
		if (wcscmp(newName6, field->GetInstanceTypeName()) == 0)
		{
			PdfButtonWidgetFieldWidget* btnField = Object::Convert<PdfButtonWidgetFieldWidget>(field);
			wstring str = btnField->GetName();
			if (str == L"submit")
			{
				btnField->SetText(L"Submit");
			}
		}
	}

	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();
	delete doc;
}
