#include "Jail.h"

Jail::Jail(string name, int boardPosition)
{
	this->name = name;
	this->boardPosition = boardPosition;
}

void Jail::actionOfPlayerOnTheField(Player * currentPlayer, int diceRollNumber)
{
	cout << "\nYou landed on jail. Just visiting!" << endl;
}

string Jail::getFieldType()
{
	return "jail";
}
