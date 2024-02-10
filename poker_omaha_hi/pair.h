#pragma once
#include"winning_play.h"

const int PAIR_VALUE = 18; 

class Pair : public WinningPlay
{
private:

public:
	int getPlayerHandRankin(Card** newHand, Card** newCommunityCards);
	bool  communityCardCombinations(Card** combinationOfCards, Card** newCommunityCards);
	void sortTheCards(Card**& vectorOfCombinations);
	bool isAPair(Card** vectorOfCombinations);

};
