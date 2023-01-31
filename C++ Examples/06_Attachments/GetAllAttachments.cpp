#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	std::wstring outputFile_p = OUTPUTPATH+L"attachment1.pdf";
	std::wstring outputFile_t = OUTPUTPATH+L"attachment1.txt";
	std::wstring outputFile_i = OUTPUTPATH+L"Demo/Logo.log";
	wstring inputFile = DATAPATH+L"Template_Pdf_2.pdf";

	//Create a new PDF document.
	PdfDocument* doc = new PdfDocument();
	//Load the file from disk.
	doc->LoadFromFile(inputFile.c_str());

	//Get all attachments
	PdfAttachmentCollection* attachments = doc->GetAttachments();

	//Save all the attachments to the files.
	attachments->GetItem(0)->GetData()->Save(outputFile_i.c_str());
	attachments->GetItem(1)->GetData()->Save(outputFile_p.c_str());
	attachments->GetItem(2)->GetData()->Save(outputFile_t.c_str());

	delete doc;
}


