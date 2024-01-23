#include"dealer.h"

void Dealer::shuffleDeck(Deck* newDeck)
{
    int startDeck = 0;
	int maxPosicion = 52;
	int randomPosicion;
	srand(time(NULL));

    for (int i = startDeck; i < maxPosicion; i++) 
    {
		maxPosicion -= startDeck;
		randomPosicion = maxPosicion + rand() % startDeck;

		Deck tempDeck = newDeck[i];
		newDeck[i] = newDeck[randomPosicion];
		newDeck[randomPosicion] = tempDeck;

		startDeck += 1;
    }
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
