#include "MonopolyGame.h"

MonopolyGame::MonopolyGame()
{
	board = new GameBoard();
	isPlaying = false;
	countRolledDoubles = 0;
	currentPlayerNumber = 0;
	playersNumber = 0;
}

void MonopolyGame::startGame()
{
	cout << "\nWelcome to C++ Monopoly!" << endl;
	cout << "\n How many players? There must be at least 2 players and at most 8 players!";
	int numberOfPlayers;
	cin >> numberOfPlayers;
	
	while (numberOfPlayers > MAX_NUMBER_OF_PLAYERS || numberOfPlayers < MIN_NUMBER_OF_PLAYERS)
	{
		cout << "Invalid number of players! here must be at least 2 players and at most 8 players!";
		cin >> numberOfPlayers;
	}
		
    for (int i = 0; i < numberOfPlayers; i++)
	{
		getPlayerInfo(i);
	}

	clearScreen();
	cout << "Welcome to Monopoly!\n" << endl;
	board->draw();	
}

void MonopolyGame::playGame()
{
	bool isPlaying = true;
	while (isPlaying) {
		takeTurn(&players[currentPlayerNumber]);
		if (isThereAWinner())
		{
			isPlaying = false;
		}
		assignNextPlayer();
	}
}

void MonopolyGame::getPlayerInfo(int playerNumber)
{
	cout << "\nWhat is Player " << playerNumber << "'s name? ";
	string name;
	cin >> name;
	players[playerNumber].setName(name);
	players[playerNumber].setNumber(playerNumber);
	vector<PlayingField*> playerProperties;
	ownedPropertiesForPlayers.push_back(playerProperties);
}

void MonopolyGame::takeTurn(Player * currentPlayer)
{
	calculateOwnedProperties();

	currentPlayerActivity(currentPlayer);

	clearScreen();
	board->draw();
	showOwnedProperties();

	determineNextPosition(currentPlayer);
}

bool MonopolyGame::isThereAWinner()
{
	int remainPlayers = playersNumber;
	Player* winningPlayer = nullptr;
	for (int i = 0; i < playersNumber; i++) {
		if (players[i].getIsBankrupted()) {
			remainPlayers--;
		}
		else {
			winningPlayer = &players[i];
		}
	}
	if (remainPlayers == 1) {
		cout << "\nWe have a winner! Congratulations " << winningPlayer->getName() << "!" << endl;
		return true;
	}

	return false;
}

void MonopolyGame::assignNextPlayer()
{
	if (countRolledDoubles == 0) {
		nextPlayer();
	}
	else if (countRolledDoubles == 3) {
		cout << "\nYou rolled doubles three times! Go immediately to jail, do not collect go, do not collect $200!" << endl;
		players[currentPlayerNumber].setIsInJail(true);
		players[currentPlayerNumber].setPosition(10);
		nextPlayer();
		countRolledDoubles = 0;
	}
	else {
		cout << "\nSince you rolled doubles, you get to take another turn!" << endl;
	}
}

void MonopolyGame::nextPlayer()
{
	if (currentPlayerNumber + 1 == playersNumber) {
		currentPlayerNumber = 0;
	}
	else {
		currentPlayerNumber++;
	}
	while (players[currentPlayerNumber].getIsBankrupted()) {
		if (currentPlayerNumber + 1 == playersNumber) {
			currentPlayerNumber = 0;
		}
		else {
			currentPlayerNumber++;
		}
	}
}

void MonopolyGame::calculateOwnedProperties()
{
	storePropertiesByOwners();
	calculatePropertiesByType();
}

