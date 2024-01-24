#pragma once
#include"dealer.h"
#include"player.h"

class PokerTable
{
private: 
	int pot; 
	int bigBlind;
	int smallBlind; 
	int numberOfPlayers;
	Dealer* dealer; 
	Deck* deck; 
	Player** players;


public: 
	PokerTable(int aNumberOfPlayers);
	PokerTable(int aPot, int aBigBlind, int aSmallBlind, int aNumberOfPlayers, Dealer* newDealer, Deck* newDeck, Player** newPlayers);
	~PokerTable();

	void setPot(int aPot);
	void setBigBlind(int aBigBlind);
	void setSmallBlind(int aSmallBlind);
	void setNumberOfPlayers(int newNumberOfPlayers);
	void setDealer(Dealer* newDealer);
	void setDeck(Deck* newDeck);
	void setPlayer(Player** newPlayers); 

	int getPot();
	int getBigBlind();
	int getSmallBlind();
	int getNumberOfPlayers();
	Dealer* getDealer();
	Deck* getDeck();
	Player** getPlayers(); 

};
