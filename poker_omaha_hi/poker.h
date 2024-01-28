#pragma once
#include"winning_play.h"
const int POKER_VALUE = 200;

class Poker : public WinningPlay
{
private: 


public: 
	virtual int getPlayerHandRankin(Card** newHand, Card** newCommunityCards);
	bool  communityCardCombinations(Card** combinationOfCards, Card** newCommunityCards);
	bool isAPoker(Card** vectorOfCombinations);

	
	





};


