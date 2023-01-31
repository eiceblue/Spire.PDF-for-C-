#include "pch.h"

using namespace std;
using namespace Spire::Pdf;

int main() {
	wstring fn1 = DATAPATH;
	wstring outputFile = OUTPUTPATH+L"DrawImage.pdf";

	//Create a pdf document
	PdfDocument* pdf = new PdfDocument();
	//Create one page
	PdfPageBase* page = new PdfPageBase();
	page = pdf->GetPages()->Add();

	//TransformText
	//Save graphics state
	PdfGraphicsState* state = page->GetCanvas()->Save();
	//Draw the text - transform
	PdfFont* font = new PdfFont(PdfFontFamily::Helvetica, 18.0f);
	PdfSolidBrush* brush1 = new PdfSolidBrush(new PdfRGBColor(Spire::Common::Color::GetBlue()));
	PdfSolidBrush* brush2 = new PdfSolidBrush(new PdfRGBColor(Spire::Common::Color::GetCadetBlue()));
	PdfStringFormat* format = new PdfStringFormat(Spire::Pdf::PdfTextAlignment::Center);
	page->GetCanvas()->TranslateTransform(page->GetCanvas()->GetClientSize()->GetWidth() / 2, 20);
	wstring s = L"Chart image";
	page->GetCanvas()->DrawString(s.c_str(), font, brush1, 0, 0, format);
	page->GetCanvas()->ScaleTransform(1.0f, -0.8f);
	page->GetCanvas()->DrawString(s.c_str(), font, brush2, 0, -2 * 18 * 1.2f, format);
	//Restore graphics
	page->GetCanvas()->Restore(state);

	//Draw_Image
	//Load an image
	PdfImage* image = new PdfImage();
	image = image->FromFile((fn1 + L"ChartImage.png").c_str());
	float width = image->GetWidth() * 0.75f;
	float height = image->GetHeight() * 0.75f;
	float x = (page->GetCanvas()->GetClientSize()->GetWidth() - width) / 2;
	//Draw the image
	page->GetCanvas()->DrawImage(image, x, 60, width, height);

	//TransformImage
	int skewX = 20;
	int skewY = 20;
	float scaleX = 0.2f;
	float scaleY = 0.6f;
	//PI 
	width = (float)((image->GetWidth() + image->GetHeight() * tan(PI * skewX / 180)) * scaleX);
	height = (float)((image->GetHeight() + image->GetWidth() * tan(PI * skewY / 180)) * scaleY);
	PdfTemplate* template1 = new PdfTemplate(width, height);
	template1->GetGraphics()->ScaleTransform(scaleX, scaleY);
	template1->GetGraphics()->SkewTransform(skewX, skewY);
	template1->GetGraphics()->DrawImage(image, 0.0f, 0.0f);
	//Save graphics state
	page->GetCanvas()->Save();
	page->GetCanvas()->TranslateTransform(page->GetCanvas()->GetClientSize()->GetWidth() - 50, 260);
	float offset = (page->GetCanvas()->GetClientSize()->GetWidth() - 100) / 12;
	for (int i = 0; i < 12; i++)
	{
		page->GetCanvas()->TranslateTransform(-offset, 0.0f);
		page->GetCanvas()->SetTransparency(i / 12.0f);
		page->GetCanvas()->DrawTemplate(template1, new PointF(0, 0));

	}
	//Restore graphics
	page->GetCanvas()->Restore(state);

	//Save the document
	pdf->SaveToFile(outputFile.c_str());

	pdf->Close();
	delete pdf;
}









