#pragma once
#include <iostream>
#include "../Classes/player_hand.h"

using namespace std;

const int NUMBER_OF_VALID_COMMUNITY_HAND = 3;
const int NUMBER_OF_VALID_PLAYER_HAND = 2;

class WinningPlay
{
private:

public:
	WinningPlay();

	virtual int getPlayerHandRankin(Card** newHand, Card** newCommunityCards) = 0;

};

