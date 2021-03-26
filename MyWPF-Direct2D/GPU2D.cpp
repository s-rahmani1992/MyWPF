#include "GPU2D.h"

GPU2D::GPU2D():factory(NULL), renderTarget(NULL), brush(NULL)
{
}

GPU2D::~GPU2D()
{
	if (factory) factory->Release();
	if (renderTarget) renderTarget->Release();
	if (brush) brush->Release();
}

ID2D1HwndRenderTarget* GPU2D::GetRenderTarget()
{
	return renderTarget;
}

bool GPU2D::Init(HWND wHandle)
{
	HRESULT res = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &factory);
	if(res != S_OK) return false;
	RECT rect;
	GetClientRect(wHandle, &rect);
	res = factory->CreateHwndRenderTarget(D2D1::RenderTargetProperties()
		, D2D1::HwndRenderTargetProperties(wHandle, D2D1::SizeU(rect.right, rect.bottom)), &renderTarget);
	if (res != S_OK) return false;
	renderTarget->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 1.0f), &brush);
	return true;
}

void GPU2D::BeginDraw()
{
	renderTarget->BeginDraw();
}

void GPU2D::EndDraw()
{
	renderTarget->EndDraw();
}

void GPU2D::ClearScreen(float r, float g, float b)
{
	renderTarget->Clear(D2D1::ColorF(r, g, b));
}

void GPU2D::DrawCircle(float x, float y, float rad, float r, float g, float b)
{
	
	brush->SetColor(D2D1::ColorF( r, g, b));
	
	renderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), rad, rad), brush, 10);
}