void MonopolyGame::currentPlayerActivity(Player* currentPlayer)
{
	bool isAnotherPlayersTurn = false;
	char chosenOption ;
	while (!isAnotherPlayersTurn) {
		showOwnedProperties();

		cout << "It is " << currentPlayer->getName() << "'s turn!" << endl;
		displayPlayerStatistic(currentPlayer);

		cout << "What would you like to do?" << "\n     a) Start turn" << "\n     b) Sell a house"<<"\n";
		cin >> chosenOption;

		while (chosenOption != 'a' && chosenOption != 'b' && chosenOption != 'A' && chosenOption != 'B') {
			cout << "\n\n Please enter a or b: ";
			cin >> chosenOption;
		}

		if (chosenOption == 'a' || chosenOption == 'A') {
			isAnotherPlayersTurn = true;
		}
		if (chosenOption == 'b' || chosenOption == 'B') {
			isAnotherPlayersTurn = isSellingHouseSuccessful();
		}
	}
}

void MonopolyGame::determineNextPosition(Player *currentPlayer)
{
	int diceRoll = 0;
	if (currentPlayer->getIsInJail()) {
		playerInJail(currentPlayer);
		
		if (players[currentPlayerNumber].getIsBankrupted()) {
			return;
		}
		else if (diceRoll == -2) {
			countRolledDoubles = 0;
			clearScreen();
			board->draw();
		}
		currentPlayer->setCountTurnsInJail(0);
	}

	if (!currentPlayer->getIsInJail() && diceRoll == 0) {
		diceRoll = rollDice();
		if (rollDoubles()) {
			countRolledDoubles++;
			cout << "\nYou rolled doubles!" << endl;
		}
		else {
			countRolledDoubles = 0;
		}

	}
	const int MAX_POSITION = 39;
	if (currentPlayer->getPosition() + rollDie() > MAX_POSITION) {
		currentPlayer->setPosition(currentPlayer->getPosition() + diceRoll - MAX_POSITION);
	}
	else {
		currentPlayer->setPosition(currentPlayer->getPosition() + diceRoll);
	}

	displayPlayerStatistic(currentPlayer);
	PlayingField* currentField = board->getFieldInfo(currentPlayer->getPosition());

	clearScreen();
	board->draw();

	currentField->actionOfPlayerOnTheField(currentPlayer, diceRoll);
}

void MonopolyGame::displayPlayerStatistic(Player *player)
{
	cout << "\nPosition: " << board->getFieldInfo(player->getPosition())->getName() << "\n";
	cout << "Funds: $" << player->getWealth() << "\n";
	if (player->getHasOutOfJailCard() == true) {
		cout << "You have a get out of jail free card!" << endl;
	}
}

void MonopolyGame::showOwnedProperties()
{
	cout << "\nHere are the currently owned properties:" << endl;
	for (int i = 0; i < playersNumber; i++) {
		if (!players[i].getIsBankrupted()) {

			cout << "     " << players[i].getName() << ":\n ";
			for (int pos = 0; pos < ownedPropertiesForPlayers.at(i).size(); pos++) {
				cout << "          " << ownedPropertiesForPlayers.at(i).at(pos)->getName() << "\n";
			}
			cout << "\n";
		}
	}
	cout << "\n";
}

void MonopolyGame::storePropertiesByOwners()
{
	for (int i = 0; i < playersNumber; i++)
	{
		if (!players[i].getIsBankrupted())
		{
			int numOwnedProp = 0;
			ownedPropertiesForPlayers.at(i).clear();
			storePropertiesOfPlayer(i);
		}
		else {
			ownedPropertiesForPlayers.at(i).clear();
		}
	}
}

