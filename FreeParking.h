#pragma once
#include "PlayingField.h"


class FreeParkingField : public PlayingField
{
public:
	FreeParkingField(string, int);
	virtual void actionOfPlayerOnTheField(Player*, int);
	virtual string getFieldType();

};
