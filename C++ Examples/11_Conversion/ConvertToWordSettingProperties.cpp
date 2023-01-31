#include "pch.h"
using namespace Spire::Pdf;
using namespace std;

int main()
{
	//Input and output files path
	wstring inputFile = DATAPATH+L"ConvertToWordSettingProperties.pdf";
	wstring outputFile = OUTPUTPATH+L"ConvertToWordSettingProperties.docx";

	//Create PdfToDocConverter
	PdfToDocConverter* converter = new PdfToDocConverter(inputFile.c_str());
	 //Set properties for the .docx document
	converter->GetDocxOptions()->SetTitle(L"PDFTODOCX");
	converter->GetDocxOptions()->SetSubject(L"Set document properties.");
	converter->GetDocxOptions()->SetTags(L"Test Tags");
	converter->GetDocxOptions()->SetCategories(L"PDF");
	converter->GetDocxOptions()->SetCommments(L"This document is just for testing the properties");
	converter->GetDocxOptions()->SetAuthors(L"E-iceblue Support Team");
	converter->GetDocxOptions()->SetLastSavedBy(L"E-iceblue Support Team");
	converter->GetDocxOptions()->SetRevision(8);
	converter->GetDocxOptions()->SetVersion(L"csharp V4.0");
	converter->GetDocxOptions()->SetProgramName(L"Spire.Pdf for .NET");
	converter->GetDocxOptions()->SetCompany(L"E-iceblue");
	converter->GetDocxOptions()->SetManager(L"E-iceblue");
	//Convert pdf to docx
	converter->SaveToDocx(outputFile.c_str());

	delete converter;
}
