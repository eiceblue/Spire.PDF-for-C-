#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring outputFile = OUTPUTPATH+L"SetFreeTextAnnotationSubject.pdf";

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
	textAnnotation->SetText(L"\nSet free text annotation subject");
	//Set subject.
	textAnnotation->SetSubject(L"SubjectTest");
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
	//Save the document
	doc->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	doc->Close();

	delete doc;
}


