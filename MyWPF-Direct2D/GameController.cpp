#include "GameController.h"

bool GameController::isLoading;
GameLevel* GameController::currentLevel;

void GameController::Initialize(){
	isLoading = true;
	currentLevel = nullptr;
}
void GameController::LoadInitialLevel(GameLevel* level){
	isLoading = true;
	currentLevel = level;
	currentLevel->Load();
	isLoading = false;
}

void GameController::SwitchLevel(GameLevel* level){
	isLoading = true;
	currentLevel->UnLoad();
	level->Load();
	delete currentLevel;
	currentLevel = level;
	isLoading = false;
}

void GameController::Update(){
	if (isLoading) return;
	currentLevel->Update();
}

void GameController::Render(){
	if (isLoading) return;
	currentLevel->Render();
}
