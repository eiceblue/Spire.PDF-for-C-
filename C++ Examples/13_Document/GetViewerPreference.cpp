#include "pch.h"
#include "stringbuilder.h"
using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

const wstring ModeToString(PdfPageMode style) {
	switch (style)
	{
	case Spire::Pdf::PdfPageMode::UseNone:
		return L"UseNone";
		break;
	case Spire::Pdf::PdfPageMode::UseOutlines:
		return L"UseOutlines";
		break;
	case Spire::Pdf::PdfPageMode::UseThumbs:
		return L"UseThumbs";
		break;
	case Spire::Pdf::PdfPageMode::FullScreen:
		return L"FullScreen";
		break;
	case Spire::Pdf::PdfPageMode::UseOC:
		return L"UseOC";
		break;
	case Spire::Pdf::PdfPageMode::UseAttachments:
		return L"UseAttachments";
		break;
	default:
		break;
	}
}
const wstring LayoutToString(PdfPageLayout style) {
	switch (style)
	{
	case Spire::Pdf::PdfPageLayout::SinglePage:
		return L"SinglePage";
		break;
	case Spire::Pdf::PdfPageLayout::OneColumn:
		return L"OneColumn";
		break;
	case Spire::Pdf::PdfPageLayout::TwoColumnLeft:
		return L"TwoColumnLeft";
		break;
	case Spire::Pdf::PdfPageLayout::TwoColumnRight:
		return L"TwoColumnRight";
		break;
	case Spire::Pdf::PdfPageLayout::TwoPageLeft:
		return L"TwoPageLeft";
		break;
	case Spire::Pdf::PdfPageLayout::TwoPageRight:
		return L"TwoPageRight";
		break;
	default:
		break;
	}
}
int main(){
	wstring inputFile = DATAPATH+L"PDFTemplate-Az.pdf";
	wstring outputFile = OUTPUTPATH+L"GetViewerPreference.txt";
	// Read a pdf file
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());

	PdfViewerPreferences* viewer = doc->GetViewerPreferences();

	// Create a StringBuilder object to put the details
	StringBuilder* builder = new StringBuilder();

	builder->appendLine(L"Whether the documents window position is in the center: ");
	wstring result = L"";
	result += L"CenterWindow:";
	result += viewer->GetCenterWindow() ? L"True" : L"False";
	builder->appendLine(result);
	builder->appendLine(L"Document displaying mode, i.e. show thumbnails, full-screen, show attachment panel: ");
	result = L"PageMode:";
	result += ModeToString(viewer->GetPageMode());
	builder->appendLine(result);
	builder->appendLine(L"The page layout, i.e. single page, one column: ");
	result = L"PageLayout:";
	
	result += LayoutToString(viewer->GetPageLayout());
	builder->appendLine(result);
	builder->appendLine(L"Whether window's title bar should display document title: ");
	
	result = L"DisplayTitle:";
	result += viewer->GetDisplayTitle() ? L"True" : L"False";
	builder->appendLine(result);
	builder->appendLine(L"Whether to resize the document's window to fit the size of the firstdisplayed page: ");
	
	result = L"FitWindow:";
	result += viewer->GetFitWindow() ? L"True" : L"False";
	builder->appendLine(result);
	builder->appendLine(L"Whether to hide menu bar of the viewer application: ");
	
	result = L"HideMenubar:";
	result += viewer->GetHideMenubar() ? L"True" : L"False";
	builder->appendLine(result);
	builder->appendLine(L"Whether to hide tool bar of the viewer application: ");
	
	result = L"HideToolbar:";
	result += viewer->GetHideToolbar() ? L"True" : L"False";
	builder->appendLine(result);
	builder->appendLine(L"Whether to hide UI elements like scroll bars and leave only the page contents displayed: ");
	
	result = L"HideWindowUI:";
	result += viewer->GetHideWindowUI() ? L"True" : L"False";
	builder->appendLine(result);

	wofstream os;
	os.open(outputFile, ios::trunc);
	os << builder->toString();
	os.close();
	doc->Close();

	delete builder;
	delete doc;
}
