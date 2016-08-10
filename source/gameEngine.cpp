#include "gameEngine.h"
#include "dice.h"
#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

HANDLE hCon;

enum Color { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE };

void SetColor(Color c) {
	if (hCon == NULL)
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, c);
}


gameEngine::gameEngine()
{
	setGameState(0);
	cout << getGameState() << endl;
	SetColor(DARKBLUE);
	
	cout << "Welcome to the SwindleStones! I'm gonna take your money!" << endl;
	SetColor(DARKGREEN);
	
	cout << "We can have a quick game with 2 dice, a long game with 5 dice, or anything inbetween" << endl;
	cin >> numberOfDice;
	while (numbDiceCheck(getNumberOfDice()) == false) {
		cout << "We do not play with that many dice. Try again. How many dice would you like to play with?" << endl;
		cin >> numberOfDice;
	}
	cout << "excellent lets play the game with " << getNumberOfDice() << " dice" << endl;
	setGameState(1);
	cout << getGameState() << endl << flush;
	int a = 0;
	
	while (a < numberOfDice) {
		cout << "hi" << endl;
		a++;
	}
	

}


gameEngine::~gameEngine()
{
}

void gameEngine::setNumberOfDice(int numDice)
{
	numberOfDice = numDice;
}

int gameEngine::getNumberOfDice()
{
	return numberOfDice;
}

void gameEngine::setGameState(int state)
{
	gameState = state;
}

int gameEngine::getGameState()
{
	return gameState;
}

bool gameEngine::numbDiceCheck(int diNum)
{
	if ((diNum >= 2) && (diNum <= 5)) {
		return true;
	}
	else
		return false;
}

//dice* gameEngine::startGame(int diceNum)
//{
//	if (diceNum == 2) {
//		dice *DiceGame[2];
//	}
//	else if (diceNum == 3) {
//		dice *DiceGame[3];
//	}
//	else if (diceNum == 4) {
//		dice *DiceGame[4];
//	}
//	else
//		dice *DiceGame[5];
//
//}
