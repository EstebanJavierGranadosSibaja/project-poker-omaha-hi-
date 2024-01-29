#pragma once
#include "winning_play.h"

class Color : public WinningPlay
{
private:
	string cardType;

public:

	Color();

	int getPlayerRanking(Card** newHand, Card** newCommunityCards);
	void getTypesColor(Card** newVectorType, Card** newHand, Card** newCommunityCards);
	bool checkColor(string newType, int* newCardParameters);
	bool isColorHand(Card** newCardColor, string newActualColor);
};