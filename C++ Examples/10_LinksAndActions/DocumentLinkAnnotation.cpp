#include "pch.h"

#include "stringhelper.h"
using namespace Spire::Common;
using namespace Spire::Pdf;
using namespace std;

int main()
{
	wstring outputFile = OUTPUTPATH + L"DocumentLinkAnnotation.pdf";
	//Create a pdf document
	PdfDocument* doc = new PdfDocument();

	//Create PdfUnitConvertor to convert the unit
	PdfUnitConvertor* unitCvtr = new PdfUnitConvertor();

	//Setting for page margin
	PdfMargins* margin = new PdfMargins();
	margin->SetTop(unitCvtr->ConvertUnits(2.54f, PdfGraphicsUnit::Centimeter, PdfGraphicsUnit::Point));
	margin->SetBottom(margin->GetTop());
	margin->SetLeft(unitCvtr->ConvertUnits(2.0f, PdfGraphicsUnit::Centimeter, PdfGraphicsUnit::Point));
	margin->SetRight(margin->GetLeft());

	//Add the first page
	PdfPageBase* page1 = doc->GetPages()->Add(new SizeF(PdfPageSize::A4()), margin);

	//Define a PdfBrush
	PdfBrush* brush1 = PdfBrushes::GetBlack();

	//Define a font
	PdfTrueTypeFont* font1 = new PdfTrueTypeFont(L"Arial", 12.0f, PdfFontStyle::Bold, true);
	//Set the string format 
	PdfStringFormat* format1 = new PdfStringFormat(PdfTextAlignment::Left);

	//Set the position for drawing 
	float x = 0;
	float y = 50;

	//Text string 
	std::wstring specification = L"The sample demonstrates how to create a local document link in PDF document.";

	//Draw text string on first page 
	page1->GetCanvas()->DrawString(specification.c_str(), font1, brush1, x, y, format1);

	//Use MeasureString to get the height of string
	y = y + font1->MeasureString(specification.c_str(), format1)->GetHeight() + 10;

	//Add the second page
	PdfPageBase* page2 = doc->GetPages()->Add(new SizeF(PdfPageSize::A4()), margin);

	//String text
	std::wstring PageContent = L"This is the second page!";

	//Draw text string on second page 
	page2->GetCanvas()->DrawString(PageContent.c_str(), font1, brush1, x, y, format1);

	//Add DocumentLinkAnnotation on the first page and link to the second page
	AddDocumentLinkAnnotation(doc, 0, 1, y);
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete unitCvtr;
}

void AddDocumentLinkAnnotation(PdfDocument* pdf, int AddPage, int DestinationPage, float y)
{
	//Define a font
	PdfTrueTypeFont* font = new PdfTrueTypeFont(L"Arial", 12.0f, PdfFontStyle::Regular, true);
	//Set the string format
	PdfStringFormat* format = new PdfStringFormat(PdfTextAlignment::Left);

	//Text string
	std::wstring prompt = L"Local document Link: ";

	//Draw text string on page that
	pdf->GetPages()->GetItem(AddPage)->GetCanvas()->DrawString(prompt.c_str(), font, PdfBrushes::GetDodgerBlue(), 0, y);

	//Use MeasureString to get the width of string
	float x = font->MeasureString(prompt.c_str(), format)->GetWidth();

	//Create a PdfDestination with specific page
	PdfDestination* dest = new PdfDestination(pdf->GetPages()->GetItem(DestinationPage));

	//Set the location of destination
	dest->SetLocation(new PointF(0, y));

	//Set 50% zoom factor
	dest->SetZoom(0.5f);

	//Label string
	std::wstring label = L"Click here to link the second page.";

	//Use MeasureString to get the SizeF of string
	SizeF* size = font->MeasureString(label.c_str());

	//Create a rectangle
	RectangleF* bounds = new RectangleF(x, y, size->GetWidth(), size->GetHeight());

	//Draw label string
	pdf->GetPages()->GetItem(AddPage)->GetCanvas()->DrawString(label.c_str(), font, PdfBrushes::GetOrangeRed(), x, y);

	//Create PdfDocumentLinkAnnotation on the rectangle and link to the destination  
	PdfDocumentLinkAnnotation* annotation = new PdfDocumentLinkAnnotation(bounds, dest);

	//Set color for annotation
	annotation->SetColor(new PdfRGBColor(Color::GetBlue()));

	//Add annotation to the page
	PdfNewPage* newPage = Object::Convert<PdfNewPage>(pdf->GetPages()->GetItem(AddPage));
	newPage->GetAnnotations()->Add(annotation);
}
