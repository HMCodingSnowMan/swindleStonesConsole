#pragma once
#include "dice.h"
#include <vector>
#include <windows.h>
#include <iostream>
#include "GameStateManager.h"
#include <string>
#include "Coin.h"
#include "Player.h"


using namespace std;

class GameEngine
{
	Player p1;
	Player p2;
	Coin coin;
public:
	GameStateManager gsm;
	int logicArray[4] = { 0,0,0,0 };
	GameEngine();
	~GameEngine();
	
//setters and getters	

	void setgDice(int di);
	int getNumberOfDice();
	bool numbDiceCheck(int diNum);

	int coinCheck(string choice);
	//void raise(vector<Dice>& pdice, int ints, int vDice);
	void logicCheck(int ints,int vDice);
	
private:
	//int gameState;
	bool firstTurn;
	//gameState can be Waiting(0) or Playing(1)
	int gameDice;
	//number of dice can be between 1 and 5
	string gState;

	

};

