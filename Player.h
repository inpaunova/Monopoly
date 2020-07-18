#pragma once
#include <iostream>
#include <string>
using namespace std;

class Player
{
public:
	Player();
	Player(string, int, int, bool, int);
	void payRent(Player*, int);

	string getName();
	void setName(string);
	int  getNumber();
	void setNumber(int);
	int getPosition();
	void setPosition(int);
	int getWealth();
	void setWealth(int);
	bool getIsInJail();
	void setIsInJail(bool);
	bool getHasOutOfJailCard();
	void setHasOutOfJailCard(bool);
	int getCountTurnsInJail();
	void setCountTurnsInJail(int);
	bool getIsBidding();
	void setIsBidding(bool);
	bool getIsBankrupted();
	void setIsBankrupted(bool);

private:
	string name;
	int number;
	int boardPosition;
	int wealth;

	bool isInJail;
	bool hasOutOfJailCard;
	int countTurnsInJail;

	bool isKeepBidding;
	bool isBankrupted;
		
	const int INITIAL_WEALTH = 1500;
};

