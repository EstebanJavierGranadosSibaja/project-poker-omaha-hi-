#include"dealer.h"

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

PlayerHand** Dealer::getPlayerCards(PlayerHand** newHand)
{
	return nullptr;
}

Card** Dealer::getFloat()
{
	return nullptr;
}

Card** Dealer::getTurn()
{
	return nullptr;
}

Card** Dealer::getRiver()
{
	return nullptr;
}

Card** Dealer::getShowedCards()
{
	return nullptr;
}
