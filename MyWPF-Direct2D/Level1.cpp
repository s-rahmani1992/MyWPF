#include "Level1.h"

void Level1::Load(){
	sprite = new SpriteSheet(L"wp1.png", gpu);
	yPos = 200;
	ySpeed = 0;
}

void Level1::UnLoad()
{
}

void Level1::Update(){
	ySpeed += 1.0f;
	yPos += ySpeed;
	if (yPos > 720) {
		yPos = 720;
		ySpeed = -ySpeed;
	}
}

void Level1::Render(){
	gpu->ClearScreen(1.f, 1.0f, 0.0f);
	gpu->DrawCircle(640, yPos, 70, 0.3f, 0.7f, 0.4f);
	sprite->Draw();
}
