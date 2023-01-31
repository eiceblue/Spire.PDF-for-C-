#include "pch.h"
#include "stringbuilder.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring inputFile = DATAPATH+L"PDFTemplate-Az.pdf";
	wstring outputFile = OUTPUTPATH+L"SetExpiryDate.pdf";

	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());

	//Set the JavaScript
	StringBuilder*  sb = new StringBuilder();
	sb->append(L"var rightNow = new Date();");
	sb->append(L"var endDate = new Date('October 20, 2015 23:59:59');");
	sb->append(L"if(rightNow.getTime() > endDate)");
	sb->append(L"app.alert('This document has expired, please contact us for a new one.',1);");
	sb->append(L"this.closeDoc();");

	PdfJavaScriptAction* js = new PdfJavaScriptAction(sb->toString().c_str());

	doc->SetAfterOpenAction(js);

	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete doc;
}

