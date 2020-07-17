#include "Chance.h"

Chance::Chance(string name, int boardPosition)
{
	this->name = name;
	this->boardPosition = boardPosition;
}

void Chance::actionOfPlayerOnTheField(Player *currentPlayer,  int dieRollNumber)
{
	int chanceCardNumber = -1;
	const int NUMBER_CARDS = 8;
	srand(time(0));
	chanceCardNumber = ((rand() % NUMBER_CARDS) + 1);
	ChanceCard* choosenCard = findProperCard(chanceCardNumber);
	choosenCard->action(currentPlayer);
}

string Chance::getFieldType()
{
	return "chance";
}

ChanceCard * Chance::findProperCard(int cardNumber)
{
	ChanceCard* card = nullptr;
	if (cardNumber == 1)
	{
		card = new OutOfJailCard();
	}
	else if (cardNumber == 2)
	{
		card = new Win200();
	}
	else if (cardNumber == 3)
	{
		card = new Loose200();
	}
	else if (cardNumber == 4)
	{
		card = new Collect150();
	}
	else if (cardNumber == 5)
	{
		card = new EmptyCard();
	}
	else if (cardNumber == 6)
	{
		card = new Give1000ForCharity();
	}
	else if (cardNumber == 7)
	{
		card = new Fine500();
	}
	else if (cardNumber == 8)
	{
		card = new Bingo1500();
	}
	return card;
}
