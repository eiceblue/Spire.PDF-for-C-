#include "pch.h"

using namespace std;
using namespace Spire::Pdf;
using namespace Spire::Common;

int main()
{
	wstring outputFile = OUTPUTPATH + L"TextWaterMark.pdf";
	wstring inputFile = DATAPATH + L"TextWaterMark.pdf";
	//Create a pdf document and load file from disk
	PdfDocument* doc = new PdfDocument();

	doc->LoadFromFile(inputFile.c_str());

	//Get the first page
	PdfPageBase* page = doc->GetPages()->GetItem(0);

	//Draw text watermark
	PdfTilingBrush* brush = new PdfTilingBrush(new SizeF(page->GetCanvas()->GetClientSize()->GetWidth() / 2, page->GetCanvas()->GetClientSize()->GetHeight() / 3));
	brush->GetGraphics()->SetTransparency(0.3f);
	brush->GetGraphics()->Save();
	brush->GetGraphics()->TranslateTransform(brush->GetSize()->GetWidth() / 2, brush->GetSize()->GetHeight() / 2);
	brush->GetGraphics()->RotateTransform(-45);

	brush->GetGraphics()->DrawString(L"Spire.Pdf Demo", new PdfFont(PdfFontFamily::Helvetica, 24), PdfBrushes::GetViolet(), 0, 0,
		new PdfStringFormat(PdfTextAlignment::Center));
	brush->GetGraphics()->Restore();
	brush->GetGraphics()->SetTransparency(1);
	page->GetCanvas()->DrawRectangle(brush, new RectangleF(new PointF(0, 0), page->GetCanvas()->GetClientSize()));

	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();
	delete doc;
}