void MonopolyGame::calculatePropertiesByType()
{
	for (int i = 0; i < playersNumber; i++) {
		int ownedRailroads = 0;
		int ownedUtilities = 0;
		int ownedPurpleProps = 0;
		int ownedSkyProps = 0;
		int ownedPinkProps = 0;
		int ownedOrangeProps = 0;
		int ownedRedProps = 0;
		int ownedYellowProps = 0;
		int ownedGreenProps = 0;
		int ownedBlueProps = 0;

		for (int pos = 0; pos < ownedPropertiesForPlayers.at(i).size(); pos++) {
			string type = ownedPropertiesForPlayers.at(i).at(pos)->getFieldType();
			if (type == "property")
			{
				Property* currentProperty = (Property*)ownedPropertiesForPlayers.at(i).at(pos);
				if (currentProperty->getGroupColor() == PURPLE)
				{
					ownedPurpleProps++;
					if (ownedPurpleProps == 2) currentProperty->setAllPropertiesOfColorsetOwned(true);
				}
				else if (currentProperty->getGroupColor() == SKY)
				{
					ownedSkyProps++;
					if (ownedPurpleProps == 3) currentProperty->setAllPropertiesOfColorsetOwned(true);
				}
				else if (currentProperty->getGroupColor() == PINK)
				{
					ownedPinkProps++;
					if (ownedPinkProps == 3) currentProperty->setAllPropertiesOfColorsetOwned(true);
				}
				else if (currentProperty->getGroupColor() == ORANGE)
				{
					ownedOrangeProps++;
					if (ownedOrangeProps == 3) currentProperty->setAllPropertiesOfColorsetOwned(true);
				}
				else if (currentProperty->getGroupColor() == RED)
				{
					ownedRedProps++;
					if (ownedRedProps == 3) currentProperty->setAllPropertiesOfColorsetOwned(true);
				}
				else if (currentProperty->getGroupColor() == YELLOW)
				{
					ownedYellowProps++;
					if (ownedYellowProps == 3) currentProperty->setAllPropertiesOfColorsetOwned(true);
				}
				else if (currentProperty->getGroupColor() == GREEN)
				{
					ownedGreenProps++;
					if (ownedGreenProps == 3) currentProperty->setAllPropertiesOfColorsetOwned(true);
				}
				else if (currentProperty->getGroupColor() == BLUE)
				{
					ownedBlueProps++;
					if (ownedBlueProps == 2) currentProperty->setAllPropertiesOfColorsetOwned(true);
				}
			}
			else if (type == "railroad")
			{
				Railroad* currentProperty = (Railroad*)ownedPropertiesForPlayers.at(i).at(pos);
				ownedRailroads++;
				if (ownedRailroads == 1)
					currentProperty->setNumberOwnedParts(ownedRailroads);
			}
			else if (type == "utility")
			{
				Utility* currentProperty = (Utility*)ownedPropertiesForPlayers.at(i).at(pos);
				ownedUtilities++;
				if (ownedUtilities == 2)
					currentProperty->setNumberOwnedParts(ownedUtilities);
			}
		}
	}
}

void MonopolyGame::storePropertiesOfPlayer(int number)
{
	for (int pos = 0; pos < board->getPropertiesNumber(); pos++) {

		if (board->isFieldPropertyReilroadOrUtility(pos))
		{
			if (board->getFieldInfo(pos)->getFieldType() == "property")
			{
				Property* currentProperty = (Property*)board->getFieldInfo(pos);
				if (currentProperty->getOwner() == &players[number])
				{
					ownedPropertiesForPlayers.at(number).push_back(board->getFieldInfo(pos));
				}
			}

			if (board->getFieldInfo(pos)->getFieldType() == "railroad")
			{
				Railroad* currentProperty = (Railroad*)board->getFieldInfo(pos);
				if (currentProperty->getOwner() == &players[number])
				{
					ownedPropertiesForPlayers.at(number).push_back(board->getFieldInfo(pos));
				}
			}
			if (board->getFieldInfo(pos)->getFieldType() == "property")
			{
				Utility* currentProperty = (Utility*)board->getFieldInfo(pos);
				if (currentProperty->getOwner() == &players[number])
				{
					ownedPropertiesForPlayers.at(number).push_back(board->getFieldInfo(pos));
				}
			}
		}
	}
}

