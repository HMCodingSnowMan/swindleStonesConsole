#include "TurnManager.h"



TurnManager::TurnManager()
{
}


TurnManager::~TurnManager()
{
}

void TurnManager::setTurn(int turnNumber)
{
	turnNum = turnNumber;
}

int TurnManager::getTurn()
{
	return turnNum;
}
