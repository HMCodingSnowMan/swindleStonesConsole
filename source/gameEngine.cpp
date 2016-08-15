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
	gsm.setGameState(GameStateManager::GameStates::START_MENU);
	cout << gsm.getGameStateString() << endl;

	SetColor(DARKBLUE);
	cout << "Welcome to the SwindleStones! I'm gonna take your money!" << endl;
	gsm.setGameState(GameStateManager::GameStates::GAME_INIT);
	cout << gsm.getGameStateString() << endl;
	SetColor(DARKGREEN);
	
	cout << "We can have a quick game with 2 dice, a long game with 5 dice, or anything inbetween" << endl;
	cin >> numberOfDice;
	while (numbDiceCheck(getNumberOfDice()) == false) {
		cout << "We do not play with that many dice. Try again. How many dice would you like to play with?" << endl;
		cin >> numberOfDice;
	}



	SetColor(RED);
	cout << "excellent lets play the game with " << getNumberOfDice() << " dice" << endl;

	
	gsm.setGameState(GameStateManager::GameStates::ROLL_DICE);
	cout << gsm.getGameStateString() << endl;
	SetColor(GREEN);
	rollTheDice(p1Dice);
	rollTheDice(p2Dice);
	
	gsm.setGameState(GameStateManager::GameStates::COINFLIP);
	cout << gsm.getGameStateString() << " time to flip the coin! " << endl;
	cout << "what do you want to call? Heads or tails?" << endl;
	string choice = "";
	cin >> choice;
	while (coinCheck(choice) == 1)
	{
		cout << "that wasn't one of the choices! Please enter heads or tails" << endl;
		cin >> choice;
	} 


	
	


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

//void GameEngine::setGameState(int state)
//{
//	gameState = state;
//}
//
//int GameEngine::getGameState()
//{
//	return gameState;
//}

bool GameEngine::numbDiceCheck(int diNum)
{
	if ((diNum >= 2) && (diNum <= 5)) {
		return true;
	}
	else
		return false;
}

vector<Dice> GameEngine::rollTheDice(vector<Dice>& myDiceSet)
{
	cout << "I'll roll the dice!" << endl;

	unsigned int k;

	for (k = 0; k < numberOfDice; k++) {
		
		Dice newDice = Dice();
		myDiceSet.push_back(newDice);
		//cout << myDiceSet[i].getDiceValue() << i << " the dice value in I loop" << endl;
		myDiceSet[k].setMaxValue(5);
		//cout << myDiceSet[i].getMaxValue() << i << " the Max value in I loop" << endl;
	}
	
	//for (unsigned int j = 0; j < k; j++) {
		//print the dice value!
		//cout << myDiceSet[j].getDiceValue() << j << " the dice value " << endl;
		//cout << myDiceSet[j].getMaxValue() << j << " the max value " << endl;

	//}
	return myDiceSet;

}

int GameEngine::coinCheck(string choice)
{
	Coin c;
	int pass;
	for (unsigned int s = 0; s < choice.length(); s++) {
		choice[s] = tolower(choice[s]);
	}
	if (choice.compare("heads") == 0) {
		if (c.coinMatch(choice)) {
			cout << "you got it right! with heads" << endl;
		}
		//cout << "it passed! with heads;" << endl;
		else
			cout << "you got it wrong with heads" << endl;
		return pass = 0;
		
	}
	else if (choice.compare("tails") == 0) {
		if (c.coinMatch(choice)) {
			cout << "you got it right! with tails" << endl;
		}
		//cout << "it passed! with tails;" << endl;
		else
			cout << "you got it wrong with tails" << endl;
		return pass = 0;
		

	}
	else
		return pass = 1;
}



/*
vector<Dice*> gameEngine::startGame(int diceNum)
{
	vector<Dice*> DiceGame;
	DiceGame.reserve(diceNum);

	for (int i = 0; i < diceNum; i++) {
		Dice *dice = new Dice(4);
		DiceGame.push_back(dice);
	}

	return DiceGame;
*/
