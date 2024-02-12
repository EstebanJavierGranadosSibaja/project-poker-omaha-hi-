#include"player_hand.h"

PlayerHand::PlayerHand()
{
	vectorOfPlayerSprites = new Sprite[SIZE_OF_PLAYER_DECK];
	vectorOfPlayerTextures = new Texture[SIZE_OF_PLAYER_DECK];
	hand = new Card * [SIZE_OF_PLAYER_DECK];
	for (int i = 0; i < SIZE_OF_PLAYER_DECK; i++) {
		hand[i] = new Card();
	}
}

void PlayerHand::createPlayerSprites()
{
	for (int i = 0; i < SIZE_OF_PLAYER_DECK; i++)
	{
		vectorOfPlayerTextures[i].loadFromFile(hand[i]->getUrl());
		vectorOfPlayerSprites[i] = Sprite(vectorOfPlayerTextures[i]);
	}
}

void PlayerHand::setHand(Card** newHand)
{
	hand = newHand;
}

void PlayerHand::setPlayersSprite(Sprite* newSprites)
{
	vectorOfPlayerSprites = newSprites;
}

string PlayerHand::getHandToText(int numberOfPlayer)
{
	string newHandText = "  ||  CARTAS_DELJUGADOR_N_" + to_string(numberOfPlayer) + "  ||  " + "\n\n";

	for (int i = 0; i < SIZE_OF_PLAYER_DECK; i++)
	{
		newHandText += "  ||  Palo: " + hand[i]->getType() + "  ||  Valor: " + hand[i]->getValue() + "  ||  Numero: " + to_string(hand[i]->getNumber()) + "  ||  " + "\n";
	}

	return newHandText;
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

void PlayerHand::setPositionAndScalesOfPlayerSprites(RectangleShape& userBox, int index)
{
	vectorOfPlayerSprites[index].setPosition(userBox.getPosition());
	vectorOfPlayerSprites[index].setScale(userBox.getSize().x / vectorOfPlayerTextures[index].getSize().x,
		userBox.getSize().y / vectorOfPlayerTextures[index].getSize().y);
}