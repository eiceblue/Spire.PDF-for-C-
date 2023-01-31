#include "pch.h"
#include "stringbuilder.h"
#include "stringhelper.h"
#include <float.h>
#include <limits>
using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

inline LineType operator &(LineType a, LineType b) {
				return static_cast<LineType>(static_cast<int>(a) & static_cast<int>(b));
                 }
				 
int main(){
	wstring outputFile = OUTPUTPATH+L"Pagination.pdf";

	//Create a pdf document
	PdfDocument* doc = new PdfDocument();

	//Set the margin
	PdfUnitConvertor* unitCvtr = new PdfUnitConvertor();
	PdfMargins* margin = new PdfMargins();

	margin->SetTop(unitCvtr->ConvertUnits(2.54f, PdfGraphicsUnit::Centimeter, PdfGraphicsUnit::Point));
	margin->SetBottom(margin->GetTop());
	margin->SetLeft(unitCvtr->ConvertUnits(3.17f, PdfGraphicsUnit::Centimeter, PdfGraphicsUnit::Point));
	margin->SetRight(margin->GetLeft());

	DrawCover(doc->GetSections()->Add(), margin);
	DrawContent(doc->GetSections()->Add(), margin);
	DrawPageNumber(doc->GetSections()->GetItem(1), margin, 1, doc->GetSections()->GetItem(1)->GetPages()->GetCount());
	doc->SetPageLabels(new PdfPageLabels());
	doc->GetPageLabels()->AddRange(0, PdfPageLabels::Lowercase_Roman_Numerals_Style(), L"cover");
	doc->GetPageLabels()->AddRange(1, PdfPageLabels::Decimal_Arabic_Numerals_Style(), L"page");


	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete unitCvtr;
	delete doc;
}

void DrawCover(PdfSection* section, PdfMargins* margin)
{
	PdfPageBase* page = section->GetPages()->Add();
	section->GetPageSettings()->SetSize(new SizeF(PdfPageSize::A4()));
	section->GetPageSettings()->GetMargins()->SetAll(0);
	DrawPageHeaderAndFooter(page, margin, true);

	//Reference content
	PdfBrush* brush1 = PdfBrushes::GetLightGray();
	PdfBrush* brush2 = PdfBrushes::GetBlue();
	PdfTrueTypeFont* font1 = new PdfTrueTypeFont(L"Arial", 8.0f, PdfFontStyle::Regular, true);
	PdfStringFormat* format = new PdfStringFormat();
	format->SetMeasureTrailingSpaces(true);
	std::wstring text1 = L"(All text and picture from ";
	std::wstring text2 = L"Wikipedia";
	std::wstring text3 = L", the free encyclopedia)";
	float x = 0, y = 10;
	x = x + margin->GetLeft();
	y = y + margin->GetTop();
	page->GetCanvas()->DrawString(text1.c_str(), font1, brush1, x, y, format);
	x = x + font1->MeasureString(text1.c_str(), format)->GetWidth();
	page->GetCanvas()->DrawString(text2.c_str(), font1, brush2, x, y, format);
	x = x + font1->MeasureString(text2.c_str(), format)->GetWidth();
	page->GetCanvas()->DrawString(text3.c_str(), font1, brush1, x, y, format);

	//Cover
	PdfBrush* brush3 = PdfBrushes::GetBlack();
	//PdfRGBColor tempVar2(0xf9, 0xf9, 0xf9);
	PdfBrush* brush4 = PdfBrushes::GetWhite();

	wstring input = DataPath"Demo/SciencePersonificationBoston.jpg";
	PdfImage* image = PdfImage::FromFile(input.c_str());

	std::wstring text = L"Personification of \"Science\" in front of the Boston Public Library";
	float r = image->GetPhysicalDimension()->GetHeight() / image->GetHeight();
	PdfPen* pen = new PdfPen(brush1, r);
	SizeF* size = font1->MeasureString(text.c_str(), image->GetPhysicalDimension()->GetWidth() - 2);
	PdfTemplate* template_Keyword = new PdfTemplate(image->GetPhysicalDimension()->GetWidth() + 4 * r + 4, image->GetPhysicalDimension()->GetHeight() + 4 * r + 7 + size->GetHeight());
	template_Keyword->GetGraphics()->DrawRectangle(pen, brush4, 0, 0, template_Keyword->GetWidth(), template_Keyword->GetHeight());
	x = y = r + 2;
	template_Keyword->GetGraphics()->DrawRectangle(brush1, x, y, image->GetPhysicalDimension()->GetWidth() + 2 * r, image->GetPhysicalDimension()->GetHeight() + 2 * r);
	x = y = x + r;
	template_Keyword->GetGraphics()->DrawImage(image, x, y);

	x = x - 1;
	y = y + image->GetPhysicalDimension()->GetHeight() + r + 2;
	template_Keyword->GetGraphics()->DrawString(text.c_str(), font1, brush3, new RectangleF(new PointF(x, y), size));

	float x1 = (page->GetCanvas()->GetClientSize()->GetWidth() - template_Keyword->GetWidth()) / 2;
	float y1 = (page->GetCanvas()->GetClientSize()->GetHeight() - margin->GetTop() - margin->GetBottom()) * (1 - 0.618f) - template_Keyword->GetHeight() / 2 + margin->GetTop();
	PdfGraphicsWidget* grWidget = Object::Convert<PdfGraphicsWidget>(template_Keyword);
	grWidget->Draw(page->GetCanvas(), x1, y1);

	//Title
	format->SetAlignment(PdfTextAlignment::Center);

	PdfTrueTypeFont* font2 = new PdfTrueTypeFont(L"Arial", 24.0f, PdfFontStyle::Bold, true);
	x = page->GetCanvas()->GetClientSize()->GetWidth() / 2;
	y = y1 + template_Keyword->GetHeight() + 10;
	page->GetCanvas()->DrawString(L"Science History and Etymology", font2, brush3, x, y, format);

	delete template_Keyword;
}

