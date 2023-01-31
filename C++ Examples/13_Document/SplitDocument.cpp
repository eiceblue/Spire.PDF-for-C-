#include "pch.h"
#include "stringbuilder.h"
#include "stringhelper.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring inputFile = DATAPATH+L"SplitDocument.pdf";
	wstring outputFile = OUTPUTPATH+L"SplitDocument\\";

	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());

	std::wstring pattern = outputFile + L"SplitDocument-{0}.pdf";
	//Split document
	doc->Split(pattern.c_str());

	std::wstring lastPageFileName = StringHelper::formatSimple(pattern, doc->GetPages()->GetCount() - 1);

	doc->Close();

	delete doc;
}


