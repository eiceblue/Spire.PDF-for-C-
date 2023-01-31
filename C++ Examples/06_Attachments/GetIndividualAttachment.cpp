#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring inputFile = DATAPATH+L"Template_Pdf_2.pdf";
	std::wstring outputFile =  OUTPUTPATH+L"GetIndividualAttachment.pdf";

	//Create a new PDF document.
	PdfDocument* pdf = new PdfDocument();

	//Load the file from disk.
	pdf->LoadFromFile(inputFile.c_str());

	//Get a collection of attachments on the PDF document.
	PdfAttachmentCollection* collection = pdf->GetAttachments();

	//Get the second attachment in PDF file and Save the second attachment to the file.
	collection->GetItem(1)->GetData()->Save(outputFile.c_str());

	delete pdf;
}

