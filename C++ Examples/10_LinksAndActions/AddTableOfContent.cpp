#include "pch.h"

#include "stringhelper.h"

using namespace Spire::Pdf;
using namespace std;

int main()
{
	wstring outputFile = OUTPUTPATH + L"AddTableOfContent.pdf";
	wstring inputFile = DATAPATH + L"AddTableOfContent.pdf";

	//open a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//get the page count
	int pageCount = doc->GetPages()->GetCount();

	//insert a blank page into the pdf document
	PdfPageBase* tocPage = doc->GetPages()->Insert(0);

	//set title
	std::wstring title = L"Table Of Contents";

	PdfTrueTypeFont* titleFont = new PdfTrueTypeFont(L"Arial", 20, PdfFontStyle::Bold, true);
	PdfStringFormat* centerAlignment = new PdfStringFormat(PdfTextAlignment::Center, PdfVerticalAlignment::Middle);
	PointF* location = new PointF(tocPage->GetCanvas()->GetClientSize()->GetWidth() / 2, titleFont->MeasureString(title.c_str())->GetHeight());
	tocPage->GetCanvas()->DrawString(title.c_str(), titleFont, PdfBrushes::GetCornflowerBlue(), location, centerAlignment);

	//draw TOC text
	PdfTrueTypeFont* titlesFont = new PdfTrueTypeFont(L"Arial", 14, PdfFontStyle::Regular, true);
	std::vector<std::wstring> titles(pageCount);
	for (int i = 0; i < titles.size(); i++)
	{
		titles[i] = StringHelper::formatSimple(L"This is page{0}", i + 1);
	}
	float y = titleFont->MeasureString(title.c_str())->GetHeight() + 10;
	float x = 0;

	for (int i = 1; i <= pageCount; i++)
	{
		std::wstring text = titles[i - 1];
		SizeF titleSize = titlesFont->MeasureString(text.c_str());

		PdfPageBase* navigatedPage = doc->GetPages()->GetItem(i);

		std::wstring pageNumText = std::to_wstring(i + 1);
		SizeF pageNumTextSize = titlesFont->MeasureString(pageNumText.c_str());
		tocPage->GetCanvas()->DrawString(text.c_str(), titlesFont, PdfBrushes::GetCadetBlue(), 0, y);
		float dotLocation = titleSize.GetWidth() + 2 + x;
		float pageNumlocation = tocPage->GetCanvas()->GetClientSize()->GetWidth() - pageNumTextSize.GetWidth();
		for (float j = dotLocation; j < pageNumlocation; j++)
		{
			if (dotLocation >= pageNumlocation)
			{
				break;
			}
			tocPage->GetCanvas()->DrawString(L".", titlesFont, PdfBrushes::GetGray(), dotLocation, y);
			dotLocation += 3;
		}
		tocPage->GetCanvas()->DrawString(pageNumText.c_str(), titlesFont, PdfBrushes::GetCadetBlue(), pageNumlocation, y);

		//add TOC action
		location = new PointF(0, y);
		RectangleF* titleBounds = new RectangleF(location, new SizeF(tocPage->GetCanvas()->GetClientSize()->GetWidth(), titleSize.GetHeight()));
		PdfDestination* Dest = new PdfDestination(navigatedPage, new PointF(-doc->GetPageSettings()->GetMargins()->GetTop(), -doc->GetPageSettings()->GetMargins()->GetLeft()));
		PdfGoToAction tempVar3(Dest);
		PdfActionAnnotation* action = new PdfActionAnnotation(titleBounds, &tempVar3);
		action->SetBorder(new PdfAnnotationBorder(0));
		PdfNewPage* newPage = Object::Convert<PdfNewPage>(tocPage);
		newPage->GetAnnotations()->Add(action);
		y += titleSize.GetHeight() + 10;

	}

	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();
	delete doc;
}
