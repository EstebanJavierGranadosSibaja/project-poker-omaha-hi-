#include"player_hand.h"

PlayerHand::PlayerHand()
{
	hand = new Card * [SIZE_OF_PLAYER_DECK];
	for (int i = 0; i < SIZE_OF_PLAYER_DECK; i++) {
		hand[i] = new Card();
	}
}

void PlayerHand::createPlayerSprites()
{
	for (int i = 0; i < SIZE_OF_PLAYER_DECK; i++)
	{
		vectorOfPlayerTextures[i].loadFromFile(hand[i]->getUrl()) ;
		vectorOfPlayerSprites[i] = Sprite(vectorOfPlayerTextures[i]);
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

Texture* PlayerHand::getPlayerTexture()
{
	return vectorOfPlayerTextures;
}

Sprite* PlayerHand::getPlayerSprite()
{
	return vectorOfPlayerSprites;
}
