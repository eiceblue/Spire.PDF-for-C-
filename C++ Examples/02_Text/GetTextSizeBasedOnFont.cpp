#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring outputFile= OUTPUTPATH+L"GetTextSizeBasedOnFont.txt";

	wstring text = L"Spire.PDF for .NET";
	//create an instance for PdfFont
	PdfFont* font1 = new PdfFont(PdfFontFamily::TimesRoman, 12.f);
	//get text size based on font name and size
	SizeF* sizeF1 = font1->MeasureString(text.c_str());
	wstring str1 = L"1. The width is: ";
	str1 += to_wstring(sizeF1->GetWidth());
	str1 += L", the height is: ";
	str1 += to_wstring(sizeF1->GetHeight());
	//create an instance for PdfTrueTypeFont
	PdfTrueTypeFont* font2 = new PdfTrueTypeFont(new Font(L"Arial", 12.f, FontStyle::Regular), true);
	//get text size based on font name and size
	SizeF* sizeF2 = font2->MeasureString(text.c_str());
	wstring str2 = L"2. The width is: ";
	str2 += to_wstring(sizeF2->GetWidth());
	str2 += L", the height is: ";
	str2 += to_wstring(sizeF2->GetHeight());
	wofstream os;
	os.open(outputFile, ios::trunc);
	os << str1 << "\n";
	os << str2 << "\n";
	os.close();

	delete font2;
	delete font1;
}

