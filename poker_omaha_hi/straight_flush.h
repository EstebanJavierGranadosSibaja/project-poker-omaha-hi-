#pragma once
#include "winning_play.h"
#include "flush.h"

const int STRIGHT_FLUSH_VALUE = 150;

class StraightFlush : public WinningPlay
{
private:

public:
	StraightFlush() : WinningPlay() {}

	int getPlayerRanking(Card** newHand, Card** newCommunityCards);
	bool communityCardCombinations(Card** combinationOfCards, Card** newCommunityCards);
	bool isSameColor(Card** vectorOfCombinations);
	bool isConsecutiveNumber(Card** vectorOfCombinations);
	void sortTheCards(Card**& vectorOfCombinations);
};
