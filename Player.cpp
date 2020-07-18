#include "Player.h"


Player::Player()
{
	name = "";
	number = 0;
	boardPosition = 0;
	wealth = INITIAL_WEALTH;
	isInJail = false;
	hasOutOfJailCard = false;
	countTurnsInJail = 0;
	isKeepBidding = false;
	isBankrupted = false;
}

Player::Player(string newPlayerName, int newPlayerNum, int newIntWealth, bool newOutJail, int newNumTurnJail)
{
	name = newPlayerName;
	number = newPlayerNum;
	isInJail = false;
	hasOutOfJailCard = newOutJail;
	countTurnsInJail = newNumTurnJail;
	isKeepBidding = false;
	isBankrupted = false;
}

void Player::payRent(Player * ownerOfProperty, int price)
{
	if (200 > wealth)
	{
		cout << "\nYou cannot afford rent! You are bancrupted!" << endl;
		isBankrupted = true;
	}
	else
	{
		wealth -= price;
		ownerOfProperty->setWealth(ownerOfProperty->getWealth() + price);
		cout << "\n" << name << " paid rent!" << endl;
	}
}

string Player::getName()
{
	return name;
}

void Player::setName(string name)
{
	this->name = name;
}

int Player::getNumber()
{
	return number;
}

void Player::setNumber(int number)
{
	this->number = number;
}

int Player::getPosition()
{
	return boardPosition;
}

void Player::setPosition(int position)
{
	boardPosition = position;
}

int Player::getWealth()
{
	return wealth;
}

void Player::setWealth(int wealth)
{
	this->wealth = wealth;
}

bool Player::getIsInJail()
{
	return isInJail;
}

void Player::setIsInJail(bool isInJail)
{
	this->isInJail = isInJail;
}

bool Player::getHasOutOfJailCard()
{
	return hasOutOfJailCard;
}

void Player::setHasOutOfJailCard(bool hasCard)
{
	hasOutOfJailCard = hasCard;
}

int Player::getCountTurnsInJail()
{
	return countTurnsInJail;
}

void Player::setCountTurnsInJail(int turns)
{
	countTurnsInJail = turns;
}

bool Player::getIsBidding()
{
	return isKeepBidding;
}

void Player::setIsBidding(bool isBidding)
{
	isKeepBidding = isBidding;
}

bool Player::getIsBankrupted()
{
	return isBankrupted;
}

void Player::setIsBankrupted(bool isBancrupted)
{
	this->isBankrupted = isBancrupted;
}






