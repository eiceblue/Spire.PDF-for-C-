#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring outputFile = OUTPUTPATH+L"AddtransparentText.pdf";

	//Create one A4 page
	PdfDocument* doc = new PdfDocument();
	SizeF* size = new SizeF(PdfPageSize::A4());
	PdfPageBase* page = doc->GetPages()->Add(size, new PdfMargins(0));
	page->GetCanvas()->Save();
	//Set alpha value
	float alpha = 0.25f;
	page->GetCanvas()->SetTransparency(alpha, alpha, PdfBlendMode::Normal);
	//Create rectangle with specified dimensions
	RectangleF* rect = new RectangleF(50, 50, 450, page->GetSize()->GetHeight());
	//Create transparent text
	wstring text = L"Spire.PDF for .NET,a professional PDF library applied to creating, writing, editing, handling and reading PDF files without any external dependencies within .NET( C#, VB.NET, ASP.NET, .NET Core) application.";
	text += L"\n\n\n\n\n";
	text += L"Spire.PDF for Java,a PDF Java API that enables developers to read, write, convert and print PDF documents in Java applications without using Adobe Acrobat.";
	LPCWSTR_S str = text.c_str();
	//Create brush from color channel
	PdfRGBColor* color = new PdfRGBColor(Color::FromArgb(30, 0, 255, 0));
	PdfSolidBrush* brush = new PdfSolidBrush(color);
	//Draw the text
	page->GetCanvas()->DrawString(str, new PdfFont(PdfFontFamily::Helvetica, 14.f), brush, rect);
	page->GetCanvas()->Restore();
	//Save the document
	doc->SaveToFile((outputFile).c_str());
	doc->Close();

	delete doc;
}

