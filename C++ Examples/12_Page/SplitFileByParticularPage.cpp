#include "pch.h"
#include "stringbuilder.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main(){
	wstring outputFile = OUTPUTPATH+L"SplitFileByParticularPage.pdf";
	wstring inputFile = DATAPATH+L"Sample.pdf";
	//Create a new pdf document
	PdfDocument* oldPdf = new PdfDocument();
	oldPdf->LoadFromFile(inputFile.c_str());

	//Create a new PDF document
	PdfDocument* newPdf = new PdfDocument();

	//Initialize a new instance of PdfPageBase class
	PdfPageBase* page;

	//Specify the pages which you want them to be split
	for (int i = 1; i < 3; i++)
	{
		//Add same size page for newPdf
		PdfMargins tempVar(0);
		page = newPdf->GetPages()->Add(oldPdf->GetPages()->GetItem(i)->GetSize(), &tempVar);

		//Create template of the oldPdf page and draw into newPdf page
		oldPdf->GetPages()->GetItem(i)->CreateTemplate()->Draw(page, new PointF(0, 0));
	}

	//Save the document
	newPdf->SaveToFile(outputFile.c_str());
	newPdf->Close();

	delete newPdf;
	delete oldPdf;
}
