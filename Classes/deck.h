#pragma once
#include"card.h"

const int NUMBER_OF_TYPES = 4;
const int NUMBER_OF_VALUES = 13;
const string ARRAY_OF_TYPES[NUMBER_OF_TYPES] = { "Hearts", "Diamonds", "Clubs", "Pikes" };
const char ARRAY_OF_VALUES[NUMBER_OF_VALUES] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9','10','J','Q', 'K' };

class Deck {
private:
	
	Card** deck;
	int amountCards;
public:
	Deck();
	~Deck();

	void setDeck(Card** newDeck);
	void setAmountCards(int newAmountCards);

	Card** getDeck();
	int getAmountCards();
	Deck* eraseAPosition(int index); 
};
