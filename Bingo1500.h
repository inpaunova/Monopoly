#pragma once
#include "ChanceCard.h"
class Bingo1500 : public ChanceCard
{
public:
	virtual void action(Player *currentPlayer) {
		cout << "\nChance: Bingo! You won 1500$!" << endl;
		currentPlayer->setWealth(currentPlayer->getWealth() + 1500);
	}
};
