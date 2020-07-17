#pragma once
#include "Player.h"
#include "PlayingField.h"

class IncomeTax : public PlayingField
{
public:
	IncomeTax(string, int);
	virtual void actionOfPlayerOnTheField(Player*, int);
	int increaseParkSpaceJackpot(int, int);
	virtual string getFieldType();
private:
	bool isOneTenthOfCurrentPlayerWealthSmallerThan200(Player*);
	void actionIfTaxIsSmallerThan200(Player*);
	void actionIfTaxIs200(Player*);
};

