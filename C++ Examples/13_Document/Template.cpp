#include "pch.h"
#include "stringbuilder.h"
#include "stringhelper.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring outputFile = OUTPUTPATH+L"Template.pdf";

	//Create a pdf document
	PdfDocument* doc = new PdfDocument();

	doc->GetViewerPreferences()->SetPageLayout(PdfPageLayout::TwoColumnLeft);

	//Set the margin
	PdfUnitConvertor* unitCvtr = new PdfUnitConvertor();
	PdfMargins* margin = new PdfMargins();
	margin->SetTop(unitCvtr->ConvertUnits(2.54f, PdfGraphicsUnit::Centimeter, PdfGraphicsUnit::Point));
	margin->SetBottom(margin->GetTop());
	margin->SetLeft(unitCvtr->ConvertUnits(3.17f, PdfGraphicsUnit::Centimeter, PdfGraphicsUnit::Point));
	margin->SetRight(margin->GetLeft());

	SetDocumentTemplate(doc, new SizeF(PdfPageSize::A4()), margin);

	//Create one section
	PdfSection* section = doc->GetSections()->Add();
	section->GetPageSettings()->SetSize(new SizeF(PdfPageSize::A4()));
	section->GetPageSettings()->SetMargins(new PdfMargins(0));
	SetSectionTemplate(section, new SizeF(PdfPageSize::A4()), margin, L"Section 1");

	//Create one page
	PdfNewPage* page = section->GetPages()->Add();

	//Draw page
	DrawPage(page);

	page = section->GetPages()->Add();
	DrawPage(page);

	page = section->GetPages()->Add();
	DrawPage(page);

	page = section->GetPages()->Add();
	DrawPage(page);

	page = section->GetPages()->Add();
	DrawPage(page);

	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete unitCvtr;
}

void SetSectionTemplate(PdfSection* section, SizeF pageSize, PdfMargins* margin, const std::wstring& label)
{
	PdfPageTemplateElement* leftSpace = new PdfPageTemplateElement(margin->GetLeft(), pageSize.GetHeight());
	leftSpace->SetForeground(true);
	section->GetTemplate()->SetOddLeft(leftSpace);

	PdfTrueTypeFont* font = new PdfTrueTypeFont(L"Arial", 9.f, PdfFontStyle::Italic, true);
	PdfStringFormat* format = new PdfStringFormat(PdfTextAlignment::Center, PdfVerticalAlignment::Middle);
	float y = (pageSize.GetHeight() - margin->GetTop() - margin->GetBottom()) * (1 - 0.618f);
	RectangleF* bounds = new RectangleF(10, y, margin->GetLeft() - 20, font->GetHeight() + 6);
	leftSpace->GetGraphics()->DrawRectangle(PdfBrushes::GetOrangeRed(), bounds);
	leftSpace->GetGraphics()->DrawString(label.c_str(), font, PdfBrushes::GetWhite(), bounds, format);

	PdfPageTemplateElement* rightSpace = new PdfPageTemplateElement(margin->GetRight(), pageSize.GetHeight());
	rightSpace->SetForeground(true);
	section->GetTemplate()->SetEvenRight(rightSpace);
	bounds = new RectangleF(10, y, margin->GetRight() - 20, font->GetHeight() + 6);
	rightSpace->GetGraphics()->DrawRectangle(PdfBrushes::GetSaddleBrown(), bounds);
	rightSpace->GetGraphics()->DrawString(label.c_str(), font, PdfBrushes::GetWhite(), bounds, format);

}

