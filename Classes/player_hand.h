#pragma once
#include "card.h"
#include <SFML/Graphics.hpp>

using namespace sf;

const int SIZE_OF_PLAYER_DECK = 4;

class PlayerHand
{
private:
	Card** hand;
	Texture vectorOfTextures[SIZE_OF_PLAYER_DECK];
	Sprite vectorOfSprites[SIZE_OF_PLAYER_DECK];
	
public:
	PlayerHand();
	PlayerHand(Card** newHand) = delete;

	void createSprites();

	void setHand(Card** newHand);

	Card** getHand();
	Texture* getTexture();
	Sprite* getSprite();
};
