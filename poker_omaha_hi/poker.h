#pragma once
#include"winning_play.h"

class Poker : public WinningPlay
{
private: 


public: 
	virtual int getPlayerHandRankin(Card** newHand, Card** newCommunityCards);
	void communityCardCombinations(Card** combinationOfCards, int sizeCommunityCards, Card** newCommunityCards);

	
	





};


