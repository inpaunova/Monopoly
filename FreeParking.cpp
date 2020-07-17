#include "FreeParking.h"


FreeParkingField::FreeParkingField(string name, int boardPosition)
{
	this->name = name;
	this->boardPosition = boardPosition;
}

void FreeParkingField::actionOfPlayerOnTheField(Player * currentPlayer, int diceRollNumber)
{
	cout << "\nYou landed on Free Parking! You won 200$" << "!" << endl;
	currentPlayer->setWealth(currentPlayer->getWealth() + 200);

}

string FreeParkingField::getFieldType()
{
	return "free parking";
}