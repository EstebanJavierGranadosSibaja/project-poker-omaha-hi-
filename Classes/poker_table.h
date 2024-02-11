#pragma once
#include"dealer.h"
#include"player.h"
#include"menu.h"
//#include"poker_display.h"
#include"../poker_omaha_hi/winning_play.h"
#include"../poker_omaha_hi/file_manager.h"

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
	fileManager file;
	

public: 
	PokerTable() {};
	PokerTable(int aBigBlind,int aNumberOfPlayers);
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

	void dealCardsToThePlayers(); 

	void startPreFloatRound();
	bool validationOfThreeBigBlindButton(int &actualUserBlind);
	bool validationOfThreePartsPotButton(int& actualUserBlind);
	bool validationOfTwoPartsPotButton(int& actualUserBlind);
	bool validationOfPotButton(int& actualUserBlind);
	bool validationOfAllInButton(int& actualUserBlind);

	string* convertHandsToText();
	string* convertCommunityCardsToText();
	void createAHistoryRanking();
};
