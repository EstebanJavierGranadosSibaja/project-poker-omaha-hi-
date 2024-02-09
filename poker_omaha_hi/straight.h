#pragma once
#include"winning_play.h"
#include "flush.h"

const int STRAIGHT_VALUE = 3;

class Straight : public WinningPlay 
{
private: 


public: 

	int getPlayerHandRankin(Card** newHand, Card** newCommunityCards);
	bool  communityCardCombinations(Card** combinationOfCards, Card** newCommunityCards);
	void sortTheCards(Card**& vectorOfCombinations);
	bool isAStraigt(Card** vectorOfCombinations);
	bool isACheckStraight(Card** vectorOfCombinations, int startOfTheStaircase);



};
