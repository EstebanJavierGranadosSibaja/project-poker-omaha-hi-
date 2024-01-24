#pragma once
#include"dealer.h"

class PokerTable
{
private: 
	int pot; 
	int bigBlind;
	int smallBlind; 
	int numberOfPlayers;
	Dealer* dealer; 
	Deck* deck; 
	
    //Player** player;


public: 
	PokerTable(); 
	PokerTable();
	PokerTable(int aPot, int aBigBlind, int aSmallBlind, int aNumberOfPlayers, Dealer* dealer, Deck* deck);
	~PokerTable();

	void setPot(int aPot);
	void setBigBlind(int aBigBlind);
	void setSmallBlind(int aSmallBlind);
	void setNumberOfPlayers(int newNumberOfPlayers);
	void setDealer(Dealer* dealer);
	void setDeck(Deck* deck);

	int getPot();
	int getBigBlind();
	int getSmallBlind();
	int getNumberOfPlayers();
	Dealer* getDealer();
	Deck* getDeck();

};
