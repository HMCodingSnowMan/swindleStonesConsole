#pragma once

class GameStateManager
{
public:
	GameStateManager();
	~GameStateManager();

	//Setters and getters :D
	void setGameState(enum GameStates a);
	enum getGameState();




private:
	static enum class GameStates {START_MENU, GAME_INIT, ROLL_DICE, COINFLIP,TURN, CALL, RESULT, RETRY, GAMEOVER };
	//StartMenu: Displays starting prompt to ask the user number dice;
	//GameInit: Starts putting the Information from StartMenu into GameEngine;
	//RollDice: Rolls the dice
	//CoinFlip: Determines who Goes first this Round
	//Turn: Reavels Dice to player and prompts player what to do. Takes place between player and other player, could be com.
	//Call: Takes the dice Values and dice count, and compared to the called amount
	//Result:Determines who loses a Dice, Who wins
	//Retry: prompts to retry
	//GameOver: prompts Gameover ROll credits and leave

	GameStates gameStates;
};

