#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring outputFile = OUTPUTPATH+L"ModifyPageMargins.pdf";
    wstring inputFile = DATAPATH+L"ModifyPageMargins.pdf";
	
	// Create a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());

	// Creates a new pdf document
	PdfDocument* newDoc = new PdfDocument();

	// Defines the page margins of the new document
	float top = 50;
	float bottom = 50;
	float left = 50;
	float right = 50;
	for (int i = 0; i < doc->GetPages()->GetCount(); i++)
	{
		PdfMargins* tempmg = new PdfMargins(0);
		PdfPageBase* newPage = newDoc->GetPages()->Add(doc->GetPages()->GetItem(i)->GetSize(), tempmg);
		// Set the scale of the new document content
		newPage->GetCanvas()->ScaleTransform((doc->GetPages()->GetItem(i)->GetActualSize()->GetWidth() - left - right) / doc->GetPages()->GetItem(i)->GetActualSize()->GetWidth(), (doc->GetPages()->GetItem(i)->GetActualSize()->GetHeight() - top - bottom) / doc->GetPages()->GetItem(i)->GetActualSize()->GetHeight());
		// Draws the content of the source page onto the new document page
		newPage->GetCanvas()->DrawTemplate(doc->GetPages()->GetItem(i)->CreateTemplate(),new PointF(left, top));

		delete newPage;
	}

	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete newDoc;
	delete doc;

}

