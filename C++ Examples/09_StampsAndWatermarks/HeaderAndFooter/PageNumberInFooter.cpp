#include "pch.h"
#include "stringhelper.h"

using namespace std;
using namespace Spire::Pdf;
using namespace Spire::Common;

int main()
{
	wstring outputFile = OUTPUTPATH + L"PageNumberInFooter.pdf";
	wstring inputFile = DATAPATH + L"MultipagePDF.pdf";
	//Load the Pdf from disk
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//Set the margin
	PdfMargins* margin = doc->GetPageSettings()->GetMargins();

	//Draw Page number
	DrawPageNumber(doc, margin, 1, doc->GetPages()->GetCount());
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();
	delete doc;
}

void DrawPageNumber(PdfDocument* doc, PdfMargins* margin, int startNumber, int pageCount)
{

	for (int i = 0; i < doc->GetPages()->GetCount(); i++)
	{
		PdfPageBase* page = doc->GetPages()->GetItem(i);
		page->GetCanvas()->SetTransparency(0.5f);
		PdfBrush* brush = PdfBrushes::GetBlack();
		PdfPen* pen = new PdfPen(brush, 0.75f);
		LPCWSTR_S arial = L"Arial";
		PdfTrueTypeFont* font = new PdfTrueTypeFont(new Font(arial, 12.f, FontStyle::Italic), true);

		PdfStringFormat* format = new PdfStringFormat(PdfTextAlignment::Right);
		format->SetMeasureTrailingSpaces(true);
		float space = font->GetHeight() * 0.75f;
		float x = margin->GetLeft();
		float width = page->GetCanvas()->GetClientSize()->GetWidth() - margin->GetLeft() - margin->GetRight();
		float y = page->GetCanvas()->GetClientSize()->GetHeight() - margin->GetBottom() + space;
		page->GetCanvas()->DrawLine(pen, x, y, x + width, y);
		y = y + 1;
		wstring numberLabel = StringHelper::formatSimple(L"{0} of {1}", startNumber++, pageCount);
		page->GetCanvas()->DrawString(numberLabel.c_str(), font, brush, x + width, y, format);
		page->GetCanvas()->SetTransparency(1);

	}
}