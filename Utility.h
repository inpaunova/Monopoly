#pragma once
#include "Player.h"
#include "PlayingField.h"

class Utility : public PlayingField
{
public:
	Utility(string, int, int, int, int);
	virtual void actionOfPlayerOnTheField(Player*, int);
	virtual string getFieldType();

	Player* getOwner();
	int getNumberOwnedParts();
	void setNumberOwnedParts(int);

private:
	void actionIfTheUtilityIsOwned(Player*, int);
	void actionIfOwnerOfUtilityIsCurrentPlayer();
	void actionIfOwnerOfUtilityIsAnotherPlayer(Player*, int);
	void onePartIsOwned(Player*, int);
	void twoPartsAreOwned(Player*, int);
	void showMenuForBuying();

	int onePartRent(int);
	int twoPartsRent(int);

	int price;
	int numberOwnedParts;
	bool isOwned;
	Player *owner;
	int mortgageValue;
	bool isMortgaged;
};
