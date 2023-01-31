#include "pch.h"

using namespace Spire::Pdf;
using namespace std;;
using namespace Spire::Common;

int main() {
	wstring outputFile = OUTPUTPATH+L"DrawText.pdf";

	PdfDocument* doc = new PdfDocument();
	PdfPageBase* page = doc->GetPages()->Add();

	Draw_Text(page);
	AlignText(page);
	AlignTextInRectangle(page);
	TransformText(page);
	RotateText(page);

	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete doc;
}

void AlignText(PdfPageBase* page)
{
	//Draw the text - alignment
	PdfFont* font = new PdfFont(PdfFontFamily::Helvetica, 20.f);
	PdfRGBColor* color = new PdfRGBColor(Color::GetBlue());
	PdfSolidBrush* brush = new PdfSolidBrush(color);
	PdfStringFormat* leftAlignment = new PdfStringFormat(PdfTextAlignment::Left, PdfVerticalAlignment::Middle);
	page->GetCanvas()->DrawString(L"Left!", font, brush, 0, 20, leftAlignment);
	page->GetCanvas()->DrawString(L"Left!", font, brush, 0, 50, leftAlignment);

	PdfStringFormat* rightAlignment = new PdfStringFormat(PdfTextAlignment::Right, PdfVerticalAlignment::Middle);
	page->GetCanvas()->DrawString(L"Right!", font, brush, page->GetCanvas()->
		GetClientSize()->GetWidth(), 20, rightAlignment);
	page->GetCanvas()->DrawString(L"Right!", font, brush, page->GetCanvas()->
		GetClientSize()->GetWidth(), 50, rightAlignment);

	PdfStringFormat* centerAlignment = new PdfStringFormat(PdfTextAlignment::Center, PdfVerticalAlignment::Middle);
	page->GetCanvas()->DrawString(L"Go! Turn Around! Go! Go! Go!", font, brush, page->GetCanvas()->
		GetClientSize()->GetWidth() / 2, 40, centerAlignment);
}

void AlignTextInRectangle(PdfPageBase* page)
{
	//Draw the text - align in rectangle
	PdfFont* font = new PdfFont(PdfFontFamily::Helvetica, 10.f);
	PdfRGBColor* color = new PdfRGBColor(Color::GetBlue());
	PdfSolidBrush* brush = new PdfSolidBrush(color);
	RectangleF* rectg1 = new RectangleF(0, 70, page->GetCanvas()->GetClientSize()->GetWidth() / 2, 100);
	RectangleF* rectg2 = new RectangleF(page->GetCanvas()->GetClientSize()->GetWidth() / 2, 70,
		page->GetCanvas()->GetClientSize()->GetWidth() / 2, 100);
	page->GetCanvas()->DrawRectangle(new PdfSolidBrush(new PdfRGBColor(Color::GetLightBlue())), rectg1);
	page->GetCanvas()->DrawRectangle(new PdfSolidBrush(new PdfRGBColor(Color::GetLightSkyBlue())), rectg2);

	PdfStringFormat* leftAlignment1 = new PdfStringFormat(PdfTextAlignment::Left, PdfVerticalAlignment::Top);
	page->GetCanvas()->DrawString(L"Left! Left!", font, brush, rectg1, leftAlignment1);
	page->GetCanvas()->DrawString(L"Left! Left!", font, brush, rectg2, leftAlignment1);

	PdfStringFormat* rightAlignment1 = new PdfStringFormat(PdfTextAlignment::Right, PdfVerticalAlignment::Middle);
	page->GetCanvas()->DrawString(L"Right! Right!", font, brush, rectg1, rightAlignment1);
	page->GetCanvas()->DrawString(L"Right! Right!", font, brush, rectg2, rightAlignment1);

	PdfStringFormat* centerAlignment1 = new PdfStringFormat(PdfTextAlignment::Center, PdfVerticalAlignment::Bottom);
	page->GetCanvas()->DrawString(L"Go! Turn Around! Go! Go! Go!", font, brush, rectg1, centerAlignment1);
	page->GetCanvas()->DrawString(L"Go! Turn Around! Go! Go! Go!", font, brush, rectg2, centerAlignment1);
}

void RotateText(PdfPageBase* page)
{
	//Save graphics state
	PdfGraphicsState* state = page->GetCanvas()->Save();
	PdfFont* font = new PdfFont(PdfFontFamily::Helvetica, 10.f);
	PdfRGBColor* color = new PdfRGBColor(Color::GetBlue());
	PdfSolidBrush* brush = new PdfSolidBrush(color);
	PdfStringFormat* centerAlignment2 = new PdfStringFormat(PdfTextAlignment::Left, PdfVerticalAlignment::Middle);
	float x = page->GetCanvas()->GetClientSize()->GetWidth() / 2;
	float y = 380;
	page->GetCanvas()->TranslateTransform(x, y);
	for (int i = 0; i < 12; i++) {
		page->GetCanvas()->RotateTransform(30);
		page->GetCanvas()->DrawString(L"Go! Turn Around! Go! Go! Go!", font, brush, 20, 0, centerAlignment2);
	}
	page->GetCanvas()->Restore(state);

}

void TransformText(PdfPageBase* page)
{
	//Save graphics state
	PdfGraphicsState* state = page->GetCanvas()->Save();
	PdfFont* font = new PdfFont(PdfFontFamily::Helvetica, 18.f);
	page->GetCanvas()->TranslateTransform(20, 200);
	page->GetCanvas()->ScaleTransform(1.f, 0.6f);
	page->GetCanvas()->SkewTransform(-10, 0);
	page->GetCanvas()->DrawString(L"Go! Turn Around! Go! Go! Go!", font, new PdfSolidBrush(new PdfRGBColor(Color::GetDeepSkyBlue())), 0.f, 0.f);
	page->GetCanvas()->SkewTransform(10, 0);
	page->GetCanvas()->DrawString(L"Go! Turn Around! Go! Go! Go!", font, new PdfSolidBrush(new PdfRGBColor(Color::GetCadetBlue())), 0.f, 0.f);
	page->GetCanvas()->ScaleTransform(1.f, -1.f);
	page->GetCanvas()->DrawString(L"Go! Turn Around! Go! Go! Go!", font, new PdfSolidBrush(new PdfRGBColor(Color::GetCadetBlue())), 0.f, -36.f);
	page->GetCanvas()->Restore(state);
}

void Draw_Text(PdfPageBase* page)
{
	PdfGraphicsState* state = page->GetCanvas()->Save();
	LPCWSTR_S text = L"Go! Turn Around! Go! Go! Go!";
	PdfPen* pen = PdfPens::GetDeepSkyBlue();
	PdfRGBColor* color1 = new PdfRGBColor(Color::GetWhite());
	PdfBrush* brush = new PdfSolidBrush(color1);
	PdfStringFormat* format = new PdfStringFormat();
	PdfFont* font = new PdfFont(PdfFontFamily::Helvetica, 18, PdfFontStyle::Italic);
	SizeF* sizeF = font->MeasureString(text, format);
	RectangleF* rctg = new RectangleF(page->GetCanvas()->GetClientSize()->GetWidth() / 2 + 10, 180,
		sizeF->GetWidth() / 3 * 2, sizeF->GetHeight() * 2);
	page->GetCanvas()->DrawString(text, font, pen, brush, rctg, format);
	page->GetCanvas()->Restore(state);
}
