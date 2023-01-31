#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring inputFile =DATAPATH+L"ExtractHighlightedText.pdf";	
	wstring outputFile = OUTPUTPATH+L"ExtractHighlightedText.txt";

	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	PdfPageBase* page = doc->GetPages()->GetItem(0);
	PdfTextMarkupAnnotationWidget* annotation;
	wstring str = L"Extracted hightlighted text:\n";
	//Get PdfTextMarkupAnnotationWidget objects
	for (int i = 0; i < page->GetAnnotationsWidget()->GetCount(); i++) {
	wchar_t nm_w[100];
	swprintf(nm_w, 100, L"%hs", typeid(PdfTextMarkupAnnotationWidget).name());
	LPCWSTR_S newName = nm_w;
		if (wcscmp(newName,page->GetAnnotationsWidget()->GetItem(i)->GetInstanceTypeName()) == 0)
		{
		annotation = Object::Convert<PdfTextMarkupAnnotationWidget>(page->GetAnnotationsWidget()->GetItem(i));
		//Get the highlighted text
		str += page->ExtractText(annotation->GetBounds());
		//Get the highlighted color
		PdfRGBColor* color = annotation->GetTextMarkupColor();
		}
	}

	wofstream os;
	os.open(outputFile, ios::trunc);
	os << str;
	os.close();
	doc->Close();

	delete doc;
}

