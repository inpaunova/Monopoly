#include "Utility.h"

Utility::Utility(string name, int boardPosition, int price, int numberOwnedParts, int mortgageValue)
{
	this->name = name;
	this->boardPosition = boardPosition;
	this->price = price;
	this->numberOwnedParts = numberOwnedParts;
	this->mortgageValue = mortgageValue;
	isMortgaged = false;
	isOwned = false;
	owner = nullptr;
}

void Utility::actionOfPlayerOnTheField(Player * currentPlayer, int diceRollNumber)
{
	if (isOwned)
		actionIfTheUtilityIsOwned(currentPlayer, diceRollNumber);
	else
	{
		showMenuForBuying();
		char chosenOption;
		cin >> chosenOption;
		while (chosenOption != 'a' && chosenOption != 'b' && chosenOption != 'A' && chosenOption != 'B') {
			cout << "\nPlease choose a or b: ";
			cin >> chosenOption;
		}

		if (chosenOption == 'a' || chosenOption == 'A') {
			if (currentPlayer->getWealth() < price) {
				cout << "\nYou can't afford to buy this utility!" << endl;
			}
			else {
				cout << "\n" << currentPlayer->getName() << " successfully bought " << name << "!" << endl;
				currentPlayer->setWealth(currentPlayer->getWealth() - price);
				isOwned = true;
				owner = currentPlayer;
			}
		}
		if (chosenOption == 'b' || chosenOption == 'B') {
			cout << "\nThe utility not be bought!" << endl;
		}
	}

}

void Utility::actionIfTheUtilityIsOwned(Player * currentPlayer, int diceRollNumber)
{
	if (owner == currentPlayer)
		actionIfOwnerOfUtilityIsCurrentPlayer();
	else
		actionIfOwnerOfUtilityIsAnotherPlayer(currentPlayer, diceRollNumber);
}

void Utility::showMenuForBuying()
{
	cout << "\nThis property is available. Would you like to buy?" << endl;
	cout << "     a) Yes" << endl;
	cout << "     b) No" << endl;
}

void Utility::actionIfOwnerOfUtilityIsCurrentPlayer()
{
	cout << "\nYou own " << name << ", kick back and relax!\m" << endl;
}

void Utility::actionIfOwnerOfUtilityIsAnotherPlayer(Player * currentPlayer, int diceRollNumber)
{
	cout << name << " is owned by " << owner << "! Rent is $";
	switch (numberOwnedParts) {
	case 1: onePartIsOwned(currentPlayer, diceRollNumber);
		break;
	case 2: twoPartsAreOwned(currentPlayer, diceRollNumber);
		break;

	}
}

void Utility::onePartIsOwned(Player *currentPlayer, int dieRollNumber)
{
	cout << onePartRent(dieRollNumber) << endl;
	currentPlayer->payRent(owner, onePartRent(dieRollNumber));
}

void Utility::twoPartsAreOwned(Player *currentPlayer, int dieRollNumber)
{
	cout << twoPartsRent(dieRollNumber) << endl;
	currentPlayer->payRent(owner, twoPartsRent(dieRollNumber));
}

int Utility::onePartRent(int dieRollNumber)
{
	return 4 * dieRollNumber;
}

int Utility::twoPartsRent(int dieRollNumber)
{
	return 10 * dieRollNumber;
}

string Utility::getFieldType()
{
	return "utility";
}

Player * Utility::getOwner()
{
	return owner;
}

int Utility::getNumberOwnedParts()
{
	return numberOwnedParts;
}

void Utility::setNumberOwnedParts(int parts)
{
	numberOwnedParts = parts;
}




