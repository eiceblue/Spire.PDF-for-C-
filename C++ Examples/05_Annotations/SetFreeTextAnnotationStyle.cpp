#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring outputFile = OUTPUTPATH+L"SetFreeTextAnnotationStyle.pdf";

	wstring inputFile = DATAPATH+L"Template_Pdf_4.pdf";
	//Create a new PDF document.
	PdfDocument* doc = new PdfDocument();
	//Load the file from disk.
	doc->LoadFromFile(inputFile.c_str());
	//Get the first page of PDF file.
	PdfPageBase* page = doc->GetPages()->GetItem(0);
	//Initialize a PdfFreeTextAnnotation.
	RectangleF* rect = new RectangleF(150, 120, 150, 30);
	PdfFreeTextAnnotation* textAnnotation = new PdfFreeTextAnnotation(rect);
	//Specify content.
	textAnnotation->SetText(L"\nFree Text Annotation Formatting");
	//Set free text annotation formatting and add it to page.
	PdfFont* font = new PdfFont(PdfFontFamily::TimesRoman, 10);
	PdfAnnotationBorder* border = new PdfAnnotationBorder(1.f);
	textAnnotation->SetFont(font);
	textAnnotation->SetBorder(border);
	textAnnotation->SetBorderColor(new PdfRGBColor(Spire::Common::Color::GetPurple()));
	textAnnotation->SetLineEndingStyle(PdfLineEndingStyle::Circle);
	textAnnotation->SetColor(new PdfRGBColor(Spire::Common::Color::GetGreen()));
	textAnnotation->SetOpacity(0.8f);
	page->GetAnnotationsWidget()->Add(textAnnotation);

	rect = new RectangleF(150, 200, 150, 40);
	textAnnotation = new PdfFreeTextAnnotation(rect);
	textAnnotation->SetText(L"\nFree Text Annotation Formatting");
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
	textAnnotation->SetText(L"\noHow to Set Free Text Annotation Formatting in Pdf file");
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
	textAnnotation->SetText(L"\nFree Text Annotation Formatting");
	border = new PdfAnnotationBorder(1.f);
	font = new PdfFont(PdfFontFamily::Helvetica, 10);
	textAnnotation->SetFont(font);
	textAnnotation->SetBorder(border);
	textAnnotation->SetBorderColor(new PdfRGBColor(Spire::Common::Color::GetPink()));
	textAnnotation->SetLineEndingStyle(PdfLineEndingStyle::RClosedArrow);
	textAnnotation->SetColor(new PdfRGBColor(Spire::Common::Color::GetLightGreen()));
	textAnnotation->SetOpacity(0.8f);
	page->GetAnnotationsWidget()->Add(textAnnotation);

	//Save the document
	doc->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	doc->Close();

	delete doc;
}

