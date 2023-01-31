#include "pch.h"

#include "stringhelper.h"
using namespace Spire::Common;
using namespace Spire::Pdf;
using namespace std;

int main()
{
	string outputFile = OUTPUTPATH + L"ExtractAndUpdateLink.pdf";
	wstring inputFile = DATAPATH + L"LinkAnnotation.pdf";

	//Create a new PDF document
	PdfDocument* doc = new PdfDocument();

	doc->LoadFromFile(inputFile.c_str());
	//Get the first page
	PdfPageBase* page = doc->GetPages()->GetItem(0);

	//Get the annotation collection
	PdfAnnotationCollection* annotations = page->GetAnnotationsWidget();

	//Verify whether widgetCollection is not null or not
	if (annotations->GetCount() > 0)
	{
		PdfTextWebLinkAnnotationWidget* annotation;
		for (int i = 0; i < page->GetAnnotationsWidget()->GetCount(); i++) {
			wchar_t nm_w[100];
			swprintf(nm_w, 100, L"%hs", typeid(PdfTextWebLinkAnnotationWidget).name());
			LPCWSTR_S newName = nm_w;
			if (wcscmp(newName, page->GetAnnotationsWidget()->GetItem(i)->GetInstanceTypeName()) == 0)
			{
				annotation = Object::Convert<PdfTextWebLinkAnnotationWidget>(page->GetAnnotationsWidget()->GetItem(i));
				annotation->SetUrl(L"http://www.e-iceblue.com/Introduce/pdf-for-net-introduce.html");
			}
		}
	}
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();
	delete doc;
}