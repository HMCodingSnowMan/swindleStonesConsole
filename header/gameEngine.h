#pragma once
#include "dice.h"
#include <vector>
#include <windows.h>
#include <iostream>

using namespace std;

class GameEngine
{
public:
	GameEngine();
	~GameEngine();
	
//setters and getters	
	void setNumberOfDice(int numDice);
	int getNumberOfDice();
	
	void setGameState(int state);
	int getGameState();

	bool numbDiceCheck(int diNum);

	vector<Dice*> startGame(int diceNum);//ty jeff

private:
	int gameState;
	//gameState can be Waiting(0) or Playing(1)
	int numberOfDice;
	//number of dice can be between 1 and 5
	

};

