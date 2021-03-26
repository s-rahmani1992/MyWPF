#pragma once

#include <Windows.h>
#include <d2d1_3.h>

#pragma comment(lib, "d2d1.lib")

class GPU2D
{
private:
	ID2D1Factory5* factory;
	ID2D1HwndRenderTarget* renderTarget;
	ID2D1SolidColorBrush* brush;

public:
	GPU2D();
	~GPU2D();
	ID2D1HwndRenderTarget* GetRenderTarget();
	bool Init(HWND wHandle);
	void BeginDraw();
	void EndDraw();

	void ClearScreen(float r, float g, float b);
	void DrawCircle(float x, float y, float rad, float r, float g, float b);
};

