#pragma once
#include "winning_play.h"

const char ROYAL_FLUSH_VALUES[NUMBER_OF_VALUES] = { 'A','J','Q','K','10' };

class RoyalFlush : public WinningPlay
{
private:

public:
	RoyalFlush();

	int getPlayerRanking(Card** newHand, Card** newCommunityCards);

	void getClubsRoyalFlush(Card** newHand, Card** newCommunityCards);
	void getPikesRoyalFlush(Card** newHand, Card** newCommunityCards);
	void getHeartsRoyalFlush(Card** newHand, Card** newCommunityCards);
	void getDiamondsRoyalFlush(Card** newHand, Card** newCommunityCards);

	bool checkRoyalFlush(Card* newCard, Card** newRoyalFlushVector);
	bool checkRankingRoyalFlush(Card* newRoyalFlushValue);

};

