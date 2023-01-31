#include "pch.h"
#include "stringbuilder.h"
#include <iostream>
#include "stringhelper.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main(){

	wstring outputFile =OUTPUTPATH+L"PageSetup.pdf";

	PdfDocument* doc = new PdfDocument();

	//Set the margin
	PdfUnitConvertor* unitCvtr = new PdfUnitConvertor();
	PdfMargins* margin = new PdfMargins();
	margin->SetTop(unitCvtr->ConvertUnits(2.54f, PdfGraphicsUnit::Centimeter, PdfGraphicsUnit::Point));
	margin->SetBottom(margin->GetTop());
	margin->SetLeft(unitCvtr->ConvertUnits(3.17f, PdfGraphicsUnit::Centimeter, PdfGraphicsUnit::Point));
	margin->SetRight(margin->GetLeft());

	//Create one page
	PdfPageBase* page = doc->GetPages()->Add(new SizeF(PdfPageSize::A4()), margin);
	page->SetBackgroundColor(Color::GetChocolate());
	//Draw page
	DrawPage(page);

	page = doc->GetPages()->Add(new SizeF(PdfPageSize::A4()), margin);
	page->SetBackgroundColor(Color::GetCoral());

	//Draw page
	DrawPage(page);

	page = doc->GetPages()->Add(new SizeF(PdfPageSize::A3()), margin, PdfPageRotateAngle::RotateAngle180, PdfPageOrientation::Landscape);
	page->SetBackgroundColor(Color::GetLightPink());

	//Draw page
	DrawPage(page);

	//create section
	PdfSection* section = doc->GetSections()->Add();
	page = section->GetPages()->Add();
	section->GetPageSettings()->SetSize(new SizeF(PdfPageSize::A4()));
	section->GetPageSettings()->SetMargins(margin);

	//Draw page
	DrawPage(page);

	//Set background color
	page = section->GetPages()->Add();
	page->SetBackgroundColor(Color::GetLightSkyBlue());
	DrawPage(page);

	//Landscape
	section = doc->GetSections()->Add();
	section->GetPageSettings()->SetOrientation(PdfPageOrientation::Landscape);
	page = section->GetPages()->Add();
	section->GetPageSettings()->SetSize(new SizeF(PdfPageSize::A4()));
	section->GetPageSettings()->SetMargins(margin);
	DrawPage(page);

	//Rotate 90
	section = doc->GetSections()->Add();
	page = section->GetPages()->Add();
	section->GetPageSettings()->SetSize(new SizeF(PdfPageSize::A4()));
	section->GetPageSettings()->SetMargins(margin);
	section->GetPageSettings()->SetRotate(PdfPageRotateAngle::RotateAngle90);
	DrawPage(page);

	//Rotate 180
	section = doc->GetSections()->Add();
	page = section->GetPages()->Add();
	section->GetPageSettings()->SetSize(new SizeF(PdfPageSize::A4()));
	section->GetPageSettings()->SetMargins(margin);
	section->GetPageSettings()->SetRotate(PdfPageRotateAngle::RotateAngle180);
	DrawPage(page);
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete unitCvtr;
	delete doc;
}

void DrawPage(PdfPageBase* page)
{
	float pageWidth = page->GetCanvas()->GetClientSize()->GetWidth();
	float y = 0;

	//Title
	y = y + 5;
	PdfBrush* brush2 = new PdfSolidBrush(new PdfRGBColor(Color::GetBlack()));

	PdfTrueTypeFont* font2 = new PdfTrueTypeFont(L"Arial", 16.0f, PdfFontStyle::Bold, true);
	PdfStringFormat* format2 = new PdfStringFormat(PdfTextAlignment::Center);
	format2->SetCharacterSpacing(1.0f);
	std::wstring text = L"Summary of Science";
	page->GetCanvas()->DrawString(text.c_str(), font2, brush2, pageWidth / 2, y, format2);
	SizeF size = font2->MeasureString(text.c_str(), format2);
	y = y + size.GetHeight() + 6;

	//Icon
	wstring inputFile = DATAPATH+L"Wikipedia_Science.png";
	PdfImage* image = PdfImage::FromFile(inputFile.c_str());
	page->GetCanvas()->DrawImage(image, new PointF(pageWidth - image->GetPhysicalDimension()->GetWidth(), y));
	float imageLeftSpace = pageWidth - image->GetPhysicalDimension()->GetWidth() - 2;
	float imageBottom = image->GetPhysicalDimension()->GetHeight() + y;

	//Reference content
	PdfTrueTypeFont* font3 = new PdfTrueTypeFont(L"Arial", 9.0f, PdfFontStyle::Regular, true);
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

	PdfTrueTypeFont* font4 = new PdfTrueTypeFont(L"Arial", 9.0f, PdfFontStyle::Underline, true);
	PdfBrush* brush3 = PdfBrushes::GetBlue();
	page->GetCanvas()->DrawString(text2.c_str(), font4, brush3, x1, y, format3);
	size = font4->MeasureString(text2.c_str(), format3);
	x1 = x1 + size.GetWidth();

	page->GetCanvas()->DrawString(text3.c_str(), font3, brush2, x1, y, format3);
	y = y + size.GetHeight();

	//Content
	PdfStringFormat* format4 = new PdfStringFormat();
	wstring inputFile_1 = DATAPATH+L"Summary_of_Science.txt";
	PdfDocument* doc = new PdfDocument();
	ifstream in_file;
	in_file.open(inputFile_1.c_str(), ios::in);
	if (!in_file.is_open())
	{
		cout << "It failed to read file" << endl;
		return;
	}
	StringBuilder* sb = new StringBuilder();
	string buf;
	while (getline(in_file, buf))
	{
		sb->appendLine(StringHelper::string_to_wstring(buf));
	}
	wstring text4 = sb->toString();
	
	PdfTrueTypeFont* font5 = new PdfTrueTypeFont(L"Arial", 10.0f, PdfFontStyle::Regular, true);
	format4->SetLineSpacing(font5->GetSize() * 1.5f);
	PdfStringLayouter* textLayouter = new PdfStringLayouter();
	float imageLeftBlockHeight = imageBottom - y;
	PdfStringLayoutResult* result = textLayouter->Layout(text4.c_str(), font5, format4, new SizeF(imageLeftSpace, imageLeftBlockHeight));
	if (result->GetActualSize()->GetHeight() < imageBottom - y)
	{
		imageLeftBlockHeight = imageLeftBlockHeight + result->GetLineHeight();
		result = textLayouter->Layout(text4.c_str(), font5, format4, new SizeF(imageLeftSpace, imageLeftBlockHeight));
	}
	
	for each (LineInfo * line in result->GetLines())
	{
		page->GetCanvas()->DrawString(line->GetText(), font5, brush2, 0, y, format4);
		y = y + result->GetLineHeight();
	}
	PdfTextWidget* textWidget = new PdfTextWidget(result->GetRemainder(), font5, brush2);
	PdfTextLayout* textLayout = new PdfTextLayout();
	textLayout->SetBreak(PdfLayoutBreakType::FitPage);
	textLayout->SetLayout(PdfLayoutType::Paginate);
	RectangleF* bounds = new RectangleF(new PointF(0, y), page->GetCanvas()->GetClientSize());
	textWidget->SetStringFormat(format4);
	PdfNewPage* newPage = Object::Convert<PdfNewPage>(page);
	textWidget->Draw(newPage, bounds, textLayout);

	delete textWidget;
	delete textLayouter;
}
