#pragma once
#include "PlayingField.h"
#include "Player.h"


enum Colors { PURPLE, SKY, PINK, ORANGE, RED, YELLOW, GREEN, BLUE, WHITE };


class Property : public PlayingField
{
public:
	Property(string, int, int, Colors, int, int, int, int, int, int, int, int, int);
	virtual void actionOfPlayerOnTheField(Player*, int);
	virtual string getFieldType();

	void setIsOwned(bool);
	Player* getOwner();
	void setOwner(Player*);
	int getBuildCost();
	string getName();
	int getNumberOwnedHouses();
	Colors getGroupColor();
	bool areAllPropertiesOfColorsetOwned();
	void setAllPropertiesOfColorsetOwned(bool);
	void setNumberOwnedHouses(int);

private:
	void actionIfThePropertyIsOwned(Player*);
	void showMenuForBuying();
	void actionIfOwnerOfPropertyIsCurrentPlayer();
	void actionIfOwnerOfPropertyIsAnotherPlayer(Player*);
	void noHousesAreOwned(Player*);
	void oneHouseIsOwned(Player*);
	void twoHousesAreOwned(Player*);
	void threeHousesAreOwned(Player*);
	void fourHousesAreOwned(Player*);
	void hotelIsOwned(Player*);
	void allPropertiesOfTheSameColorAreOwned(Player*);
	void notAllPropertiesOfTheSameColorAreOwned(Player*);
	
	int price;
	bool isOwned;
	Player* owner = nullptr;
	bool areAllPropertiesOfSameColorOwned;
	Colors groupColor;
	int numberOwnedHouses;
	int noHouseRent;
	int oneHouseRent;
	int twoHouseRent;
	int threeHouseRent;
	int fourHouseRent;
	int hotelRent;
	int buildCost;
	int mortgageValue;
	bool isMortgaged;
};


