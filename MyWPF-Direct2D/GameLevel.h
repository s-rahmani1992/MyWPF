#pragma once
#include "GPU2D.h"
#include "SpriteSheet.h"
class GameLevel {
protected:
	static GPU2D* gpu;
public:
	static void Init(GPU2D* gpuIn);
	virtual void Load() = 0;
	virtual void UnLoad() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
};


