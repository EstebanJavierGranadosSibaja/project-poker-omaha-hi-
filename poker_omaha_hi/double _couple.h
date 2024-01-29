#pragma once
#include"winning_play.h"

const int DOUBLE_COUPLE_VALUE = 11; 

class DoubleCouple : public WinningPlay
{
private: 



public: 

	int getPlayerHandRankin(Card** newHand, Card** newCommunityCards);
	bool  communityCardCombinations(Card** combinationOfCards, Card** newCommunityCards);
	void sortTheCards(Card**& vectorOfCombinations);
	bool isADoubleCouple(Card** vectorOfCombinations); 




};
