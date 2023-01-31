#include "pch.h"
#include "stringbuilder.h"
#include "stringhelper.h"

using namespace Spire::Pdf;
using namespace std;

int main(){
				
	wstring outputFile = OUTPUTPATH+L"TextToPDF.pdf";
	wstring inputFile = DATAPATH+L"TextToPdf.txt";
	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	ifstream in_file;
	in_file.open(inputFile.c_str());
	if (!in_file.is_open()) {
		cout << "It failed to read file" << endl;
		return;
	}
	StringBuilder* sb = new StringBuilder();
	string buf;
	while (getline(in_file, buf)) {
		sb->appendLine(StringHelper::string_to_wstring(buf));
	}
	wstring text = sb->toString();
	PdfSection* section = doc->GetSections()->Add();
	PdfPageBase* page = section->GetPages()->Add();
	//Create a PdfFont
	PdfFont* font = new PdfFont(PdfFontFamily::Helvetica, 11);
	//Set string format
	PdfStringFormat* format = new PdfStringFormat();
	format->SetLineSpacing(20);
	PdfBrush* brush = PdfBrushes::GetBlack();
	//Set text layout
	PdfTextLayout* textLayout = new PdfTextLayout();
	textLayout->SetBreak(PdfLayoutBreakType::FitPage);
	textLayout->SetLayout(PdfLayoutType::Paginate);
	RectangleF* bounds = new RectangleF(new PointF(10, 20), page->GetCanvas()->GetClientSize());
	PdfTextWidget* textWidget = new PdfTextWidget(text.c_str(), font, brush);
	textWidget->SetStringFormat(format);
	PdfNewPage* newPage = Object::Convert<PdfNewPage>(page);
	textWidget->Draw(newPage, bounds, textLayout);
	//Save to file
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete textWidget;
	delete doc;

}
