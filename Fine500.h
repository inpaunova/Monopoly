#pragma once
#include "ChanceCard.h"

class Fine500 : public ChanceCard
{
public:
	virtual void action(Player *currentPlayer)
	{
		cout << "\nChance: You are fined with 500$!" << endl;

		if (500 >= currentPlayer->getWealth())
		{
			cout << "\nYou cannot pay 500$! You are bancrupted!" << endl;
			currentPlayer->setIsBankrupted(true);
		}
		else
		{
			currentPlayer->setWealth(currentPlayer->getWealth() - 500);
		}
	}
};