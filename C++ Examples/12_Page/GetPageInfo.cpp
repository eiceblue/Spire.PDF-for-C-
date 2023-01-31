#include "pch.h"
#include "stringbuilder.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main(){
	wstring outputFile = OUTPUTPATH+L"GetPageInfo.txt";
	wstring inputFile = DATAPATH+L"GetPageInfo.pdf";
	
	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());

	//Get the first page of the loaded PDF file
	PdfPageBase* page = doc->GetPages()->GetItem(0);

	//Get the size of page MediaBox based on "point"
	float MediaBoxWidth = page->GetMediaBox()->GetWidth();
	float MediaBoxHeight = page->GetMediaBox()->GetHeight();
	float MediaBoxX = page->GetMediaBox()->GetX();
	float MediaBoxY = page->GetMediaBox()->GetY();

	//Get the size of page BleedBox based on "point"
	float BleedBoxWidth = page->GetBleedBox()->GetWidth();
	float BleedBoxHeight = page->GetBleedBox()->GetHeight();
	float BleedBoxX = page->GetBleedBox()->GetX();
	float BleedBoxY = page->GetBleedBox()->GetY();

	//Get the size of page CropBox based on "point"
	float CropBoxWidth = page->GetCropBox()->GetWidth();
	float CropBoxHeight = page->GetCropBox()->GetHeight();
	float CropBoxX = page->GetCropBox()->GetX();
	float CropBoxY = page->GetCropBox()->GetY();

	//Get the size of page ArtBox based on "point"
	float ArtBoxWidth = page->GetArtBox()->GetWidth();
	float ArtBoxHeight = page->GetArtBox()->GetHeight();;
	float ArtBoxX = page->GetArtBox()->GetX();
	float ArtBoxY = page->GetArtBox()->GetY();

	//Get the size of page TrimBox based on "point"
	float TrimBoxWidth = page->GetTrimBox()->GetWidth();
	float TrimBoxHeight = page->GetArtBox()->GetHeight();
	float TrimBoxX = page->GetTrimBox()->GetX();
	float TrimBoxY = page->GetTrimBox()->GetY();

	//Get the actual size of page
	float actualSizeW = page->GetActualSize()->GetWidth();
	float actualSizeH = page->GetActualSize()->GetHeight();

	//Gets the rotation angle of the current page
	PdfPageRotateAngle rotationAngle = page->GetRotation();
	std::wstring rotation = std::to_wstring(static_cast<int>(rotationAngle));

	//Create StringBuilder to save 
	StringBuilder* content = new StringBuilder();

	//Add page information string to StringBuilder
	content->appendLine(L"MediaBox width: " + std::to_wstring(MediaBoxWidth) + L"pt, height: " + std::to_wstring(MediaBoxHeight) + L"pt, RectangleF X: " + std::to_wstring(MediaBoxX) + L"pt, RectangleF Y: " + std::to_wstring(MediaBoxY) + L"pt.");
	content->appendLine(L"BleedBox width: " + std::to_wstring(BleedBoxWidth) + L"pt,  height: " + std::to_wstring(BleedBoxHeight) + L"pt, RectangleF X: " + std::to_wstring(BleedBoxX) + L"pt, RectangleF Y: " + std::to_wstring(BleedBoxY) + L"pt.");
	content->appendLine(L"CropBox width: " + std::to_wstring(CropBoxWidth) + L"pt,  height: " + std::to_wstring(CropBoxHeight) + L"pt, RectangleF X: " + std::to_wstring(CropBoxX) + L"pt, RectangleF Y: " + std::to_wstring(CropBoxY) + L"pt.");
	content->appendLine(L"ArtBox width: " + std::to_wstring(ArtBoxWidth) + L"pt,  height: " + std::to_wstring(ArtBoxHeight) + L"pt, RectangleF X: " + std::to_wstring(ArtBoxX) + L"pt, RectangleF Y: " + std::to_wstring(ArtBoxY) + L"pt.");
	content->appendLine(L"TrimBox width: " + std::to_wstring(TrimBoxWidth) + L"pt,  height: " + std::to_wstring(TrimBoxHeight) + L"pt, RectangleF X: " + std::to_wstring(TrimBoxX) + L"pt, RectangleF Y: " + std::to_wstring(TrimBoxY) + L"pt.");
	content->appendLine(L"The actual size of the current page width: " + std::to_wstring(actualSizeW));
	content->appendLine(L"The actual size of the current page height: " + std::to_wstring(actualSizeH));
	content->appendLine(L"The rotation angle of the current page: " + rotation);

	wofstream os;
	os.open(outputFile, ios::trunc);
	os << content->toString();
	os.close();

	delete content;
	delete doc;
}
