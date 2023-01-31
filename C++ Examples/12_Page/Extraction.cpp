#include "pch.h"
#include "stringbuilder.h"
#include "stringhelper.h"
using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main(){
	wstring outputFile = OUTPUTPATH+L"Extraction.txt";
	wstring outputFile_I = OUTPUTPATH+L"Extraction\\";
	wstring inputFile = DATAPATH+L"Extraction.pdf";
	

	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());

	StringBuilder* buffer = new StringBuilder();
	
	std::vector<Image*> images;
	for (int i = 0; i < doc->GetPages()->GetCount(); i++)
	{
		PdfPageBase* page = doc->GetPages()->GetItem(i);
		buffer->append(page->ExtractText());
		
		std::vector<Image*> exImages = page->ExtractImages();
		for (int j = 0; j < exImages.size(); j++)
		{
			images.push_back(exImages[j]);
		}
	}
	
	doc->Close();
	//save text
	wofstream os;
	os.open(outputFile, ios::trunc);
	os << buffer->toString();
	os.close();

	//save image
	int index = 0;
	for (auto image : images)
	{
		std::wstring imageFileName = StringHelper::formatSimple(outputFile_I + L"Image-{0}.png", index++);
		image->Save(imageFileName.c_str(), ImageFormat::GetPng());
	}

	delete buffer;
	delete doc;
}
