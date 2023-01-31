#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring inputFile = DATAPATH+L"SearchReplaceTemplate.pdf";
	wstring outputFile= OUTPUTPATH+L"SearchTextAndAddHyperlink.pdf";

	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	// Get the first page of pdf file
	PdfPageBase* page = doc->GetPages()->GetItem(0);
	// Create PdfTextFindCollection object to find all the matched phrases
	PdfTextFindCollection* collection = page->FindText(L"e-iceblue", Find_TextFindParameter::IgnoreCase);
	// hyperlink url
	wstring url = L"http://www.e-iceblue.com";
	for each (PdfTextFind * find in collection->GetFinds())
	{
		// Create a PdfUriAnnotation object to add hyperlink for the searched text 
		PdfUriAnnotation* uri = new PdfUriAnnotation(find->GetBounds());
		uri->SetUri(url.c_str());
		uri->SetBorder(new PdfAnnotationBorder(1.f));
		uri->SetColor(new PdfRGBColor(Color::GetBlue()));
		page->GetAnnotationsWidget()->Add(uri);
	}
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete doc;
}

