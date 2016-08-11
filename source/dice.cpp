#include "gameEngine.h"







HANDLE hCon;

enum Color { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE };

void SetColor(Color c) {
	if (hCon == NULL)
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, c);
}


GameEngine::GameEngine() //prompts user for menu and stuff
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
}


GameEngine::~GameEngine()
{
}

void GameEngine::setNumberOfDice(int numDice)
{
	numberOfDice = numDice;
}

int GameEngine::getNumberOfDice()
{
	return numberOfDice;
}

void GameEngine::setGameState(int state)
{
	gameState = state;
}

int GameEngine::getGameState()
{
	return gameState;
}

bool GameEngine::numbDiceCheck(int diNum)
{
	if ((diNum >= 2) && (diNum <= 5)) {
		return true;
	}
	else
		return false;
}

vector<Dice*> GameEngine::startGame(int diceNum)
{
	cout << "start the game!" << endl;

	vector<Dice*> diceGame;
	diceGame.reserve(diceNum);

	for (int i = 0; i < diceNum; i++) {
		Dice *dice = new Dice(4);
		diceGame.push_back(dice);
	}

	return diceGame;

}
