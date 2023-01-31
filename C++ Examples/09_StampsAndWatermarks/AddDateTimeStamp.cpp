#include "pch.h"

using namespace std;
using namespace Spire::Pdf;
using namespace Spire::Common;

int main()
{
	wstring outputFile = OUTPUTPATH + L"AddDateTimeStamp.pdf";
	wstring inputFile = DATAPATH + L"PDFTemplate_N.pdf";

	//Load the Pdf from disk
	PdfDocument* document = new PdfDocument();
	document->LoadFromFile(inputFile.c_str());

	//Get the first page
	PdfPageBase* page = document->GetPages()->GetItem(0);

	//Set the font and brush
	LPCWSTR_S arial = L"Arial";
	PdfTrueTypeFont* font = new PdfTrueTypeFont(new Font(arial, 12.f, FontStyle::Regular), true);

	PdfSolidBrush* brush = new PdfSolidBrush(new PdfRGBColor(Color::GetBlue()));

	//Time text
	LPCWSTR_S t = L"MM/dd/yy hh:mm:ss tt";
	wstring timeString = DateTime::GetNow()->ToString(t);

	//Create a template and rectangle, draw the string
	PdfTemplate* template1 = new PdfTemplate(140, 15);
	RectangleF* rect = new RectangleF(new PointF(page->GetActualSize()->GetWidth() - template1->GetWidth() - 10,
		page->GetActualSize()->GetHeight() - template1->GetHeight() - 10), template1->GetSize());
	template1->GetGraphics()->DrawString(timeString.c_str(), font, brush, new PointF(0, 0));

	//Create stamp annoation
	PdfRubberStampAnnotation* stamp = new PdfRubberStampAnnotation(rect);
	PdfAppearance* apprearance = new PdfAppearance(stamp);
	apprearance->SetNormal(template1);
	stamp->SetAppearance(apprearance);
	page->GetAnnotationsWidget()->Add(stamp);

	//Save the document
	document->SaveToFile(outputFile.c_str());
	document->Close();
	delete document;
}