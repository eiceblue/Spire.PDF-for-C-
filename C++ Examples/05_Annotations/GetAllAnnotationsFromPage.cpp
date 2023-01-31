#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring inputFile = DATAPATH+L"Template_Pdf_3.pdf";
	wstring outputFile = OUTPUTPATH+L"GetAllAnnotationsFromPage.txt";

	//Create a new PDF document.
	PdfDocument* doc = new PdfDocument();
	//Load the file from disk.
	doc->LoadFromFile(inputFile.c_str());
	//Get all annotations from the first page.
	PdfAnnotationCollection* annotations = doc->GetPages()->GetItem(0)->GetAnnotationsWidget();
	wstring content;
	for (int i = 0; i < annotations->GetCount(); i++) {
		//A text annotation will attach a popup annotation since they are father-son relationship. 
		//The annotation information exists in the text annotation, so here we mask the blank popup annotation.
		wchar_t nm_w[100];
		swprintf(nm_w, 100, L"%hs", typeid(PdfPopupAnnotationWidget).name());
		LPCWSTR_S newName = nm_w;
		if (wcscmp(newName, annotations->GetItem(i)->GetInstanceTypeName()) == 0)
		continue;
		content.append(L"Annotation information: \n");
		content.append(L"Text: ");
		content.append(annotations->GetItem(i)->GetText());
		wstring modifiedDate = annotations->GetItem(i)->GetModifiedDate()->ToString();
		content.append(L"\nModifiedDate: " + modifiedDate);
		content.append(L"\n");
	}
	//Save to file.
	wofstream os;
	os.open(outputFile, ios::trunc);
	os << content;
	os.close();
	doc->Close();

	delete doc;
}


