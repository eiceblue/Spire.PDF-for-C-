#include "pch.h"


using namespace Spire::Pdf;
using namespace std;

int main()
{
	wstring outputFile = OUTPUTPATH + L"ChangeFormFieldLocation.pdf";
	wstring inputFile = DATAPATH + L"FormField.pdf";
	//Open pdf document
	PdfDocument* pdf = new PdfDocument();
	pdf->LoadFromFile(inputFile.c_str());

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
			if (str == L"TextBox1")
			{
				// Change field location
				textbox->SetLocation(new PointF(390, 525));
			}
		}
	}
	//Save the document
	pdf->SaveToFile(outputFile.c_str());
	pdf->Close();
	delete pdf;
}
