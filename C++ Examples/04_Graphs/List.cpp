#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring outputFile = OUTPUTPATH+L"List.pdf";
	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	PdfUnitConvertor* unitCvtr = new PdfUnitConvertor();
	//Margin
	PdfMargins* margin = new PdfMargins();
	margin->SetTop(unitCvtr->ConvertUnits(2.54f, PdfGraphicsUnit::Centimeter, PdfGraphicsUnit::Point));
	margin->SetBottom(margin->GetTop());
	margin->SetLeft(unitCvtr->ConvertUnits(3.17f, PdfGraphicsUnit::Centimeter, PdfGraphicsUnit::Point));
	margin->SetRight(margin->GetLeft());
	//Create one page
	PdfPageBase* page = doc->GetPages()->Add(new SizeF(PdfPageSize::A4()), margin);
	float y = 10;
	//Title
	PdfBrush* brush1 = PdfBrushes::GetBlack();
	PdfTrueTypeFont* font1 = new PdfTrueTypeFont(L"Arial", 16.f, PdfFontStyle::Bold, true);
	PdfStringFormat* format1 = new PdfStringFormat(PdfTextAlignment::Center);
	page->GetCanvas()->DrawString(L"Categories List", font1, brush1, page->GetCanvas()->GetClientSize()->GetWidth() / 2, y, format1);
	y = y + font1->MeasureString(L"Categories List", format1)->GetHeight();
	y = y + 5;
	RectangleF* rctg = new RectangleF(new PointF(0, 0), page->GetCanvas()->GetClientSize());
	PdfLinearGradientBrush* brush = new PdfLinearGradientBrush(rctg,
		new PdfRGBColor(Spire::Common::Color::GetNavy()), new PdfRGBColor(Spire::Common::Color::GetOrangeRed()), PdfLinearGradientMode::Vertical);
	PdfFont* font = new PdfFont(PdfFontFamily::Helvetica, 12.f, PdfFontStyle::Bold);
	wstring formatted = L"Beverages\nCondiments\nConfections\nDairy Products\nGrains/Cereals\nMeat/Poultry\nProduce\nSeafood";
	PdfList* list = new PdfList(formatted.c_str());

	//create a list
	list->SetFont(font);
	list->SetIndent(8);
	list->SetTextIndent(5);
	list->SetBrush(brush);
	//Draw the list on the page
	PdfLayoutResult* result = Object::Convert<PdfLayoutWidget>(list)->Draw(page, 0, y);
	y = result->GetBounds()->GetBottom();

	//Create another list
	PdfSortedList* sortedList = new PdfSortedList(formatted.c_str());
	sortedList->SetFont(font);
	sortedList->SetIndent(8);
	sortedList->SetTextIndent(5);
	sortedList->SetBrush(brush);
	//Draw the list on the page
	PdfLayoutResult* result2 = Object::Convert<PdfLayoutWidget>(sortedList)->Draw(page, 0, y);
	y = result2->GetBounds()->GetBottom();

	PdfOrderedMarker* marker1 = new PdfOrderedMarker(PdfNumberStyle::LowerRoman, new PdfFont(PdfFontFamily::Helvetica, 12.f));
	PdfSortedList* list2 = new PdfSortedList(formatted.c_str());
	list2->SetFont(font);
	list2->SetMarker(marker1);
	list2->SetIndent(8);
	list2->SetTextIndent(5);
	list2->SetBrush(brush);
	PdfLayoutResult* result3 = Object::Convert<PdfLayoutWidget>(list2)->Draw(page, 0, y);
	y = result3->GetBounds()->GetBottom();

	PdfOrderedMarker* marker2 = new PdfOrderedMarker(PdfNumberStyle::LowerLatin, new PdfFont(PdfFontFamily::Helvetica, 12.f));
	PdfSortedList* list3 = new PdfSortedList(formatted.c_str());
	list3->SetFont(font);
	list3->SetMarker(marker2);
	list3->SetIndent(8);
	list3->SetTextIndent(5);
	list3->SetBrush(brush);
	Object::Convert<PdfLayoutWidget>(list3)->Draw(page, 0, y);
	
	//Save pdf file
	doc->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	doc->Close();

	delete list3;
	delete list2;
	delete sortedList;
	delete list;
	delete unitCvtr;
	delete doc;
}

