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

	

	while (gsm.getGameStateString().compare("GameOver")!=0) {
		switch (gsm.getGameState()) {
		case GameStateManager::GameStates::START_MENU:
			startMenu(p1, p2);
			gsm.setGameState(GameStateManager::GameStates::GAME_INIT);
			cout << "ending start menu" << endl;
			break;

		case GameStateManager::GameStates::GAME_INIT:
			//game init
			
			setGameInit(p1, p2);
			
			gsm.setGameState(GameStateManager::GameStates::ROLL_DICE);
			
			break;

		case GameStateManager::GameStates::ROLL_DICE:
			//setting up dice and sets logicArray! 
			initRollAll(p1, p2);
			gsm.setGameState(GameStateManager::GameStates::COINFLIP);
			break;

		case GameStateManager::GameStates::COINFLIP:
			//setting up the coinFlip!
			firstCoin(p1);
			gsm.setGameState(GameStateManager::GameStates::TURN);
			break;

		case GameStateManager::GameStates::TURN:
			//starting turn!!
			SetColor(RED);
			
			//this sets up the dice and logic check
			//cout << gsm.getGameStateString() << "it's time to start the turns!" << endl << flush;
			playerDiceInfo(p1);
			
			//this sets up the first turn! either the comp or the player will go first!
			if (turnNum <1) {
				firstTurnGoes(p1);
				
			}
			//while (gsm.getGameStateString().compare("Turn") == 0) {
			else
				turnPlus();
			break;

		case GameStateManager::GameStates::CPTURN:
			{
				cpTurn();
				break;
			}
		case GameStateManager::GameStates::CALL:
			logicCheck();
			break;


		case GameStateManager::GameStates::RESULT:
			resultScreen();
			break;

		case GameStateManager::GameStates::RETRY:
			reTryScreen();

			break;

		default:
			SetColor(RED);
			cout << "hi"<< endl;
			cout << "look what you've done! you've broken my game! " << endl;
			cout << "leave!" << endl;
			gsm.setGameState(GameStateManager::GameStates::GAMEOVER);
			break;
		}//end of gState switch statements
		//gsm.setGameState(GameStateManager::GameStates::GAMEOVER);
	}//end of while(gState!=GameOver)
	gameOverScreen();
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

void GameEngine::setTotalGameDice(Player *p, Player *q)
{
	totalGameDice = p->getNumberOfDice() + q->getNumberOfDice();
}

int GameEngine::getTotalGameDice()
{
	return totalGameDice;
}

void GameEngine::incTurnNum()
{
	turnNum++;
}

void GameEngine::resetTurnNum()
{
	turnNum = 0;
}

void GameEngine::startMenu(Player *p, Player *q)
{
	gsm.setGameState(GameStateManager::GameStates::START_MENU);
	cout << gsm.getGameStateString() << endl;

	SetColor(DARKBLUE);
	cout << "Welcome to the SwindleStones! I'm gonna take your money!" << endl;


	SetColor(DARKGREEN);

	cout << "We can have a quick game with 2 dice, a long game with 5 dice, or anything inbetween" << endl;
	cin >> gameDice;
	while (!numbDiceCheck(gameDice)) {
		if (cin.fail()) {
			cout << "that doesn't work please put an int between 2 and 5" << endl;
			cin.clear();
			cout << "I cleared it! " << endl;
			cin.ignore(256, '\n');
			cin >> gameDice;

		}
		else {


			cout << "We do not play with that many dice. Try again. How many dice would you like to play with?" << endl;

			cin >> gameDice;
		}
	}
	SetColor(RED);
	cout << "excellent lets play the game with " << getNumberOfgDice() << " dice" << endl;
	p->setNumberOfDice(gameDice);
	q->setNumberOfDice(gameDice);

}


void GameEngine::setGameInit(Player *p, Player *q)
{
	
	
	//cout << "p.setNumDice=" << p->getNumberOfDice() << endl;
	
	//cout << "q.setNumDice=" << q->getNumberOfDice() << endl;
	setTotalGameDice(p, q);
	//cout << totalGameDice << endl;
	//cout << p.getNumberOfDice() << "p1" << endl;
	//cout << q.getNumberOfDice() << "p2" << endl;
}

void GameEngine::initRollAll(Player* p, Player* q)
{
	gsm.setGameState(GameStateManager::GameStates::ROLL_DICE);
	//cout << gsm.getGameStateString() << endl;
	SetColor(GREEN);
	p->rollTheDice();
	q->rollTheDice();
	setLogicArray(p);
	setLogicArray(q);
}

void GameEngine::firstCoin(Player *p)
{
	gsm.setGameState(GameStateManager::GameStates::COINFLIP);
	cout << gsm.getGameStateString() << " time to flip the coin! " << endl;
	cout << "what do you want to call? Heads or tails? if you win you go first!" << endl;
	string choice = "";
	cin >> choice;
	while (!coinCheck(choice))
	{
		cout << "that wasn't one of the choices! Please enter heads or tails" << flush << endl;
		cin >> choice;
	}
	if (coin.coinMatch(choice)) {
		cout << "you get to go first!" << endl;
		p->setFirstTurn(true);
	}
	else {
		cout << "you get to go second!" << endl;
		p->setFirstTurn(false);
	}

}



