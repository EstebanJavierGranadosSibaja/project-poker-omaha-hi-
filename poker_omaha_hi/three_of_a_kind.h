#pragma once
#include"winning_play.h"
const int THREE_OF_A_KIND_VALUE = 10; 

class ThreeOfAkind : public WinningPlay
{
private: 
	
public: 
	int getPlayerHandRankin(Card** newHand, Card** newCommunityCards);
	bool  communityCardCombinations(Card** combinationOfCards, Card** newCommunityCards);
	void sortTheCards(Card**& vectorOfCombinations);
	bool isAThreeOfAkind(Card** vectorOfCombinations);

};
