#include "pch.h"
#include "stringbuilder.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring inputFile = DATAPATH+L"PDFTemplate-Az.pdf";
	wstring outputFile = OUTPUTPATH+L"RemovePageMargins.pdf";

	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	// Creates a new page
	PdfDocument* newDoc = new PdfDocument();

	// Get page margins of source pdf page
	PdfMargins* margins = doc->GetPageSettings()->GetMargins();
	float top = margins->GetLeft();
	float bottom = margins->GetBottom();
	float left = margins->GetLeft();
	float right = margins->GetRight();

	for (int i =0;i< doc->GetPages()->GetCount();i++)
	{
		PdfPageBase* page = doc->GetPages()->GetItem(0);
		// Adds a new page to the new document
		PdfMargins tempVar(0);
		PdfPageBase* newPage = newDoc->GetPages()->Add(new SizeF(page->GetSize()->GetWidth() - left - right, page->GetSize()->GetHeight() - top - bottom), &tempVar);

		// Draws the content of the source page onto the new document page
		newPage->GetCanvas()->DrawTemplate(page->CreateTemplate(),new PointF(-left, -top));

		delete newPage;
	}
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete newDoc;
	delete doc;
}


