#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring outputFile = OUTPUTPATH+L"Barcode.pdf";

	//Create a pdf document.
	PdfDocument* doc = new PdfDocument();
	PdfUnitConvertor* unitCvtr = new PdfUnitConvertor();
	//Set the margin
	PdfMargins* margin = new PdfMargins();
	margin->SetTop(unitCvtr->ConvertUnits(2.54f, PdfGraphicsUnit::Centimeter, PdfGraphicsUnit::Point));
	margin->SetBottom(margin->GetTop());
	margin->SetLeft(unitCvtr->ConvertUnits(3.17f, PdfGraphicsUnit::Centimeter, PdfGraphicsUnit::Point));
	margin->SetRight(margin->GetLeft());
	PdfSection* section = doc->GetSections()->Add();
	section->GetPageSettings()->SetMargins(margin);
	section->GetPageSettings()->SetSize(new SizeF(PdfPageSize::A4()));
	//Create one page
	PdfPageBase* page = section->GetPages()->Add();
	float y = 10;
	PdfBrush* brush1 = PdfBrushes::GetBlack();
	PdfTrueTypeFont* font1 = new PdfTrueTypeFont(L"Arial", 12.f, PdfFontStyle::Bold, true);
	RectangleF* rctg = new RectangleF(new PointF(0, 0), page->GetCanvas()->GetClientSize());
	PdfLinearGradientBrush* brush2
		= new PdfLinearGradientBrush(rctg, new PdfRGBColor(Spire::Common::Color::GetNavy()), new PdfRGBColor(Spire::Common::Color::GetOrangeRed()), PdfLinearGradientMode::Vertical);

	//draw codabar
	PdfTextWidget* text = new PdfTextWidget();
	text->SetFont(font1);
	text->SetText(L"Codabar:");
	PdfLayoutResult* result = ((PdfLayoutWidget*)text)->Draw(page, 0.f, y);
	page = result->GetPage();
	y = result->GetBounds()->GetBottom() + 2;
	PdfCodabarBarcode* barcode1 = new PdfCodabarBarcode(L"00:12-3456/7890");
	barcode1->SetBarcodeToTextGapHeight(1.f);
	barcode1->SetEnableCheckDigit(true);
	barcode1->SetShowCheckDigit(true);
	barcode1->SetTextDisplayLocation(TextLocation::Bottom);
	barcode1->SetTextColor(new PdfRGBColor(Spire::Common::Color::GetBlue()));
	barcode1->Draw(page, new PointF(0, y));
	y = barcode1->GetBounds()->GetBottom() + 5;

	//draw code11Barciode
	text->SetText(L"Code11:");
	result = ((PdfLayoutWidget*)text)->Draw(page, 0.f, y);
	page = result->GetPage();
	y = result->GetBounds()->GetBottom() + 2;
	PdfCode11Barcode* barcode2 = new PdfCode11Barcode(L"123-4567890");
	barcode2->SetBarcodeToTextGapHeight(1.f);
	barcode2->SetTextDisplayLocation(TextLocation::Bottom);
	barcode2->SetTextColor(new PdfRGBColor(Spire::Common::Color::GetBlue()));
	barcode2->Draw(page, new PointF(0, y));
	y = barcode2->GetBounds()->GetBottom() + 5;

	//draw code128-A
	text->SetText(L"Code128-A:");
	result = ((PdfLayoutWidget*)text)->Draw(page, 0.f, y);
	page = result->GetPage();
	y = result->GetBounds()->GetBottom() + 2;
	PdfCode128ABarcode* barcode3 = new PdfCode128ABarcode(L"HELLO 00-123");
	barcode3->SetBarcodeToTextGapHeight(1.f);
	barcode3->SetTextDisplayLocation(TextLocation::Bottom);
	barcode3->SetTextColor(new PdfRGBColor(Spire::Common::Color::GetBlue()));
	barcode3->Draw(page, new PointF(0, y));
	y = barcode3->GetBounds()->GetBottom() + 5;

	//draw code128-B
	text->SetText(L"Code128-B:");
	result = ((PdfLayoutWidget*)text)->Draw(page, 0.f, y);
	page = result->GetPage();
	y = result->GetBounds()->GetBottom() + 2;
	PdfCode128BBarcode* barcode4 = new PdfCode128BBarcode(L"Hello 00-123");
	barcode4->SetBarcodeToTextGapHeight(1.f);
	barcode4->SetTextDisplayLocation(TextLocation::Bottom);
	barcode4->SetTextColor(new PdfRGBColor(Spire::Common::Color::GetBlue()));
	barcode4->Draw(page, new PointF(0, y));
	y = barcode4->GetBounds()->GetBottom() + 5;

	//draw code32
	text->SetText(L"Code32:");
	result = ((PdfLayoutWidget*)text)->Draw(page, 0.f, y);
	page = result->GetPage();
	y = result->GetBounds()->GetBottom() + 2;
	PdfCode32Barcode* barcode5 = new PdfCode32Barcode(L"16273849");
	barcode5->SetBarcodeToTextGapHeight(1.f);
	barcode5->SetTextDisplayLocation(TextLocation::Bottom);
	barcode5->SetTextColor(new PdfRGBColor(Spire::Common::Color::GetBlue()));
	barcode5->Draw(page, new PointF(0, y));
	y = barcode5->GetBounds()->GetBottom() + 5;

	page = section->GetPages()->Add();
	y = 10;
	//draw code39
	text->SetText(L"Code39:");
	result = ((PdfLayoutWidget*)text)->Draw(page, 0.f, y);
	page = result->GetPage();
	y = result->GetBounds()->GetBottom() + 2;
	PdfCode39Barcode* barcode6 = new PdfCode39Barcode(L"16-273849");
	barcode6->SetBarcodeToTextGapHeight(1.f);
	barcode6->SetTextDisplayLocation(TextLocation::Bottom);
	barcode6->SetTextColor(new PdfRGBColor(Spire::Common::Color::GetBlue()));
	barcode6->Draw(page, new PointF(0, y));
	y = barcode6->GetBounds()->GetBottom() + 5;

	//draw code39-E
	text->SetText(L"Code39-E:");
	result = ((PdfLayoutWidget*)text)->Draw(page, 0.f, y);
	page = result->GetPage();
	y = result->GetBounds()->GetBottom() + 2;
	PdfCode39ExtendedBarcode* barcode7 = new PdfCode39ExtendedBarcode(L"16-273849");
	barcode7->SetBarcodeToTextGapHeight(1.f);
	barcode7->SetTextDisplayLocation(TextLocation::Bottom);
	barcode7->SetTextColor(new PdfRGBColor(Spire::Common::Color::GetBlue()));
	barcode7->Draw(page, new PointF(0, y));
	y = barcode7->GetBounds()->GetBottom() + 5;

	//draw code93
	text->SetText(L"Code93:");
	result = ((PdfLayoutWidget*)text)->Draw(page, 0.f, y);
	page = result->GetPage();
	y = result->GetBounds()->GetBottom() + 2;
	PdfCode93Barcode* barcode8 = new PdfCode93Barcode(L"16-273849");
	barcode8->SetBarcodeToTextGapHeight(1.f);
	barcode8->SetTextDisplayLocation(TextLocation::Bottom);
	barcode8->SetTextColor(new PdfRGBColor(Spire::Common::Color::GetBlue()));
	barcode8->GetQuietZone()->SetBottom(5.f);
	barcode8->Draw(page, new PointF(0, y));
	y = barcode8->GetBounds()->GetBottom() + 5;

	//draw code93-E
	text->SetText(L"Code93-E:");
	result = ((PdfLayoutWidget*)text)->Draw(page, 0.f, y);
	page = result->GetPage();
	y = result->GetBounds()->GetBottom() + 2;
	PdfCode93ExtendedBarcode* barcode9 = new PdfCode93ExtendedBarcode(L"16-273849");
	barcode9->SetBarcodeToTextGapHeight(1.f);
	barcode9->SetTextDisplayLocation(TextLocation::Bottom);
	barcode9->SetTextColor(new PdfRGBColor(Spire::Common::Color::GetBlue()));
	barcode9->Draw(page, new PointF(0, y));
	y = barcode9->GetBounds()->GetBottom() + 5;

	doc->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	doc->Close();

	delete barcode9;
	delete barcode8;
	delete barcode7;
	delete barcode6;
	delete barcode5;
	delete barcode4;
	delete barcode3;
	delete barcode2;
	delete barcode1;
	delete text;
	delete brush2;
	delete unitCvtr;
	delete doc;
}

