#pragma once
#include "deck.h"
#include"player.h"



class Dealer
{
private:
	Card** communityCards;
	Texture vectorOfDealerTextures[SIZE_OF_PLAYER_DECK];
	Sprite vectorOfDealerSprites[SIZE_OF_PLAYER_DECK];

public:
	Dealer();
	Dealer(Card** newCommunityCads); 
	void createDealerSprites();
	void setCommunityCards(Deck*& deck); 
	void shuffleDeck(Deck*& newDeck);
	Player** getPlayerCards(Player**& players, int amountOfPlayers, Deck*& pokerTableDeck);
	Card** getCommunityCards();
	Card** getFloat();
	Card** getTurn();
	Card** getRiver();
	Card** getShowedCards();
	Texture* getDealerTexture();
	Sprite* getDealerSprite();
}; 
