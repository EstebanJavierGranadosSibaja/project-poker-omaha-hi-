#pragma once
#include "winning_play.h"

class HighCard : public WinningPlay
{
private:
	Card* highCard;

public:
	HighCard();

	int getPlayerRanking(Card** newHand, Card** newCommunityCards);

	//bool checkHighCard();

};

