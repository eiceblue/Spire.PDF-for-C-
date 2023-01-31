#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring inputFile = DATAPATH+L"Template_Pdf_3.pdf";
	wstring outputFile = OUTPUTPATH+L"CreatePdfLinkAnnotation.pdf";
	//Create a new object of PdfDocument.
	PdfDocument* doc = new PdfDocument();
	//Add a page to it.
	PdfPageBase* page = doc->GetPages()->Add();
	//Declare two parameters that will be passed to the constructor of PdfFileLinkAnnotation class.
	RectangleF* rect = new RectangleF(0, 40, 250, 35);
	
	//Create a file link annotation based on the two parameters and add the annotation to the new page.
	PdfFileLinkAnnotation* link = new PdfFileLinkAnnotation(rect, inputFile.c_str());
	page->GetAnnotationsWidget()->Add(link);
	//Create a free text annotation based on the same RectangleF, specifying the content.
	PdfFreeTextAnnotation* text = new PdfFreeTextAnnotation(rect);
	text->SetText(L"Click here! This is a link annotation.");
	PdfFont* font = new PdfFont(PdfFontFamily::Helvetica, 15);
	text->SetFont(font);
	page->GetAnnotationsWidget()->Add(text);

	//Save the document
	doc->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	doc->Close();

	delete doc;
}


