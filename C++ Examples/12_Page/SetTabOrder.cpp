#include "pch.h"
#include "stringbuilder.h"
using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main()
{
	wstring outputFile = OUTPUTPATH+L"SetTabOrder.pdf";
	wstring inputFile = DATAPATH+L"SetTabOrder.pdf";
	//Create a new pdf document
	PdfDocument* pdf = new PdfDocument();
	pdf->LoadFromFile(inputFile.c_str());

	//Set using document structure
	pdf->GetFileInfo()->SetIncrementalUpdate(false);
	PdfPageBase* page = pdf->GetPages()->GetItem(0);
	page->SetTabOrder(TabOrder::Structure);
	//Save the document
	pdf->SaveToFile(outputFile.c_str());
	pdf->Close();

	delete pdf;
}
