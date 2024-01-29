#pragma once
#include"winning_play.h"
const int TRIO_VALUE = 10; 

class Trio : public WinningPlay
{
private: 
	


public: 

	int getPlayerHandRankin(Card** newHand, Card** newCommunityCards);
	bool  communityCardCombinations(Card** combinationOfCards, Card** newCommunityCards);
	void sortTheCards(Card**& vectorOfCombinations);
	bool isATrio(Card** vectorOfCombinations);



};
