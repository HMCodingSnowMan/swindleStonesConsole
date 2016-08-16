#pragma once
#include <string>
#include <vector>
#include "dice.h"
#include <iostream>

using namespace std;


class Player
{
	vector<Dice> p1Dice
public:
	Player();
	~Player();

	vector<Dice> rollTheDice(vector<Dice>&);//ty jeff

private:
	unsigned int numberOfDice;
};

