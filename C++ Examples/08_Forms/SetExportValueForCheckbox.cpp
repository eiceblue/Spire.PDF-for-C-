#include "pch.h"


using namespace Spire::Pdf;
using namespace std;

int main()
{
	//Input and output file paths
	wstring outputFile = OUTPUTPATH + L"SetExportValueForCheckbox.pdf";
	wstring inputFile = DATAPATH + L"SetExportValueForCheckbox.pdf";

	PdfDocument* pdf = new PdfDocument();
	//Load from disk
	pdf->LoadFromFile(inputFile.c_str());
	PdfFormWidget* formWidget = Object::Convert<PdfFormWidget>(pdf->GetForm());
	int count = 1;
	//Traverse all FieldsWidget
	for (int i = 0; i < formWidget->GetFieldsWidget()->GetCount(); i++)
	{
		PdfField* field = formWidget->GetFieldsWidget()->GetItem(i);
		//Find the checkbox
		wchar_t nm_w[100];
		swprintf(nm_w, 100, L"%hs", typeid(PdfCheckBoxWidgetFieldWidget).name());
		LPCWSTR_S newName = nm_w;
		if (wcscmp(newName, field->GetInstanceTypeName()) == 0)
		{
			PdfCheckBoxWidgetFieldWidget* checkbox = Object::Convert<PdfCheckBoxWidgetFieldWidget>(field);
			//Set export value for checkbox
			checkbox->SetExportValue((L"True" + to_wstring(count++)).c_str());
		}
	}
	//Save the pdf file
	pdf->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	pdf->Close();
	delete pdf;
}

