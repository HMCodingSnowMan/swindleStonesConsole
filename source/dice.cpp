#include "dice.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;


Dice::Dice()
{
	maxValue = 0;
	diceRoll();
}

Dice::Dice( int a)
{
	maxValue = a;
	diceRoll();
}

Dice::~Dice()
{
	diceRoll();
	maxValue = 0;
}

void Dice::setMaxValue(int value) {
	maxValue = value;
}

int Dice::getDiceValue()
{
	return diceValue;
}

int Dice::getMaxValue()
{
	return maxValue;
}

void Dice::diceRoll() 
{
	diceValue = 1 + (rand() % getMaxValue());
}
