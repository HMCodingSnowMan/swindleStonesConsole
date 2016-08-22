#include "Player.h"



Player::Player()
{
}

Player::~Player()
{
}

Player::Player(string name)
{
	pName = name;
}

void Player::setNumberOfDice(int numDice)
{
	numberOfDice = numDice;
}

int Player::getNumberOfDice()
{
	return numberOfDice;
}

void Player::setFirstTurn(bool turn)
{
	firstTurn = turn;
}

bool Player::getFirstTurn()
{
	return firstTurn;
}

void Player::setPName(string name)
{
	pName = name;
}

string Player::getPName()
{
	return pName;
}

void Player::rollTheDice()
{
	cout << "I'll roll the dice! " << numberOfDice <<  endl;
	
	for (int k = 0; k < numberOfDice; k++) {

		Dice newDice = Dice();
		pDice.push_back(newDice);
		//cout << pDice[k].getDiceValue() << k << " the dice value in I loop" << endl;
		pDice[k].setMaxValue(4);
		pDice[k].diceRoll();
	}
	cout << pDice.size()<< " is the size of the player"<< endl;
	
}
