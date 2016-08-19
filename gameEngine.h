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
	//vector<Dice> p1Dice;
	//vector<Dice> p2Dice;
	Player p1;
	Player p2;
	Coin coin;
public:
	GameStateManager gsm;
	int logicArray[4] = { 0,0,0,0 };
	GameEngine();
	~GameEngine();
	
//setters and getters	
	void setNumberOfgDice(int numDice);
	int getNumberOfgDice();

	void setTotalGameDice(Player p, Player q);
	int getTotalGameDice();

	void incTurnNum();
	void resetTurnNum();
	
	void startMenu();

	void setGameInit(Player p, Player q);
	void initRollAll(Player p, Player q);
	void firstCoin();

	bool numbDiceCheck(int diNum);
	void pLoseDice(Player p);

	bool coinCheck(string choice);
	
	void setLogicArray(Player p);
	void playerDiceInfo(Player p);
	
	bool logicCheck();
	void logicResult(Player p, Player q);
	
	void firstTurnGoes(Player p);
	void turnOne();//if Player is First
	void turnOneC();//if Computer goes First
	void turnPlus();

	void resultScreen();
	
private:
	//int gameState;
	bool firstTurn;
	//gameState can be Waiting(0) or Playing(1)
	int gameDice;
	int totalGameDice;

	int turnNum=0;

	char e;
	int instances = 0;
	int valueDice = 0;
	//unsigned int numberOfDice2;
	//number of dice can be between 1 and 5
	
	

};

