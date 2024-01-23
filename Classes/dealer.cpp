#include"dealer.h"

void Dealer::shuffleDeck(Deck* deck)
{

	int maxPosicion = 52;
	int randomPosicion;
	srand(time(NULL));

    for (int startDeck = 0; startDeck < maxPosicion; startDeck++)
    {
		maxPosicion -= startDeck;
		randomPosicion = maxPosicion + rand() % startDeck;

		Deck tempDeck = deck[startDeck];
		deck[startDeck] = deck[randomPosicion];
		deck[randomPosicion] = tempDeck;

		
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
