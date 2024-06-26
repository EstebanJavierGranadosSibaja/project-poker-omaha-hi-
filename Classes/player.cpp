#include"player.h"

Player::Player(int blindPrice)
{
	numberPlayer = 0;
	isActive = true;
	userBlind = 100 * blindPrice;
	userHand = new PlayerHand();
}

Player::Player(int aNumberPlayer, bool newIsActive, int aUserBlind, PlayerHand* aUserHand)
{
	numberPlayer = aNumberPlayer;
	isActive = newIsActive;
	userBlind = userBlind;
	userHand = aUserHand;
}


void Player::setNumberPlayer(int aNumberPlayer)
{
	numberPlayer = aNumberPlayer;
}

void Player::setUserBlind(int aUserBlind)
{
	userBlind = aUserBlind;
}

void Player::setActivePlayer(bool newIsActive)
{
	isActive = newIsActive;
}

void Player::setUserHand(PlayerHand* aUserHand)
{
	userHand = aUserHand; 
}

int Player::getNumberPlayer()
{
	return numberPlayer;
}

bool Player::getIsActive()
{
	return isActive;
}

int Player::getUserBlind()
{
	return userBlind;
}

PlayerHand* Player::getUserHand()
{
	return userHand;
}
