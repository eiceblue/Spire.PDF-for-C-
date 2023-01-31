#include "pch.h"

#include "stringhelper.h"
#include "stringbuilder.h"
using namespace Spire::Common;

using namespace Spire::Pdf;
using namespace std;

int main()
{
	wstring outputFile = OUTPUTPATH + L"GoToAction.pdf";
	//Create a new PDF document and add a page to it
	//create a pdf document
	PdfDocument* pdf = new PdfDocument();
	PdfPageBase* page = pdf->GetPages()->Add();

	//add a GoToE in pdf 
	EmbeddedGoToAction(pdf, page);

	//creat a action that could jump to specific location
	JumpToSpecificLocationAction(pdf, page);

	//Save the document
	pdf->SaveToFile(outputFile.c_str());
	pdf->Close();
}

void EmbeddedGoToAction(PdfDocument* pdf, PdfPageBase* page)
{
	//add a attachment
	wstring inputFile = DATAPATH + L"GoToAction.pdf";
	PdfAttachment* attachment = new PdfAttachment(inputFile.c_str());
	pdf->GetAttachments()->Add(attachment);

	std::wstring text = L"Test embedded go-to action! Click this will open the attached PDF in a new window.";

	PdfTrueTypeFont* font = new PdfTrueTypeFont(L"Arial", 13.0f, PdfFontStyle::Regular, true);
	float width = 490.0f;
	float height = font->GetHeight() * 2.2f;
	RectangleF* rect = new RectangleF(0, 100, width, height);
	page->GetCanvas()->DrawString(text.c_str(), font, PdfBrushes::GetBlack(), rect);

	//create a PdfDestination with specific page, location and 200% zoom factor
	PdfDestination* dest = new PdfDestination(1, new PointF(0, 842), 2.0f);

	//create GoToE action with dest
	PdfEmbeddedGoToAction* action = new PdfEmbeddedGoToAction(attachment->GetFileName(), dest, true);
	PdfActionAnnotation* annotation = new PdfActionAnnotation(rect, action);

	//add the annotation
	PdfNewPage* newPage = Object::Convert<PdfNewPage>(page);
	newPage->GetAnnotations()->Add(annotation);
}

void JumpToSpecificLocationAction(PdfDocument* pdf, PdfPageBase* page)
{
	//add a new page
	PdfPageBase* pagetwo = pdf->GetPages()->Add();

	//draw text on the page
	PdfFont tempVar(PdfFontFamily::Helvetica, 20.0f);
	PdfSolidBrush tempVar2(new PdfRGBColor(Color::GetBlack()));
	pagetwo->GetCanvas()->DrawString(L"This is Page Two.", &tempVar, &tempVar2, 10, 10);

	//create PdfDestination instance and link to PdfGoToAction
	PdfDestination* pageBottomDest = new PdfDestination(pagetwo);
	pageBottomDest->SetLocation(new PointF(0, 5));
	pageBottomDest->SetMode(PdfDestinationMode::Location);
	pageBottomDest->SetZoom(1.0f);
	PdfGoToAction* action = new PdfGoToAction(pageBottomDest);

	PdfTrueTypeFont* buttonFont = new PdfTrueTypeFont(L"Arial", 10.0f, PdfFontStyle::Bold, true);

	float buttonWidth = 70;
	float buttonHeight = buttonFont->GetHeight() * 1.5f;
	PdfStringFormat* format2 = new PdfStringFormat(PdfTextAlignment::Center, PdfVerticalAlignment::Middle);
	RectangleF* buttonBounds = new RectangleF(0, 200, buttonWidth, buttonHeight);

	//create a rectangle and draw text
	page->GetCanvas()->DrawRectangle(PdfBrushes::GetDarkGray(), buttonBounds);
	page->GetCanvas()->DrawString(L"To Last Page", buttonFont, PdfBrushes::GetCadetBlue(), buttonBounds, format2);

	//add the annotation
	PdfActionAnnotation* annotation = new PdfActionAnnotation(buttonBounds, action);
	annotation->SetBorder(new PdfAnnotationBorder(0.75f));
	annotation->SetColor(new PdfRGBColor(Color::GetLightGray()));
	PdfNewPage* newPage = Object::Convert<PdfNewPage>(page);
	newPage->GetAnnotations()->Add(annotation);
}
