#include "pch.h"
#include "stringbuilder.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main()
{
	wstring outputFile = OUTPUTPATH+L"PageLable_1.pdf";
	wstring inputFile = DATAPATH+L"Sample.pdf";
	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	doc->SetPageLabels(new PdfPageLabels());
	doc->GetPageLabels()->AddRange(0, PdfPageLabels::Decimal_Arabic_Numerals_Style(), L"label test ");
	//Save the document
	doc->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	delete doc;
}

void PageLable_2()
{
	wstring outputFile = OUTPUTPATH+L"PageLable_2.pdf";
	wstring inputFile = DATAPATH+L"hasLable.pdf";

	PdfDocument* newdoc = new PdfDocument();
	newdoc->LoadFromFile(inputFile.c_str());

	PdfPageLabels* pageLabels = newdoc->GetPageLabels();
	pageLabels->AddRange(0, PdfPageLabels::Decimal_Arabic_Numerals_Style(), L"new lable");
	newdoc->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	newdoc->Dispose();

	delete pageLabels;
	delete newdoc;
}

