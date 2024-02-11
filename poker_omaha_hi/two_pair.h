#pragma once
#include"winning_play.h"

const int TWO_PAIR_VALUE = 11; 

class TwoPair : public WinningPlay
{
private: 



public: 

	int getPlayerHandRankin(Card** newHand, Card** newCommunityCards);
	bool  communityCardCombinations(Card** combinationOfCards, Card** newCommunityCards);
	void sortTheCards(Card**& vectorOfCombinations);
	bool isATwoPair(Card** vectorOfCombinations);




};
