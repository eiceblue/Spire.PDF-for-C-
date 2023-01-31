#include "pch.h"
#include "stringbuilder.h"
#include "stringhelper.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	std::wstring output_path = OUTPUTPATH;
	std::wstring outputFile = output_path + L"WrapTextAroundImage.pdf";
	// Creates a pdf document
	PdfDocument* doc = new PdfDocument();
	// Creates a page 
	PdfPageBase* page = doc->GetPages()->Add();
	//Gets page width
	float pageWidth = page->GetCanvas()->GetClientSize()->GetWidth();
	float y = 0;
	y += 8;
	// Creates a brush
	PdfBrush* brush = new PdfSolidBrush(new PdfRGBColor(Color::GetBlack()));
	// Defines a font
	PdfTrueTypeFont* font1 = new PdfTrueTypeFont(L"Arial", 20.f, PdfFontStyle::Bold, true);
	// Defines a text center alignment format
	PdfStringFormat* format1 = new PdfStringFormat(PdfTextAlignment::Center);
	format1->SetCharacterSpacing(1);
	wstring text = L"Spire.PDF for .NET";
	// Draws text at the specified position
	page->GetCanvas()->DrawString(text.c_str(), font1, brush, pageWidth / 2, y, format1);
	// Get the size of text
	SizeF* size = font1->MeasureString(text.c_str(), format1);
	y = y + size->GetHeight() + 6;
	// Loads an image 
	wstring imageIn = DataPath + L"PdfImage.png";
	PdfImage* image = PdfImage::FromFile(imageIn.c_str());
	// Draws image at the specified position
	page->GetCanvas()->DrawImage(image, new PointF(pageWidth - image->GetPhysicalDimension()->GetWidth(), y));
	float imageLeftSpace = pageWidth - image->GetPhysicalDimension()->GetWidth() - 2;
	float imageBottom = image->GetPhysicalDimension()->GetHeight() + y;
	PdfStringFormat* format2 = new PdfStringFormat();
	ifstream in_file;
	// Loads the text around the image
	wstring textIn = DataPath + L"text.txt";
	in_file.open(textIn.c_str());
	if (!in_file.is_open()) {
		cout << "读取txt文本失败" << endl;
		return;
	}

	StringBuilder* sb = new StringBuilder();
	string buf;
	while (getline(in_file, buf)) {
		sb->appendLine(StringHelper::string_to_wstring(buf));
	}
	wstring filetext = sb->toString();
	PdfTrueTypeFont* font2 = new PdfTrueTypeFont(L"Arial", 16.f, PdfFontStyle::Regular, true);
	//Set line spacing
	format2->SetLineSpacing(font2->GetSize() * 1.5);
	PdfStringLayouter* textLayouter = new PdfStringLayouter();
	float imageLeftBlockHeight = imageBottom - y;
	// Splits the text around into multiple lines based on the draw area
	PdfStringLayoutResult* result
		= textLayouter->Layout(filetext.c_str(), font2, format2, new SizeF(imageLeftSpace, imageLeftBlockHeight));
	if (result->GetActualSize()->GetHeight() < imageLeftBlockHeight)
	{
		imageLeftBlockHeight = imageLeftBlockHeight + result->GetLineHeight();
		result = textLayouter->Layout(filetext.c_str(), font2, format2, new SizeF(imageLeftSpace, imageLeftBlockHeight));
	}
	// Draws all the lines onto the page
	for each (LineInfo * line in result->GetLines())
	{
		page->GetCanvas()->DrawString(line->GetText(), font2, brush, 0, y, format2);
		y = y + result->GetLineHeight();
	}
	// Draw the rest of the text onto the page
	PdfTextWidget* textWidget = new PdfTextWidget(result->GetRemainder(), font2, brush);
	PdfTextLayout* textLayout = new PdfTextLayout();
	textLayout->SetBreak(PdfLayoutBreakType::FitPage);
	textLayout->SetLayout(PdfLayoutType::Paginate);
	RectangleF* bounds = new RectangleF(new PointF(0, y), page->GetCanvas()->GetClientSize());
	textWidget->SetStringFormat(format2);
	PdfNewPage* newPage = Object::Convert<PdfNewPage>(page);
	textWidget->Draw(newPage, bounds, textLayout);
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();
	delete textWidget;
	delete textLayouter;
	delete doc;
}

	