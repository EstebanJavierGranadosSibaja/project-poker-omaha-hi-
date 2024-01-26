#include"dealer.h"

Dealer::Dealer()
{
	communityCards = new Card* [COMMUNITY_CARD_SIZE]; 

	for (int i = 0; i < COMMUNITY_CARD_SIZE; i++)
	{
		communityCards[i] = new Card(); 
	}
}

Dealer::Dealer(Card** newCommunityCads)
{
	communityCards = newCommunityCads; 
}

void Dealer::setCommunityCards(Deck*& deck)
{
	for (int i = 0; i < COMMUNITY_CARD_SIZE; i++)
	{
		communityCards[i] = deck-> getDeck()[i];
		deck = deck->eraseAPosition(i); 
	}
}

void Dealer::shuffleDeck(Deck*& deck)
{
	int auxiliary = 0; 
	int sizeDeck = deck->getAmountCards(); 
	Deck* randomDeck = new Deck; 

	for (int i = 0; i < sizeDeck; i++)
	{
		auxiliary = rand() % sizeDeck; 
		randomDeck->getDeck()[i] = deck->getDeck()[auxiliary]; 
		deck = deck->eraseAPosition(auxiliary); 
	}
	delete[] deck; 
	deck = randomDeck; 
}

Player** Dealer::getPlayerCards(PokerTable*& pokerTable)
{
	int firtsPosition = 0; 
	for (int i = 0; i < pokerTable->getNumberOfPlayers(); i++)
	{
		for (int j = 0; j < SIZE_OF_PLAYER_DECK; j++)
		{
			pokerTable->getPlayers()[i]-> getUserHand()-> getHand()[j] = pokerTable-> getDeck()-> getDeck()[firtsPosition];
			pokerTable-> setDeck(pokerTable->getDeck()->eraseAPosition(firtsPosition));
		}
	}

	return pokerTable-> getPlayers();
}

Card** Dealer::getFloat()
{
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
	Card** fourthPositions = new Card* [fourthPosition];

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
