#include "pch.h"

#include "stringhelper.h"

using namespace Spire::Pdf;
using namespace std;

int main()
{
	wstring outputFile = OUTPUTPATH + L"AutomaticField.pdf";
	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->GetDocumentInformation()->SetAuthor(L"Spire.Pdf");

	//Set the margin
	PdfUnitConvertor* unitCvtr = new PdfUnitConvertor();
	PdfMargins* margin = new PdfMargins();
	margin->SetTop(unitCvtr->ConvertUnits(2.54f, PdfGraphicsUnit::Centimeter, PdfGraphicsUnit::Point));
	margin->SetBottom(margin->GetTop());
	margin->SetLeft(unitCvtr->ConvertUnits(3.17f, PdfGraphicsUnit::Centimeter, PdfGraphicsUnit::Point));
	margin->SetRight(margin->GetLeft());

	//Create section
	PdfSection* section = doc->GetSections()->Add();
	section->GetPageSettings()->SetSize(PdfPageSize::A4());
	section->GetPageSettings()->SetMargins(margin);

	//Create one page
	PdfPageBase* page = section->GetPages()->Add();

	//Draw automatic fields
	DrawAutomaticField(page);

	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();
	delete unitCvtr;
	delete doc;
}

void DrawAutomaticField(PdfPageBase* page) {

	float y = 20;

	//Title
	PdfBrush* brush1 = PdfBrushes::GetCadetBlue();

	PdfTrueTypeFont* font1 = new PdfTrueTypeFont(L"Arial", 16.0f, PdfFontStyle::Bold, true);

	PdfStringFormat* format1 = new PdfStringFormat(PdfTextAlignment::Center);
	page->GetCanvas()->DrawString(L"Automatic Field List", font1, brush1, page->GetCanvas()->GetClientSize()->GetWidth() / 2, y, format1);
	y = y + font1->MeasureString(L"Automatic Field List", format1)->GetHeight();
	y = y + 15;

	std::vector<std::wstring> fieldList = { L"DateTimeField", L"CreationDateField", L"DocumentAuthorField", L"SectionNumberField", L"SectionPageNumberField", L"SectionPageCountField", L"PageNumberField", L"PageCountField", L"DestinationPageNumberField", L"CompositeField" };


	PdfTrueTypeFont* font = new PdfTrueTypeFont(L"Arial", 12.0f, PdfFontStyle::Regular, true);

	PdfStringFormat* fieldNameFormat = new PdfStringFormat();
	fieldNameFormat->SetMeasureTrailingSpaces(true);
	for (auto fieldName : fieldList)
	{
		//Draw field name
		std::wstring text = StringHelper::formatSimple(L"{0}: ", fieldName);
		page->GetCanvas()->DrawString(text.c_str(), font, PdfBrushes::GetDodgerBlue(), 0, y);
		float x = font->MeasureString(text.c_str(), fieldNameFormat)->GetWidth();
		RectangleF* bounds = new RectangleF(x, y, 200, font->GetHeight());
		DrawAutomaticField(fieldName, page, bounds);
		y = y + font->GetHeight() + 8;
	}
}

