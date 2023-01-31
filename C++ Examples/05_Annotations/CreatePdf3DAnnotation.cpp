#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring outputFile = OUTPUTPATH+L"CreatePdf3DAnnotation.pdf";

	//Create a new Pdf document.
	PdfDocument* doc = new PdfDocument();
	//Add a new page to it.
	PdfPageBase* page = doc->GetPages()->Add();
	//Draw a rectangle on the page to define the canvas area for the 3D file.
	RectangleF* rt = new RectangleF(0, 80, 200, 200);

	//Initialize a new object of Pdf3DAnnotation, load the .u3d file as 3D annotation.
	wstring inputFile = DATAPATH+L"CreatePdf3DAnnotation.u3d";
	Pdf3DAnnotation* annotation = new Pdf3DAnnotation(rt, inputFile.c_str());
	annotation->SetActivation(new Pdf3DActivation());
	annotation->GetActivation()->SetActivationMode(Pdf3DActivationMode::PageOpen);
	//Define a 3D view mode.
	Pdf3DView* View = new Pdf3DView();
	View->SetBackground(new Pdf3DBackground(new PdfRGBColor(Spire::Common::Color::GetPurple())));
	View->SetViewNodeName(L"3DAnnotation");
	View->SetRenderMode(new Pdf3DRendermode(Pdf3DRenderStyle::Solid));
	View->SetInternalName(L"3DAnnotation");
	View->SetLightingScheme(new Pdf3DLighting());
	View->GetLightingScheme()->SetStyle(Pdf3DLightingStyle::Day);
	
	//Set the 3D view mode for the annotation.
	annotation->GetViews()->Add(View);
	//Add the annotation to Pdf.
	page->GetAnnotationsWidget()->Add(annotation);

	//Save the document
	doc->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	doc->Close();

	delete doc;

}


