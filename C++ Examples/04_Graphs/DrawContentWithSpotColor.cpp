#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring outputFile = OUTPUTPATH +L"DrawContentWithSpotColor.pdf";

	wstring inputFile = DATAPATH+L"DrawContentWithSpotColor.pdf";
	//Load the document from disk
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//Get the first page
	PdfPageBase* page = doc->GetPages()->GetItem(0);
	//Initialize an instance of PdfSeparationColorSpace
	PdfSeparationColorSpace* cs = new PdfSeparationColorSpace(L"MySpotColor", new PdfRGBColor(Spire::Common::Color::GetDarkViolet()));
	//Set tini = 1 for the cs
	PdfSeparationColor* color = new PdfSeparationColor(cs, 1.f);
	//Create a brush with spot color
	PdfSolidBrush* brush = new PdfSolidBrush(color);

	//Draw a string
	page->GetCanvas()->DrawString(L"Tint=1.0", new PdfFont(PdfFontFamily::Helvetica, 10.f), brush, new PointF(160, 160));
	//Draw pie with spot color(DarkViolet)
	page->GetCanvas()->DrawPie(brush, 148, 200, 60, 60, 360, 360);
	
	page->GetCanvas()->DrawString(L"Tint=0.7", new PdfFont(PdfFontFamily::Helvetica, 10.f), brush, new PointF(230, 160));
	color = new PdfSeparationColor(cs, 0.7f);
	brush = new PdfSolidBrush(color);
	page->GetCanvas()->DrawPie(brush, 218, 200, 60, 60, 360, 360);

	page->GetCanvas()->DrawString(L"Tint=0.4", new PdfFont(PdfFontFamily::Helvetica, 10.f), brush, new PointF(300, 160));
	color = new PdfSeparationColor(cs, 0.4f);
	brush = new PdfSolidBrush(color);
	page->GetCanvas()->DrawPie(brush, 288, 200, 60, 60, 360, 360);

	page->GetCanvas()->DrawString(L"Tint=0.1", new PdfFont(PdfFontFamily::Helvetica, 10.f), brush, new PointF(370, 160));
	color = new PdfSeparationColor(cs, 0.1f);
	brush = new PdfSolidBrush(color);
	page->GetCanvas()->DrawPie(brush, 358, 200, 60, 60, 360, 360);

	//Draw pie with spot color(Purple)
	cs = new PdfSeparationColorSpace(L"MySpotColor", new PdfRGBColor(Spire::Common::Color::GetPurple()));
	color = new PdfSeparationColor(cs, 1.f);
	brush = new PdfSolidBrush(color);
	page->GetCanvas()->DrawPie(brush, 148, 280, 60, 60, 360, 360);

	color = new PdfSeparationColor(cs, 0.7f);
	brush = new PdfSolidBrush(color);
	page->GetCanvas()->DrawPie(brush, 218, 280, 60, 60, 360, 360);

	color = new PdfSeparationColor(cs, 0.4f);
	brush = new PdfSolidBrush(color);
	page->GetCanvas()->DrawPie(brush, 288, 280, 60, 60, 360, 360);

	color = new PdfSeparationColor(cs, 0.1f);
	brush = new PdfSolidBrush(color);
	page->GetCanvas()->DrawPie(brush, 358, 280, 60, 60, 360, 360);

	//Draw pie with spot color(DarkSlateBlue)
	cs = new PdfSeparationColorSpace(L"MySpotColor", new PdfRGBColor(Spire::Common::Color::GetDarkSlateBlue()));
	color = new PdfSeparationColor(cs, 1.f);
	brush = new PdfSolidBrush(color);
	page->GetCanvas()->DrawPie(brush, 148, 280, 60, 60, 360, 360);

	color = new PdfSeparationColor(cs, 0.7f);
	brush = new PdfSolidBrush(color);
	page->GetCanvas()->DrawPie(brush, 218, 280, 60, 60, 360, 360);

	color = new PdfSeparationColor(cs, 0.4f);
	brush = new PdfSolidBrush(color);
	page->GetCanvas()->DrawPie(brush, 288, 280, 60, 60, 360, 360);

	color = new PdfSeparationColor(cs, 0.1f);
	brush = new PdfSolidBrush(color);
	page->GetCanvas()->DrawPie(brush, 358, 280, 60, 60, 360, 360);

	//Save the document
	doc->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	doc->Close();

	delete doc;
}


