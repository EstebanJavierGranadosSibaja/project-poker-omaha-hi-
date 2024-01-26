#pragma once
#include "winning_play.h"

const int NUMBER_OF_ROYAL_FLUSH_TYPES = 4;
const int NUMBER_OF_ROYAL_FLUSH_VALUES = 5;
const string ROYAL_FLUSH_TYPES[NUMBER_OF_ROYAL_FLUSH_TYPES] = { "Hearts", "Diamonds", "Clubs", "Pikes" };
const char ROYAL_FLUSH_VALUES[NUMBER_OF_ROYAL_FLUSH_VALUES] = { 'A','J','Q','K','10' };

class RoyalFlush : public WinningPlay
{
private:

public:
	RoyalFlush();

	int getPlayeRanking(Card** newHand, Card** newCommunityCards);
	bool isValidCommunityHand(Card** newCommunityCards);
	bool isValidPlayerHand(Card** newHand);
	bool checkCommunityHandPosition(Card** newCommunityCards, string newType);
	bool checkPlayerHandPosition(Card** newHand, char newValue);

};

