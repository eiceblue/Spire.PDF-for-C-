#include "pch.h"
using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main()
{
	wstring inputFile = DATAPATH+L"GetZoomFactor.pdf";
	wstring outputFile = OUTPUTPATH+L"GetZoomFactor.txt";
	
	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	
	PdfGoToAction* action = doc->GetAfterOpenAction();

	float zoomvalue = action->GetDestination()->GetZoom();
	wstring result = L"The zoom factor of the document is " + std::to_wstring(zoomvalue * 100) + L"%.";
	wofstream os;
	os.open(outputFile, ios::trunc);
	os << result;
	os.close();
	doc->Close();

	delete doc;
}
