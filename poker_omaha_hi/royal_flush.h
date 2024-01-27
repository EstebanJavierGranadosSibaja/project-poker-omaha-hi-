#pragma once
#include "winning_play.h"

const int NUMBER_OF_ROYAL_FLUSH_TYPES = 4;
const int NUMBER_OF_ROYAL_FLUSH_VALUES = 5;
const char ROYAL_FLUSH_VALUES[NUMBER_OF_ROYAL_FLUSH_VALUES] = { 'A','J','Q','K','10' };

class RoyalFlush : public WinningPlay
{
private:
	char clubsRoyalFlush[NUMBER_OF_ROYAL_FLUSH_VALUES];
	char pikesRoyalFlush[NUMBER_OF_ROYAL_FLUSH_VALUES];
	char heartskRoyalFlush[NUMBER_OF_ROYAL_FLUSH_VALUES];
	char diamondsRoyalFlush[NUMBER_OF_ROYAL_FLUSH_VALUES];

public:
	RoyalFlush();

	int getPlayerRanking(Card** newHand, Card** newCommunityCards);

	void getClubsRoyalFlush(Card** newHand, Card** newCommunityCards);
	void getPikesRoyalFlush(Card** newHand, Card** newCommunityCards);
	void getHeartsRoyalFlush(Card** newHand, Card** newCommunityCards);
	void getDiamondsRoyalFlush(Card** newHand, Card** newCommunityCards);

	bool checkRoyalFlush(Card* newCard, int newPikesPosition, int newNumberOfType);

};

