#include "pch.h"
#include "stringbuilder.h"
#include "stringhelper.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	std::wstring input_1 = DATAPATH+L"SampleB_1.pdf";
	std::wstring input_2 = DATAPATH+L"SampleB_2.pdf";
	std::wstring input_3 = DATAPATH+L"SampleB_3.pdf";
	std::wstring outputFile = OUTPUTPATH+L"SortFileInPdf.pdf";
	//Create a pdf document
	PdfDocument* doc = new PdfDocument();

	doc->GetCollection()->AddCustomField(L"No", L"number", CustomFieldType::NumberField);
	doc->GetCollection()->AddFileRelatedField(L"Desc", L"desc", FileRelatedFieldType::Desc);
	doc->GetCollection()->Sort({ L"No", L"Desc" }, {true, true});

	//Get the attachment.
	PdfAttachment* pdfAttachment = new PdfAttachment(input_1.c_str());
	doc->GetCollection()->AddAttachment(pdfAttachment);
	pdfAttachment = new PdfAttachment(input_2.c_str());
	doc->GetCollection()->AddAttachment(pdfAttachment);
	pdfAttachment = new PdfAttachment(input_3.c_str());
	doc->GetCollection()->AddAttachment(pdfAttachment);

	std::vector<PdfAttachment*> attachment = doc->GetCollection()->GetAssociatedFiles();
	for (int j = 0; j < attachment.size(); j++)
	{
		attachment[j]->SetFieldValue(L"No", j+1);
		attachment[j]->SetFieldValue(L"Desc", attachment[j]->GetFileName());
	}

	//Save the document
	doc->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	doc->Close();

	delete doc;

}

