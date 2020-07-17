#include "Property.h"

Property::Property(string name, int position, int price, Colors groupColor,
	int numberOfHouses, int noHouseRent, int oneHouseRent, int twoHouseRent,
	int threeHouseRent, int fourHouseRent, int hotelRent, int buildCost, int mortgageValue)
{
	this->name = name;
	this->boardPosition = position;
	this->price = price;
	this->groupColor = groupColor;
	this->numberOwnedHouses = numberOfHouses;
	this->noHouseRent = noHouseRent;
	this->oneHouseRent = oneHouseRent;
	this->twoHouseRent = twoHouseRent;
	this->threeHouseRent = threeHouseRent;
	this->fourHouseRent = fourHouseRent;
	this->hotelRent = hotelRent;
	this->buildCost = buildCost;
	this->mortgageValue = mortgageValue;
	isOwned = false;
	areAllPropertiesOfSameColorOwned = false;
	isMortgaged = false;
}

void Property::actionOfPlayerOnTheField(Player * currentPlayer, int dieRollNumber)
{
	if (isOwned && !owner->getIsBankrupted())
		actionIfThePropertyIsOwned(currentPlayer);
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
				cout << "\nYou can't afford to buy this property!" << endl;
			}
			else {
				cout << "\n" << currentPlayer->getName() << " successfully bought " << name << "!" << endl;
				currentPlayer->setWealth(currentPlayer->getWealth() - price);
				isOwned = true;
				owner = currentPlayer;
			}
		}
		if (chosenOption == 'b' || chosenOption == 'B') {
			cout << "\nThe property not be bought!" << endl;
		}
	}
}

void Property::actionIfThePropertyIsOwned(Player * currentPlayer)
{
	if (owner == currentPlayer)
		actionIfOwnerOfPropertyIsCurrentPlayer();
	else
		actionIfOwnerOfPropertyIsAnotherPlayer(currentPlayer);
}

void Property::showMenuForBuying()
{
	cout << "\n" << name << "is available. price: "<< price << "$ "<< "\n" << "Would you like to buy?" << endl;
	cout << "     a) Yes" << endl;
	cout << "     b) No" << endl;
}

void Property::actionIfOwnerOfPropertyIsCurrentPlayer()
{
	cout << "\nYou own " << name << ", kick back and relax!\m" << endl;
}

void Property::actionIfOwnerOfPropertyIsAnotherPlayer(Player* currentPlayer)
{

	switch (numberOwnedHouses) {
	case 0: noHousesAreOwned(currentPlayer);
		break;
	case 1: oneHouseIsOwned(currentPlayer);
		break;
	case 2: twoHousesAreOwned(currentPlayer);
		break;
	case 3:
		threeHousesAreOwned(currentPlayer);
		break;
	case 4:
		fourHousesAreOwned(currentPlayer);
		break;
	case 5:
		hotelIsOwned(currentPlayer);
		break;
	}
}

void Property::noHousesAreOwned(Player * currentPlayer)
{
	if (areAllPropertiesOfSameColorOwned)
		allPropertiesOfTheSameColorAreOwned(currentPlayer);
	else
		notAllPropertiesOfTheSameColorAreOwned(currentPlayer);
}

void Property::oneHouseIsOwned(Player *currentPlayer)
{
	cout << oneHouseRent << endl;
	currentPlayer->payRent(owner, oneHouseRent);
}

void Property::twoHousesAreOwned(Player *currentPlayer)
{
	cout << twoHouseRent << endl;
	currentPlayer->payRent(owner, twoHouseRent);

}

void Property::threeHousesAreOwned(Player *currentPlayer)
{
	cout << threeHouseRent << endl;
	currentPlayer->payRent(owner, threeHouseRent);

}

void Property::fourHousesAreOwned(Player *currentPlayer)
{
	cout << fourHouseRent << endl;
	currentPlayer->payRent(owner, fourHouseRent);

}

void Property::hotelIsOwned(Player *currentPlayer)
{
	cout << hotelRent << endl;
	currentPlayer->payRent(owner, hotelRent);

}

string Property::getFieldType()
{
	return "property";
}

void Property::setIsOwned(bool isOwnedNow)
{
	isOwned = isOwnedNow;
}

void Property::setOwner(Player * newOwner)
{
	owner = newOwner;
}

Player * Property::getOwner()
{
	return owner;
}

int Property::getBuildCost()
{
	return buildCost;
}

string Property::getName()
{
	return name;
}

int Property::getNumberOwnedHouses()
{
	return numberOwnedHouses;
}

Colors Property::getGroupColor()
{
	return groupColor;
}

bool Property::areAllPropertiesOfColorsetOwned()
{
	return areAllPropertiesOfSameColorOwned;
}

void Property::setAllPropertiesOfColorsetOwned(bool areOwned)
{
	areAllPropertiesOfSameColorOwned = areOwned;
}

void Property::setNumberOwnedHouses(int numberHouses)
{
	numberOwnedHouses = numberHouses;
}





void Property::allPropertiesOfTheSameColorAreOwned(Player * currentPlayer)
{
	cout << (2 * noHouseRent) << endl;
	currentPlayer->payRent(owner, 2 * noHouseRent);

}

void Property::notAllPropertiesOfTheSameColorAreOwned(Player * currentPlayer)
{
	cout << noHouseRent << endl;
	currentPlayer->payRent(owner, noHouseRent);
}
