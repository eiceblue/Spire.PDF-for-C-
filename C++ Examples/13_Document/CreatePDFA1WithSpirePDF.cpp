#include "pch.h"
#include "stringbuilder.h"
#include <iostream>
#include "stringhelper.h"
using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main(){
	//Input and output files path
	wstring outputFile = OUTPUTPATH+L"CreatePDFA1WithSpirePDF_A1B.pdf";
	wstring outputFile_Temp = OUTPUTPATH+L"CreatePDFA1WithSpirePDF_Temp.pdf";
    //Open pdf document
	PdfNewDocument* doc = new PdfNewDocument();
	//Create one A4 page
	PdfMargins tempVar(40);
	PdfPageBase* page = doc->GetPages()->Add(new SizeF(PdfPageSize::A4()), &tempVar);

	// Draw content
	DrawPage(page);
	//Save the document
	PdfDocumentBase* docBase = Object::Convert<PdfDocumentBase>(doc);
	docBase->Save(outputFile_Temp.c_str());
	doc->Close(true);
	PdfStandardsConverter* converter = new PdfStandardsConverter(outputFile_Temp.c_str());
	converter->ToPdfA1B(outputFile.c_str());

	delete converter;
	delete doc;
}

void DrawPage(PdfPageBase* page){
     float pageWidth = page->GetCanvas()->GetClientSize()->GetWidth();
     float y = 0;
     
     //Title
     y = y + 5;
     PdfBrush* brush2 = new PdfSolidBrush(new PdfRGBColor(Color::GetBlack()));
     
     PdfTrueTypeFont* font2 = new PdfTrueTypeFont(L"Arial", 16.f, PdfFontStyle::Bold, true);
     
     PdfStringFormat* format2 = new PdfStringFormat(PdfTextAlignment::Center);
     format2->SetCharacterSpacing(1.0f);
     LPCWSTR_S text = L"Summary of Science";
     page->GetCanvas()->DrawString(text, font2, brush2, pageWidth / 2, y, format2);
     SizeF* size = font2->MeasureString(text, format2);
     y = y + size->GetHeight() + 6;
     
     //Icon
     wstring inputFile = DATAPATH+L"Wikipedia_Science.png";
     PdfImage* image = PdfImage::FromFile(inputFile.c_str());
     page->GetCanvas()->DrawImage(image, new PointF(pageWidth - image->GetPhysicalDimension()->GetWidth(), y));
     float imageLeftSpace = pageWidth - image->GetPhysicalDimension()->GetWidth() - 2;
     float imageBottom = image->GetPhysicalDimension()->GetHeight() + y;
     
     //Reference content           
     PdfTrueTypeFont* font3 = new PdfTrueTypeFont(L"Arial", 9.f, PdfFontStyle::Regular, true);
     
     PdfStringFormat* format3 = new PdfStringFormat();
     format3->SetParagraphIndent(font3->GetSize() * 2);
     format3->SetMeasureTrailingSpaces(true);
     format3->SetLineSpacing(font3->GetSize() * 1.5f);
     LPCWSTR_S text1 = L"(All text and picture from ";
     LPCWSTR_S text2 = L"Wikipedia";
     LPCWSTR_S text3 = L", the free encyclopedia)";
     page->GetCanvas()->DrawString(text1, font3, brush2, 0, y, format3);
     
     size = font3->MeasureString(text1, format3);
     float x1 = size->GetWidth();
     format3->SetParagraphIndent(0);
     
     PdfTrueTypeFont* font4 = new PdfTrueTypeFont(L"Arial", 9.0f, PdfFontStyle::Underline, true);
     
     PdfBrush* brush3 = new PdfSolidBrush(new PdfRGBColor(Color::GetBlue()));
     page->GetCanvas()->DrawString(text2, font4, brush3, x1, y, format3);
     size = font4->MeasureString(text2, format3);
     x1 = x1 + size->GetWidth();
     
     page->GetCanvas()->DrawString(text3, font3, brush2, x1, y, format3);
     y = y + size->GetHeight();
     
     //Content
     PdfStringFormat* format4 = new PdfStringFormat();
     
     wstring inputFile1 = DATAPATH+L"Summary_of_Science.txt";
     PdfDocument* doc = new PdfDocument();
     
     ifstream in_file;
     in_file.open(inputFile1.c_str(), ios::in);
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
     wstring text4 = sb->toString();
     
     LPCWSTR_S fontname = L"Arial";
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
     if (page->GetImagesInfo().size() != 0)
     {
     	vector<LineInfo*> line = result->GetLines();
     	for (int j = 0; j < line.size(); j++)
     	{
     		page->GetCanvas()->DrawString(line[j]->GetText(), font5, brush2, 0, y, format4);
     		y = y + result->GetLineHeight();
     	}
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
		
	

