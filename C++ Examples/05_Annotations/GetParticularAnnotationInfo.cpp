#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring inputFile = DATAPATH+L"Template_Pdf_3.pdf";
	wstring outputFile = OUTPUTPATH+L"GetParticularAnnotationInfo.txt";

	//Create a new PDF document.
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//Get the annotation collection from the document.
	PdfAnnotationCollection* annotations = doc->GetPages()->GetItem(0)->GetAnnotationsWidget();
	//Get particular annotation information from the document.
	wstring content;
	wchar_t nm_w[100];
	swprintf(nm_w, 100, L"%hs", typeid(PdfTextAnnotationWidget).name());
	LPCWSTR_S newName = nm_w;
	if (wcscmp(newName, annotations->GetItem(0)->GetInstanceTypeName()) == 0) {
	PdfTextAnnotationWidget* textAnnotation = Object::Convert<PdfTextAnnotationWidget>(annotations->GetItem(0));
	content.append(L"Annotation text: ");
	content.append(textAnnotation->GetText());
	content.append(L"\nAnnotation ModifiedDate: ");
	content.append(textAnnotation->GetModifiedDate()->ToString());
	content.append(L"\nAnnotation author: ");
	content.append(textAnnotation->GetAuthor());
	content.append(L"\nAnnotation Name: ");
	content.append(textAnnotation->GetName());
	}
	//Save to file.
	wofstream os;
	os.open(outputFile, ios::trunc);
	os << content;
	os.close();
	doc->Close();


	delete doc;
}


