#include "LuxuryTax.h"

LuxuryTax::LuxuryTax(string name, int boardPosition)
{
	this->name = name;
	this->boardPosition = boardPosition;
}

void LuxuryTax::actionOfPlayerOnTheField(Player * currentPlayer, int diceRollNumber)
{
	cout << "\n" << currentPlayer->getName() << " is required to pay a Luxury Tax! Pay $75." << endl;

	while (currentPlayer->getWealth() < LUXURY_TAX) {
		if (LUXURY_TAX > currentPlayer->getWealth())
		{
			cout << "\nYou cannot afford rent! You are bancrupted!" << endl;
			currentPlayer->setIsBankrupted(true);
		}
	}
	currentPlayer->setWealth(currentPlayer->getWealth() - LUXURY_TAX);
}

string LuxuryTax::getFieldType()
{
	return "luxury tax";
}