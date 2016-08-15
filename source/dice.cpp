#include "dice.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;


Dice::Dice()
{
	setMaxValue(4);
	setDiceValue(4);
	
	
}

Dice::Dice( int a)
{
	setMaxValue(4);
	setDiceValue(4);
}

Dice::~Dice()
{
}

void Dice::setMaxValue(int value) {
	maxValue = value;
}

void Dice::setDiceValue(int value)
{
	diceValue = value;
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
