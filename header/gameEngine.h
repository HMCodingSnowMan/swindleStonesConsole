#pragma once
#include "dice.h"
#include <vector>
#include <windows.h>
#include <iostream>
#include "GameStateManager.h"
#include <string>
#include "Coin.h"

using namespace std;

class GameEngine
{
	vector<Dice> p1Dice;
	vector<Dice> p2Dice;
	Coin coin;
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

	vector<Dice> rollTheDice(vector<Dice>&);//ty jeff

	int coinCheck(string choice);

private:
	//int gameState;
	//gameState can be Waiting(0) or Playing(1)
	unsigned int numberOfDice;
	//number of dice can be between 1 and 5
	string gState;
	

};

