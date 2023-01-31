#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring outputFile= OUTPUTPATH+L"SetLineBreak.pdf";

	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	//Create one A4 page
	SizeF* size = new SizeF(PdfPageSize::A4());
	PdfPageBase* page = doc->GetPages()->Add(size, new PdfMargins(40));
	//Create brush from color channel
	PdfSolidBrush* brush = new PdfSolidBrush(new PdfRGBColor(Color::GetBlack()));
	//Create text
	wstring text = L"Spire.PDF for .NET\n";
	text += L"A professional PDF library applied to";
	text += L" creating, writing, editing, handling and reading PDF files";
	text += L" without any external dependencies within .NET";
	text += L"( C#, VB.NET, ASP.NET, .NET Core) application.";
	text += L"\n\rSpire.PDF for Java\n";
	text += L"A PDF Java API that enables developers to read, ";
	text += L"write, convert and print PDF documents";
	text += L"in Java applications without using Adobe Acrobat.";
	text += L"\n\r";
	text += L"Welcome to evaluate Spire.PDF!";
	//Create rectangle with specified dimensions      
	RectangleF* rect = new RectangleF(50, 50, page->GetSize()->GetWidth() - 150, page->GetSize()->GetHeight());
	//Draw the text
	page->GetCanvas()->DrawString(text.c_str(), new PdfFont(PdfFontFamily::Helvetica, 13.f), brush, rect);
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete doc;
}


