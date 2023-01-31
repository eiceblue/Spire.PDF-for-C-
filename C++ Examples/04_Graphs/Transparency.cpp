#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring inputFile = DATAPATH+L"ChartImage.png";
	wstring outputFile = OUTPUTPATH+L"Transparency.pdf";

	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	//Create one section
	PdfSection* section = doc->GetSections()->Add();
	//Load an image
	PdfImage* image = PdfImage::FromFile(inputFile.c_str());
	float imageWidth = image->GetPhysicalDimension()->GetWidth() / 2;
	float imageHeight = image->GetPhysicalDimension()->GetHeight() / 2;

	enum PdfBlendMode mode;
	for (mode = PdfBlendMode::Normal; mode <= PdfBlendMode::Luminosity; mode = (PdfBlendMode)((int)mode + 1)) {
		PdfPageBase* page = section->GetPages()->Add();
		float pageWidth = page->GetCanvas()->GetClientSize()->GetWidth();
		float y = 0;
		//Title
		y += 15;
		PdfBrush* brush = new PdfSolidBrush(new PdfRGBColor(Spire::Common::Color::GetOrangeRed()));
		PdfTrueTypeFont* font = new PdfTrueTypeFont(L"Arial", 16.f, PdfFontStyle::Bold, true);
		PdfStringFormat* format = new PdfStringFormat(PdfTextAlignment::Center);
		wstring text = L"Transparency Blend Mode: ";
		text += StyleToStr(mode);
		//DrawImage
		page->GetCanvas()->DrawString(text.c_str(), font, brush, pageWidth / 2, y, format);
		SizeF* size = font->MeasureString(text.c_str(), format);
		y += size->GetHeight() + 25;
		page->GetCanvas()->DrawImage(image, 0, y, imageWidth, imageHeight);
		page->GetCanvas()->Save();
		float d = (page->GetCanvas()->GetClientSize()->GetWidth() - imageWidth) / 5;
		float x = d;
		y = y + d / 2 + 40;
		for (int i = 0; i < 5; i++) {
			float alpha = 1.0f / 6 * (5 - i);
			page->GetCanvas()->SetTransparency(alpha, alpha, mode);
			page->GetCanvas()->DrawImage(image, x, y, imageWidth, imageHeight);
			x = x + d;
			y = y + d / 2 + 40;
		}
		page->GetCanvas()->Restore();
	}
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete doc;
}
const wstring StyleToStr(PdfBlendMode mode) {
	switch (mode)
	{
	case Spire::Pdf::PdfBlendMode::Normal:
		return L"Normal";
		break;
	case Spire::Pdf::PdfBlendMode::Multiply:
		return L"Multiply";
		break;
	case Spire::Pdf::PdfBlendMode::Screen:
		return L"Screen";
		break;
	case Spire::Pdf::PdfBlendMode::Overlay:
		return L"Overlay";
		break;
	case Spire::Pdf::PdfBlendMode::Darken:
		return L"Darken";
		break;
	case Spire::Pdf::PdfBlendMode::Lighten:
		return L"Lighten";
		break;
	case Spire::Pdf::PdfBlendMode::ColorDodge:
		return L"ColorDodge";
		break;
	case Spire::Pdf::PdfBlendMode::ColorBurn:
		return L"ColorBurn";
		break;
	case Spire::Pdf::PdfBlendMode::HardLight:
		return L"HardLight";
		break;
	case Spire::Pdf::PdfBlendMode::SoftLight:
		return L"SoftLight";
		break;
	case Spire::Pdf::PdfBlendMode::Difference:
		return L"Difference";
		break;
	case Spire::Pdf::PdfBlendMode::Exclusion:
		return L"Exclusion";
		break;
	case Spire::Pdf::PdfBlendMode::Hue:
		return L"Hue";
		break;
	case Spire::Pdf::PdfBlendMode::Saturation:
		return L"Saturation";
		break;
	case Spire::Pdf::PdfBlendMode::Color:
		return L"Color";
		break;
	case Spire::Pdf::PdfBlendMode::Luminosity:
		return L"Luminosity";
		break;
	default:
		break;
	}
}