bool MonopolyGame::isSellingHouseSuccessful()
{
	if (ownedPropertiesForPlayers.at(currentPlayerNumber).empty()) {
		cout << "\nYou don't have houses to sell!\n" << endl;
		return false;
	}

	for (int i = 0; i < ownedPropertiesForPlayers.at(currentPlayerNumber).size(); i++) {
		Property* currentProperty = (Property*)ownedPropertiesForPlayers.at(currentPlayerNumber).at(i);
		addPropertiesForSale(currentProperty, board);
	}
	if (!doesPlayerOwnsEntireColorSet())
	{
		cout << "\nYou don't have houses to sell!\n" << endl;
		return false;
	}
	if (!haveHousesForSale())
	{
		cout << "\nYou do not have any houses to sell!\n" << endl;
		return false;
	}
	return isHouseSold();
}

void MonopolyGame::addPropertiesForSale(Property *p, GameBoard *board)
{
	if (p->areAllPropertiesOfColorsetOwned()) {
		doesPlayerOwnEntireColorSet = false;
		if (p->getGroupColor() == PURPLE && arePurplePropertiesAddedForSale == false) {
			addPurplePropertiesForSale(board);
			arePurplePropertiesAddedForSale = true;
		}
		else if (p->getGroupColor() == SKY && areSkyPropertiesAddedForSale == false) {
			addSkyPropertiesForSale(board);
			areSkyPropertiesAddedForSale = true;
		}
		else if (p->getGroupColor() == PINK && arePinkPropertiesAddedForSale == false) {
			addPinkPropertiesForSale(board);
			arePinkPropertiesAddedForSale = true;
		}
		else if (p->getGroupColor() == ORANGE && areOrangePropertiesAddedForSale == false) {
			addOrangePropertiesForSale(board);
			areOrangePropertiesAddedForSale = true;
		}
		else if (p->getGroupColor() == RED && areRedPropertiesAddedForSale == false) {
			addRedPropertiesForSale(board);
			areRedPropertiesAddedForSale = true;
		}
		else if (p->getGroupColor() == YELLOW && areYellowPropertiesAddedForSale == false) {
			addYellowPropertiesForSale(board);
			areYellowPropertiesAddedForSale = true;
		}
		else if (p->getGroupColor() == GREEN && areGreenPropertiesAddedForSale == false) {
			addGreenPropertiesForSale(board);
			areGreenPropertiesAddedForSale = true;
		}
		else if (p->getGroupColor() == BLUE && areBluePropertiesAddedForSale == false) {
			addBluePropertiesForSale(board);
			areBluePropertiesAddedForSale = true;
		}
	}
}

bool MonopolyGame::doesPlayerOwnsEntireColorSet()
{
	return doesPlayerOwnEntireColorSet;
}

bool MonopolyGame::haveHousesForSale()
{
	return propertiesForSale.empty();
}

bool MonopolyGame::isHouseSold()
{
	cout << "What property would you like to sell from?" << endl;
	showPropertiesForSale();
	int chosenOption = selectPropertyForSale();
	const int OPTION_FOR_REFUSE_SELLING = -1;
	if (chosenOption == OPTION_FOR_REFUSE_SELLING)
	{
		cout << "You chose not to sell." << endl;
		return false;
	}
	else
	{
		Property* sellingPropery = propertiesForSale.at(chosenOption);
		Player *owner = sellingPropery->getOwner();
		sellingPropery->setNumberOwnedHouses(sellingPropery->getNumberOwnedHouses() - 1);
		int updatedWealth = owner->getWealth() + (sellingPropery->getBuildCost() / 2);
		owner->setWealth(updatedWealth);

		cout << sellingPropery->getName() << " now has " << sellingPropery->getNumberOwnedHouses() << " houses." << endl;
	}
	return true;
}


void MonopolyGame::addPurplePropertiesForSale(GameBoard *board)
{
	Property* atPosition1 = (Property*)board->getFieldInfo(1);
	Property* atPosition3 = (Property*)board->getFieldInfo(3);
	if (areNumberOwnedHousesEqual(atPosition1, atPosition3) && haveOwnedHousesOfProperty(atPosition1)) {
		propertiesForSale.push_back(atPosition1);
		propertiesForSale.push_back(atPosition3);
	}
	else {
		propertiesForSale.push_back(propertyWithMoreOwnedHouses(atPosition1, atPosition3));
	}
}

