#pragma once
#include "PlayingField.h"

class Jail : public PlayingField
{
public:
	Jail(string, int);
	virtual void actionOfPlayerOnTheField(Player*, int);
	virtual string getFieldType();
};
