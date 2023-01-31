#include "pch.h"
#include "../../stringbuilder.h"
#include "../../stringhelper.h"

using namespace Spire::Pdf;
using namespace std;
int main() {
	wstring inputFile = DATAPATH+L"Template_Pdf_2.pdf";
	std::wstring outputFile = OUTPUTPATH+L"GetPdfAttachmentInfo.txt";

	//Create a new PDF document
	PdfDocument* pdf = new PdfDocument();

	//Load the file from disk.
	pdf->LoadFromFile(inputFile.c_str());

	//Get a collection of attachments on the PDF document
	PdfAttachmentCollection* collection = pdf->GetAttachments();

	//Get the first attachment.
	PdfAttachment* attachment = collection->GetItem(0);

	//Get the information of the first attachment.
	StringBuilder* content = new StringBuilder();
	content->appendLine(L"Filename: " + (wstring)attachment->GetFileName());
	content->appendLine(L"Description: " + (wstring)attachment->GetDescription());
	content->appendLine(L"Creation Date: " + (wstring)attachment->GetCreationDate()->ToString());
	content->appendLine(L"Modification Date: " + (wstring)attachment->GetModificationDate()->ToString());
	//Save to file.
	wofstream os;
	wstring str = content->toString();
	os.open(outputFile, ios::trunc);
	os << str;
	os.close();

	delete content;
	delete pdf;

}


