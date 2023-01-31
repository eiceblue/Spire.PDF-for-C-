#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
int main() {
	wstring outputFile = OUTPUTPATH+L"DeleteAllAttachments.pdf";
	wstring inputFile = DATAPATH+L"DeleteAllAttachments.pdf";

	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());

	//Get all attachments
	PdfAttachmentCollection* attachments = doc->GetAttachments();

	//Delete all attachments
	attachments->Clear();
	//Save pdf file
	doc->SaveToFile(outputFile.c_str());
	doc->Close();


	delete doc;
}


