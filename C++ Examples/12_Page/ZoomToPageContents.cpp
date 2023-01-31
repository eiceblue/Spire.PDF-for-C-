#include "pch.h"
#include "stringbuilder.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main()
{
	
	wstring outputFile = OUTPUTPATH+L"ZoomToPageContents.pdf";
	wstring inputFile = DATAPATH+L"PDFTemplate_N.pdf";
	//Create a new pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());

	//Create a newDoc
	PdfDocument* newDoc = new PdfDocument();

	for (int i =0;i<doc->GetPages()->GetCount();i++)
	{
		//Add new page with 'A3' size
		PdfMargins tempVar(0, 0);
		PdfPageBase* newPage = newDoc->GetPages()->Add(new SizeF(PdfPageSize::A3()), &tempVar);
		PdfPageBase* page = doc->GetPages()->GetItem(i);
		//Zoom content to the new page
		newPage->GetCanvas()->ScaleTransform(newPage->GetActualSize()->GetWidth() / page->GetActualSize()->GetWidth(), (newPage->GetActualSize()->GetHeight() / page->GetActualSize()->GetHeight()));

		//Draw the page to new page
		newPage->GetCanvas()->DrawTemplate(page->CreateTemplate(),new PointF(0, 0));

		delete newPage;
	}

	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete newDoc;
	delete doc;
}
