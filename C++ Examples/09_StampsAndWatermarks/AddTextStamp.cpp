#include "pch.h"

using namespace std;
using namespace Spire::Pdf;
using namespace Spire::Common;

int main()
{
	wstring outputFile = OUTPUTPATH + L"AddTextStamp.pdf";
	wstring inputFile = DATAPATH + L"AddTextStamp.pdf";

	//Load the Pdf from disk
	PdfDocument* document = new PdfDocument();
	document->LoadFromFile(inputFile.c_str());

	//Get the first page
	PdfPageBase* page = document->GetPages()->GetItem(0);

	//Create a pdf template
	PdfTemplate* template_Keyword = new PdfTemplate(125, 55);
	LPCWSTR_S ele = L"Elephant";
	PdfTrueTypeFont* font1 = new PdfTrueTypeFont(new Font(ele, 10.f, FontStyle::Italic), true);
	PdfSolidBrush* brush = new PdfSolidBrush(new PdfRGBColor(Color::GetDarkRed()));
	PdfPen* pen = new PdfPen(brush);
	RectangleF* rectangle = new RectangleF(new PointF(5, 5), template_Keyword->GetSize());
	int CornerRadius = 20;
	PdfPath* path = new PdfPath();
	path->AddArc(template_Keyword->GetBounds()->GetX(), template_Keyword->GetBounds()->GetY(), CornerRadius, CornerRadius, 180, 90);
	path->AddArc(template_Keyword->GetBounds()->GetX() + template_Keyword->GetWidth() - CornerRadius, template_Keyword->GetBounds()->GetY(), CornerRadius, CornerRadius, 270, 90);
	path->AddArc(template_Keyword->GetBounds()->GetX() + template_Keyword->GetWidth() - CornerRadius, template_Keyword->GetBounds()->GetY() + template_Keyword->GetHeight() - CornerRadius, CornerRadius, CornerRadius, 0, 90);
	path->AddArc(template_Keyword->GetBounds()->GetX(), template_Keyword->GetBounds()->GetY() + template_Keyword->GetHeight() - CornerRadius, CornerRadius, CornerRadius, 90, 90);
	path->AddLine(template_Keyword->GetBounds()->GetX(), template_Keyword->GetBounds()->GetY() + template_Keyword->GetHeight() - CornerRadius, template_Keyword->GetBounds()->GetX(), template_Keyword->GetBounds()->GetY() + CornerRadius / 2);
	template_Keyword->GetGraphics()->DrawPath(pen, path);

	//Draw stamp text
	std::wstring s1 = L"REVISED\n";
	LPCWSTR_S t = L"MM dd, yyyy";
	wstring timeString = DateTime::GetNow()->ToString(t);
	wstring s2 = L"by E-iceblue at " + timeString;
	template_Keyword->GetGraphics()->DrawString(s1.c_str(), font1, brush, new PointF(5, 10));
	LPCWSTR_S luc = L"Lucida Sans Unicod";
	PdfTrueTypeFont* font2 = new PdfTrueTypeFont(new Font(luc, 9.f, FontStyle::Bold), true);

	template_Keyword->GetGraphics()->DrawString(s2.c_str(), font2, brush, new PointF(2, 30));

	//Create a rubber stamp
	PdfRubberStampAnnotation* stamp = new PdfRubberStampAnnotation(rectangle);
	PdfAppearance* apprearance = new PdfAppearance(stamp);
	apprearance->SetNormal(template_Keyword);
	stamp->SetAppearance(apprearance);

	//Draw stamp into page
	page->GetAnnotationsWidget()->Add(stamp);

	//Save the document
	document->SaveToFile(outputFile.c_str());
	document->Close();
	delete document;
}
