#include "pch.h"

using namespace std;
using namespace Spire::Pdf;
using namespace Spire::Common;

int main()
{
	wstring outputFile = OUTPUTPATH + L"ImageWatermarkSecond.pdf";
	wstring inputFile = DATAPATH + L"PDFTemplate_N.pdf";

	//Load Pdf document from disk
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//Load an image
	wstring inputFile_i = DATAPATH + L"E-logo.png";

	//Insert an image into the first PDF page at specific position
	PdfImage* pdfImage = PdfImage::FromFile(inputFile_i.c_str());

	PdfPageBase* page = doc->GetPages()->GetItem(0);
	PointF* position = new PointF(160, 260);
	page->GetCanvas()->Save();
	page->GetCanvas()->SetTransparency(0.5f, 0.5f, PdfBlendMode::Multiply);
	page->GetCanvas()->DrawImage(pdfImage, position);
	page->GetCanvas()->Restore();

	///Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();
	delete doc;
}
