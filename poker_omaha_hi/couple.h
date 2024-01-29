#pragma once
#include"winning_play.h"
const int COUPLE_VALUE = 18; 

class Couple : public WinningPlay
{
private: 


public:
	int getPlayerHandRankin(Card** newHand, Card** newCommunityCards);
	bool  communityCardCombinations(Card** combinationOfCards, Card** newCommunityCards);
	void sortTheCards(Card**& vectorOfCombinations);
	bool isACouple(Card** vectorOfCombinations);






};
