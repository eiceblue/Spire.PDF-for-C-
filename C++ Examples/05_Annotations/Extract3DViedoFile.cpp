#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring inputFile = DATAPATH+L"3D.pdf";
	wstring outputFile = OUTPUTPATH+L"3d0.u3d";

	//Load old PDF from disk.
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//Get the first page.
	PdfPageBase* page = doc->GetPages()->GetItem(0);
	//Get the annotation collection of the first page
	PdfAnnotationCollection* annot = page->GetAnnotationsWidget();
	//Define an int variable
	int count = 0;
	//Traverse the annotations
	for (int i = 0; i < annot->GetCount(); i++) {
		wchar_t nm_w[100];
		swprintf(nm_w, 100, L"%hs", typeid(Pdf3DAnnotation).name());
		LPCWSTR_S newName = nm_w;
		//If it is Pdf3DAnnotation
		if (wcscmp(newName, annot->GetItem(i)->GetInstanceTypeName()) == 0) {
			Pdf3DAnnotation* annot3D = Object::Convert<Pdf3DAnnotation>(annot->GetItem(i));
			//Get the 3D video data
			Stream* stream = annot3D->Get_3DData();
			//Write the data into .u3d format file
			stream->Save(outputFile .c_str());
		}
	}
	doc->Close();

	delete doc;
}

