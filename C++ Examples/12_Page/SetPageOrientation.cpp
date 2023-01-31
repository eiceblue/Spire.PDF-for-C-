#include "pch.h"
#include "stringbuilder.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main(){
				
	wstring outputFile = OUTPUTPATH+L"SetPageOrientation.pdf";
	//Create a new pdf document
	PdfDocument* doc = new PdfDocument();

	//Add a section
	PdfSection* section = doc->GetSections()->Add();

	//Load a image
	wstring inputFile = DATAPATH+L"scenery.jpg";
	PdfImage* image = PdfImage::FromFile(inputFile.c_str());

	//Check whether the width of the image file is greater than default page width or not
	if (image->GetPhysicalDimension()->GetWidth() > section->GetPageSettings()->GetSize()->GetWidth())
	{

		//Set the orientation as landscape
		section->GetPageSettings()->SetOrientation(PdfPageOrientation::Landscape);
	}
	else
	{
		section->GetPageSettings()->SetOrientation(PdfPageOrientation::Portrait);
	}

	//Add a new page with orientation Landscape
	PdfPageBase* page = section->GetPages()->Add();

	//Draw the image on the page
	page->GetCanvas()->DrawImage(image, new PointF(0, 0));

	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();
	
	delete doc;
}
