#pragma once
#include "winning_play.h"

const int SIZE_OF_HAND_HIGH_CARD = 5;

class HighCard : public WinningPlay
{
private:
	int highNumber;

public:
	HighCard() : highNumber(0) {}

	int getPlayerRanking(Card** newHand, Card** newCommunityCards);
	bool communityCardCombinations(Card** combinationOfCards, Card** newCommunityCards);
	int getTheMostHigherCard(Card** vectorOfCombinations);
	void sortTheCards(Card**& vectorOfCombinations);

};

