#pragma once
#include "deck.h"
#include "player_hand.h"

class Dealer
{
private:
	Card** communityCards;

public:
	void shuffleDeck(Deck*& newDeck);
	PlayerHand** getPlayerCards(PlayerHand** newHand, int newQuantityOfHands);
	Card** getFloat();
	Card** getTurn();
	Card** getRiver();
	Card** getShowedCards();


}; 
