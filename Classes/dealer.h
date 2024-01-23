#pragma once
#include "deck.h"
#include "player_hand.h"

class Dealer
{
private:

public:
	void shuffleDeck(Deck* newDeck);
	PlayerHand** getPlayerCards(PlayerHand** newHand);
	Card** getFloat();
	Card** getTurn();
	Card** getRiver();
	Card** getShowedCards();


}; 
