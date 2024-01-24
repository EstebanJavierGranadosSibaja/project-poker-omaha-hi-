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
