#include "GameStateManager.h"



GameStateManager::GameStateManager()
{
	GameStates gameState = GameStates::START_MENU;
}


GameStateManager::~GameStateManager()
{
	GameStates gameState = GameStates::START_MENU;
}

void GameStateManager::setGameState(enum GameStates a)
{
	GameStates gameStates = a;
}

enum GameStateManager::getGameState()
{
	return GameStates.gameState;
}

