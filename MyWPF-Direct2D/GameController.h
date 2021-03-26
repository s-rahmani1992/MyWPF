#pragma once

#include "GameLevel.h"
class GameController
{
	GameController() {}
	static GameLevel* currentLevel;
public:
	static void Initialize();
	static bool isLoading;
	static void LoadInitialLevel(GameLevel* level);
	static void SwitchLevel(GameLevel* level);
	static void Update();
	static void Render();
};

