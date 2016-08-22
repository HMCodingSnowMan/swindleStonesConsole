#pragma once
#include <string>
#include <vector>
#include "dice.h"
#include <iostream>

using namespace std;


class Player
{
	

public:

	vector<Dice> pDice;

	Player();
	~Player();

	Player(string name);

	void setNumberOfDice(int numDice);
	int getNumberOfDice();

	void setFirstTurn(bool turn);
	bool getFirstTurn();

	void setPName(string name);
	string getPName();

	void rollTheDice();//ty jeff

private:
	int numberOfDice;
	bool firstTurn;
	string pName;
};

