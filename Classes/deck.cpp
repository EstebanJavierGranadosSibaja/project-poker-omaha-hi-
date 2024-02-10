#include"deck.h"

Deck::Deck()
{
	amountCards = 52;
	int position = 0;

	deck = new Card* [amountCards];
	for (int i = 0; i < amountCards; i++) 
	{
		deck[i] = new Card();
	}

	for (int i = 0; i < NUMBER_OF_TYPES; i++)
	{
		for (int j = 0; j < NUMBER_OF_VALUES; j++)
		{
			deck[position] = new Card(ARRAY_OF_VALUES[j], ARRAY_OF_TYPES[i], j + 1, "Images" + ARRAY_OF_TYPES[i] + "/" + to_string(j + 1) + ".png");
			position++;
		}
	}
}

//Deck::~Deck()
//{
//	/*for (int i = 0; i < amountCards; i++) 
//	{
//		delete deck[i];
//	}
//	delete deck;*/
//}

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

//void Deck::eraseAPosition(int index)
//{
//	// Eliminar la carta en la posición index
//	delete deck[index];
//
//	// Mover todas las cartas después de la posición index una posición hacia adelante
//	for (int i = index; i < amountCards - 1; ++i)
//	{
//		deck[i] = deck[i + 1];
//	}
//
//	// Reducir el tamaño del mazo en una carta
//	amountCards--;
//}

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

		newDeck->getDeck()[increase] = deck[i];
		increase++;
	}

	return newDeck; 
}