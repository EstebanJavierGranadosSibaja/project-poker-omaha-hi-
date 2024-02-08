#pragma once
#include "../Classes/player_hand.h"

using namespace std;

const int NUMBER_OF_VALID_COMMUNITY_HAND = 3;
const int NUMBER_OF_VALID_PLAYER_HAND = 2;
const int NUMBER_OF_CARD_PARAMETERS = 3;
const int NUMBER_OF_VECTORS = 5;
const int NUMBER_OF_USER_VALUES = 5;
const int SIZE_OF_COMMUNITY_CARDS = 5;

class WinningPlay
{
protected:
	Card* clubsTypes[NUMBER_OF_USER_VALUES];
	Card* pikesTypes[NUMBER_OF_USER_VALUES];
	Card* heartsTypes[NUMBER_OF_USER_VALUES];
	Card* diamondsTypes[NUMBER_OF_USER_VALUES];
	int cardParameters[NUMBER_OF_CARD_PARAMETERS];

public:
	WinningPlay();

	virtual int getPlayerHandRankin(Card** newHand, Card** newCommunityCards) = 0;
	virtual void sortTheCards(Card** vectorOfCombinations);
};

