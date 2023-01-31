#include "pch.h"


using namespace Spire::Pdf;
using namespace std;


int main()
{
	wstring outputFile = OUTPUTPATH + L"AddPdfLaunchAction.pdf";
	wstring inputFile = DATAPATH + L"text.txt";
	//Create a new PDF document and add a page to it
	PdfDocument* doc = new PdfDocument();
	PdfPageBase* page = doc->GetPages()->Add();

	//Create a PDF Launch Action    
	PdfLaunchAction* launchAction = new PdfLaunchAction(outputFile.c_str());
	//Create a PDF Action Annotation with the PDF Launch Action
	wstring text = L"Click here to open file";

	PdfTrueTypeFont* font = new PdfTrueTypeFont(L"Arial", 13.0f, PdfFontStyle::Regular, true);
	RectangleF* rect = new RectangleF(50, 50, 230, 15);
	page->GetCanvas()->DrawString(text.c_str(), font, PdfBrushes::GetForestGreen(), rect);
	PdfActionAnnotation* annotation = new PdfActionAnnotation(rect, launchAction);

	//Add the PDF Action Annotation to page
	PdfNewPage* newPage = Object::Convert<PdfNewPage>(page);
	newPage->GetAnnotations()->Add(annotation);

	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();
	delete doc;
}
