#include"deck.h"

Deck::Deck()
{
	//define 52 cards on the vector, with all the attributes
	amountCards = 52;
	deck = new Card * [amountCards];
	for (int i = 0; i < amountCards; i++) {
		deck[i] = nullptr;
	}
	//make a method to build the 52 cards and put them into the vector
}

Deck::~Deck()
{
	for (int i = 0; i < amountCards; i++) {
		delete[] deck[i];
	}
	delete[] deck;
}

void Deck::setDeck(Card** newDeck)
{
	deck = newDeck;
}

void Deck::setAmountCards(int newAmountCards)
{
	amountCards = newAmountCards;
}

Card** Deck::getDeck()
{
	return deck;
}

int Deck::getAmountCards()
{
	return amountCards;
}