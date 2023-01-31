#include "pch.h"

using namespace std;
using namespace Spire::Pdf;

int main() {
	wstring inputFile = DATAPATH+L"ReplaceImage.pdf";
	wstring outputFile = OUTPUTPATH+L"ReplaceImageWithText.pdf";

	//Create a pdf document
	PdfDocument* pdf = new PdfDocument();
	pdf->LoadFromFile(inputFile.c_str());
	//Get the first page.
	PdfPageBase* page = pdf->GetPages()->GetItem(0);
	//Get images of the first page.
	std::vector<PdfImageInfo*> imageInfo = page->GetImagesInfo();

	//Get width and height of image
	Stream* imgStream = imageInfo[0]->GetImage();
	PdfImage * image = new PdfImage();
	image = image->FromStream(imgStream);
	float widthInPixel = image->GetWidth();
	float heightInPixel = image->GetHeight();
	//Convert unit from Pixel to Point
	PdfUnitConvertor* convertor = new PdfUnitConvertor();
	float width = convertor->ConvertFromPixels(widthInPixel, PdfGraphicsUnit::Point);
	float height = convertor->ConvertFromPixels(heightInPixel, PdfGraphicsUnit::Point);
	//Get location of image 
	float xPos = imageInfo[0]->GetBounds()->GetX();
	float yPos = imageInfo[0]->GetBounds()->GetY();

	//Remove the image
	page->DeleteImage(0);
	//Define a rectangle
	RectangleF* rect = new RectangleF(new PointF(xPos, yPos), new SizeF(width, height));

	//Define wstring format
	PdfStringFormat* format = new PdfStringFormat();
	format->SetAlignment(PdfTextAlignment::Center);
	format->SetLineAlignment(PdfVerticalAlignment::Middle);
	PdfFont* font = new PdfFont(PdfFontFamily::Helvetica, 18.0f);
	wstring s = L"ReplacedText";
	page->GetCanvas()->DrawString(s.c_str(), font, PdfBrushes::GetPurple(), rect, format);
	//Save the document
	pdf->SaveToFile(outputFile.c_str());

	pdf->Close();
	delete pdf;
}











