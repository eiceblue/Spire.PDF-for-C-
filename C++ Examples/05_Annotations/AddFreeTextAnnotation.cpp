#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring outputFile = OUTPUTPATH+L"AddFreeTextAnnotation.pdf";
	wstring inputFile = DATAPATH+L"AddFreeTextAnnotation.pdf";

	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	PdfPageBase* page = doc->GetPages()->GetItem(0);
	RectangleF* rect = new RectangleF(0, 300, 100, 80);
	//Add free text annotation
	PdfFreeTextAnnotation* textAnnotation = new PdfFreeTextAnnotation(rect);
	textAnnotation->SetText(L"\n  Spire.PDF");
	PdfAnnotationBorder* border = new PdfAnnotationBorder(1.f);
	PdfFont* font = new PdfFont(PdfFontFamily::TimesRoman, 20);
	textAnnotation->SetFont(font);
	textAnnotation->SetBorder(border);
	textAnnotation->SetBorderColor(new PdfRGBColor(Spire::Common::Color::GetGray()));
	textAnnotation->SetLineEndingStyle(PdfLineEndingStyle::Slash);
	textAnnotation->SetColor(new PdfRGBColor(Spire::Common::Color::GetLightBlue()));
	textAnnotation->SetOpacity(0.8f);
	page->GetAnnotationsWidget()->Add(textAnnotation);

	rect = new RectangleF(150, 200, 150, 40);
	textAnnotation = new PdfFreeTextAnnotation(rect);
	textAnnotation->SetText(L"\nHigh Fidelity Pdf file Conversion");
	border = new PdfAnnotationBorder(1.f);
	font = new PdfFont(PdfFontFamily::Helvetica, 10);
	textAnnotation->SetFont(font);
	textAnnotation->SetBorder(border);
	textAnnotation->SetBorderColor(new PdfRGBColor(Spire::Common::Color::GetLightGoldenrodYellow()));
	textAnnotation->SetLineEndingStyle(PdfLineEndingStyle::RClosedArrow);
	textAnnotation->SetColor(new PdfRGBColor(Spire::Common::Color::GetLightPink()));
	textAnnotation->SetOpacity(0.8f);
	page->GetAnnotationsWidget()->Add(textAnnotation);

	rect = new RectangleF(150, 280, 280, 40);
	textAnnotation = new PdfFreeTextAnnotation(rect);
	textAnnotation->SetText(L"\nEasily Manipulate document and Form fields");
	border = new PdfAnnotationBorder(1.f);
	font = new PdfFont(PdfFontFamily::Helvetica, 10);
	textAnnotation->SetFont(font);
	textAnnotation->SetBorder(border);
	textAnnotation->SetBorderColor(new PdfRGBColor(Spire::Common::Color::GetGray()));
	textAnnotation->SetLineEndingStyle(PdfLineEndingStyle::Circle);
	textAnnotation->SetColor(new PdfRGBColor(Spire::Common::Color::GetLightSkyBlue()));
	textAnnotation->SetOpacity(0.8f);
	page->GetAnnotationsWidget()->Add(textAnnotation);

	rect = new RectangleF(150, 360, 200, 40);
	textAnnotation = new PdfFreeTextAnnotation(rect);
	textAnnotation->SetText(L"\nSecurity features");
	border = new PdfAnnotationBorder(1.f);
	font = new PdfFont(PdfFontFamily::Helvetica, 10);
	textAnnotation->SetFont(font);
	textAnnotation->SetBorder(border);
	textAnnotation->SetBorderColor(new PdfRGBColor(Spire::Common::Color::GetPink()));
	textAnnotation->SetLineEndingStyle(PdfLineEndingStyle::RClosedArrow);
	textAnnotation->SetColor(new PdfRGBColor(Spire::Common::Color::GetLightGreen()));
	textAnnotation->SetOpacity(0.8f);
	page->GetAnnotationsWidget()->Add(textAnnotation);

	rect = new RectangleF(150, 440, 200, 40);
	textAnnotation = new PdfFreeTextAnnotation(rect);
	textAnnotation->SetText(L"\nExtract data from Pdf documents");
	border = new PdfAnnotationBorder(1.f);
	font = new PdfFont(PdfFontFamily::Helvetica, 10);
	textAnnotation->SetFont(font);
	textAnnotation->SetBorder(border);
	textAnnotation->SetBorderColor(new PdfRGBColor(Spire::Common::Color::GetOrangeRed()));
	textAnnotation->SetLineEndingStyle(PdfLineEndingStyle::RClosedArrow);
	textAnnotation->SetColor(new PdfRGBColor(Spire::Common::Color::GetLightGoldenrodYellow()));
	textAnnotation->SetOpacity(0.8f);
	page->GetAnnotationsWidget()->Add(textAnnotation);

	//Save pdf file
	doc->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	doc->Close();

	delete doc;
}

