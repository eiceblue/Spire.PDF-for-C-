# Spire.PDF for C++ - A C++ Library for Processing & Manipulating PDF Files

[![Foo](https://i.imgur.com/9oTrtOu.png)](https://www.e-iceblue.com/Introduce/pdf-for-CPP.html)

[Product Page](https://www.e-iceblue.com/Introduce/pdf-for-CPP.html)  |  [Forum](https://www.e-iceblue.com/forum/spire-pdf-f7.html) | [Temporary License](https://www.e-iceblue.com/TemLicense.html) | [Customized Demo](https://www.e-iceblue.com/Misc/customized-demo.html)

[Spire.PDF for C++](https://www.e-iceblue.com/Introduce/pdf-for-CPP.html) is a professional **C++ PDF API** applied to creating, writing, editing, handling and reading PDF files without any external dependencies within C++ application.

Many rich features can be supported by the C++ PDF API, such as creating PDF Portfolio, PDF text/attachment/image extract, PDF merge/split, metadata update, section, graph/image drawing and inserting, PDF conversion, data importing, etc. Besides, Spire.PDF for C++ can be applied to easily converting Text, Image, SVG, HTML to PDF and converting PDF to Excel with C++ in high quality.

### High Fidelity PDF file Conversion

Spire.PDF for C++ supports converting HTML, XPS, Text and Image to PDF and converting PDF to Excel with efficient performance. Developers can transform PDF to Word, XPS, SVG, EMF, JPG, PNG, BMP, TIFF, HTML, PostScript, PCL (Printer Command Language), Text format. Furthermore, along with Spire.Doc for C++ and Spire.XLS for C++, developers can convert Word (Doc/Docx), Excel (Xls/Xlsx) and XML to PDF.

### Easily Manipulate document and Form fields

Spire.PDF for C++ offers the facility to merge/split PDF documents and overlay documents. Meanwhile, Spire.PDF for C++ can provide import and stamp feature, booklet feature and form filling which can help users read value from form fields and populate a database.

### Security Features

Spire.PDF for C++ can protect PDF documents by setting passwords. User password and owner password can determine the encrypted PDF documents readability, modifiability, printability and other selective restrictions.

### Extract data from Pdf documents

Spire.PDF for C++ can be used to extract images, text, pages and attachments from a PDF document with great speed and accuracy.

### Document Settings features

Document information can be set with Spire.PDF for C++ including custom metadata, document properties, page orientation, and page size. Wherein, document properties consist of document restrictions (printing, document assembly, page extraction, comment etc. allowed or not) and document description about file title, author, subject, keywords and so on. By using Spire.PDF for C++, viewer preferences can be set with position, title display, resize, page mode and print scaling etc.

### Examples

### Add Layers to PDF

```C++
#include "pch.h"
using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main(){
				
	wstring inputFile = DATAPATH+L"AddLayers.pdf";
	wstring outputFile = OUTPUTPATH+L"AddLayers.pdf";
	
	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());

	PdfPageBase* page = doc->GetPages()->GetItem(0);

	//create a layer named "red line"
	PdfLayer* layer = doc->GetLayers()->AddLayer(L"red line", PdfVisibility::On);
	PdfCanvas* pcA = layer->CreateGraphics(page->GetCanvas());

	PdfPen* tempVar = new PdfPen(PdfBrushes::GetRed(), 2);
	pcA->DrawLine(tempVar,new PointF(100, 350),new PointF(300, 350));

	//create a layer named "blue line"
	layer = doc->GetLayers()->AddLayer(L"blue line");
	PdfCanvas* pcB = layer->CreateGraphics(doc->GetPages()->GetItem(0)->GetCanvas());

	PdfPen* tempVar2 = new PdfPen(PdfBrushes::GetBlue(), 2);
	pcB->DrawLine(tempVar2, new PointF(100, 400), new PointF(300, 400));

	//create a layer named "green line"
	layer = doc->GetLayers()->AddLayer(L"green line");
	PdfCanvas* pcC = layer->CreateGraphics(doc->GetPages()->GetItem(0)->GetCanvas());

	PdfPen* tempVar3 = new PdfPen(PdfBrushes::GetGreen(), 2);
	pcC->DrawLine(tempVar3,new PointF(100, 450),new PointF(300, 450));
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete doc;
	
}
```

### Add Watermarks to PDF

```C++
#include "pch.h"

using namespace std;
using namespace Spire::Pdf;
using namespace Spire::Common;

int main()
{
	wstring outputFile = OUTPUTPATH + L"TextWaterMark.pdf";
	wstring inputFile = DATAPATH + L"TextWaterMark.pdf";
	//Create a pdf document and load file from disk
	PdfDocument* doc = new PdfDocument();

	doc->LoadFromFile(inputFile.c_str());

	//Get the first page
	PdfPageBase* page = doc->GetPages()->GetItem(0);

	//Draw text watermark
	PdfTilingBrush* brush = new PdfTilingBrush(new SizeF(page->GetCanvas()->GetClientSize()->GetWidth() / 2, page->GetCanvas()->GetClientSize()->GetHeight() / 3));
	brush->GetGraphics()->SetTransparency(0.3f);
	brush->GetGraphics()->Save();
	brush->GetGraphics()->TranslateTransform(brush->GetSize()->GetWidth() / 2, brush->GetSize()->GetHeight() / 2);
	brush->GetGraphics()->RotateTransform(-45);

	brush->GetGraphics()->DrawString(L"Spire.Pdf Demo", new PdfFont(PdfFontFamily::Helvetica, 24), PdfBrushes::GetViolet(), 0, 0,
		new PdfStringFormat(PdfTextAlignment::Center));
	brush->GetGraphics()->Restore();
	brush->GetGraphics()->SetTransparency(1);
	page->GetCanvas()->DrawRectangle(brush, new RectangleF(new PointF(0, 0), page->GetCanvas()->GetClientSize()));

	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();
	delete doc;
}
```

### Convert PDF to Word

```C++
#include "pch.h"
using namespace Spire::Pdf;
using namespace std;

int main(){
	//Input and output files path
	wstring inputFile = DATAPATH+L"ToDocx.pdf";
	wstring outputFile =  OUTPUTPATH+L"ToDocx.docx";
	//Create a new PDF document.
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//save to file
	doc->SaveToFile(outputFile.c_str(), FileFormat::DOCX);
	doc->Close();

	delete doc;
}
```

### Convert PDF to PNG

```C++
#include "pch.h"
using namespace Spire::Pdf;
using namespace std;

int main(){
	//Input and output files path
	wstring outputFile = OUTPUTPATH+L"ToImage\\";
	wstring inputFile = DATAPATH+L"ToImage.pdf";
	//Create a new PDF document.
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//Save to images
	for (int i = 0; i < doc->GetPages()->GetCount(); i++) {
		Stream* image = doc->SaveAsImage(i);
		wstring fileName = outputFile + to_wstring(i) + L".bmp";
		image->Save(fileName.c_str());
	}
	doc->Close();
	delete doc;
}
```

[Product Page](https://www.e-iceblue.com/Introduce/pdf-for-CPP.html)  |  [Forum](https://www.e-iceblue.com/forum/spire-pdf-f7.html) | [Temporary License](https://www.e-iceblue.com/TemLicense.html) | [Customized Demo](https://www.e-iceblue.com/Misc/customized-demo.html)
