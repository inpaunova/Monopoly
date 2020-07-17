#pragma once
#include "Player.h"

class PlayingField
{
public:
	virtual void actionOfPlayerOnTheField(Player*, int) = 0;
	virtual string getFieldType() = 0;
	string getName()
	{
		return name;
	}
protected:
	string name;
	int boardPosition;
};

