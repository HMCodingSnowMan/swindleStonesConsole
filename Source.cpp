#include <iostream>
#include "dice.h"
#include <windows.h>
#include "gameEngine.h"
#include "Coin.h"
#include "Player.h"


using namespace std;



int main() {
	GameEngine Game;
	
	//GameStateManager gsm;
	//gsm.setGameState(GameStateManager::GameStates::GAME_INIT);
	//cout << gsm.getGameState() << endl;
	//gsm.setGameState(GameStateManager::GameStates::ROLL_DICE);
	//cout << gsm.getGameState() << endl;
	//gsm.setGameState(GameStateManager::GameStates::COINFLIP);
	//cout << gsm.getGameState() << endl;
	//gsm.setGameState(GameStateManager::GameStates::GAMEOVER);
	//cout << gsm.getGameState() << endl;

	//Coin cn;

	//for (int i = 0; i < 20; i++) {
	//	cn.coinFlip();
	//	cout << "the coin value is " << cn.getCoinValue() << endl;
		
	//}

	//Player p1;
	//p1.setNumberOfDice(5);
	//cout << p1.getNumberOfDice() << endl;
	//p1.rollTheDice();
	//for (int i = 0; i < p1.getNumberOfDice(); i++)
	//{
	//	cout << p1.pDice[i].getDiceValue() << endl;
	//}


	//Dice di;
	//cout << di.getDiceValue() << endl;
	//cout << di.getMaxValue() << endl;
	return 0;

}