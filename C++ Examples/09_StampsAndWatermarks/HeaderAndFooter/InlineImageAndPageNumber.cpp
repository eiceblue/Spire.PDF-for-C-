#include "pch.h"

using namespace std;
using namespace Spire::Pdf;
using namespace Spire::Common;

int main()
{
	wstring outputFile = OUTPUTPATH + L"InlineImageAndPageNumber.pdf";
	wstring inputFile = DATAPATH + L"PDFTemplate_HF.pdf";
	PdfDocument* doc = new PdfDocument();
	//Load Pdf from disk
	doc->LoadFromFile(inputFile.c_str());

	//Get the first page
	PdfPageBase* page = doc->GetPages()->GetItem(0);

	wstring text1 = L"Spire.Pdf is a robust component by";
	wstring text2 = L"Technology Co., Ltd.";
	wstring inputFile1 = DataPath"Demo/Top-logo.png";
	PdfImage* image = PdfImage::FromFile(inputFile1.c_str());

	//Define font and bursh     
	LPCWSTR_S impact = L"Impact";
	PdfTrueTypeFont* font = new PdfTrueTypeFont(new Font(impact, 10.f));
	PdfBrush* bursh = PdfBrushes::GetDarkGray();


	//Get the size of text
	SizeF* s1 = font->MeasureString(text1.c_str());
	SizeF* s2 = font->MeasureString(text2.c_str());

	float x = 10;
	float y = 10;

	//Define image size
	SizeF* imgSize = new SizeF(image->GetWidth() / 2, image->GetHeight() / 2);

	//Define rectangle and string format
	SizeF* size = new  SizeF(s1->GetWidth(), imgSize->GetWidth());
	RectangleF* rect1 = new RectangleF(new PointF(x, y), size);
	PdfStringFormat* format = new PdfStringFormat(PdfTextAlignment::Left, PdfVerticalAlignment::Middle);

	//Draw the text1
	page->GetCanvas()->DrawString(text1.c_str(), font, bursh, rect1, format);

	//Draw the image
	x += s1->GetWidth();
	page->GetCanvas()->DrawImage(image, new PointF(x, y), imgSize);


	//Draw the text2
	x += imgSize->GetWidth();
	size = new SizeF(s2->GetWidth(), imgSize->GetHeight());
	rect1 = new RectangleF(new PointF(x, y), size);
	page->GetCanvas()->DrawString(text2.c_str(), font, bursh, rect1, format);

	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();
	delete doc;
}