void MonopolyGame::addSkyPropertiesForSale(GameBoard *board)
{
	Property* atPosition6 = (Property*)board->getFieldInfo(6);
	Property* atPosition8 = (Property*)board->getFieldInfo(8);
	Property* atPosition9 = (Property*)board->getFieldInfo(9);
	if (areNumberOwnedHousesEqual(atPosition6, atPosition8, atPosition9))
	{
		propertiesForSale.push_back(atPosition6);
		propertiesForSale.push_back(atPosition8);
		propertiesForSale.push_back(atPosition9);
	}
	else
		addPropertyWithMoreOwnedHouses(atPosition6, atPosition8, atPosition9);
}

void MonopolyGame::addPinkPropertiesForSale(GameBoard *board)
{
	Property* atPosition13 = (Property*)board->getFieldInfo(13);
	Property* atPosition14 = (Property*)board->getFieldInfo(14);
	Property* atPosition11 = (Property*)board->getFieldInfo(11);
	if (areNumberOwnedHousesEqual(atPosition13, atPosition14, atPosition11))
	{
		propertiesForSale.push_back(atPosition13);
		propertiesForSale.push_back(atPosition14);
		propertiesForSale.push_back(atPosition11);
	}
	else
		addPropertyWithMoreOwnedHouses(atPosition13, atPosition14, atPosition11);
}

void MonopolyGame::addOrangePropertiesForSale(GameBoard *board)
{
	Property* atPosition16 = (Property*)board->getFieldInfo(16);
	Property* atPosition18 = (Property*)board->getFieldInfo(18);
	Property* atPosition19 = (Property*)board->getFieldInfo(19);
	if (areNumberOwnedHousesEqual(atPosition16, atPosition18, atPosition19))
	{
		propertiesForSale.push_back(atPosition16);
		propertiesForSale.push_back(atPosition18);
		propertiesForSale.push_back(atPosition19);
	}
	else
		addPropertyWithMoreOwnedHouses(atPosition16, atPosition19, atPosition19);
}

void MonopolyGame::addRedPropertiesForSale(GameBoard *board)
{
	Property* atPosition21 = (Property*)board->getFieldInfo(21);
	Property* atPosition23 = (Property*)board->getFieldInfo(23);
	Property* atPosition24 = (Property*)board->getFieldInfo(24);
	if (areNumberOwnedHousesEqual(atPosition21, atPosition23, atPosition24))
	{
		propertiesForSale.push_back(atPosition21);
		propertiesForSale.push_back(atPosition23);
		propertiesForSale.push_back(atPosition24);
	}
	else
		addPropertyWithMoreOwnedHouses(atPosition21, atPosition23, atPosition24);
}

void MonopolyGame::addYellowPropertiesForSale(GameBoard *board)
{
	Property* atPosition26 = (Property*)board->getFieldInfo(26);
	Property* atPosition27 = (Property*)board->getFieldInfo(27);
	Property* atPosition29 = (Property*)board->getFieldInfo(29);
	if (areNumberOwnedHousesEqual(atPosition26, atPosition27, atPosition29))
	{
		propertiesForSale.push_back(atPosition26);
		propertiesForSale.push_back(atPosition27);
		propertiesForSale.push_back(atPosition29);
	}
	else
		addPropertyWithMoreOwnedHouses(atPosition26, atPosition27, atPosition29);
}

void MonopolyGame::addGreenPropertiesForSale(GameBoard *board)
{
	Property* atPosition31 = (Property*)board->getFieldInfo(31);
	Property* atPosition32 = (Property*)board->getFieldInfo(32);
	Property* atPosition34 = (Property*)board->getFieldInfo(34);
	if (areNumberOwnedHousesEqual(atPosition31, atPosition32, atPosition34))
	{
		propertiesForSale.push_back(atPosition32);
		propertiesForSale.push_back(atPosition31);
		propertiesForSale.push_back(atPosition34);
	}
	else
		addPropertyWithMoreOwnedHouses(atPosition32, atPosition31, atPosition34);
}

