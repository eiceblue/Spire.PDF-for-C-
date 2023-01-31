#include "pch.h"
#include "stringbuilder.h"
using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main()
{
	wstring outputFile =OUTPUTPATH+L"GetDocumentProperties.txt";
	
	// Creates a pdf document
	PdfDocument* doc = new PdfDocument();
	wstring inputFile = DATAPATH+L"PDFTemplate-Az.pdf";
	doc->LoadFromFile(inputFile.c_str());

	// Get document information
	PdfDocumentInformation* docInfo = doc->GetDocumentInformation();

	// Create a StringBuilder object to put the details
	StringBuilder* builder = new StringBuilder();
	wstring result = L"";
	result += L"Author:";
	result += docInfo->GetAuthor();
	builder->appendLine(result);
	result = L"Creation Date: ";
	result += docInfo->GetCreationDate()->ToString();
	builder->appendLine(result);
	result = L"Keywords: ";
	result += docInfo->GetKeywords();
	builder->appendLine(result);
	result = L"Modify Date: ";
	result += docInfo->GetModificationDate()->ToString();
	builder->appendLine(result);
	result = L"Subject: ";
	result += docInfo->GetSubject();
	builder->appendLine(result);
	result = L"Title: ";
	result += docInfo->GetTitle();
	builder->appendLine(result);

	//Save to file.
	wofstream os;
	os.open(outputFile, ios::trunc);
	os << builder->toString();
	os.close();

	doc->Close();

	delete builder;
	delete doc;
}
