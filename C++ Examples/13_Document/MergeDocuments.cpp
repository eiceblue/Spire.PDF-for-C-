#include "pch.h"

using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main() {
	wstring outputFile = OUTPUTPATH+L"MergeDocuments.pdf";
    wstring input1 = DATAPATH+L"MergePdfsTemplate_1.pdf";
	wstring input2 = DATAPATH+L"MergePdfsTemplate_2.pdf";
	wstring input3 = DATAPATH+L"MergePdfsTemplate_3.pdf";

	std::vector<std::wstring> files = { 
		input1
		, input2
		, input3 };
	//Open pdf documents            
	std::vector<PdfDocument*> docs(files.size());
	for (int i = 0; i < files.size(); i++)
	{
		docs[i] = new PdfDocument();
		docs[i]->LoadFromFile(files[i].c_str());
	}

	//Append document
	docs[0]->AppendPage(docs[1]);

	//Import page
	for (int i = 0; i < docs[2]->GetPages()->GetCount(); i = i + 2)
	{
		docs[0]->InsertPage(docs[2], i);
	}

	//Save pdf file
	docs[0]->SaveToFile(outputFile.c_str());

	//Close
	for (auto doc : docs)
	{
		doc->Close();
	}

}

