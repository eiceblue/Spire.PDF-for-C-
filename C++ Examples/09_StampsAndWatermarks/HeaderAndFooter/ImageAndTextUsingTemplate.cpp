#include "pch.h"

using namespace std;
using namespace Spire::Pdf;
using namespace Spire::Common;

int main()
{
	wstring outputFile = OUTPUTPATH + L"ImageAndTextUsingTemplate.pdf";
	wstring inputFile = DATAPATH + L"PDFTemplate_HF.pdf";

	//Load the Pdf from disk
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//Get the first page
	PdfPageBase* page = doc->GetPages()->GetItem(0);

	//Get the margins of Pdf
	PdfMargins* margin = doc->GetPageSettings()->GetMargins();

	//Define font and brush
	LPCWSTR_S impact = L"Impact";
	PdfTrueTypeFont* font = new PdfTrueTypeFont(new Font(impact, 14.f, FontStyle::Regular));
	PdfSolidBrush* brush = new PdfSolidBrush(new PdfRGBColor(Color::GetGray()));

	//Load an image
	wstring inputFile1 = DATAPATH + L"E-iceblueLogo.png";
	PdfImage* image = PdfImage::FromFile(inputFile1.c_str());

	//Specify the image size
	SizeF* imageSize = new SizeF(image->GetWidth() / 2, image->GetHeight() / 2);

	//Create a header template
	PdfTemplate* headerTemplate = new PdfTemplate(page->GetActualSize()->GetWidth() - margin->GetLeft() - margin->GetRight(), imageSize->GetHeight());

	//Draw the image in the template
	headerTemplate->GetGraphics()->DrawImage(image, new PointF(0, 0), imageSize);

	//Create a retangle
	RectangleF* rect = headerTemplate->GetBounds();

	//string format
	PdfStringFormat* format1 = new PdfStringFormat(PdfTextAlignment::Right, PdfVerticalAlignment::Middle);

	//Draw a string in the template
	headerTemplate->GetGraphics()->DrawString(L"Header", font, brush, rect, format1);

	//Create a footer template and draw a text
	PdfTemplate* footerTemplate = new PdfTemplate(page->GetActualSize()->GetWidth() - margin->GetLeft() - margin->GetRight(), imageSize->GetHeight());
	PdfStringFormat* format2 = new PdfStringFormat(PdfTextAlignment::Center, PdfVerticalAlignment::Middle);
	footerTemplate->GetGraphics()->DrawString(L"Footer", font, brush, rect, format2);

	float x = margin->GetLeft();
	float y = 0;

	//Draw the header template on page at specified location
	page->GetCanvas()->DrawTemplate(headerTemplate, new PointF(x, y));

	//Draw the footer template on page at specified location
	y = page->GetActualSize()->GetHeight() - footerTemplate->GetHeight() - 10;
	page->GetCanvas()->DrawTemplate(footerTemplate, new PointF(x, y));


	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();
	delete doc;
}
