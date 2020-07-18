#pragma once
#include "ChanceCard.h"

class Collect150 : public ChanceCard
{
public:
	virtual void action(Player *currentPlayer) {
		cout << "\nhance: Your Building and Loan Matures. Collect $150!" << endl;
		currentPlayer->setWealth(currentPlayer->getWealth() + 150);
	}
};