#pragma once
#include "winning_play.h"
#include "royal_flush.h"

const int COLOR_VALUE = 50;

class Color : public WinningPlay
{
private:

public:

	Color() : WinningPlay() {}

	int getPlayerRanking(Card** newHand, Card** newCommunityCards);
	bool communityCardCombinations(Card** combinationOfCards, Card** newCommunityCards);
	bool isSameColor(Card** vectorOfCombinations);
	void sortTheCards(Card**& vectorOfCombinations);
};