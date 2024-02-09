#pragma once
#include "winning_play.h"

const int SIZE_OF_HAND_HIGH_CARD = 5;

class HighCard : public WinningPlay
{
private:
	int HandHighCardNumber[SIZE_OF_HAND_HIGH_CARD];

public:
	HighCard() : WinningPlay() {}

	int getPlayerRanking(Card** newHand, Card** newCommunityCards);
	int getHighNumbers(Card** newCommunityCards, int newHighCardIndex);
	int getTheMostHigherNumber();

};

