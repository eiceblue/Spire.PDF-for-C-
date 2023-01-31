#include "pch.h"
#include "stringbuilder.h"
using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main(){
				
	wstring outputFile = OUTPUTPATH+L"ResetPageSize.pdf";
	wstring inputFile = DATAPATH+L"ResetPageSize.pdf";
	PdfDocument* originalDoc = new PdfDocument();
	originalDoc->LoadFromFile(inputFile.c_str());
	//Set the margins
	PdfMargins* margins = new PdfMargins(0);
	//Create a new pdf document
	PdfDocument newDoc = PdfDocument();
	float scale = 0.8f;
	for(int i = 0; i < originalDoc->GetPages()->GetCount(); i++)
	{
		PdfPageBase* page = originalDoc->GetPages()->GetItem(i);

		//Use same scale to set width and height
		float width = page->GetSize()->GetWidth() * scale;
		float height = page->GetSize()->GetHeight() * scale;

		//Add new page with expected width and height
		PdfPageBase* newPage = newDoc.GetPages()->Add(new SizeF(width, height), margins);
		newPage->GetCanvas()->ScaleTransform(scale, scale);

		//Copy content of original page into new page
		newPage->GetCanvas()->DrawTemplate(page->CreateTemplate(), PointF::Empty());

		delete newPage;
	}

	//Save the document
	newDoc.SaveToFile(outputFile.c_str());
	newDoc.Close();

	delete originalDoc;
}
