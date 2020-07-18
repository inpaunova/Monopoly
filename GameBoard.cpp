#include "GameBoard.h"


GameBoard::GameBoard()
{
	setFields();
	numberProperties = MAX_NUMBER_OF_FIELDS;
}

void GameBoard::setFields()
{
	fields[0] = new StartField("Go", 0);
	fields[1] = new Property("Mediterranean Avenue", 1, 60, PURPLE, 0, 2, 10, 30, 90, 160, 250, 50, 30);
	fields[2] = new Chance("Chance Field", 2);
	fields[3] = new Property("Baltic Ave.", 3, 30, PURPLE, 0, 4, 20, 60, 180, 20, 450, 50, 60);
	fields[4] = new IncomeTax("Luxury Tax", 4);
	fields[5] = new Railroad("Reading Railroad", 5, 200, 0, 100);
	fields[6] = new Property("Oriental Ave.", 6, 50, SKY, 0, 6, 30, 90, 270, 400, 550, 50, 100);
	fields[7] = new Chance("Chance", 7);
	fields[8] = new Property("Vermont Ave.", 8, 100, SKY, 0, 6, 30, 90, 270, 400, 550, 50, 50);
	fields[9] = new Property("Connecticut Ave.", 9, 120, SKY, 0, 8, 40, 100, 300, 450, 600, 50, 60);
	fields[10] = new Jail("Jail", 10);
	fields[11] = new Property("St. Charles Place", 11, 140, PINK, 0, 10, 50, 150, 450, 625, 750, 100, 70);
	fields[12] = new Utility("Electric Company", 12, 150, 0, 75);
	fields[13] = new Property("States Ave.", 13, 140, PINK, 0, 10, 50, 150, 450, 625, 750, 100, 70);
	fields[14] = new Property("Virginia Ave.", 14, 160, PINK, 0, 12, 60, 180, 500, 700, 900, 100, 80);
	fields[15] = new Railroad("Pennsylvania Railroad", 15, 200, 0, 100);
	fields[16] = new Property("St. James Place", 16, 180, ORANGE, 0, 14, 70, 200, 550, 750, 950, 100, 90);
	fields[17] = new Chance("Chance", 17);
	fields[18] = new Property("Tennessee Ave.", 18, 180, ORANGE, 0, 14, 70, 200, 550, 750, 950, 100, 90);
	fields[19] = new Property("New York Ave.", 19, 180, ORANGE, 0, 14, 70, 200, 550, 750, 950, 100, 90);
	fields[20] = new FreeParkingField("Free Parking", 20);
	fields[21] = new Property("Kentucky Ave.", 21, 220, RED, 0, 18, 90, 250, 700, 875, 1050, 150, 110);
	fields[22] = new Chance("Chance", 22);
	fields[23] = new Property("Indiana Ave.", 23, 220, RED, 0, 18, 90, 250, 700, 875, 1050, 150, 110);
	fields[24] = new Property("Illinois Ave.", 24, 240, YELLOW, 0, 20, 100, 300, 750, 925, 1150, 150, 120);
	fields[25] = new Railroad("B. & O. Railroad", 25, 200, 0, 100);
	fields[26] = new Property("Atlantic Ave.", 26, 260, YELLOW, 0, 22, 110, 330, 800, 975, 1100, 150, 130);
	fields[27] = new Property("Ventnor Ave.", 27, 260, YELLOW, 0, 22, 110, 330, 800, 975, 1150, 150, 130);
	fields[28] = new Utility("Water Works", 28, 150, 0, 75);
	fields[29] = new Property("Marvin Gardens", 29, 280, YELLOW, 0, 24, 120, 360, 850, 1025, 1200, 150, 140);
	fields[30] = new GoToJailField("Go to Jail", 30);
	fields[31] = new Property("Pacific Ave.", 31, 300, GREEN, 0, 26, 130, 390, 900, 1100, 1275, 200, 150);
	fields[32] = new Property("North Caroline Ave.", 32, 300, GREEN, 0, 26, 130, 390, 900, 1100, 1275, 200, 150);
	fields[33] = new Chance("Chance", 33);
	fields[34] = new Property("Pennsylvania Ave.", 34, 320, GREEN, 0, 28, 150, 450, 1000, 1200, 1400, 200, 160);
	fields[35] = new Railroad("Short Line", 35, 200, 0, 100);
	fields[36] = new Chance("Chance", 36);
	fields[37] = new Property("Park Place", 37, 350, BLUE, 0, 35, 175, 500, 1100, 1300, 1500, 200, 175);
	fields[38] = new LuxuryTax("Luxury Tax", 38);
	fields[39] = new Property("Boardwalk", 39, 400, BLUE, 0, 50, 200, 600, 1400, 1700, 2000, 200, 200);
}

