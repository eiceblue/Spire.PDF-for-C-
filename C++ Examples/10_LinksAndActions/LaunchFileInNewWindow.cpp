#include "pch.h"

#include "stringhelper.h"
#include "stringbuilder.h"
using namespace Spire::Common;

using namespace Spire::Pdf;
using namespace std;

int main()
{
	wstring outputFile = OUTPUTPATH + L"LaunchFileInNewWindow.pdf";
	wstring inputFile = DATAPATH + L"DocumentsLinks.pdf";

	//Load old PDF from disk.
	PdfDocument* pdf = new PdfDocument();

	pdf->LoadFromFile(inputFile.c_str());

	//Define the variables
	std::vector<PdfTextFind*> finds;
	std::vector<std::wstring> test = { L"Spire.PDF" };

	//Traverse the pages
	for (int j = 0; j < pdf->GetPages()->GetCount(); j++)
	{
		PdfPageBase* page = pdf->GetPages()->GetItem(j);
		for (int i = 0; i < test.size(); i++)
		{
			//Find the defined string
			finds = page->FindText(test[i].c_str(), Find_TextFindParameter::WholeWord)->GetFinds();

			//Traverse the finds
			for (auto find : finds)
			{
				PdfLaunchAction* launchAction = new PdfLaunchAction(outputFile.c_str(), PdfFilePathType::Relative);

				//Set open document in a new window
				launchAction->SetIsNewWindow(true);

				//Add annotation
				RectangleF* rect = new RectangleF(find->GetPosition()->GetX(), find->GetPosition()->GetY(), find->GetSize()->GetWidth(), find->GetSize()->GetHeight());
				PdfActionAnnotation* annotation = new PdfActionAnnotation(rect, launchAction);
				PdfPageWidget* pageWg = Object::Convert<PdfPageWidget>(page);
				pageWg->GetAnnotationsWidget()->Add(annotation);

			}
		}
	}

	//Save the document
	pdf->SaveToFile(outputFile.c_str());
	pdf->Close();
	delete pdf;
}
