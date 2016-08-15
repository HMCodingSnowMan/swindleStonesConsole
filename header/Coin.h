#pragma once
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

class Coin
{
public:
	Coin();
	~Coin();
	void coinFlip();
	string getCoinValue();
	bool coinMatch(string);


private:
	string coinValue; //heads or tails
};

