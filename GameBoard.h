#pragma once
#include "PlayingField.h"
#include "Property.h"
#include "StartField.h"
#include "LuxuryTax.h"
#include "IncomeTax.h"
#include "Railroad.h"
#include "Chance.h"
#include "Jail.h"
#include "GoToJail.h"
#include "FreeParking.h"
#include "Utility.h"

class GameBoard
{
public:
	GameBoard();
	void draw();

	PlayingField* getFieldInfo(int);
	int getPropertiesNumber();
	bool isFieldPropertyReilroadOrUtility(int);

private:
	void setFields();

	static const int MAX_NUMBER_OF_FIELDS = 40;
	PlayingField* fields[MAX_NUMBER_OF_FIELDS];
	int numberProperties;
};

