#pragma once
class Dice
{
public:

	Dice();
	Dice(int a);
	~Dice();

	void diceRoll();

	void setMaxValue(int value);
	void setDiceValue(int value);


	int getDiceValue();
	int getMaxValue();


private:
	int diceValue;
	int maxValue;

	
};

