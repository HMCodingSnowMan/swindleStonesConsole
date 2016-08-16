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
	p1.rollTheDice();
	p2.rollTheDice();
	
	gsm.setGameState(GameStateManager::GameStates::COINFLIP);
	cout << gsm.getGameStateString() << " time to flip the coin! " << endl;
	cout << "what do you want to call? Heads or tails? if you win you go first!" << endl;
	string choice = "";
	cin >> choice;
	while (coinCheck(choice) == 1)
	{
		cout << "that wasn't one of the choices! Please enter heads or tails" << flush << endl;
		cin >> choice;
	} 
	if (coin.coinMatch(choice)) {
		cout << "you get to go first!" << endl;
	}
	else {
		cout << "you get to go second!" << endl;
	}
	
	gsm.setGameState(GameStateManager::GameStates::TURN);
	SetColor(BLUE);
	cout << gsm.getGameStateString() << "it's time to start the turns!" << endl << flush;
	char e;
	int instances=0;
	int valueDice=0;
	for (int i = 0; i < p1Dice.size(); i++) {
		cout << "you have" << p1Dice[i].getDiceValue() << " ";
		logicArray[p1.pDice[i].getDiceValue() - 1] = logicArray[p1.pDice[i].getDiceValue() - 1] + 1;
		logicArray[p2.pDice[i].getDiceValue() - 1] = logicArray[p2.pDice[i].getDiceValue() - 1] + 1;
	}
	while (gsm.getGameStateString().compare("Turn") == 0) {

		cout << endl << "would you like to Raise(r) or Call(c)?" << endl;
		cin >> e;
		switch (e) {
		case 'r':
			cout << "how many instances of the dice are you thinking of?" << endl;
			cin >> instances;
			cout << "what value of dice did you want to use? " << endl;
			cin >> valueDice;
			gsm.setGameState(GameStateManager::GameStates::RESULT);
			break;
		case 'c':
			cout << "CALL time to see the results" << endl;
			gsm.setGameState(GameStateManager::GameStates::RESULT);
			logicCheck(instances, valueDice);
			break;
		default:
			cout << "that wasn't an option! try again!" << endl;
			gsm.setGameState(GameStateManager::GameStates::RESULT);
			break;
		}
	}
	for (int i = 0; i < 4; i++) {
		SetColor(RED);
		cout << "the dice values are" << p1Dice[i].getDiceValue() << endl;
		SetColor(GREEN);
		cout << "the logic array has" << logicArray[i] << endl;
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

void GameEngine::setNumberOfDice2(int numDice)
{
	numberOfDice2 = numDice;
}

int GameEngine::getNumberOfDice2()
{
	return numberOfDice2;
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

void GameEngine::setFirstTurn(bool turn)
{
	firstTurn = turn;
}

bool GameEngine::getFirstTurn()
{
	return firstTurn;
}

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
		myDiceSet[k].setMaxValue(4);
		myDiceSet[k].diceRoll();
	}
	

	return myDiceSet;

}

int GameEngine::coinCheck(string choice)
{
	
	int pass;//if the answers are either heads or tails

	for (unsigned int s = 0; s < choice.length(); s++) {
		choice[s] = tolower(choice[s]);
	}
	if (choice.compare("heads") == 0) {
		
		return pass = 0;
		
	}
	else if (choice.compare("tails") == 0) {
		return pass = 0;
		

	}
	else
		return pass = 1;
}

void GameEngine::logicCheck(int ints, int vDice)
{
	if (logicArray[vDice - 1] >= ints) {
		cout << "good guess! the other player loses dice" << endl;
	}
	else
		cout << "Wrong! you lose a dice!" << endl;
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