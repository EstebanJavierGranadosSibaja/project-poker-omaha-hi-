#pragma once
#include"player_hand.h"

class Player
{
private:
	int numberPlayer;
	bool isActive; 
	int userBlind; 
	PlayerHand* userHand; 

public: 
	Player();
	Player(int aNumberPlayer, bool newIsActive, int aUserBlind, int aUserCash, PlayerHand* aUserHand);

	Player(int aNumberPlayer, bool newIsActive, PlayerHand* aUserHand);

	void setNumberPlayer(int aNumberPlayer);
	void setUserBlind(int aUserBlind);
	void setActivePlayer(bool newIsActive);
	void setUserHand(PlayerHand* aUserHand); 

	int getNumberPlayer(); 
	bool getIsActive(); 
	int getUserBlind(); 
	PlayerHand* getUserHand(); 
};
