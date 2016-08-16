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
	vector<Dice> p1Dice;
	vector<Dice> p2Dice;
	Player p1;
	Player p2;
	Coin coin;
public:
	GameStateManager gsm;
	int logicArray[4] = { 0,0,0,0 };
	GameEngine();
	~GameEngine();
	
//setters and getters	
	void setNumberOfDice(int numDice);
	int getNumberOfDice();

	void setNumberOfDice2(int numDice);
	int getNumberOfDice2();
	
	//void setGameState();
	//string getGameState();

	void setFirstTurn(bool turn);
	bool getFirstTurn();

	bool numbDiceCheck(int diNum);

	vector<Dice> rollTheDice(vector<Dice>&);//ty jeff

	int coinCheck(string choice);
	//void raise(vector<Dice>& pdice, int ints, int vDice);
	void logicCheck(int ints,int vDice);

	
private:
	//int gameState;
	bool firstTurn;
	//gameState can be Waiting(0) or Playing(1)
	unsigned int numberOfDice;
	unsigned int numberOfDice2;
	//number of dice can be between 1 and 5
	string gState;

	

};

