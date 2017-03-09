#pragma once
class TurnManager
{
public:
	TurnManager();
	~TurnManager();
	//@@ToDo
	//Transfer from GameEngine's turn to here.


	//set/get turn
	void setTurn(int turnNumber);
	int getTurn();
	//Todo
	void turnOne();
	void turnOneC();
	//Todo
	void TurnPlusPlus();
	//Todo
	void cpTurn();

private:
	int turnNum;
};