void GameBoard::draw()
{
	cout << "|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|" << endl;
	cout << "|  Free   |Kentucky | Chance  | Indiana |Illinois | B. & O. |Atlantic | Ventnor |  Water  |  Marvin |  Go To  |" << endl;
	cout << "| Parking | Avenue  |    ?    |  Avenue | Avenue  |Railroad | Avenue  |  Avenue |  Works  | Gardens |  Jail   |" << endl;
	cout << "| Jackpot:|         |         |         |         |         |         |         |         |         |         |" << endl;
	cout << "|         |   RED   |         |   RED   |   RED   |         |  YELLOW |  YELLOW | UTILITY | YELLOW  |         |  " << endl;
	cout << "|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|" << endl;
	cout << "| New York|                                                                                         | Pacific |" << endl;
	cout << "| Avenue  |                                                                                         |  Avenue |" << endl;
	cout << "|         |                                                                                         |         |" << endl;
	cout << "|  ORANGE |                                                                                         |  GREEN  |" << endl;
	cout << "|---------|                                                                                         |---------|" << endl;
	cout << "|Tennessee|                                                                                         |  North  |" << endl;
	cout << "|  Avenue |                                                                                         |Carolina |" << endl;
	cout << "|         |                                                                                         |  Avenue |" << endl;
	cout << "|  ORANGE |                                                                                         |  GREEN  |" << endl;
	cout << "|---------|                                                                                         |---------|" << endl;
	cout << "|Community|                                                                                         |Community|" << endl;
	cout << "|  Chest  |                                                                                         |  Chest  |" << endl;
	cout << "|         |                                                                                         |         |" << endl;
	cout << "|         |                                                                                         |         |" << endl;
	cout << "|---------|                                                                                         |---------|" << endl;
	cout << "|St.James |                                   Monopoly                                              |Pennsylva|" << endl;
	cout << "| Place   |                                                                                         |  -nia   |" << endl;
	cout << "|         |                                                                                         |  Avenue |" << endl;
	cout << "| ORANGE  |                                                                                         |  GREEN  |" << endl;
	cout << "|---------|                                                                                         |---------|" << endl;
	cout << "|Pennsylva|                                                                                         |ShortLine|" << endl;
	cout << "| -nia    |                                                                                         | Railroad|" << endl;
	cout << "|Railroad |                                                                                         |         |" << endl;
	cout << "|         |                                                                                         |         |" << endl;
	cout << "|---------|                                                                                         |---------|" << endl;
	cout << "|Virginia |                                                                                         |  Chance |" << endl;
	cout << "| Avenue  |                                                                                         |    ?    |" << endl;
	cout << "|         |                                                                                         |         |" << endl;
	cout << "|   PINK  |                                                                                         |         |" << endl;
	cout << "|---------|                                                                                         |---------|" << endl;
	cout << "|  States |                                                                                         |  Park   |" << endl;
	cout << "|  Avenue |                                                                                         |  Place  |" << endl;
	cout << "|         |                                                                                         |         |" << endl;
	cout << "|   PINK  |                                                                                         |   BLUE  |" << endl;
	cout << "|---------|                                                                                         |---------|" << endl;
	cout << "|Electric |                                                                                         |  Luxury |" << endl;
	cout << "| Company |                                                                                         |   Tax   |" << endl;
	cout << "|         |                                                                                         |         |" << endl;
	cout << "| UTILITY |                                                                                         |         |" << endl;
	cout << "|---------|                                                                                         |---------|" << endl;
	cout << "|   St.   |                                                                                         |Boardwalk|" << endl;
	cout << "| Charles |                                                                                         |         |" << endl;
	cout << "|  Place  |                                                                                         |         |" << endl;
	cout << "|   PINK  |                                                                                         |   BLUE  |" << endl;
	cout << "|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|" << endl;
	cout << "|  Jail   |Connectic| Vermont |  Chance | Oriental| Reading | Income  | Baltic  |Community|Mediterra|   Go    |" << endl;
	cout << "|         |   -ut   |  Avenue |    ?    |  Avenue | Railroad|  Tax    | Avenue  |  Chest  |  -nean  |         |" << endl;
	cout << "|         |  Avenue |         |         |         |         |         |         |         | Avenue  | Collect |" << endl;
	cout << "|         |   SKY   |   SKY   |         |   SKY   |         |         |  PURPLE |         |  PURPLE |  $200   |" << endl;
	cout << "|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|\n" << endl;
}

PlayingField * GameBoard::getFieldInfo(int position)
{
	return fields[position];
}

int GameBoard::getPropertiesNumber()
{
	return numberProperties;
}

bool GameBoard::isFieldPropertyReilroadOrUtility(int position)
{
	return (fields[position]->getFieldType() == "property" ||
		fields[position]->getFieldType() == "railroad" ||
		fields[position]->getFieldType() == "utility");
}



