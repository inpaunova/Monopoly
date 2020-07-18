#pragma once
#include "ChanceCard.h"


class Loose200 : public ChanceCard
{
public:
	virtual void action(Player *currentPlayer)
	{
		cout << "\nChance: You lost 200$!" << endl;

		if (200 > currentPlayer->getWealth())
		{
			cout << "\nYou cannot afford rent! You are bancrupted!" << endl;
		}
		else
		{
			currentPlayer->setWealth(currentPlayer->getWealth() - 200);
		}
	}
};