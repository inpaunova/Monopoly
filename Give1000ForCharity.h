#pragma once
#include "ChanceCard.h"

class Give1000ForCharity : public ChanceCard
{
public:
	virtual void action(Player *currentPlayer)
	{
		cout << "\nChance: Give 1000$ for charity!" << endl;

		if (1000 >= currentPlayer->getWealth())
		{
			cout << "\nYou cannot donate 1000$!" << endl;
		}
		else
		{
			currentPlayer->setWealth(currentPlayer->getWealth() - 1000);
		}
	}
};

