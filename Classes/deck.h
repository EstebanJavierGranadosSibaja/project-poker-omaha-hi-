#pragma once
#include"card.h"

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
