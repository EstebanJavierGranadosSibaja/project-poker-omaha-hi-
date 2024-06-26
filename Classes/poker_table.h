#pragma once
#include"dealer.h"
#include"player.h"
#include"menu.h"

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

	PokerTable(int aBigBlind, int aNumberOfPlayers);
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
	int getPlayerBlind(int index);
	void setPlayerBlind(int index, int newBlinds);
	Dealer* getDealer();
	Deck* getDeck();
	Player** getPlayers();

	void dealCardsToThePlayers();


	bool validationOfThreeBigBlindButton(int& actualUserBlind);
	bool validationOfThreePartsPotButton(int& actualUserBlind);
	bool validationOfTwoPartsPotButton(int& actualUserBlind);
	bool validationOfPotButton(int& actualUserBlind);
	bool validationOfAllInButton(int& actualUserBlind);
	void validationOfGoOut(int& actualUserBlind, int playerIndex);

	string* convertHandsToText();
	string* convertCommunityCardsToText();
	void createAHistoryRanking();

	void preFloatIncreaseThePot(int index, int& actualUserBlind, int actualUser);
	void posFloatIncreaseThePot(int index, int& actualUserBlind, int actualUser);

	void drawActualPlayerHand(int index, RenderWindow& window);
};