#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring outputFile = OUTPUTPATH+L"Overlay.pdf";

	//Load two documents from disk
	PdfDocument* doc1 = new PdfDocument();
	PdfDocument* doc2 = new PdfDocument();
	doc1->LoadFromFile(DATAPATH+L"Overlay1.pdf");
	doc2->LoadFromFile(DATAPATH+L"Overlay2.pdf");
	//Create page template
	PdfTemplate* templates = doc1->GetPages()->GetItem(0)->CreateTemplate();
	for (int i = 0; i < doc2->GetPages()->GetCount(); i++) {
		PdfPageBase* page = doc2->GetPages()->GetItem(i);
		page->GetCanvas()->SetTransparency(0.25f, 0.25f, PdfBlendMode::Overlay);
		page->GetCanvas()->DrawTemplate(templates, PointF::Empty());
	}
	//Save the document
	doc2->SaveToFile(outputFile.c_str());
	doc1->Close();
	doc2->Close();

	delete doc2;
	delete doc1;
}

