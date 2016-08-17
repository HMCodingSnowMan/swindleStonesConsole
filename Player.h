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

	void setNumberOfDice(int numDice);

	int getNumberOfDice();

	void setFirstTurn(bool turn);

	bool getFirstTurn();

	vector<Dice> rollTheDice();

private:
	unsigned int numberOfDice;
	bool firstTurn;
};

