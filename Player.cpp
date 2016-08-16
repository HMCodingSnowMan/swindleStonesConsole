#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
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

vector<Dice> Player::rollTheDice()
{
	cout << "I'll roll the dice!" << endl;

	unsigned int k;

	for (k = 0; k < numberOfDice; k++) {

		Dice newDice = Dice();
		pDice.push_back(newDice);
		//cout << myDiceSet[i].getDiceValue() << i << " the dice value in I loop" << endl;
		pDice[k].setMaxValue(4);
		pDice[k].diceRoll();
	}
	return pDice;
}
