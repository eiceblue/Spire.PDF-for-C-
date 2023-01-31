#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring outputFile = OUTPUTPATH+L"Attachment.pdf";
	wstring inputFile = DATAPATH+L"Attachment.pdf";

	PdfDocument* doc = new PdfDocument();
	doc->LoadFromFile(inputFile.c_str());
	PdfPageBase* page = doc->GetPages()->GetItem(0);

	float y = 320;

	//Title
	PdfBrush* brush1 = PdfBrushes::GetCornflowerBlue();
	PdfTrueTypeFont* font1 = new PdfTrueTypeFont(L"Arial", 18.f, PdfFontStyle::Bold, true);
	PdfStringFormat* format1 = new PdfStringFormat(PdfTextAlignment::Center);
	wstring text1 = L"Attachment";
	page->GetCanvas()->DrawString(text1.c_str(), font1, brush1, page->GetCanvas()->GetClientSize()->GetWidth() / 2, y, format1);
	y = y + font1->MeasureString(text1.c_str(), format1)->GetHeight();
	y = y + 10;

	//Add an attachment
	PdfAttachment* attachment = new PdfAttachment(L"Header.png");
	wstring inputFile_h = DATAPATH+L"Header.png";
	ifstream is(inputFile_h.c_str(), ifstream::in | ios::binary);
	//计算图片长度
	is.seekg(0, is.end);
	int length = is.tellg();
	is.seekg(0, is.beg);
	//创建内存换存区
	char* buffer = new  char[length];
	//读取图片 至此 图片已经被读入到内存Buffer中
	is.read(buffer, length);

	attachment->SetData((unsigned char*)buffer, length);

	attachment->SetDescription(L"Page header picture of demo.");
	attachment->SetMimeType(L"image/png");
	doc->GetAttachments()->Add(attachment);

	//Add an attachment
	attachment = new PdfAttachment(L"Footer.png");
	wstring inputFile_f = DATAPATH+L"Footer.png";
	ifstream is5(inputFile_f.c_str(), ifstream::in | ios::binary);
	//计算图片长度
	is5.seekg(0, is5.end);
	int length5 = is5.tellg();
	is5.seekg(0, is5.beg);
	//创建内存换存区
	char* buffer5 = new  char[length5];
	//读取图片 至此 图片已经被读入到内存Buffer中
	is5.read(buffer5, length5);
	Stream* stream = new Spire::Common::Stream((unsigned char*)buffer,length);
	attachment->SetData((unsigned char*)buffer5, length5);
	attachment->SetDescription(L"Page footer picture of demo.");
	attachment->SetMimeType(L"image/png");
	doc->GetAttachments()->Add(attachment);
	float x = 50;
	PdfTrueTypeFont* font2 = new PdfTrueTypeFont(L"Arial", 14.f, PdfFontStyle::Bold, true);
	PointF* location = new PointF(x, y);

	wstring inputFile_F = DATAPATH+L"Footer.png";
	ifstream is1(inputFile_F.c_str(), ifstream::in | ios::binary);
	//计算图片长度
	is1.seekg(0, is1.end);
	int length1 = is.tellg();
	is1.seekg(0, is1.beg);
	//创建内存换存区
	char* buffer1 = new  char[length1];
	//读取图片 至此 图片已经被读入到内存Buffer中
	is1.read(buffer1, length1);
	Stream* streamD = new Spire::Common::Stream((unsigned char*)buffer1, length1);

	wstring label = L"Sales Report Chart";
	SizeF* size = font2->MeasureString(label.c_str());
	RectangleF* bounds = new RectangleF(location, size);
	page->GetCanvas()->DrawString(label.c_str(), font2, PdfBrushes::GetDarkOrange(), bounds);
	bounds = new RectangleF(bounds->GetRight() + 3, bounds->GetTop(), font2->GetHeight() / 2, font2->GetHeight());

	//Create a PdfAttachmentAnnotation 
	LPCWSTR_S filename = L"SalesReportChart.png";
	PdfAttachmentAnnotation* annotation1 = new PdfAttachmentAnnotation(bounds, filename, streamD);
	annotation1->SetColor(new PdfRGBColor(Spire::Common::Color::GetDarkOrange()));
	annotation1->SetFlags(PdfAnnotationFlags::ReadOnly);
	annotation1->SetIcon(PdfAttachmentIcon::Graph);
	annotation1->SetText(L"Sales Report Chart");
	//Add the annotation1
	page->GetAnnotationsWidget()->Add(annotation1);
	y = y + size->GetHeight() + 3;

	location = new PointF(x, y);
	label = L"Science Personification Boston";
	wstring inputFile_S = DATAPATH+L"SciencePersonificationBoston.jpg";
	ifstream is2(inputFile_S.c_str(), ifstream::in | ios::binary);
	//计算图片长度
	is2.seekg(0, is2.end);
	int length2 = is2.tellg();
	is2.seekg(0, is2.beg);
	//创建内存换存区
	char* buffer2 = new  char[length2];
	//读取图片 至此 图片已经被读入到内存Buffer中
	is2.read(buffer2, length2);
	Stream* streamS = new Spire::Common::Stream((unsigned char*)buffer2, length2);
	size = font2->MeasureString(label.c_str());
	bounds = new RectangleF(location, size);
	page->GetCanvas()->DrawString(label.c_str(), font2, PdfBrushes::GetDarkOrange(), bounds);

	bounds = new RectangleF(bounds->GetRight() + 3, bounds->GetTop(), font2->GetHeight() / 2, font2->GetHeight());

	PdfAttachmentAnnotation* annotation2 = new PdfAttachmentAnnotation(bounds, L"SciencePersonificationBoston.jpg", streamS);
	annotation2->SetColor(new PdfRGBColor(Spire::Common::Color::GetOrange()));
	annotation2->SetFlags(PdfAnnotationFlags::NoZoom);
	annotation2->SetIcon(PdfAttachmentIcon::PushPin);
	annotation2->SetText(L"SciencePersonificationBoston.jpg, from Wikipedia, the free encyclopedia");
	page->GetAnnotationsWidget()->Add(annotation2);
	y = y + size->GetHeight() + 2;

	location = new PointF(x, y);
	label = L"Picture of Science";
	wstring inputFile_w = DATAPATH+L"SciencePersonificationBoston.jpg";
	ifstream is3(inputFile_w.c_str(), ifstream::in | ios::binary);
	//计算图片长度
	is3.seekg(0, is3.end);
	int length3 = is3.tellg();
	is3.seekg(0, is3.beg);
	//创建内存换存区
	char* buffer3 = new  char[length3];
	//读取图片 至此 图片已经被读入到内存Buffer中
	is3.read(buffer3, length3);
	Stream* streamW = new Spire::Common::Stream((unsigned char*)buffer3, length3);
	size = font2->MeasureString(label.c_str());
	bounds = new RectangleF(location, size);
	page->GetCanvas()->DrawString(label.c_str(), font2, PdfBrushes::GetDarkOrange(), bounds);
	bounds = new RectangleF(bounds->GetRight() + 3, bounds->GetTop(), font2->GetHeight() / 2, font2->GetHeight());
	PdfAttachmentAnnotation* annotation3 = new PdfAttachmentAnnotation(bounds, L"Wikipedia_Science.png", streamW);
	annotation3->SetColor(new PdfRGBColor(Spire::Common::Color::GetSaddleBrown()));
	annotation3->SetFlags(PdfAnnotationFlags::Locked);
	annotation3->SetIcon(PdfAttachmentIcon::Tag);
	annotation3->SetText(L"Wikipedia_Science.png, from Wikipedia, the free encyclopedia");
	page->GetAnnotationsWidget()->Add(annotation3);
	y = y + size->GetHeight() + 2;

	location = new PointF(x, y);
	label = L"Hawaii Killer Font";
	wstring inputFile_tiff = DATAPATH+L"PT_Serif-Caption-Web-Regular.ttf";
	ifstream is4(inputFile_tiff.c_str(), ifstream::in | ios::binary);
	//计算图片长度
	is4.seekg(0, is4.end);
	int length4 = is4.tellg();
	is4.seekg(0, is4.beg);
	//创建内存换存区
	char* buffer4 = new  char[length4];
	//读取图片 至此 图片已经被读入到内存Buffer中
	is4.read(buffer4, length4);
	Stream* streamP = new Spire::Common::Stream((unsigned char*)buffer4, length4);
	size = font2->MeasureString(label.c_str());
	bounds = new RectangleF(location, size);
	page->GetCanvas()->DrawString(label.c_str(), font2, PdfBrushes::GetDarkOrange(), bounds);
	bounds = new RectangleF(bounds->GetRight() + 3, bounds->GetTop(), font2->GetHeight() / 2, font2->GetHeight());
	PdfAttachmentAnnotation* annotation4 = new PdfAttachmentAnnotation(bounds, L"PT_Serif-Caption-Web-Regular.ttf", streamP);
	annotation4->SetColor(new PdfRGBColor(Spire::Common::Color::GetCadetBlue()));
	annotation4->SetFlags(PdfAnnotationFlags::NoRotate);
	annotation4->SetIcon(PdfAttachmentIcon::Paperclip);
	annotation4->SetText(L"PT_Serif-Caption-Web-Regular, from https://company.paratype.com");
	page->GetAnnotationsWidget()->Add(annotation4);
	y = y + size->GetHeight() + 2;

	//Save pdf file
	doc->SaveToFile(outputFile.c_str());
	doc->Close();

	delete doc;

}

