#include "pch.h"
using namespace Spire::Pdf;
using namespace std;
using namespace Spire::Common;

int main(){
				
	wstring outputFile = OUTPUTPATH+L"GetNumberOfPages.txt";
	wstring inputFile = DATAPATH+L"DeletePage.pdf";

	try
	{
		{
			//Create a new PDF document.
			PdfDocument pdf = PdfDocument();
			pdf.LoadFromFile(inputFile.c_str());
			int count = pdf.GetPages()->GetCount();
			//Save to file.
			wofstream os;
			os.open(outputFile, ios::trunc);
			os << L"The page count of the pdf document is " + std::to_wstring(count);
			os.close();
		}
	}
	catch (const std::runtime_error& exe)
	{
		wofstream os;
		os.open(outputFile, ios::trunc);
		os << exe.what();
		os.close();
	}
}
