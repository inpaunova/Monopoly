#include "Railroad.h"
Railroad::Railroad(string name, int boardPosition, int price, int numberOwnedParts, int mortgageValue)
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

void Railroad::actionOfPlayerOnTheField(Player * currentPlayer, int diceRollNumber)
{
	if (isOwned)
		actionIfTheRailroadIsOwned(currentPlayer);
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
				cout << "\nYou can't afford to buy this railroad!" << endl;
			}
			else {
				cout << "\n" << currentPlayer->getName() << " successfully bought " << name << "!" << endl;
				currentPlayer->setWealth(currentPlayer->getWealth() - price);
				isOwned = true;
				owner = currentPlayer;
			}
		}
		if (chosenOption == 'b' || chosenOption == 'B') {
			cout << "\nThe railroad not be bought!" << endl;
		}
	}
}

void Railroad::actionIfTheRailroadIsOwned(Player * currentPlayer)
{
	if (owner == currentPlayer)
		actionIfOwnerOfRailroadIsCurrentPlayer();
	else
		actionIfOwnerOfRailroadIsAnotherPlayer(currentPlayer);
}

void Railroad::showMenuForBuying()
{
	cout << "\nThis property is available. Would you like to buy?" << endl;
	cout << "     a) Yes" << endl;
	cout << "     b) No" << endl;
}

void Railroad::actionIfOwnerOfRailroadIsCurrentPlayer()
{
	cout << "\nYou own " << name << ", kick back and relax!\m" << endl;
}

void Railroad::actionIfOwnerOfRailroadIsAnotherPlayer(Player * currentPlayer)
{
	cout << name << " is owned by " << owner << "! Rent is $";
	switch (numberOwnedParts) {
	case 1: onePartIsOwned(currentPlayer);
		break;
	case 2: twoPartsAreOwned(currentPlayer);
		break;
	case 3: threePartsAreOwned(currentPlayer);
		break;
	case 4: fourPartsAreOwned(currentPlayer);
		break;
	}
}

void Railroad::onePartIsOwned(Player *currentPlayer)
{
	cout << ONE_PART_RENT << endl;
	currentPlayer->payRent(owner, ONE_PART_RENT);
}

void Railroad::twoPartsAreOwned(Player *currentPlayer)
{
	cout << TWO_PARTS_RENT << endl;
	currentPlayer->payRent(owner, TWO_PARTS_RENT);
}

void Railroad::threePartsAreOwned(Player *currentPlayer)
{
	cout << THREE_PARTS_RENT << endl;
	currentPlayer->payRent(owner, THREE_PARTS_RENT);
}

void Railroad::fourPartsAreOwned(Player *currentPlayer)
{
	cout << FOUR_PARTS_RENT << endl;
	currentPlayer->payRent(owner, FOUR_PARTS_RENT);
}

string Railroad::getFieldType()
{
	return "railroad";
}

Player * Railroad::getOwner()
{
	return owner;
}

int Railroad::getNumberOwnedParts()
{
	return numberOwnedParts;
}

void Railroad::setNumberOwnedParts(int parts)
{
	numberOwnedParts = parts;
}