void MonopolyGame::addBluePropertiesForSale(GameBoard *)
{
	Property* atPosition37 = (Property*)board->getFieldInfo(37);
	Property* atPosition39 = (Property*)board->getFieldInfo(39);
	if (areNumberOwnedHousesEqual(atPosition37, atPosition39) && haveOwnedHousesOfProperty(atPosition37)) {
		propertiesForSale.push_back(atPosition37);
		propertiesForSale.push_back(atPosition39);
	}
	else {
		propertiesForSale.push_back(propertyWithMoreOwnedHouses(atPosition37, atPosition39));
	}
}

void MonopolyGame::showPropertiesForSale()
{
	for (int i = 0; i < propertiesForSale.size(); i++) {

		cout << "     " << i << ") " << propertiesForSale.at(i)->getName() << "  pays $"
			<< (propertiesForSale.at(i)->getBuildCost() / 2) << " to sell. (" << propertiesForSale.at(i)->getNumberOwnedHouses()
			<< " house(s) built)" << endl;
	}
}

int MonopolyGame::selectPropertyForSale()
{
	int chosenOption;
	cin >> chosenOption;

	while (chosenOption >= 0 && chosenOption < propertiesForSale.size() || chosenOption == -1)
	{
		cout << "Please enter one of the above number to choose a property or -1 if you don't want to sell!" << endl;
		cin >> chosenOption;
	}

	return chosenOption;
}

bool MonopolyGame::haveOwnedHousesOfProperty(Property *p)
{
	return p->getNumberOwnedHouses() > 0;
}

bool MonopolyGame::areNumberOwnedHousesEqual(Property *p1, Property *p2)
{
	return p1->getNumberOwnedHouses() == p2->getNumberOwnedHouses();
}

bool MonopolyGame::areNumberOwnedHousesEqual(Property *p1, Property *p2, Property *p3)
{
	return areNumberOwnedHousesEqual(p1, p2) && areNumberOwnedHousesEqual(p2, p3);
}

Property * MonopolyGame::propertyWithMoreOwnedHouses(Property *p1, Property *p2)
{
	if (p1->getNumberOwnedHouses() > p2->getNumberOwnedHouses())
		return p1;
	else
		return p2;
}

void MonopolyGame::addPropertyWithMoreOwnedHouses(Property *p1, Property *p2, Property *p3)
{
	if (propertyWithMoreOwnedHouses(p1, p2) == p1 && propertyWithMoreOwnedHouses(p1, p3) == p1) {
		propertiesForSale.push_back(p1);
	}
	else if (propertyWithMoreOwnedHouses(p1, p3) == p3 && propertyWithMoreOwnedHouses(p1, p2) == p2) {
		propertiesForSale.push_back(p3);
		propertiesForSale.push_back(p2);
	}
	else if (propertyWithMoreOwnedHouses(p1, p3) == p3 && areNumberOwnedHousesEqual(p1, p2)) {
		propertiesForSale.push_back(p3);
	}
	else if (propertyWithMoreOwnedHouses(p1, p2) == p1 && propertyWithMoreOwnedHouses(p2, p3) == p3) {
		propertiesForSale.push_back(p1);
		propertiesForSale.push_back(p3);
	}
	else if (propertyWithMoreOwnedHouses(p1, p2) == p1 && areNumberOwnedHousesEqual(p2, p3)) {
		propertiesForSale.push_back(p1);
	}
	else if (propertyWithMoreOwnedHouses(p1, p3) == p1 && propertyWithMoreOwnedHouses(p2, p3) == p2) {
		propertiesForSale.push_back(p1);
		propertiesForSale.push_back(p2);
	}
}

