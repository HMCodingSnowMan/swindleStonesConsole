#include "dice.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;


Dice::Dice()
{
	maxValue = 10;
	diceRoll();
	
	
}

Dice::Dice( int a)
{
	maxValue = a;
	diceValue = a;
}

Dice::~Dice()
{
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