bool GameEngine::numbDiceCheck(int diNum)
{
	
	if ((diNum >= 2) && (diNum <= 5)) {
		return true;
	}
	else

		return false;
}

void GameEngine::pLoseDice(Player *p)
{
	p->setNumberOfDice(p->getNumberOfDice() - 1);
	if (p->getNumberOfDice() == 0) {
		gsm.setGameState(GameStateManager::GameStates::GAMEOVER);
	}
	else
		cout << p->getPName() << "lost a dice!" << endl;
}



bool GameEngine::coinCheck(string choice)
{
	
	bool pass;//if the answers are either heads or tails

	for (unsigned int s = 0; s < choice.length(); s++) {
		choice[s] = tolower(choice[s]);
	}
	if (choice.compare("heads") == 0) {
		
		return pass = true;
		
	}
	else if (choice.compare("tails") == 0) {
		return pass = true;
		

	}
	else
		return pass = false;
}

void GameEngine::setLogicArray(Player *p)
{
	for (int i = 0; i < p->getNumberOfDice(); i++) {
		logicArray[p->pDice[i].getDiceValue() - 1] = logicArray[p->pDice[i].getDiceValue() - 1] + 1;
	}
}

void GameEngine::playerDiceInfo(Player *p)
{
	SetColor(BLUE);
	
	int j = p->getNumberOfDice();
	cout << j << "is the value of the dice" << endl;
	cout << "you have ";
	for (int i = 0; i < j; i++) {
	
		cout << p->pDice[i].getDiceValue() << " ";
	}
	cout << endl;

}

void GameEngine::clearLogicArray()
{
	for (int i = 0; i < 4; i++) {
		logicArray[i] = 0;

	}
}

bool GameEngine::logicCheck()
{
	if (logicArray[valueDice - 1] >= instances) {
		cout << "good guess! the other player loses dice" << endl;
		gsm.setGameState(GameStateManager::GameStates::RESULT);
		return true;
	}
	else
	{
		cout << "Wrong! you lose a dice!" << endl;
		gsm.setGameState(GameStateManager::GameStates::RESULT);
		return false;
	}
}

void GameEngine::logicResult(Player *p, Player *q)
{
	if (logicCheck()) {
		q->setNumberOfDice(q->getNumberOfDice() - 1);
	}
	else
	{
		p->setNumberOfDice(p->getNumberOfDice() - 1);
	}
}

void GameEngine::setTurn(int a)
{
	currentTurn = a;
}

int GameEngine::getTurn()
{
	return currentTurn;
}

void GameEngine::firstTurnGoes(Player *p)
{
	if (p->getFirstTurn()) {
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
	incTurnNum();

}

void GameEngine::turnOneC()
{
	cout << "I'm cheating I'm going to bet " << logicArray[3] << " 4" << endl;
	instances = logicArray[3];
	valueDice = 4;
	incTurnNum();
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
			gsm.setGameState(GameStateManager::GameStates::CPTURN);
			setTurn(0);
			break;
		case 'c':
			cout << "Call time to see the results" << endl;
			
			gsm.setGameState(GameStateManager::GameStates::CALL);
			break;
		default:
			cout << "that wasn't an option! try again!" << endl;
			break;
		}
	}
}

void GameEngine::cpTurn()
{
	int pcNumDice = 0;
	int pcDiceVale = 0;
	cout << "HAI! That's a good bet. I think I will..." << endl;
	coin.coinFlip();
	if (coinCheck("heads")) {
		cout << "I'm going to raise!" << endl;
		cout << "I'll bet ";
		gsm.setGameState(GameStateManager::GameStates::TURN);
		setTurn(1);
	}
	else
	{
		cout << "Hah I'm gonna call" << endl;
		gsm.setGameState(GameStateManager::GameStates::CALL);
	}
	
}

void GameEngine::resultScreen()
{
	cout << "Welcome to the results of last round!" << endl;
	//cout << "You now have " << p1.getNumberOfDice() << " dice left." << endl;
	//cout << "The other player has " << p2.getNumberOfDice() << " dice left" << endl;
	cout << "Are you ready for the next round? (y/n)" << endl;
	char a;
	bool pass;
	cin >> a;
	do {
		if (a == 'y') {
			gsm.setGameState(GameStateManager::GameStates::RETRY);
			pass = true;
		}
		else if (a == 'n') {
			gsm.setGameState(GameStateManager::GameStates::GAMEOVER);
			pass = true;
		}
		else
		{
			cout << "I do not understand that. Do you want to do another round? (y/n)" << endl;
			cin >> a;
			pass = false;
		}
	} while (!pass);


		

}

void GameEngine::reTryScreen()
{
	cout << "going in for the next round!" << endl;
	clearLogicArray();

	gsm.setGameState(GameStateManager::GameStates::GAME_INIT);
}

void GameEngine::gameOverScreen()
{
	for (int i = 0; i < 20; i++) {
		cout << endl;
	}

	cout << "Game Over! Well Played! Come back and play again! " << endl;

	for (int i = 0; i < 20; i++) {
		cout << endl;
	}

}