void DrawAutomaticField(const std::wstring& fieldName, PdfPageBase* page, RectangleF* bounds)
{

	PdfTrueTypeFont* font = new PdfTrueTypeFont(L"Arial", 12.0f, PdfFontStyle::Italic, true);
	PdfBrush* brush = PdfBrushes::GetOrangeRed();
	PdfStringFormat* format = new PdfStringFormat(PdfTextAlignment::Left, PdfVerticalAlignment::Middle);

	if (L"DateTimeField" == fieldName)
	{
		PdfDateTimeField* field = new PdfDateTimeField();
		field->SetFont(font);
		field->SetBrush(brush);
		field->SetStringFormat(format);
		field->SetBounds(bounds);
		field->SetDateFormatString(L"yyyy-MM-dd HH:mm:ss");
		dynamic_cast<PdfGraphicsWidget*>(field)->Draw(page->GetCanvas());

		delete field;
	}

	if (L"CreationDateField" == fieldName)
	{
		PdfCreationDateField* field = new PdfCreationDateField();
		field->SetFont(font);
		field->SetBrush(brush);
		field->SetStringFormat(format);
		field->SetBounds(bounds);
		field->SetDateFormatString(L"yyyy-MM-dd HH:mm:ss");
		dynamic_cast<PdfGraphicsWidget*>(field)->Draw(page->GetCanvas());

		delete field;
	}

	if (L"DocumentAuthorField" == fieldName)
	{
		PdfDocumentAuthorField* field = new PdfDocumentAuthorField();
		field->SetFont(font);
		field->SetBrush(brush);
		field->SetStringFormat(format);
		field->SetBounds(bounds);
		dynamic_cast<PdfGraphicsWidget*>(field)->Draw(page->GetCanvas());

		delete field;
	}


	if (L"SectionNumberField" == fieldName)
	{
		PdfSectionNumberField* field = new PdfSectionNumberField();
		field->SetFont(font);
		field->SetBrush(brush);
		field->SetStringFormat(format);
		field->SetBounds(bounds);
		dynamic_cast<PdfGraphicsWidget*>(field)->Draw(page->GetCanvas());

		delete field;
	}

	if (L"SectionPageNumberField" == fieldName)
	{
		PdfSectionPageNumberField* field = new PdfSectionPageNumberField();
		field->SetFont(font);
		field->SetBrush(brush);
		field->SetStringFormat(format);
		field->SetBounds(bounds);
		dynamic_cast<PdfGraphicsWidget*>(field)->Draw(page->GetCanvas());
		delete field;
	}

	if (L"SectionPageCountField" == fieldName)
	{
		PdfSectionPageCountField* field = new PdfSectionPageCountField();
		field->SetFont(font);
		field->SetBrush(brush);
		field->SetStringFormat(format);
		field->SetBounds(bounds);
		dynamic_cast<PdfGraphicsWidget*>(field)->Draw(page->GetCanvas());

		delete field;
	}

	if (L"PageNumberField" == fieldName)
	{
		PdfPageNumberField* field = new PdfPageNumberField();
		field->SetFont(font);
		field->SetBrush(brush);
		field->SetStringFormat(format);
		field->SetBounds(bounds);
		dynamic_cast<PdfGraphicsWidget*>(field)->Draw(page->GetCanvas());

		delete field;
	}

	if (L"PageCountField" == fieldName)
	{
		PdfPageCountField* field = new PdfPageCountField();
		field->SetFont(font);
		field->SetBrush(brush);
		field->SetStringFormat(format);
		field->SetBounds(bounds);
		dynamic_cast<PdfGraphicsWidget*>(field)->Draw(page->GetCanvas());

		delete field;
	}

	if (L"DestinationPageNumberField" == fieldName)
	{
		PdfDestinationPageNumberField* field = new PdfDestinationPageNumberField();
		field->SetFont(font);
		field->SetBrush(brush);
		field->SetStringFormat(format);
		field->SetBounds(bounds);
		field->SetPage(dynamic_cast<PdfNewPage*>(page));
		dynamic_cast<PdfGraphicsWidget*>(field)->Draw(page->GetCanvas());

		delete field;
	}

	if (L"CompositeField" == fieldName)
	{
		PdfSectionPageNumberField* field1 = new PdfSectionPageNumberField();
		field1->SetNumberStyle(PdfNumberStyle::LowerRoman);
		PdfSectionPageCountField* field2 = new PdfSectionPageCountField();
		PdfCompositeField* fields = new PdfCompositeField();
		fields->SetFont(font);
		fields->SetBrush(brush);
		fields->SetStringFormat(format);
		fields->SetBounds(bounds);
		fields->SetAutomaticFields({ field1, field2 });
		fields->SetText(L"section page {0} of {1}");
		dynamic_cast<PdfGraphicsWidget*>(fields)->Draw(page->GetCanvas());

		delete fields;
		delete field2;
		delete field1;
	}
}
		
