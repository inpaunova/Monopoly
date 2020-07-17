#include "IncomeTax.h"

IncomeTax::IncomeTax(string name, int boardPosition)
{
	this->name = name;
	this->boardPosition = boardPosition;
}

string IncomeTax::getFieldType()
{
	return "income tax";
}

void IncomeTax::actionOfPlayerOnTheField(Player *currentPlayer, int diceRollNumber)
{
	cout << "\n" << currentPlayer->getName() << " is required to pay income tax! It will be: $";
	if (isOneTenthOfCurrentPlayerWealthSmallerThan200(currentPlayer))
		actionIfTaxIsSmallerThan200(currentPlayer);
	else
		actionIfTaxIs200(currentPlayer);
}


bool IncomeTax::isOneTenthOfCurrentPlayerWealthSmallerThan200(Player* currentPlayer)
{
	return currentPlayer->getWealth() * .10 < 200;
}

void IncomeTax::actionIfTaxIsSmallerThan200(Player* currentPlayer)
{
	int newWealth = currentPlayer->getWealth() - 200;
	currentPlayer->setWealth(newWealth);
}

void IncomeTax::actionIfTaxIs200(Player *currentPlayer)
{
	if (200 > currentPlayer->getWealth()) {
		cout << "You cannot pay income tax! You are bancrupted!" << "\n";
		currentPlayer->setIsBankrupted(true);
	}
	else {
		int newWealth = currentPlayer->getWealth() - 200;
		currentPlayer->setWealth(newWealth);
	}
}
