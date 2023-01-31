#include "pch.h"


using namespace Spire::Pdf;
using namespace std;

int main()
{
	wstring outputFile = OUTPUTPATH + L"FlattenFormField.pdf";
	wstring inputFile = DATAPATH + L"FlattenFormField.pdf";

	//Open pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//Flatten form fields
	doc->GetForm()->SetIsFlatten(true);

	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete doc;
}
