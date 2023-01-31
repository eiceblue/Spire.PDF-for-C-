#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

inline PdfAnnotationFlags operator|(PdfAnnotationFlags a, PdfAnnotationFlags b) {
				return static_cast<PdfAnnotationFlags>(static_cast<int>(a) | static_cast<int>(b));
			}
			
int main() {
	wstring outputFile = OUTPUTPATH+L"InvisibleFreeTextAnnotation.Pdf";
	wstring inputFile = DATAPATH+L"Template_Pdf_4.pdf";
	
	//Create a new PDF document.
	PdfDocument* doc = new PdfDocument();
	//Load the file from disk.
	doc->LoadFromFile(inputFile.c_str());
	//Get the first page of PDF file.
	PdfPageBase* page = doc->GetPages()->GetItem(0);
	//Add a free text annotation to the page and set it invisible.
	RectangleF* rect = new RectangleF(100, 120, 150, 30);
	PdfFreeTextAnnotation* FreetextAnnotation = new PdfFreeTextAnnotation(rect);
	FreetextAnnotation->SetText(L"Invisible Free Text Annotation");
	PdfFont* font = new PdfFont(PdfFontFamily::TimesRoman, 10);
	PdfAnnotationBorder* border = new PdfAnnotationBorder(1.f);
	FreetextAnnotation->SetFont(font);
	FreetextAnnotation->SetBorder(border);
	FreetextAnnotation->SetBorderColor(new PdfRGBColor(Spire::Common::Color::GetPurple()));
	FreetextAnnotation->SetLineEndingStyle(PdfLineEndingStyle::Circle);
	FreetextAnnotation->SetColor(new PdfRGBColor(Spire::Common::Color::GetGreen()));
	FreetextAnnotation->SetOpacity(0.8f);
	//Invisible free text annotation.
	FreetextAnnotation->SetFlags(PdfAnnotationFlags::Print | PdfAnnotationFlags::NoView);
	page->GetAnnotationsWidget()->Add(FreetextAnnotation);

	//Add a free text annotation show it on the page.
	rect = new RectangleF(100, 180, 150, 30);
	FreetextAnnotation = new PdfFreeTextAnnotation(rect);
	FreetextAnnotation->SetText(L"Show Free Text Annotation");
	FreetextAnnotation->SetFont(font);
	FreetextAnnotation->SetBorder(border);
	FreetextAnnotation->SetBorderColor(new PdfRGBColor(Spire::Common::Color::GetLightPink()));
	FreetextAnnotation->SetLineEndingStyle(PdfLineEndingStyle::Circle);
	FreetextAnnotation->SetColor(new PdfRGBColor(Spire::Common::Color::GetLightGreen()));
	FreetextAnnotation->SetOpacity(0.8f);
	page->GetAnnotationsWidget()->Add(FreetextAnnotation);

	//Save the document
	doc->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	doc->Close();
	delete doc;
}


