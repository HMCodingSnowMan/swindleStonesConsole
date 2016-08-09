#include "dice.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;


dice::dice()
{
	maxValue = 6;
	diceRoll();
}

dice::dice( int a)
{
	maxValue = a;
	diceRoll();
}

dice::~dice()
{
	diceRoll();
	maxValue = 6;
}

void dice::setMaxValue(int value) {
	maxValue = value;
}

int dice::getDiceValue()
{
	return diceValue;
}

int dice::getMaxValue()
{
	return maxValue;
}

void dice::diceRoll() 
{
	diceValue = 1 + (rand() % getMaxValue());
}
