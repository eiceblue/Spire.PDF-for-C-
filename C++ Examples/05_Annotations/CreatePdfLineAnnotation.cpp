#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring outputFile = OUTPUTPATH+L"CreatePdfLineAnnotation.pdf";

	//Create a PDF document.
	PdfDocument* doc = new PdfDocument();
	//Add a new page.
	PdfPageBase* page = doc->GetPages()->Add();
	//Create a line annotation.
	int* linePoints = new int[] { 100, 650, 180, 650 };
	vector<int> vec;
	vec.insert(vec.begin(), linePoints, linePoints + 4);
	PdfLineAnnotation* lineAnnotation = new PdfLineAnnotation(vec, L"This is the first line annotation");
	//Set the line border.
	lineAnnotation->GetlineBorder()->SetBorderStyle(PdfBorderStyle::Solid);
	lineAnnotation->GetlineBorder()->SetBorderWidth(1);
	//Set the line intent.
	lineAnnotation->SetLineIntent(PdfLineIntent::LineDimension);
	lineAnnotation->SetBeginLineStyle(PdfLineEndingStyle::Butt);
	//Set the line style.
	lineAnnotation->SetEndLineStyle(PdfLineEndingStyle::Diamond);
	//Set the line flag.
	lineAnnotation->SetFlags(PdfAnnotationFlags::Default);
	//Set the line color.
	lineAnnotation->SetInnerLineColor(new PdfRGBColor(Spire::Common::Color::GetGreen()));
	lineAnnotation->SetBackColor(new PdfRGBColor(Spire::Common::Color::GetGreen()));
	//Set the leader line.
	lineAnnotation->SetLeaderLineExt(0);
	lineAnnotation->SetLeaderLine(0);
	//Add the line annotation to the page.
	page->GetAnnotationsWidget()->Add(lineAnnotation);

	linePoints = new int[] { 100, 550, 280, 550 };
	vector<int> vec1(linePoints, linePoints + sizeof(linePoints));
	lineAnnotation = new PdfLineAnnotation(vec1, L"This is the second line annotation");
	lineAnnotation->GetlineBorder()->SetBorderStyle(PdfBorderStyle::Underline);
	lineAnnotation->GetlineBorder()->SetBorderWidth(2);
	lineAnnotation->SetLineIntent(PdfLineIntent::LineArrow);
	lineAnnotation->SetBeginLineStyle(PdfLineEndingStyle::Circle);
	lineAnnotation->SetEndLineStyle(PdfLineEndingStyle::Diamond);
	lineAnnotation->SetFlags(PdfAnnotationFlags::Default);
	lineAnnotation->SetInnerLineColor(new PdfRGBColor(Spire::Common::Color::GetPink()));
	lineAnnotation->SetBackColor(new PdfRGBColor(Spire::Common::Color::GetPink()));
	lineAnnotation->SetLeaderLineExt(0);
	lineAnnotation->SetLeaderLine(0);
	page->GetAnnotationsWidget()->Add(lineAnnotation);

	linePoints = new int[] { 100, 450, 280, 450 };
	vector<int> vec2(linePoints, linePoints + sizeof(linePoints));
	lineAnnotation = new PdfLineAnnotation(vec2, L"This is the third line annotation");
	lineAnnotation->GetlineBorder()->SetBorderStyle(PdfBorderStyle::Beveled);
	lineAnnotation->GetlineBorder()->SetBorderWidth(2);
	lineAnnotation->SetLineIntent(PdfLineIntent::LineDimension);
	lineAnnotation->SetBeginLineStyle(PdfLineEndingStyle::None);
	lineAnnotation->SetEndLineStyle(PdfLineEndingStyle::None);
	lineAnnotation->SetFlags(PdfAnnotationFlags::Default);
	lineAnnotation->SetInnerLineColor(new PdfRGBColor(Spire::Common::Color::GetBlue()));
	lineAnnotation->SetBackColor(new PdfRGBColor(Spire::Common::Color::GetBlue()));
	lineAnnotation->SetLeaderLineExt(1);
	lineAnnotation->SetLeaderLine(1);
	page->GetAnnotationsWidget()->Add(lineAnnotation);

	//Save the document
	doc->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	doc->Close();

	delete doc;
}


