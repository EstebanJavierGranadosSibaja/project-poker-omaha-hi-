#pragma once
#include "../Classes/player_hand.h"

using namespace std;

const int NUMBER_OF_VALID_COMMUNITY_HAND = 3;
const int SIZE_OF_COMMUNITY_CARDS = 5;

class WinningPlay
{
private:

public:
	WinningPlay() {};

	virtual int getPlayerHandRankin(Card** newHand, Card** newCommunityCards) = 0;
	virtual void sortTheCards(Card** vectorOfCombinations);
};

