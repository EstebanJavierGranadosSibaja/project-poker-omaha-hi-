#include"player_hand.h"

PlayerHand::PlayerHand()
{
	hand = new Card * [SIZE_OF_PLAYER_DECK];
	for (int i = 0; i < SIZE_OF_PLAYER_DECK; i++) {
		hand[i] = nullptr;
	}
}

void PlayerHand::setHand(Card** newHand)
{
	hand = newHand;
}

Card** PlayerHand::getHand()
{
	return hand;
}


