#pragma once
#include "PlayingField.h"


class GoToJailField : public PlayingField
{
public:
	GoToJailField(string, int);
	virtual void actionOfPlayerOnTheField(Player*, int);
	virtual string getFieldType();
};
