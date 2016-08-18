#include "GameStateManager.h"



GameStateManager::GameStateManager()
{
	GameStates gameState = GameStates::START_MENU;
}


GameStateManager::~GameStateManager()
{
	GameStates gameState = GameStates::START_MENU;
}

string GameStateManager::getGameStateString()
{
	switch (gameState) {
	case (GameStates::START_MENU): return "StartMenu";
	case (GameStates::GAME_INIT): return "GameInit";
	case (GameStates::ROLL_DICE): return "RollDice";
	case (GameStates::COINFLIP): return "CoinFlip";
	case (GameStates::TURN): return "Turn";
	case (GameStates::CALL): return "Call";
	case (GameStates::RESULT): return "Result";
	case (GameStates::RETRY): return "Retry";
	case (GameStates::GAMEOVER): return "GameOver";
	default: return  "ERROR";

	}
}

void GameStateManager::setGameState(GameStates a)
{

	if (gameState == a)
		return;
	gameState = a;
}

GameStateManager::GameStates GameStateManager::getGameState()
{
	return gameState;
}



//void GameStateManager::GameStates GameStateManager::setGameState(GameStates a)
//{
//	if (gameState == a)
//		return;
//	gameState = a;
//}