void DrawContent(PdfSection* section, PdfMargins* margin)
{
	PdfPageBase* page = section->GetPages()->Add();
	section->GetPageSettings()->SetSize(new SizeF(PdfPageSize::A4()));
	section->GetPageSettings()->GetMargins()->SetAll(0);
	DrawPageHeaderAndFooter(page, margin, false);

	float x = margin->GetLeft();
	float y = margin->GetTop() + 8;
	float width = page->GetCanvas()->GetClientSize()->GetWidth() - margin->GetLeft() - margin->GetRight();

	PdfTrueTypeFont* font1 = new PdfTrueTypeFont(L"Arial", 16.0f, PdfFontStyle::Regular, true);
	PdfBrush* brush1 = PdfBrushes::GetBlack();
	PdfPen* pen1 = new PdfPen(brush1, 0.75f);
	page->GetCanvas()->DrawString(L"Science History and Etymology", font1, brush1, x, y);
	y = y + font1->MeasureString(L"Science History and Etymology")->GetHeight() + 6;
	page->GetCanvas()->DrawLine(pen1, x, y, page->GetCanvas()->GetClientSize()->GetWidth() - margin->GetRight(), y);
	y = y + 1.75f;

	wstring input = DATAPATH+L"Science_History_and_Etymology_ANSI.txt";
	PdfDocument* doc = new PdfDocument();

	ifstream in_file;
	in_file.open(input.c_str(), ios::in);
	if (!in_file.is_open())
	{
		cout << "读取txt文件失败" << endl;
		return;
	}
	StringBuilder* sb = new StringBuilder();
	string buf;
	while (getline(in_file, buf))
	{
		sb->appendLine(StringHelper::string_to_wstring(buf));
	}
	wstring content = sb->toString();
	std::vector<std::wstring> lines = StringHelper::split(content,{ L'\n'});

	PdfTrueTypeFont* font2 = new PdfTrueTypeFont(L"Arial", 10.0f, PdfFontStyle::Italic, true);
	PdfStringFormat* format1 = new PdfStringFormat();
	format1->SetMeasureTrailingSpaces(true);
	format1->SetLineSpacing(font2->GetHeight() * 1.5f);
	format1->SetParagraphIndent(font2->MeasureString(L"\t", format1)->GetWidth());
	y = y + font2->GetHeight() * 0.5f;
	SizeF* size = font2->MeasureString(lines[0].c_str(), width, format1);
	page->GetCanvas()->DrawString(lines[0].c_str(), font2, brush1, new RectangleF(new PointF(x, y), size), format1);
	y = y + size->GetHeight();
	PdfTrueTypeFont* font3 = new PdfTrueTypeFont(L"Arial", 10.0f, PdfFontStyle::Regular, true);
	PdfStringFormat* format2 = new PdfStringFormat();
	format2->SetLineSpacing(font3->GetHeight() * 1.4f);
	format2->SetMeasureTrailingSpaces(true);
	size = font3->MeasureString(lines[1].c_str(), width, format2);
	page->GetCanvas()->DrawString(lines[1].c_str(), font3, brush1, new RectangleF(new PointF(x, y), size), format2);
	y = y + size->GetHeight();

	y = y + font3->GetHeight() * 0.75f;
	float indent = font3->MeasureString(L"\t\t", format2)->GetWidth();
	float x1 = x + indent;
	size = font3->MeasureString(lines[2].c_str(), width - indent, format2);
	page->GetCanvas()->DrawString(lines[2].c_str(), font3, brush1, new RectangleF(new PointF(x1, y), size), format2);
	y = y + size->GetHeight() + font3->GetHeight() * 0.75f;

	StringBuilder* buff = new StringBuilder();
	for (int i = 3; i < lines.size(); i++)
	{
		buff->append(lines[i]+L"\n");
	}
	content = buff->toString();

	PdfStringLayouter* textLayouter = new PdfStringLayouter();
	float flmax = 999999.f;
	PdfStringLayoutResult* result = textLayouter->Layout(content.c_str(), font3, format2,new SizeF(width, flmax));
	
	for each (LineInfo * line in result->GetLines())
	{
		if ((line->GetLineType() & LineType::FirstParagraphLine) == LineType::FirstParagraphLine)
		{
			y = y + font3->GetHeight() * 0.75f;
		}
		if (y > (page->GetCanvas()->GetClientSize()->GetHeight() - margin->GetBottom() - result->GetLineHeight()))
		{
			page = section->GetPages()->Add();
			DrawPageHeaderAndFooter(page, margin, false);
			y = margin->GetTop();
		}
		page->GetCanvas()->DrawString(line->GetText(), font3, brush1, x, y, format2);
		y = y + result->GetLineHeight();
	}
	delete textLayouter;
	delete buff;
}

