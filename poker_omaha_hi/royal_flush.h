#pragma once
#include "winning_play.h"

const char ROYAL_FLUSH_VALUES[NUMBER_OF_VALUES] = { 'A','X','J','Q','K' };
const char ROYAL_FLUSH_VALUE = 300;

class RoyalFlush : public WinningPlay
{
private:

public:
	RoyalFlush() : WinningPlay() {}

	int getPlayerRanking(Card** newHand, Card** newCommunityCards);
	bool communityCardCombinations(Card** combinationOfCards, Card** newCommunityCards);
	bool isSameColor(Card** vectorOfCombinations);
	bool isRoyalFlush(Card** vectorOfCombinations);
	void sortTheCards(Card**& vectorOfCombinations);

};

