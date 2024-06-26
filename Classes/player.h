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
	Player(int blindPrice);
	Player(int aNumberPlayer, bool newIsActive, int aUserBlind, PlayerHand* aUserHand);

	void setNumberPlayer(int aNumberPlayer);
	void setUserBlind(int aUserBlind);
	void setActivePlayer(bool newIsActive);
	void setUserHand(PlayerHand* aUserHand); 

	int getNumberPlayer(); 
	bool getIsActive(); 
	int getUserBlind(); 
	PlayerHand* getUserHand(); 
};