void DrawPageHeaderAndFooter(PdfPageBase* page, PdfMargins* margin, bool isCover)
{
	page->GetCanvas()->SetTransparency(0.5f);
	wstring input1 = DATAPATH+L"Header.png";
	PdfImage* headerImage = PdfImage::FromFile(input1.c_str());
	wstring input2 = DATAPATH+L"Footer.png";
	PdfImage* footerImage = PdfImage::FromFile(input2.c_str());
	page->GetCanvas()->DrawImage(headerImage, new PointF(0, 0));
	page->GetCanvas()->DrawImage(footerImage, new PointF(0, page->GetCanvas()->GetClientSize()->GetHeight() - footerImage->GetPhysicalDimension()->GetHeight()));
	if (isCover)
	{
		page->GetCanvas()->SetTransparency(1);
		return;
	}

	PdfBrush* brush = PdfBrushes::GetBlack();
	PdfPen* pen = new PdfPen(brush, 0.75f);
	PdfTrueTypeFont* font = new PdfTrueTypeFont(L"Arial", 9.0f, PdfFontStyle::Italic, true);
	PdfStringFormat* format = new PdfStringFormat(PdfTextAlignment::Right);
	format->SetMeasureTrailingSpaces(true);
	float space = font->GetHeight() * 0.75f;
	float x = margin->GetLeft();
	float width = page->GetCanvas()->GetClientSize()->GetWidth() - margin->GetLeft() - margin->GetRight();
	float y = margin->GetTop() - space;
	page->GetCanvas()->DrawLine(pen, x, y, x + width, y);
	y = y - 1 - font->GetHeight();
	page->GetCanvas()->DrawString(L"Demo of Spire.Pdf", font, brush, x + width, y, format);
	page->GetCanvas()->SetTransparency(1);

}

void DrawPageNumber(PdfSection* section, PdfMargins* margin, int startNumber, int pageCount)
{
	for (int i =0;i<section->GetPages()->GetCount();i++)
	{
		PdfPageBase* page = section->GetPages()->GetItem(i);
		page->GetCanvas()->SetTransparency(0.5f);
		PdfBrush* brush = PdfBrushes::GetBlack();
		PdfPen* pen = new PdfPen(brush, 0.75f);
		PdfTrueTypeFont* font = new PdfTrueTypeFont(L"Arial", 9.0f, PdfFontStyle::Italic, true);
		PdfStringFormat* format = new PdfStringFormat(PdfTextAlignment::Right);
		format->SetMeasureTrailingSpaces(true);
		float space = font->GetHeight() * 0.75f;
		float x = margin->GetLeft();
		float width = page->GetCanvas()->GetClientSize()->GetWidth() - margin->GetLeft() - margin->GetRight();
		float y = page->GetCanvas()->GetClientSize()->GetHeight() - margin->GetBottom() + space;
		page->GetCanvas()->DrawLine(pen, x, y, x + width, y);
		y = y + 1;
		std::wstring numberLabel = StringHelper::formatSimple(L"{0} of {1}", startNumber++, pageCount);
		page->GetCanvas()->DrawString(numberLabel.c_str(), font, brush, x + width, y, format);
		page->GetCanvas()->SetTransparency(1);
	}
}
		


