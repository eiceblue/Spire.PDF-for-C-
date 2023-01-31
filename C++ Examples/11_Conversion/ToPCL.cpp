#include "pch.h"
using namespace Spire::Pdf;
using namespace std;

int main(){
	//Input and output files path
	wstring outputFile = OUTPUTPATH+L"ToPCL.pcl";
	wstring inputFile = DATAPATH+L"ToPCL.pdf";
	//Create a new PDF document
	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	//Save to PCL file
	doc->SaveToFile(outputFile.c_str(), FileFormat::PCL);
	delete doc;
}
		

