#pragma once
#include "ChanceCard.h"

class OutOfJailCard : public ChanceCard
{
public:
	virtual void action(Player *currentPlayer) {
		cout << "\nChance: Get out of jail free! This card may be kept until needed or sold." << endl;
		currentPlayer->setHasOutOfJailCard(true);
	}
};