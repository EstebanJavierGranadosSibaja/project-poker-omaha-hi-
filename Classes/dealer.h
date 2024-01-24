#pragma once
#include "deck.h"
#include "player_hand.h"
#include"poker_table.h"

class Dealer
{
private:
	Card** communityCards;

public:
	void shuffleDeck(Deck*& newDeck);
	PlayerHand** getPlayerCards(PokerTable* pokerTable);
	Card** getFloat();
	Card** getTurn();
	Card** getRiver();
	Card** getShowedCards();


}; 
