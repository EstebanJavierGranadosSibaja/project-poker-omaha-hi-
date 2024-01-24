#include "poker_table.h"

PokerTable::PokerTable()
{
	pot = 0;
	bigBlind = 0;
	smallBlind = 0;
	numberOfPlayers = 0;
	dealer = nullptr;
	deck = nullptr;
}

PokerTable::PokerTable(int aPot, int aBigBlind, int aSmallBlind, int aNumberOfPlayers, Dealer* aDealer, Deck* aDeck)
{
	pot = aPot;
	bigBlind = aBigBlind;
	smallBlind = aSmallBlind;
	numberOfPlayers = aNumberOfPlayers;
	dealer = aDealer;
	deck = aDeck;
}

PokerTable::~PokerTable()
{
}

void PokerTable::setPot(int aPot)
{
	pot = aPot;
}

void PokerTable::setBigBlind(int aBigBlind)
{
	bigBlind = aBigBlind;
}

void PokerTable::setSmallBlind(int aSmallBlind)
{
	smallBlind = aSmallBlind;
}

void PokerTable::setNumberOfPlayers(int newNumberOfPlayers)
{
	numberOfPlayers = newNumberOfPlayers;
}

void PokerTable::setDealer(Dealer* newDealer)
{
	dealer = newDealer;
}

void PokerTable::setDeck(Deck* newDeck)
{
	deck = newDeck;
}

int PokerTable::getPot()
{
	return pot;
}

int PokerTable::getBigBlind()
{
	return bigBlind;
}

int PokerTable::getSmallBlind()
{
	return smallBlind;
}

int PokerTable::getNumberOfPlayers()
{
	return numberOfPlayers;
}

Dealer* PokerTable::getDealer()
{
	return dealer;
}

Deck* PokerTable::getDeck()
{
	return deck;
}