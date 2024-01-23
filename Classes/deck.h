#pragma once
#include"card.h"

const int numberOfTypes = 4;
const int numberOfValues = 13;
const string arrayOfTypes[numberOfTypes] = { "Hearts", "Diamonds", "Clubs", "Pikes" };
const char arrayOfValues[numberOfValues] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9','10','J','Q', 'K' };

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
};
