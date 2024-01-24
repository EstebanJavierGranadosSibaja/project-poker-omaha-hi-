#pragma once
#include "deck.h"
#include "player_hand.h"
#include"poker_table.h"

const int COMMUNITY_CARD_SIZE = 5;

class Dealer
{
private:
	Card** communityCards;

public:
	Dealer();
	Dealer(Card** newCommunityCads); 
	void setCommunityCards(Deck*& deck); 
	void shuffleDeck(Deck*& newDeck);
	Player** getPlayerCards(PokerTable*& pokerTable);
	Card** getFloat();
	Card** getTurn();
	Card** getRiver();
	Card** getShowedCards();



}; 
