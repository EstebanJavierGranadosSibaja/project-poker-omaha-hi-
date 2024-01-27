#include "high_card.h"

HighCard::HighCard()
{
	highCard = new Card('ANYONE', "ANYONE", 0, "ANYONE")
}

int HighCard::getPlayerRanking(Card** newHand, Card** newCommunityCards)
{
	for (int i = 0; i < COMMUNITY_CARD_SIZE; i++)
	{
		if (newHand[i]->getNumber() > highCard->getNumber())
		{

		}

	}
	SIZE_OF_PLAYER_DECK


	return 0;
}

bool HighCard::checkHighCard(Card** newHand)
{
	if (newHand[i]->getNumber() > highCard->getNumber())
	{

	}
	return false;
}
