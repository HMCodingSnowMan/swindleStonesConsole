#include "Coin.h"





Coin::Coin()
{
	coinFlip();
	
}


Coin::~Coin()
{
}

void Coin::coinFlip()
{
	int flip;
	flip = 1+ rand() % 100;
	if (flip <=50) {
		coinValue = "heads";
	}
	else
		coinValue = "tails";
}

string Coin::getCoinValue()
{
	return coinValue;
}

bool Coin::coinMatch(string a)
{
	if (coinValue.compare(a) == 0) {
		return true;
	}
	else
		return false;
}
