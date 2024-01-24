#pragma once
#include "deck.h"

const int SIZE_OF_PLAYER_DECK = 4;

class PlayerHand
{
private:
	Card** hand;
	
	

public:
	PlayerHand();
	PlayerHand(Card** newHand) = delete;

	void setHand(Card** newHand);
	Card** getHand();
	
};
