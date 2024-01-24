#pragma once
#include "deck.h"

const int SIZE_OF_PLAYER_DECK = 4;

class PlayerHand
{
private:
	Card** hand;
	int quantityOfHands = 3;

public:
	PlayerHand();
	PlayerHand(Card** newHand) = delete;

	void setHand(Card** newHand);
	Card** getHand();
	int getQuantityOfHands();
};
