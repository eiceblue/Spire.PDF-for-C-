#include "pch.h"


using namespace Spire::Pdf;
using namespace std;


const wstring ToString(PdfCheckBoxStyle style) {
	switch (style)
	{
	case Spire::Pdf::PdfCheckBoxStyle::Check:
		return L"Check";
		break;
	case Spire::Pdf::PdfCheckBoxStyle::Circle:
		return L"Circle";
		break;
	case Spire::Pdf::PdfCheckBoxStyle::Cross:
		return L"Cross";
		break;
	case Spire::Pdf::PdfCheckBoxStyle::Diamond:
		return L"Diamond";
		break;
	case Spire::Pdf::PdfCheckBoxStyle::Square:
		return L"Square";
		break;
	case Spire::Pdf::PdfCheckBoxStyle::Star:
		return L"Star";
		break;
	default:
		break;
	}
}
int main() {

	wstring outputFile = OUTPUTPATH + L"GetStyleOfRadioButton.txt";
	wstring inputFile = DATAPATH + L"GetStyleOfRadioButton.pdf";
	//Open pdf document
	PdfDocument* pdf = new PdfDocument();
	pdf->LoadFromFile(inputFile.c_str());

	//Get the first page
	PdfPageBase* page = pdf->GetPages()->GetItem(0);

	//Get all form fields
	PdfFormWidget* formWidget = Object::Convert<PdfFormWidget>(pdf->GetForm());

	wstring str = L"";

	int num = 0;
	//Loop through all fields
	for (int i = 0; i < formWidget->GetFieldsWidget()->GetCount(); i++)
	{
		PdfField* field = formWidget->GetFieldsWidget()->GetItem(i);

		//Find the radio button field
		wchar_t nm_w[100];
		swprintf(nm_w, 100, L"%hs", typeid(PdfRadioButtonListFieldWidget).name());
		LPCWSTR_S newName = nm_w;
		if (wcscmp(newName, field->GetInstanceTypeName()) == 0)
		{
			num++;
			PdfRadioButtonListFieldWidget* radio = Object::Convert<PdfRadioButtonListFieldWidget>(field);

			//Get the button style
			PdfCheckBoxStyle buttonStyle = radio->GetButtonStyle();
			str.append(L"The button style of Radio button " + to_wstring(num) + L" is: ");
			str += ToString(buttonStyle) + L"\r\n";
		}
	}

	//Save the document
	wofstream os;
	os.open(outputFile, ios::trunc);
	os << str;
	os.close();
	pdf->Close();
	delete pdf;
}
