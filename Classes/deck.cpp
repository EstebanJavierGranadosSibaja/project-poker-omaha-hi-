#include"deck.h"

Deck::Deck()
{
	amountCards = 52;
	int position = 0; 

	deck = new Card * [amountCards];
	for (int i = 0; i < amountCards; i++) {
		deck[i] = new Card();
	}

	for (int i = 0; i < numberOfTypes; i++)
	{
		for (int j = 0; j < numberOfValues; j++)
		{
			deck[position] = new Card(arrayOfValues[j], arrayOfTypes[i], j+1, " ");
			position++; 
		}
	}
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

Deck* Deck::eraseAPosition(int index)
{
	Deck* newDeck = new Deck();
	newDeck->setAmountCards(amountCards - 1); 
	int increase = 0; 
	
	for (int i = 0; i < amountCards; i++)
	{
		bool isSameCard = deck[i] == deck[index];

		if (isSameCard)
		{
			continue; 
		}

		newDeck-> getDeck()[increase] = deck[i];
		increase++;
	}

	return newDeck; 
}
