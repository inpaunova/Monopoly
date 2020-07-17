#pragma once
#include "Player.h"
#include "PlayingField.h"


class StartField : public PlayingField
{
public:
	StartField(string, int);
	virtual void actionOfPlayerOnTheField(Player*, int);

	virtual string getFieldType();
};

