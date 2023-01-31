#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring outputFile = OUTPUTPATH+L"AddTooltipToText.pdf";

	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	//Create one page
	PdfPageBase* page = doc->GetPages()->Add();
	PdfTrueTypeFont* font = new PdfTrueTypeFont(L"Arial", 15.f, PdfFontStyle::Regular, true);
	page->GetCanvas()->DrawString(L"Move the mouse cursor over the following text to display a tooltip",
		font, PdfBrushes::GetBlack(), new PointF(10, 20));

	//Define the text and its style
	LPCWSTR_S text1 = L"Your Office Development Master";
	PdfTrueTypeFont* font1 = new PdfTrueTypeFont(L"Arial", 18, PdfFontStyle::Regular, true);
	SizeF* sizef1 = font1->MeasureString(text1);
	RectangleF* rec1 = new RectangleF(new PointF(100, 100), sizef1);
	//Draw text 
	page->GetCanvas()->DrawString(text1, font1, new PdfSolidBrush(new PdfRGBColor(Spire::Common::Color::GetBlue())), rec1);
	//Create invisible button on text position
	PdfButtonField* field1 = new PdfButtonField(page, L"field1");
	//Set the bounds and size of field
	field1->SetBounds(rec1);
	//Set tooltip content
	field1->SetToolTip(L"E-iceblue Co. Ltd., a vendor of .NET, Java and WPF development components");
	//Set no border for field
	field1->SetBorderWidth(0);
	//Set backcolor and forcolor for field
	PdfRGBColor* color = new PdfRGBColor(Color::GetTransparent());
	field1->SetBackColor(color);
	field1->SetForeColor(color);
	field1->SetLayoutMode(PdfButtonLayoutMode::IconOnly);
	field1->GetIconLayout()->SetIsFitBounds(true);

	//Define the text and its style 
	LPCWSTR_S text2 = L"Spire.PDF";
	PdfFont* font2 = new PdfFont(PdfFontFamily::TimesRoman, 20);
	SizeF* sizef2 = font2->MeasureString(text2);
	RectangleF* rec2 = new RectangleF(new PointF(100, 160), sizef2);
	//Draw text 
	page->GetCanvas()->DrawString(text2, font2, PdfBrushes::GetDarkOrange(), rec2);
	//Create invisible button on text position
	PdfButtonField* field2 = new PdfButtonField(page, L"field2");
	field2->SetBounds(rec2);
	field2->SetToolTip(L"A professional PDF library applied to creating,writing, editing, handling and reading PDF fileswithout any external dependencies within .NET( C#, VB.NET, ASP.NET, .NET Core) application.");
	field2->SetBorderWidth(0);
	field2->SetBackColor(color);
	field2->SetForeColor(color);
	field2->SetLayoutMode(PdfButtonLayoutMode::IconOnly);
	field2->GetIconLayout()->SetIsFitBounds(true);

	//Add the buttons to pdf form
	doc->SetAllowCreateForm(true);
	doc->GetForm()->GetFields()->Add(field1);
	doc->GetForm()->GetFields()->Add(field2);
	doc->SaveToFile((outputFile).c_str());
	doc->Close();

	delete doc;
}

