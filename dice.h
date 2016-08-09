#pragma once
class dice
{
public:

	dice();
	dice(int a);
	~dice();
	void diceRoll();
	void setMaxValue(int value);
	int getDiceValue();
	int getMaxValue();


private:
	int diceValue;
	int maxValue;

	
};

