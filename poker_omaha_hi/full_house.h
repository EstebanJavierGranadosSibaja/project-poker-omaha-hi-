#pragma once
#include"winning_play.h"
const int FULL_HOUSE_VALUE = 100; 

class FullHouse : public WinningPlay
{
private: 



public: 
	int getPlayerHandRankin(Card** newHand, Card** newCommunityCards);
	bool  communityCardCombinations(Card** combinationOfCards, Card** newCommunityCards);
	void sortTheCards(Card**& vectorOfCombinations);
	bool isAFullHouse(Card** vectorOfCombinations);


};
