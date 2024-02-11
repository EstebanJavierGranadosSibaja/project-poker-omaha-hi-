#pragma once
#include "card.h"
#include <SFML/Graphics.hpp>

using namespace sf;

const int SIZE_OF_PLAYER_DECK = 4;

class PlayerHand
{
private:
	Card** hand;
	Texture* vectorOfPlayerTextures;
	Sprite* vectorOfPlayerSprites;
	
public:
	PlayerHand();
	PlayerHand(Card** newHand) = delete;

	void createPlayerSprites();
	void setHand(Card** newHand);
	void setPlayersSprite(Sprite* newSprites);

	string getHandToText(int numberOfPlayer);

	Card** getHand();
	Texture* getPlayerTexture();
	Sprite* getPlayerSprite();
};
