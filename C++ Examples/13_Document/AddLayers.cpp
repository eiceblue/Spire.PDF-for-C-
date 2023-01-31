#include "pch.h"
using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main(){
				
	wstring inputFile = DATAPATH+L"AddLayers.pdf";
	wstring outputFile = OUTPUTPATH+L"AddLayers.pdf";
	
	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());

	PdfPageBase* page = doc->GetPages()->GetItem(0);

	//create a layer named "red line"
	PdfLayer* layer = doc->GetLayers()->AddLayer(L"red line", PdfVisibility::On);
	PdfCanvas* pcA = layer->CreateGraphics(page->GetCanvas());

	PdfPen* tempVar = new PdfPen(PdfBrushes::GetRed(), 2);
	pcA->DrawLine(tempVar,new PointF(100, 350),new PointF(300, 350));

	//create a layer named "blue line"
	layer = doc->GetLayers()->AddLayer(L"blue line");
	PdfCanvas* pcB = layer->CreateGraphics(doc->GetPages()->GetItem(0)->GetCanvas());

	PdfPen* tempVar2 = new PdfPen(PdfBrushes::GetBlue(), 2);
	pcB->DrawLine(tempVar2, new PointF(100, 400), new PointF(300, 400));

	//create a layer named "green line"
	layer = doc->GetLayers()->AddLayer(L"green line");
	PdfCanvas* pcC = layer->CreateGraphics(doc->GetPages()->GetItem(0)->GetCanvas());

	PdfPen* tempVar3 = new PdfPen(PdfBrushes::GetGreen(), 2);
	pcC->DrawLine(tempVar3,new PointF(100, 450),new PointF(300, 450));
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete doc;
	
}
