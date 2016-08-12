#pragma once
#include "dice.h"
#include <vector>
#include <windows.h>
#include <iostream>
#include "GameStateManager.h"
#include <string>

using namespace std;

class GameEngine
{
public:
	GameStateManager gsm;

	GameEngine();
	~GameEngine();
	
//setters and getters	
	void setNumberOfDice(int numDice);
	int getNumberOfDice();
	
	//void setGameState();
	//string getGameState();



	bool numbDiceCheck(int diNum);

	void rollTheDice(vector<Dice>&);//ty jeff

private:
	//int gameState;
	//gameState can be Waiting(0) or Playing(1)
	int numberOfDice;
	//number of dice can be between 1 and 5
	string gState;
	

};

