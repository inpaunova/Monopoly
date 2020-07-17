#pragma once
#include "PlayingField.h"

class LuxuryTax: public PlayingField
{
public:
	LuxuryTax(string, int);
	virtual void actionOfPlayerOnTheField(Player*, int);
	virtual string getFieldType();

private:
	const int LUXURY_TAX = 75;
};
