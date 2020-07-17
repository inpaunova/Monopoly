#pragma once
#include "Player.h"
#include "PlayingField.h"
#include <iostream>
using namespace std;

class Railroad : public PlayingField
{
public:
	Railroad(string, int, int, int, int);
	virtual void actionOfPlayerOnTheField(Player*, int);
	virtual string getFieldType();
	Player* getOwner();
	int getNumberOwnedParts();
	void setNumberOwnedParts(int);

private:
	void actionIfTheRailroadIsOwned(Player*);
	void showMenuForBuying();
	void actionIfOwnerOfRailroadIsCurrentPlayer();
	void actionIfOwnerOfRailroadIsAnotherPlayer(Player*);
	void onePartIsOwned(Player*);
	void twoPartsAreOwned(Player*);
	void threePartsAreOwned(Player*);
	void fourPartsAreOwned(Player*);
	

	int price;
	int numberOwnedParts;
	bool isOwned;
	Player *owner;
	int mortgageValue;
	bool isMortgaged;

	const int ONE_PART_RENT = 25;
	const int TWO_PARTS_RENT = 50;
	const int THREE_PARTS_RENT = 100;
	const int FOUR_PARTS_RENT = 200;
};
