#pragma once
#include <wincodec.h>
#include <string>
#include "GPU2D.h"

#pragma comment(lib, "windowscodecs.lib")
class SpriteSheet
{
	GPU2D* gpuRender;
	ID2D1Bitmap* bitmap;
public:
	SpriteSheet(std::wstring fileName, GPU2D* gpu);
	~SpriteSheet();
	void Draw();
};

