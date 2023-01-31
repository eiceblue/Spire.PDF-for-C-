#include "pch.h"

using namespace std;
using namespace Spire::Pdf;
using namespace Spire::Common;

int main()
{
	wstring outputFile = OUTPUTPATH + L"SetPropertiesForStamp.pdf";
	wstring inputFile = DATAPATH + L"TextStamp.pdf";

	//Load old PDF from disk.
	PdfDocument* pdf = new PdfDocument();
	pdf->LoadFromFile(inputFile.c_str());
	//Get the first page
	PdfPageBase* page = pdf->GetPages()->GetItem(0);
	//Traverse annotations widget

	for (int i = 0; i < page->GetAnnotationsWidget()->GetCount(); i++)
	{
		PdfAnnotation* annotation = page->GetAnnotationsWidget()->GetItem(i);
		wchar_t nm_w[100];
		swprintf(nm_w, 100, L"%hs", typeid(PdfRubberStampAnnotationWidget).name());
		LPCWSTR_S newName = nm_w;
		//If it is PdfRubberStampAnnotationWidget
		if (wcscmp(newName, annotation->GetInstanceTypeName()) == 0)
		{
			PdfRubberStampAnnotationWidget* stamp = Object::Convert<PdfRubberStampAnnotationWidget>(annotation);
			stamp->SetAuthor(L"TestUser");
			stamp->SetSubject(L"E-iceblue");
			stamp->SetCreationDate(DateTime::GetNow());
			stamp->SetModifiedDate(DateTime::GetNow());
		}
	}

	//Save the document
	pdf->SaveToFile(outputFile.c_str());
	pdf->Close();
	delete pdf;
}
