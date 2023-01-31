#include "pch.h"

#include "stringhelper.h"
using namespace Spire::Common;

using namespace Spire::Pdf;
using namespace std;

int main()
{
	wstring outputFile = OUTPUTPATH + L"EmbedSoundFile.pdf";
	wstring inputFile = DATAPATH + L"EmbedSoundFile.pdf";

	//Create a new PDF document
	PdfDocument* doc = new PdfDocument();

	doc->LoadFromFile(inputFile.c_str());

	//Add a page
	PdfPageBase* page = doc->GetPages()->GetItem(0);

	//Create a sound action
	wstring inputFile_wav = DATAPATH+L"Music.wav";
	PdfSoundAction* soundAction = new PdfSoundAction(inputFile_wav.c_str());
	soundAction->GetSound()->SetBits(15);
	soundAction->GetSound()->SetChannels(PdfSoundChannels::Stereo);
	soundAction->GetSound()->SetEncoding(PdfSoundEncoding::Signed);
	soundAction->SetVolume(0.8f);
	soundAction->SetRepeat(true);

	// Set the sound action to be executed when the PDF document is opened
	doc->SetAfterOpenAction(soundAction);
	//Save the document
	doc->SaveToFile(outputFile.c_str());
	doc->Close();
	delete doc;
}
