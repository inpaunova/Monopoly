#pragma once
#include "ChanceCard.h"

class EmptyCard: public ChanceCard
{
public:
	virtual void action(Player *currentPlayer) {
		cout << "\nChance: Try again next time!" << endl;
	}
};
