#include "pch.h"
using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main()
{
	wstring outputFile = OUTPUTPATH+L"Booklet.pdf";
	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	wstring srcPdf = DATAPATH+L"Booklet.pdf";
	SizeF* w = new SizeF(PdfPageSize::A4());
	SizeF* h = new SizeF(PdfPageSize::A4());
	float width = w->GetWidth() * 2;
	float height = h->GetHeight();
	doc->CreateBooklet(srcPdf.c_str(), width, height, true);
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete doc;
}
