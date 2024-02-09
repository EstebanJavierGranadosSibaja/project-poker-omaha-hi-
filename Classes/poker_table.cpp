#include "poker_table.h"


PokerTable::PokerTable()
{
}

PokerTable::PokerTable(int aBigBlind, int aNumberOfPlayers)
{
	pot = 0;
	bigBlind = aBigBlind;
	smallBlind =aBigBlind / 2;
	numberOfPlayers = aNumberOfPlayers;
	dealer = new Dealer();
	deck = new Deck;
	players = new Player * [numberOfPlayers];

	for (int i = 0; i < numberOfPlayers; i++)
	{
		players[i] = new Player();
	}

	dealer->shuffleDeck(deck); 
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

void PokerTable::setPlayer(Player** newPlayers)
{
	players = newPlayers;
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

Player** PokerTable::getPlayers()
{
	return players;
}
