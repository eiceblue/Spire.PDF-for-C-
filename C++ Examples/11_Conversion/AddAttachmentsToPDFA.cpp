#include "pch.h"
using namespace Spire::Pdf;
using namespace std;

int main(){
	//Input and output files path
	wstring inputFile = DATAPATH+L"SampleB_2.pdf";
	wstring outputFile = OUTPUTPATH+L"AddAttachmentsToPDF_A1B.pdf";
	wstring output_ = OUTPUTPATH+L"AddAttachmentsToPDF_Temp.pdf";
	//Open pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	PdfNewDocument* newDoc = new PdfNewDocument();
    //Set Pdf_A1B
	newDoc->SetConformance(PdfConformanceLevel::Pdf_A1B);
	for (int i = 0; i < doc->GetPages()->GetCount(); i++) {
		PdfPageBase* page = doc->GetPages()->GetItem(i);
		SizeF* size = page->GetSize();
		PdfPageBase* p = newDoc->GetPages()->Add(size, new PdfMargins(0));
		page->CreateTemplate()->Draw(p, 0.f, 0.f);
	}

	//Load files and add in attachments
	wstring data1 = DATAPATH+L"SampleB_1.png";
	wstring data2 = DATAPATH+L"SampleB_1.pdf";
	Stream* s1 = new Stream(data1.c_str());
	PdfAttachment* attach1 = new PdfAttachment(L"attachment1.png", s1);
	Stream* s2 = new Stream(data2.c_str());
	PdfAttachment* attach2 = new PdfAttachment(L"attachment2.pdf", s2);
	newDoc->GetAttachments()->Add(attach1);
	newDoc->GetAttachments()->Add(attach2);
    //Save to file
	Stream* file = new Stream(output_.c_str());
	newDoc->Save(file);
	newDoc->Close(true);
	PdfStandardsConverter* converter = new PdfStandardsConverter(file);
	converter->ToPdfA1B(outputFile.c_str());
	delete converter;
	delete newDoc;
	delete doc;
}

    

	

