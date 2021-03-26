#include "GPU2D.h"
#include "GameController.h"
#include "Level1.h"

GPU2D* gpu;

LRESULT CALLBACK myWndProc(HWND win, UINT msg, WPARAM wParam, LPARAM lParam) {
	if (msg == WM_DESTROY) {
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(win, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE appInstance, HINSTANCE prev, LPSTR cmd, int ncmdShow) {
	WNDCLASSEX winClass;
	ZeroMemory(&winClass, sizeof(WNDCLASSEX));
	winClass.cbSize = sizeof(WNDCLASSEX);
	winClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	winClass.hInstance = appInstance;
	winClass.lpfnWndProc = myWndProc;
	winClass.lpszClassName = L"MyWindow";
	winClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClassEx(&winClass);

	RECT rect = { 0,0,1280, 720 };
	AdjustWindowRectEx(&rect, WS_OVERLAPPEDWINDOW, false, WS_EX_OVERLAPPEDWINDOW);

	HWND winHandle = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, L"MyWindow", L"Direct 2D adjusted", WS_OVERLAPPEDWINDOW
		, 0, 0, rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, appInstance, NULL);
	if (!winHandle) return -1;

	gpu = new GPU2D();
	if (!(gpu->Init(winHandle))) {
		delete gpu;
		return -1;
	}
	GameLevel::Init(gpu);
	ShowWindow(winHandle, ncmdShow);

	GameController::LoadInitialLevel(new Level1());

	MSG message;
	message.message = NULL;
	while (message.message != WM_QUIT) {
		if( PeekMessageW(&message, NULL, 0, 0, PM_REMOVE) )
			DispatchMessage(&message);

		else {
			
			GameController::Update();
			//render
			gpu->BeginDraw();
			GameController::Render();
			gpu->EndDraw();
		}
	
	}
	
	delete gpu;
	return 0;
}