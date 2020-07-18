#pragma once
#include "GameBoard.h"
#include "PlayingField.h"
#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <string>
using namespace std;

class MonopolyGame
{
public:
	MonopolyGame();
	void startGame();
	void playGame();
	
	bool isSellingHouseSuccessful();
	
private:
	void getPlayerInfo(int);
	void takeTurn(Player*);
	bool isThereAWinner();
	void assignNextPlayer();
	void nextPlayer();

	void calculateOwnedProperties();
	void currentPlayerActivity(Player* );
	void determineNextPosition(Player *);

	void displayPlayerStatistic(Player*);
	void showOwnedProperties();
	void storePropertiesByOwners();
	void calculatePropertiesByType();
	void storePropertiesOfPlayer(int);

//sell option
	void addPropertiesForSale(Property*, GameBoard*);
	bool doesPlayerOwnsEntireColorSet();
	bool haveHousesForSale();
	bool isHouseSold();

	void addPurplePropertiesForSale(GameBoard*);
	void addSkyPropertiesForSale(GameBoard*);
	void addPinkPropertiesForSale(GameBoard*);
	void addOrangePropertiesForSale(GameBoard*);
	void addRedPropertiesForSale(GameBoard*);
	void addYellowPropertiesForSale(GameBoard*);
	void addGreenPropertiesForSale(GameBoard*);
	void addBluePropertiesForSale(GameBoard*);

	void showPropertiesForSale();
	int selectPropertyForSale();

	bool haveOwnedHousesOfProperty(Property*);
	bool areNumberOwnedHousesEqual(Property*, Property*);
	bool areNumberOwnedHousesEqual(Property*, Property*, Property*);
	Property* propertyWithMoreOwnedHouses(Property*, Property*);
	void addPropertyWithMoreOwnedHouses(Property*, Property*, Property*);


//jail 
	void playerInJail(Player *);
	void showOpportunities();
	char enterLetter();
	void checkForA(GameBoard *inputBoard, Player *inputPlayer, char chosenJailOption);
	void checkForB(GameBoard *inputBoard, Player *inputPlayer, char chosenJailOption);
	void checkForC(GameBoard *inputBoard, Player *inputPlayer, char chosenJailOption);

	
	bool rollDoubles();
	int rollDie();
	int rollDice();

	void clearScreen();

	vector<Property*> propertiesForSale;
	bool doesPlayerOwnEntireColorSet = true;
	bool arePurplePropertiesAddedForSale = false;
	bool areSkyPropertiesAddedForSale = false;
	bool arePinkPropertiesAddedForSale = false;
	bool areOrangePropertiesAddedForSale = false;
	bool areRedPropertiesAddedForSale = false;
	bool areYellowPropertiesAddedForSale = false;
	bool areGreenPropertiesAddedForSale = false;
	bool areBluePropertiesAddedForSale = false;

	vector<vector<PlayingField*>> ownedPropertiesForPlayers;
	GameBoard* board;

	bool isPlaying;
	static const int MIN_NUMBER_OF_PLAYERS = 2;
	static const int MAX_NUMBER_OF_PLAYERS = 8;
	Player players[MAX_NUMBER_OF_PLAYERS];

	int countRolledDoubles;
	int currentPlayerNumber;
	int playersNumber;	
};



