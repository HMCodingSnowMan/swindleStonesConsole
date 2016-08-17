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
	cin >> gameDice;
	while (numbDiceCheck(gameDice) == false) {
		cout << "We do not play with that many dice. Try again. How many dice would you like to play with?" << endl;
		cin >> gameDice;
	}
	p1.setNumberOfDice(gameDice);
	p2.setNumberOfDice(gameDice);
	cout << p1.getNumberOfDice() << "p1" << endl;
	cout << p2.getNumberOfDice() << "p2" << endl;


	SetColor(RED);
	cout << "excellent lets play the game with " << getNumberOfgDice() << " dice" << endl;

	
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
		p1.setFirstTurn(true);
	}
	else {
		cout << "you get to go second!" << endl;
		p1.setFirstTurn(false);
	}
	
	gsm.setGameState(GameStateManager::GameStates::TURN);
	SetColor(BLUE);




	//this sets up the dice and logic check
	cout << gsm.getGameStateString() << "it's time to start the turns!" << endl << flush;


	setLogicArray(p1);
	setLogicArray(p2);
	cout << "you have ";
	playerDiceInfo(p1);
	cout << endl;
	setGState(gsm.getGameStateString());
	
	//this sets up the first turn! either the comp or the player will go first!
	firstTurnGoes(p1);
	
	
	//while (gsm.getGameStateString().compare("Turn") == 0) {
	turnPlus();
}


GameEngine::~GameEngine()
{
}

void GameEngine::setNumberOfgDice(int numDice)
{
	gameDice = numDice;
}

int GameEngine::getNumberOfgDice()
{
	return gameDice;
}

void GameEngine::setGState(string state)
{
	gState = state;
}

string GameEngine::getGState()
{
	return gState;
}



bool GameEngine::numbDiceCheck(int diNum)
{
	if ((diNum >= 2) && (diNum <= 5)) {
		return true;
	}
	else
		return false;
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

void GameEngine::setLogicArray(Player p)
{
	for (int i = 0; i < p.getNumberOfDice(); i++) {
		logicArray[p.pDice[i].getDiceValue() - 1] = logicArray[p.pDice[i].getDiceValue() - 1] + 1;
	}
}

void GameEngine::playerDiceInfo(Player p)
{
	SetColor(GREEN);
	for (int i = 0; i < p.getNumberOfDice(); i++) {
		cout << p.pDice[i].getDiceValue() << " ";
	}
}

bool GameEngine::logicCheck(int ints, int vDice)
{
	if (logicArray[vDice - 1] >= ints) {
		cout << "good guess! the other player loses dice" << endl;
		return true;
	}
	else
	{
		cout << "Wrong! you lose a dice!" << endl;
		return false;
	}
}

void GameEngine::logicResult(bool logic, Player p, Player q)
{
	if (logic) {
		q.setNumberOfDice(q.getNumberOfDice() - 1);
	}
	else
	{
		p.setNumberOfDice(p.getNumberOfDice() - 1);
	}
}

void GameEngine::firstTurnGoes(Player p)
{
	if (p.getFirstTurn()) {
		turnOne();
	}
	else
		turnOneC();
}

void GameEngine::turnOne()
{
	cout << "what would you like to bet?" << endl;
	cout << "what dice value are you betting" << endl;
	cin >> valueDice;
	cout << "how many of that dice are you betting?" << endl;
	cin >> instances;
}

void GameEngine::turnOneC()
{
	cout << "I'm cheating I'm going to bet " << logicArray[3] << " 4" << endl;
	instances = logicArray[3];
	valueDice = 4;
}

void GameEngine::turnPlus()
{
	while (gsm.getGameStateString().compare("Turn")==0) {
		cout << "would you like to Raise(r) or Call(c)?" << endl;
		cin >> e;
		switch (e) {
		case 'r':
			cout << "how many instances of the dice are you thinking of?" << endl;
			cin >> instances;
			cout << "what value of dice did you want to use? " << endl;
			cin >> valueDice;
			cout << "the current bet is " << instances << " 's " << valueDice << endl;
			break;
		case 'c':
			cout << "CALL time to see the results" << endl;
			logicCheck(instances, valueDice);
			gsm.setGameState(GameStateManager::GameStates::RESULT);
			break;
		default:
			cout << "that wasn't an option! try again!" << endl;
			break;
		}
	}
}





