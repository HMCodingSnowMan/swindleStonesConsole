#pragma once
#include "dice.h"
#include <vector>

class gameEngine
{
public:
	gameEngine();
	~gameEngine();
	
//setters and getters	
	void setNumberOfDice(int numDice);
	int getNumberOfDice();
	
	void setGameState(int state);
	int getGameState();

	bool numbDiceCheck(int diNum);

	std::vector<Dice*> startGame(int diceNum);

	//dice *startGame(int diceNum);
private:
	int gameState;
	//gameState can be Waiting(0) or Playing(1)
	int numberOfDice;
	//number of dice can be between 1 and 5
	

};

