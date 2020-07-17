#include "GoToJail.h"


GoToJailField::GoToJailField(string name, int boardPosition)
{
	this->name = name;
	this->boardPosition = boardPosition;
}

void GoToJailField::actionOfPlayerOnTheField(Player * currentPlayer, int diceRollNumber)
{
	cout << "\n" << currentPlayer->getName() << " has been found guilty of jaywalking. Go straight to Alkatraz. Do not pass Go. Do not collect $200." << endl;
	currentPlayer->setPosition(10);
	currentPlayer->setIsInJail(true);
}

string GoToJailField::getFieldType()
{
	return "go to jail";
}
