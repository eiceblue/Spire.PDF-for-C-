#include "pch.h"


using namespace Spire::Pdf;
using namespace std;

int main()
{
	wstring outputFile = OUTPUTPATH + L"FillImageInButtonField.pdf";
	wstring input1 = DATAPATH + L"ButtonField.pdf";
	wstring input2 = DATAPATH + L"E-logo.png";

	//Load old PDF from disk.
	PdfDocument* pdf = new PdfDocument();
	pdf->LoadFromFile(input1.c_str());

	//Get pdf forms
	PdfFormWidget* form = Object::Convert<PdfFormWidget>(pdf->GetForm());

	//Traverse all the forms
	for (int i = 0; i < form->GetFieldsWidget()->GetCount(); i++)
	{
		//If it is Button field
		wchar_t nm_w[100];
		swprintf(nm_w, 100, L"%hs", typeid(PdfButtonWidgetFieldWidget).name());
		LPCWSTR_S newName = nm_w;
		if (wcscmp(newName, form->GetFieldsWidget()->GetItem(i)->GetInstanceTypeName()) == 0)
		{
			PdfButtonWidgetFieldWidget* field = Object::Convert<PdfButtonWidgetFieldWidget>(form->GetFieldsWidget()->GetItem(i));
			wstring str = field->GetName();
			if (str == L"Button1")
			{
				//Set "true" to fit bounds
				field->GetIconLayout()->SetIsFitBounds(true);

				//Fill the annotation rectangle exactly without its original aspect ratio
				field->GetIconLayout()->SetScaleMode(PdfButtonIconScaleMode::Anamorphic);

				//Fill an image
				field->SetButtonImage(PdfImage::FromFile(input2.c_str()));
			}
		}
	}

	//Save the document
	pdf->SaveToFile(outputFile.c_str());
	pdf->Close();
	delete pdf;
}
