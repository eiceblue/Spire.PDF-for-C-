#include "pch.h"
#include "../../stringbuilder.h"
#include "../../stringhelper.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring input_Img = DATAPATH+L"E-logo.png";
	wstring  inputFile = DATAPATH+L"Attachment.pdf";
	std::wstring  outputFile = OUTPUTPATH+L"PdfAttachmentRelationship.pdf";

	//Load document from disk
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//Define PdfAttachment
	PdfAttachment* attachment = new PdfAttachment(input_Img.c_str());
	//Add addachment
	doc->GetAttachments()->Add(attachment, doc, PdfAttachmentRelationship::Alternative);
	//Save the document
	doc->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	doc->Close();

}

