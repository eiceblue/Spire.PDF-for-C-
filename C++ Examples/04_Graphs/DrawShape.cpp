#include "pch.h"

using namespace Spire::Pdf;
using namespace std;

int main() {
	wstring outputFile = OUTPUTPATH +L"DrawShape.pdf";

	//Create a pdf document
	PdfDocument* doc = new PdfDocument();
	PdfPageBase* page = doc->GetPages()->Add();

	DrawPath(page);
	DrawSpiro(page);
	DrawRectangle(page);
	DrawPie(page);
	DrawEllipse(page);

	//Save the document
	doc->SaveToFile(outputFile.c_str(), FileFormat::PDF);
	doc->Close();

	delete doc;
}

void DrawPath(PdfPageBase* page)
{
	PointF* points[5];
	float PI = 3.1415926;
	for (int i = 0; i < 5; i++) {
		float x = cos(i * 2 * PI / 5);
		float y = sin(i * 2 * PI / 5);
		points[i] = new PointF(x, y);
	}
	PdfPath* path = new PdfPath();
	path->AddLine(points[2], points[0]);
	path->AddLine(points[0], points[3]);
	path->AddLine(points[3], points[1]);
	path->AddLine(points[1], points[4]);
	path->AddLine(points[4], points[2]);
	PdfGraphicsState* state = page->GetCanvas()->Save();
	PdfPen* pen = new PdfPen(new PdfRGBColor(Spire::Common::Color::GetDeepSkyBlue()), 0.02f);
	PdfBrush* brush1 = new PdfSolidBrush(new PdfRGBColor(Spire::Common::Color::GetCadetBlue()));
	page->GetCanvas()->ScaleTransform(50.f, 50.f);
	page->GetCanvas()->TranslateTransform(5.f, 1.2f);
	page->GetCanvas()->DrawPath(pen, path);

	page->GetCanvas()->TranslateTransform(2.f, 0.f);
	path->SetFillMode(PdfFillMode::Alternate);
	page->GetCanvas()->DrawPath(pen, brush1, path);

	page->GetCanvas()->TranslateTransform(2.f, 0.f);
	path->SetFillMode(PdfFillMode::Winding);
	page->GetCanvas()->DrawPath(pen, brush1, path);

	PdfLinearGradientBrush* brush2 = new PdfLinearGradientBrush(new PointF(-2, 0),
		new PointF(2, 0), new PdfRGBColor(Spire::Common::Color::GetRed()), new PdfRGBColor(Spire::Common::Color::GetBlue()));
	page->GetCanvas()->TranslateTransform(-4.f, 2.f);
	path->SetFillMode(PdfFillMode::Alternate);
	page->GetCanvas()->DrawPath(pen, brush2, path);

	PdfRadialGradientBrush* brush3 = new PdfRadialGradientBrush(new PointF(0, 0), 0.f,
		new PointF(0, 0), 1.f, new PdfRGBColor(Spire::Common::Color::GetRed()), new PdfRGBColor(Spire::Common::Color::GetBlue()));
	page->GetCanvas()->TranslateTransform(2.f, 0.f);
	path->SetFillMode(PdfFillMode::Winding);
	page->GetCanvas()->DrawPath(pen, brush3, path);

	PdfTilingBrush* brush4 = new PdfTilingBrush(new RectangleF(0, 0, 4.f, 4.f));
	brush4->GetGraphics()->DrawRectangle(brush2, 0, 0, 4.f, 4.f);
	page->GetCanvas()->TranslateTransform(2.f, 0.f);
	path->SetFillMode(PdfFillMode::Winding);
	page->GetCanvas()->DrawPath(pen, brush4, path);
	page->GetCanvas()->Restore(state);
}

void DrawSpiro(PdfPageBase* page)
{
	//Save graphics state
	PdfGraphicsState* state = page->GetCanvas()->Save();
	PdfPen* pen = PdfPens::GetDeepSkyBlue();
	int nPoints = 1000;
	float PI = 3.1415926;
	double r1 = 30;
	double r2 = 25;
	double p = 35;
	double x1 = r1 + r2 - p;
	double y1 = 0;
	double x2 = 0;
	double y2 = 0;
	page->GetCanvas()->TranslateTransform(100, 100);
	for (int i = 0; i < nPoints; i++) {
		double t = i * PI / 90;
		x2 = (r1 + r2) * cos(t) - p * cos((r1 + r2) * t / r2);
		y2 = (r1 + r2) * sin(t) - p * sin((r1 + r2) * t / r2);
		page->GetCanvas()->DrawLine(pen, (float)x1, (float)y1, (float)x2, (float)y2);
		x1 = x2;
		y1 = y2;
	}
	page->GetCanvas()->Restore(state);
}

void DrawRectangle(PdfPageBase* page)
{
	//Save graphics state
	PdfGraphicsState* state = page->GetCanvas()->Save();

	PdfPen* pen = new PdfPen(new PdfRGBColor(Spire::Common::Color::GetChocolate()), 1.f);
	page->GetCanvas()->DrawRectangle(pen, new RectangleF(new PointF(20, 310), new SizeF(150, 120)));
	page->GetCanvas()->Restore(state);


}

void DrawPie(PdfPageBase* page)
{
	//Save graphics state
	PdfGraphicsState* state = page->GetCanvas()->Save();
	PdfPen* pen = new PdfPen(new PdfRGBColor(Spire::Common::Color::GetDarkRed()), 2.f);
	page->GetCanvas()->DrawPie(pen, 220, 320, 100, 90, 360, 360);
	page->GetCanvas()->Restore(state);


}

void DrawEllipse(PdfPageBase* page)
{
	//Save graphics state
	PdfGraphicsState* state = page->GetCanvas()->Save();
	PdfBrush* brush = new PdfSolidBrush(new PdfRGBColor(Spire::Common::Color::GetCadetBlue()));
	page->GetCanvas()->DrawEllipse(brush, 380, 325, 80, 80);
	page->GetCanvas()->Restore(state);

}
