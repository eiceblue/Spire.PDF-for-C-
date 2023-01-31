#include "pch.h"


using namespace Spire::Pdf;
using namespace std;

int main()
{
	wstring outputFile = OUTPUTPATH + L"ExtractJavaScript.txt";
	wstring inputFile = DATAPATH + L"ExtractJavaScript.pdf";
	//Create a pdf document
	PdfDocument* pdf = new PdfDocument();

	//Load a pdf document
	pdf->LoadFromFile(inputFile.c_str());

	std::wstring js = L"";
	PdfFormWidget* form = Object::Convert<PdfFormWidget>(pdf->GetForm());
	for (int i = 0; i < form->GetFieldsWidget()->GetCount(); i++)
	{
		PdfField* field = form->GetFieldsWidget()->GetItem(i);
		wchar_t nm_w[100];
		swprintf(nm_w, 100, L"%hs", typeid(PdfTextBoxFieldWidget).name());
		LPCWSTR_S newName = nm_w;
		if (wcscmp(newName, field->GetInstanceTypeName()) == 0)
		{
			PdfTextBoxFieldWidget* textbox = Object::Convert<PdfTextBoxFieldWidget>(field);

			//Find the textbox named total
			wstring str = textbox->GetName();
			if (str == L"total")
			{
				//Get the action
				PdfJavaScriptAction* jsa = textbox->GetActions()->GetCalculate();

				if (jsa != nullptr)
				{
					//Get JavaScript
					js = jsa->GetScript();
				}
			}
		}
	}

	//Save and launch the result file
	wofstream os;
	os.open(outputFile, ios::trunc);
	os << js;
	os.close();
	pdf->Close();
	delete pdf;
}
