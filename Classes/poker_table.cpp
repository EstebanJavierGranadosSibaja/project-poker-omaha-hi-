#include "poker_table.h"


PokerTable::PokerTable(int aNumberOfPlayers)
{
	pot = 0;
	bigBlind = 0;
	smallBlind = 0;
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

PokerTable::PokerTable(int aPot, int aBigBlind, int aSmallBlind, int aNumberOfPlayers, Dealer* newDealer, Deck* newDeck, Player** newPlayers)
{
	pot = aPot;
	bigBlind = aBigBlind;
	smallBlind = aSmallBlind;
	numberOfPlayers = aNumberOfPlayers;
	dealer = newDealer;
	deck = newDeck;
	players = newPlayers;
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
