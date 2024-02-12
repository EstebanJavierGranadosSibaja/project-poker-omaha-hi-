#include"dealer.h"

Dealer::Dealer()
{
	communityCards = new Card * [COMMUNITY_CARD_SIZE];
	vectorOfDealerSprites = new Sprite[COMMUNITY_CARD_SIZE];
	vectorOfDealerTextures = new Texture[COMMUNITY_CARD_SIZE];

	for (int i = 0; i < COMMUNITY_CARD_SIZE; i++)
	{
		communityCards[i] = new Card();
	}
}

Dealer::Dealer(Card** newCommunityCads)
{
	communityCards = newCommunityCads;
}

void Dealer::createDealerSprites()
{
	for (int i = 0; i < COMMUNITY_CARD_SIZE; i++)
	{
		vectorOfDealerTextures[i].loadFromFile(communityCards[i]->getUrl());
		vectorOfDealerSprites[i].setTexture(vectorOfDealerTextures[i]);
	}
}

void Dealer::setCommunityCards(Deck*& deck)
{
	for (int i = 0; i < COMMUNITY_CARD_SIZE; i++)
	{
		communityCards[i] = deck->getDeck()[i];
		deck = deck->eraseAPosition(i);
	}
}

void Dealer::shuffleDeck(Deck*& deck)
{
	srand(time(NULL));

	int sizeDeck = deck->getAmountCards();
	Deck* randomDeck = new Deck;

	for (int i = 0; i < sizeDeck; i++)
	{
		int index = rand() % deck->getAmountCards();
		randomDeck->getDeck()[i] = deck->getDeck()[index];
		deck = deck->eraseAPosition(index);
	}

	delete deck;
	deck = randomDeck;
}

void Dealer::getPlayerCards(Player**& players, int amountOfPlayers, Deck*& pokerTableDeck)
{
	int firtsPosition = 0;
	for (int i = 0; i < amountOfPlayers; i++)
	{
		for (int j = 0; j < SIZE_OF_PLAYER_DECK; j++)
		{
			players[i]->getUserHand()->getHand()[j] = pokerTableDeck->getDeck()[firtsPosition];
			pokerTableDeck = pokerTableDeck->eraseAPosition(firtsPosition);
		}
	}

}

Card** Dealer::getCommunityCards()
{
	return communityCards;
}

Card** Dealer::getFloat()
{
	int starPosition = 0;
	int threePositions = 3;
	Card** firstThreePositions = new Card * [threePositions];

	for (int i = 0; i < threePositions; i++)
	{
		firstThreePositions[i] = communityCards[i];
	}

	return firstThreePositions;
}

Card** Dealer::getTurn()
{
	int fourthPosition = 1;
	Card** fourthPositions = new Card * [fourthPosition];

	fourthPositions[0] = communityCards[3];

	return fourthPositions;
}

Card** Dealer::getRiver()
{
	int fifthPosition = 1;
	Card** fifthPositions = new Card * [fifthPosition];

	fifthPositions[0] = communityCards[4];

	return fifthPositions;
}

Card** Dealer::getShowedCards()
{
	return communityCards;
}

Texture* Dealer::getDealerTexture()
{
	return vectorOfDealerTextures;
}

Sprite* Dealer::getDealerSprite()
{
	return vectorOfDealerSprites;
}

string Dealer::getCommunityCardsToText()
{
	string newCommunityCardsText = "";

	newCommunityCardsText = "  ||  CARTAS_COMUNITARIAS_DEL_DEALER  ||  \n\n";

	for (int i = 0; i < COMMUNITY_CARD_SIZE; i++)
	{
		newCommunityCardsText += "  ||  Palo: " + communityCards[i]->getType() + "  ||  Valor: " + communityCards[i]->getValue() + "  ||  Numero: " + to_string(communityCards[i]->getNumber()) + "  ||  " + "\n";
	}

	return newCommunityCardsText;
}

void Dealer::setPositionAndScalesOfDealerSprites(RectangleShape& userBox, int index)
{
	vectorOfDealerSprites[index].setPosition(userBox.getPosition());
	vectorOfDealerSprites[index].setScale(userBox.getSize().x / vectorOfDealerTextures[index].getSize().x,
		userBox.getSize().y / vectorOfDealerTextures[index].getSize().y);
}