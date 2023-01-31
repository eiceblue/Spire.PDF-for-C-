#include "pch.h"
#include "stringbuilder.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring outputFile = OUTPUTPATH+L"ViewerPreference.pdf";
    wstring inputFile = DATAPATH+L"ViewerPreference.pdf";

    //Create a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());

	//Set view reference
	doc->GetViewerPreferences()->SetCenterWindow(true);
	doc->GetViewerPreferences()->SetDisplayTitle(false);
	doc->GetViewerPreferences()->SetFitWindow(false);
	doc->GetViewerPreferences()->SetHideMenubar(true);
	doc->GetViewerPreferences()->SetHideToolbar(true);
	doc->GetViewerPreferences()->SetPageLayout(PdfPageLayout::SinglePage);

	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete doc;
}