void SetDocumentTemplate(PdfDocument* doc, SizeF pageSize, PdfMargins* margin)
{
	PdfPageTemplateElement* leftSpace = new PdfPageTemplateElement(margin->GetLeft(), pageSize.GetHeight());
	doc->GetTemplate()->SetLeft(leftSpace);

	PdfPageTemplateElement* topSpace = new PdfPageTemplateElement(pageSize.GetWidth(), margin->GetTop());
	topSpace->SetForeground(true);
	doc->GetTemplate()->SetTop(topSpace);

	//Draw header label           
	PdfTrueTypeFont* font = new PdfTrueTypeFont(L"Arial", 9.f, PdfFontStyle::Italic, true);
	PdfStringFormat* format = new PdfStringFormat(PdfTextAlignment::Right);
	std::wstring label = L"Demo of Spire.Pdf";
	SizeF size = font->MeasureString(label.c_str(), format);
	float y = topSpace->GetHeight() - font->GetHeight() - 1;
	PdfPen* pen = new PdfPen(new PdfRGBColor(Color::GetBlack()), 0.75f);
	topSpace->GetGraphics()->SetTransparency(0.5f);
	topSpace->GetGraphics()->DrawLine(pen, margin->GetLeft(), y, pageSize.GetWidth() - margin->GetRight(), y);
	y = y - 1 - size.GetHeight();
	topSpace->GetGraphics()->DrawString(label.c_str(), font, PdfBrushes::GetBlack(), pageSize.GetWidth() - margin->GetRight(), y, format);

	PdfPageTemplateElement* rightSpace = new PdfPageTemplateElement(margin->GetRight(), pageSize.GetHeight());
	doc->GetTemplate()->SetRight(rightSpace);

	PdfPageTemplateElement* bottomSpace = new PdfPageTemplateElement(pageSize.GetWidth(), margin->GetBottom());
	bottomSpace->SetForeground(true);
	doc->GetTemplate()->SetBottom(bottomSpace);

	//Draw footer label
	y = font->GetHeight() + 1;
	bottomSpace->GetGraphics()->SetTransparency(0.5f);
	bottomSpace->GetGraphics()->DrawLine(pen, margin->GetLeft(), y, pageSize.GetWidth() - margin->GetRight(), y);
	y = y + 1;
	PdfPageNumberField* pageNumber = new PdfPageNumberField();
	PdfPageCountField* pageCount = new PdfPageCountField();
	PdfCompositeField* pageNumberLabel = new PdfCompositeField();
	pageNumberLabel->SetAutomaticFields({ pageNumber, pageCount });
	pageNumberLabel->SetBrush(PdfBrushes::GetBlack());
	pageNumberLabel->SetFont(font);
	pageNumberLabel->SetStringFormat(format);
	pageNumberLabel->SetText(L"page {0} of {1}");
	pageNumberLabel->Draw(bottomSpace->GetGraphics(), pageSize.GetWidth() - margin->GetRight(), y);
	wstring ImgFile1 = DATAPATH+L"Header.png";
	PdfImage* headerImage = PdfImage::FromFile(ImgFile1.c_str());
	PointF* pageLeftTop = new PointF(-margin->GetLeft(), -margin->GetTop());
	PdfPageTemplateElement* header = new PdfPageTemplateElement(pageLeftTop, headerImage->GetPhysicalDimension());
	header->SetForeground(false);
	header->GetGraphics()->SetTransparency(0.5f);
	header->GetGraphics()->DrawImage(headerImage, 0.f, 0.f);
	doc->GetTemplate()->GetStamps()->Add(header);

	wstring ImgFile2 = DATAPATH+L"Footer.png";
	PdfImage* footerImage = PdfImage::FromFile(ImgFile2.c_str());
	y = pageSize.GetHeight() - footerImage->GetPhysicalDimension()->GetHeight();
	PointF* footerLocation = new PointF(-margin->GetLeft(), y);
	PdfPageTemplateElement* footer = new PdfPageTemplateElement(footerLocation, footerImage->GetPhysicalDimension());
	footer->SetForeground(false);
	footer->GetGraphics()->SetTransparency(0.5f);;
	footer->GetGraphics()->DrawImage(footerImage, 0.f, 0.f);
	doc->GetTemplate()->GetStamps()->Add(footer);
	delete pageNumberLabel;
	delete pageCount;
	delete pageNumber;
}

