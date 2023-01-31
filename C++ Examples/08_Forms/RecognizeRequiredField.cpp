#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main()
{
	wstring outputFile = OUTPUTPATH + L"RecognizeRequiredField.txt";
	wstring inputFile = DATAPATH + L"RecognizeRequiredField.pdf";

	//Open pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//Get pdf forms
	PdfFormWidget* formWidget = Object::Convert<PdfFormWidget>(doc->GetForm());
	wstring str = L"";
	for (int i = 0; i < formWidget->GetFieldsWidget()->GetCount(); i++)
	{
		PdfField* field = formWidget->GetFieldsWidget()->GetItem(i);
		//Judge if the field is required
		if (field->GetRequired())
		{
			str.append(L"The field named: ");
			str.append(field->GetName());
			str.append(L" is required\r\n");
		}
	}
	wofstream os;
	os.open(outputFile, ios::trunc);
	os << str;
	os.close();
	//Save the document
	doc->Close();
	delete doc;
}