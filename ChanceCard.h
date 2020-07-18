#pragma once
#include "Player.h"

class ChanceCard
{
public:
	virtual void action(Player *) = 0;
};

