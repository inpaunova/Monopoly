#pragma once
#include "ChanceCard.h"
class Win200 : public ChanceCard
{
public:
	virtual void action(Player *currentPlayer) {
		cout << "\nChance: You won 200$!" << endl;
		currentPlayer->setWealth(currentPlayer->getWealth() + 200);
	}
};

