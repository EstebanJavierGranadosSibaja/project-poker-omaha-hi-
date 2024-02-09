#include"player_hand.h"

PlayerHand::PlayerHand()
{
	hand = new Card * [SIZE_OF_PLAYER_DECK];
	for (int i = 0; i < SIZE_OF_PLAYER_DECK; i++) {
		hand[i] = new Card();
	}
}

void PlayerHand::createSprites()
{
	for (int i = 0; i < SIZE_OF_PLAYER_DECK; i++)
	{
		vectorOfTextures[i].loadFromFile(hand[i]->getUrl()) ;
		vectorOfSprites[i] = Sprite(vectorOfTextures[i]);
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

Texture* PlayerHand::getTexture()
{
	return vectorOfTextures;
}

Sprite* PlayerHand::getSprite()
{
	return vectorOfSprites;
}
