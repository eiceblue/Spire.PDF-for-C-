#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring outputFile = OUTPUTPATH+L"MergePdfsByStream.pdf";
	wstring input1 = DATAPATH+L"MergePdfsTemplate_1.pdf";
    wstring input2 = DATAPATH+L"MergePdfsTemplate_2.pdf";
    wstring input3 = DATAPATH+L"MergePdfsTemplate_3.pdf";
	Stream* stream1 = new Stream(input1.c_str());
	Stream* stream2 = new Stream(input2.c_str());
	Stream* stream3 = new Stream(input3.c_str());
	//Pdf document streams 
	std::vector<Stream*> streams = { stream1, stream2, stream3 };

	//Also can merge files by filename
	//Merge files by stream
	PdfDocumentBase* doc = PdfDocument::MergeFiles(streams);

	//Save the document
	doc->Save(outputFile.c_str(), FileFormat::PDF);
	doc->Close();

}

