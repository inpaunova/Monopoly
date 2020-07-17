#include "StartField.h"

StartField::StartField(string name, int boardPosition)
{
	this->name = name;
	this->boardPosition = boardPosition;
}

void StartField::actionOfPlayerOnTheField(Player * currentPlayer, int diceRollNumber)
{
	cout << "\n" << currentPlayer->getName() << " landed on Go! Collect $200!" << endl;
	currentPlayer->setWealth(currentPlayer->getWealth() + 200);
}

string StartField::getFieldType()
{
	return "start field";
}