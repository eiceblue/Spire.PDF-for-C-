#include "pch.h"
using namespace Spire::Pdf;
using namespace std;

int main(){
	//Pdf file	
	wstring outputFile = OUTPUTPATH+L"PDFAToPDF.pdf";
	wstring inputFile = DATAPATH+L"SamplePDFA.pdf";
	//Open pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//Create a new pdf and draw content on new file
	PdfNewDocument* newDoc = new PdfNewDocument();
	newDoc->SetCompressionLevel(PdfCompressionLevel::None);
	for (int i = 0; i < doc->GetPages()->GetCount(); i++) {
			PdfPageBase* page = doc->GetPages()->GetItem(i);
			SizeF* size = page->GetSize();
			PdfPageBase* p = newDoc->GetPages()->Add(size, new PdfMargins(0));
			page->CreateTemplate()->Draw(p, 0.f, 0.f);
	}
	doc->SaveToFile(outputFile.c_str());
	doc->Close();
	delete newDoc;
	delete doc;
}
