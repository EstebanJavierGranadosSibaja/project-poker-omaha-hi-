#pragma once
#include "winning_play.h"
#include "color.h"

class StraightFlush : public WinningPlay
{
private:
	string cardType;
	Color* cardColor;

public:
	StraightFlush();

	int getPlayerRanking(Card** newHand, Card** newCommunityCards);
	int getMostMinorNumber(Card** newCardColor);
	int getMosthigherNumber(Card** newCardColor);
	bool isConsecutiveNumber(Card** newCardColor);
	bool checkConsecutiveNumber(Card** newCardColor, int &newCompareNumber);
};
