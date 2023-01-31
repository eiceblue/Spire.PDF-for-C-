#include "pch.h"

#include "stringhelper.h"
#include "stringbuilder.h"
using namespace Spire::Common;

using namespace Spire::Pdf;
using namespace std;

int main()
{
	wstring outputFile = OUTPUTPATH + L"GetLinkAnnotation.txt";
	wstring inputFile = DATAPATH + L"LinkAnnotation.pdf";

	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	//Load file from disk
	doc->LoadFromFile(inputFile.c_str());

	//Get the first page
	PdfPageBase* page = doc->GetPages()->GetItem(0);

	//Get the annotation collection
	PdfAnnotationCollection* annotations = page->GetAnnotationsWidget();

	//Create StringBuilder to save 
	StringBuilder* content = new StringBuilder();

	//Verify whether widgetCollection is not null or not
	if (annotations->GetCount() > 0)
	{
		PdfTextWebLinkAnnotationWidget* WebLinkAnnotation;
		for (int i = 0; i < page->GetAnnotationsWidget()->GetCount(); i++) {
			//if it is PdfTextWebLinkAnnotationWidget
			wchar_t nm_w[100];
			swprintf(nm_w, 100, L"%hs", typeid(PdfTextWebLinkAnnotationWidget).name());
			LPCWSTR_S newName = nm_w;
			if (wcscmp(newName, page->GetAnnotationsWidget()->GetItem(i)->GetInstanceTypeName()) == 0)
			{
				WebLinkAnnotation = Object::Convert<PdfTextWebLinkAnnotationWidget>(page->GetAnnotationsWidget()->GetItem(i));
				//Get the Url
				std::wstring url = WebLinkAnnotation->GetUrl();
				content->appendLine(L"The url of link annotation is " + url);
				std::wstring strC = L"The text of link annotation is ";
				strC += WebLinkAnnotation->GetText();
				content->appendLine(strC);
			}
		}
	}
	//Save them to a txt file
	wstring str = content->toString();
	wofstream os;
	os.open(outputFile, ios::trunc);
	os << str;
	os.close();
	doc->Close();

	delete content;
	delete doc;
}

