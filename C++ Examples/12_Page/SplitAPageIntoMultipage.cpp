#include "pch.h"
#include "stringbuilder.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main(){
	wstring outputFile = OUTPUTPATH+L"SplitAPageIntoMultipage.pdf";
	wstring inputFile = DATAPATH+L"PDFTemplate_N.pdf";

	//Create a new pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());

	//Get the first page
	PdfPageBase* page = doc->GetPages()->GetItem(0);

	//Create a new Pdf
	PdfDocument* newPdf = new PdfDocument();

	//Remove all the margins
	newPdf->GetPageSettings()->GetMargins()->SetAll(0);

	//Set the page size of new Pdf
	newPdf->GetPageSettings()->SetWidth(page->GetSize()->GetWidth());
	newPdf->GetPageSettings()->SetHeight(page->GetSize()->GetHeight() / 2);

	//Add a new page
	PdfPageBase* newPage = newPdf->GetPages()->Add();

	PdfTextLayout* format = new PdfTextLayout();
	format->SetBreak(PdfLayoutBreakType::FitPage);
	format->SetLayout(PdfLayoutType::Paginate);

	//Draw the page in the new page
	page->CreateTemplate()->Draw(newPage, new PointF(0, 0), format);

	//Save the document
	newPdf->SaveToFile(outputFile.c_str());
	newPdf->Close();

	delete newPdf;
	delete doc;
}
