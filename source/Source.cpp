#include <iostream>
//#include "dice.h"
#include <windows.h>
#include "gameEngine.h"

using namespace std;



int main() {
	GameEngine Game;
	Game.startGame(Game.getNumberOfDice());
	/*dice di;
	dice dic(100);
	int i;*/
	//SetColor(RED);
	//cout << "please enter poop";
	//cin >> i;
	//SetColor(BLUE);
	//cout << "hi hans your number is" << i << endl;
	//int diceV = di.getDiceValue();
	//SetColor(GREEN);
	//cout << "dice value is "  << diceV << endl;
	//int diceM = di.getMaxValue();
	//SetColor(GRAY);
	//cout << "max dice is " << diceM << endl;

	//int ddiceV = dic.getDiceValue();
	//SetColor(TEAL);
	//cout << "dice value is " << ddiceV << endl;
	//int ddiceM = dic.getMaxValue();
	//SetColor(PINK);
	//cout << "max dice is " << ddiceM << endl;


	return 0;

}
