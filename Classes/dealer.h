#pragma once
#include "deck.h"
#include"player.h"



class Dealer
{
private:
	Card** communityCards;
	Texture* vectorOfDealerTextures;
	Sprite* vectorOfDealerSprites;

public:
	Dealer();
	Dealer(Card** newCommunityCads);
	void createDealerSprites();
	void setCommunityCards(Deck*& deck);
	void shuffleDeck(Deck*& newDeck);
	void getPlayerCards(Player**& players, int amountOfPlayers, Deck*& pokerTableDeck);
	Card** getCommunityCards();
	Card** getFloat();
	Card** getTurn();
	Card** getRiver();
	Card** getShowedCards();
	Texture* getDealerTexture();
	Sprite* getDealerSprite();
	string getCommunityCardsToText();
}; 
