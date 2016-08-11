#include "GameStateManager.h"



GameStateManager::GameStateManager()
{
	GameStates gameState = GameStates::START_MENU;
}


GameStateManager::~GameStateManager()
{
	GameStates gameState = GameStates::START_MENU;
}

void GameStateManager::setGameState(enum GameStates a)//setGameState doesn't work
{
	GameStates gameStates = a;
}

enum GameStateManager::getGameState()//GAmeStateManager Can't set up.
{
	return GameStates.gameState;
}

