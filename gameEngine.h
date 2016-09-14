#pragma once
#include "dice.h"
#include <vector>
#include <windows.h>
#include <iostream>
#include "GameStateManager.h"
#include <string>
#include "Coin.h"
#include "Player.h"
#include "TurnManager.h"


using namespace std;

class GameEngine
{
	//vector<Dice> p1Dice;
	//vector<Dice> p2Dice;

public:
	Player* p1 = new Player();
	Player* p2 = new Player();
	Coin coin;
	GameStateManager gsm;
	TurnManager *tm = new TurnManager();
	int logicArray[4] = { 0,0,0,0 };
	GameEngine();
	~GameEngine();
	
//setters and getters	
	void setNumberOfgDice(int numDice);
	int getNumberOfgDice();

	void setTotalGameDice(Player *p, Player *q);
	int getTotalGameDice();

	
	
	void startMenu(Player *p, Player *q);

	void setGameInit(Player* p, Player* q);
	void initRollAll(Player* p, Player* q);
	void firstCoin(Player *p);

	bool numbDiceCheck(int diNum);
	void pLoseDice(Player *p);

	bool coinCheck(string choice);
	
	void setLogicArray(Player *p);
	void playerDiceInfo(Player *p);
	void clearLogicArray();
	
	void incTurnNum();
	void resetTurnNum();

	void setTurn(int a);
	int getTurn();

	void firstTurnGoes(Player *p);
	void turnOne();//if Player is First
	void turnOneC();//if Computer goes First
	void turnPlus();
	void cpTurn();//making the computer turn

	bool logicCheck();
	void logicResult(Player *p, Player *q);

	void resultScreen();

	void reTryScreen();

	void gameOverScreen();
	


	
private:
	//int gameState;
	bool firstTurn;
	//gameState can be Waiting(0) or Playing(1)
	int gameDice;
	int totalGameDice;
	int currentTurn; // player is 0, pc is 1;
	int turnNum=0;

	char e;
	int instances = 0;
	int valueDice = 0;
	//unsigned int numberOfDice2;
	//number of dice can be between 1 and 5
	
	

};

