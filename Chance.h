#include "PlayingField.h"
#include "ChanceCard.h"
#include "OutOfJailCard.h"
#include "Win200.h"
#include "Loose200.h"
#include "Collect200.h"
#include "EmptyCard.h"
#include "Give1000ForCharity.h"
#include "Fine500.h"
#include "Bingo1500.h"
#include <time.h>

class Chance: public PlayingField
{
public:
	Chance(string, int);
	virtual void actionOfPlayerOnTheField(Player*, int);
	virtual string getFieldType();
private:
	ChanceCard* findProperCard(int);
};
