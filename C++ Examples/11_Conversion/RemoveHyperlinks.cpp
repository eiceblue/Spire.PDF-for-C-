#include "pch.h"
using namespace Spire::Pdf;
using namespace std;
int main(){
	//Input and output files path	
	wstring outputFile = OUTPUTPATH+L"RemoveHyperlinks.pdf";
	wstring inputFile = DATAPATH+L"RemoveHyperlinks.pdf";
	//Create a new PDF document.
	PdfDocument* doc = new PdfDocument();
	//Load an existing PDF
	doc->LoadFromFile(inputFile.c_str());
	PdfPageBase* page = doc->GetPages()->GetItem(0);
	PdfAnnotationCollection* widgetCollection = page->GetAnnotationsWidget();
	//Verify whether widgetCollection is null or not
	if (widgetCollection->GetCount() > 0) {
		for (int i = widgetCollection->GetCount() - 1; i >= 0; i--) {
			PdfAnnotation* annotation = widgetCollection->GetItem(i);
			wchar_t nm_w[100];
			swprintf(nm_w, 100, L"%hs", typeid(PdfTextWebLinkAnnotationWidget).name());
			LPCWSTR_S newName = nm_w;
			if (wcscmp(newName, annotation->GetInstanceTypeName()) == 0) {
				PdfTextWebLinkAnnotationWidget* link = Object::Convert<PdfTextWebLinkAnnotationWidget>(annotation);
				widgetCollection->Remove(link);
			}
		}
	}
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete doc;
	
}