void MonopolyGame::playerInJail(Player *currentPlayer)
{
	char chosenJailOption = '-1';
	int diceRoll;
	bool leaveJail = false;

	showOpportunities();
	char opportunity = enterLetter();
	checkForA(board, currentPlayer, chosenJailOption);
	checkForB(board, currentPlayer, chosenJailOption);
	checkForC(board, currentPlayer, chosenJailOption);
}


void MonopolyGame::showOpportunities()
{
	cout << "\nYou are in Jail! What would you like to do?" << endl;
	cout << "     a) Roll for doubles";
	cout << "     b) Pay $50 bail";
	cout << "     c) Use Get out of Jail Free card";
}

char MonopolyGame::enterLetter()
{
	char chosenJailOption;
	cin >> chosenJailOption;
	while (chosenJailOption != 'a' && chosenJailOption != 'b'&& chosenJailOption != 'c' && chosenJailOption != 'A' && chosenJailOption != 'B' && chosenJailOption != 'C') {
		cout << "\n\nPlease choose a, b, or c: ";
		cin >> chosenJailOption;
	}
	return chosenJailOption;
}

void MonopolyGame::checkForC(GameBoard * inputBoard, Player * inputPlayer, char chosenJailOption)
{
	if (chosenJailOption == 'c' || chosenJailOption == 'C') {
		clearScreen();
		inputBoard->draw();
		cout << "\nYou used your Get out of Jail Free card!" << endl;
		inputPlayer->setHasOutOfJailCard(false);
		inputPlayer->setIsInJail(false);
		inputPlayer->setCountTurnsInJail(0);
		while (!players[currentPlayerNumber].getHasOutOfJailCard()) {
			cout << "\n You are in Jail! What would you like to do?" << endl;
			cout << "     a) Roll for doubles";
			cout << "     b) Pay $50 bail";

			while (chosenJailOption != 'a' && chosenJailOption != 'b'&& chosenJailOption != 'A' && chosenJailOption != 'B') {
				cout << "\n\nPlease choose a or b: ";
				cin >> chosenJailOption;

			}
			checkForA(inputBoard, inputPlayer, chosenJailOption);
			checkForB(inputBoard, inputPlayer, chosenJailOption);
		}

	}
}

void MonopolyGame::checkForA(GameBoard * inputBoard, Player * inputPlayer, char chosenJailOption)
{
	if (chosenJailOption == 'A' || chosenJailOption == 'a')
	{
		int diceRoll = rollDie();
		bool leaveJail = rollDoubles();
		inputPlayer->setCountTurnsInJail(inputPlayer->getCountTurnsInJail() + 1);
		inputPlayer->setIsInJail(false);
		inputPlayer->setCountTurnsInJail(0);

	}
}

void MonopolyGame::checkForB(GameBoard * inputBoard, Player * inputPlayer, char chosenJailOption)
{
	if (chosenJailOption == 'b' || chosenJailOption == 'B') {

		if (players[currentPlayerNumber].getWealth() < 50) {
			cout << "You can't afford to pay $50!" << endl;

		}
		else {
			clearScreen();
			inputBoard->draw();
			cout << "\nYou paid $50 to leave jail!" << endl;
			inputPlayer->setWealth(inputPlayer->getWealth() - 50);
			inputPlayer->setIsInJail(false);
			inputPlayer->setCountTurnsInJail(0);

		}
	}
}
 

bool MonopolyGame::rollDoubles()
{
	int rollFirstDieNumber = rollDie();
	int rollSecondDieNumber = rollDie();
	if (rollFirstDieNumber == rollSecondDieNumber)
		return true;

	return false;
}

int MonopolyGame::rollDie()
{
	srand(time(0));
	return ((rand() % 6) + 1);
}

int MonopolyGame::rollDice()
{
	srand(time(0));
	return ((rand() % 11) + 2);
}

void MonopolyGame::clearScreen()
{
	system("cls");
}