void DrawPage(PdfPageBase* page)
{
	float pageWidth = page->GetCanvas()->GetClientSize()->GetWidth();
	float y = 0;

	//Title
	y = y + 5;
	PdfBrush* brush2 = new PdfSolidBrush(new PdfRGBColor(Color::GetBlack()));

	PdfTrueTypeFont* font2 = new PdfTrueTypeFont(L"Arial", 16.f, PdfFontStyle::Bold, true);
	PdfStringFormat* format2 = new PdfStringFormat(PdfTextAlignment::Center);
	format2->SetCharacterSpacing(1.0f);
	std::wstring text = L"Summary of Science";
	page->GetCanvas()->DrawString(text.c_str(), font2, brush2, pageWidth / 2, y, format2);
	SizeF size = font2->MeasureString(text.c_str(), format2);
	y = y + size.GetHeight() + 6;

	//Icon
	wstring ImgFile = DATAPATH+L"Wikipedia_Science.png";
	PdfImage* image = PdfImage::FromFile(ImgFile.c_str());
	page->GetCanvas()->DrawImage(image, new PointF(pageWidth - image->GetPhysicalDimension()->GetWidth(), y));
	float imageLeftSpace = pageWidth - image->GetPhysicalDimension()->GetWidth() - 2;
	float imageBottom = image->GetPhysicalDimension()->GetHeight() + y;

	//Reference content
	PdfTrueTypeFont* font3 = new PdfTrueTypeFont(L"Arial", 9.f, PdfFontStyle::Regular, true);
	PdfStringFormat* format3 = new PdfStringFormat();
	format3->SetParagraphIndent(font3->GetSize() * 2);
	format3->SetMeasureTrailingSpaces(true);
	format3->SetLineSpacing(font3->GetSize() * 1.5f);
	std::wstring text1 = L"(All text and picture from ";
	std::wstring text2 = L"Wikipedia";
	std::wstring text3 = L", the free encyclopedia)";
	page->GetCanvas()->DrawString(text1.c_str(), font3, brush2, 0, y, format3);

	size = font3->MeasureString(text1.c_str(), format3);
	float x1 = size.GetWidth();
	format3->SetParagraphIndent(0);
	PdfTrueTypeFont* font4 = new PdfTrueTypeFont(L"Arial", 9.f, PdfFontStyle::Underline, true);
	PdfBrush* brush3 = PdfBrushes::GetBlue();
	page->GetCanvas()->DrawString(text2.c_str(), font4, brush3, x1, y, format3);
	size = font4->MeasureString(text2.c_str(), format3);
	x1 = x1 + size.GetWidth();

	page->GetCanvas()->DrawString(text3.c_str(), font3, brush2, x1, y, format3);
	y = y + size.GetHeight();

	//Content
	PdfStringFormat* format4 = new PdfStringFormat();

	wstring inputFile = DATAPATH+L"Summary_of_Science.txt";

	ifstream in_file;
	in_file.open(inputFile.c_str(), ios::in);
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
	text = sb->toString();
	PdfTrueTypeFont* font5 = new PdfTrueTypeFont(L"Arial", 10.f, PdfFontStyle::Regular, true);
	format4->SetLineSpacing(font5->GetSize() * 1.5f);
	PdfStringLayouter* textLayouter = new PdfStringLayouter();
	float imageLeftBlockHeight = imageBottom - y;
	PdfStringLayoutResult* result = textLayouter->Layout(text.c_str(), font5, format4, new SizeF(imageLeftSpace, imageLeftBlockHeight));
	if (result->GetActualSize()->GetHeight() < imageBottom - y)
	{
		imageLeftBlockHeight = imageLeftBlockHeight + result->GetLineHeight();
		result = textLayouter->Layout(text.c_str(), font5, format4, new SizeF(imageLeftSpace, imageLeftBlockHeight));
	}

	std::vector<LineInfo*> line = result->GetLines();
	for (int i = 0; i < line.size(); i++)
	{
		page->GetCanvas()->DrawString(line[i]->GetText(), font5, brush2, 0, y, format4);
		y = y + result->GetLineHeight();
	}

	PdfTextWidget* textWidget = new PdfTextWidget(result->GetRemainder(), font5, brush2);
	PdfTextLayout* textLayout = new PdfTextLayout();
	textLayout->SetBreak(PdfLayoutBreakType::FitPage);
	textLayout->SetLayout(PdfLayoutType::Paginate);
	RectangleF* bounds = new RectangleF(new PointF(0, y), page->GetCanvas()->GetClientSize());
	textWidget->SetStringFormat(format4);
	textWidget->Draw(Object::Convert<PdfNewPage>(page), bounds, textLayout);

	delete textWidget;
	delete textLayouter;
}