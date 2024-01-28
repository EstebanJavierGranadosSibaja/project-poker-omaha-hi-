#include "high_card.h"

HighCard::HighCard()
{
	highCard = new Card();
}

int HighCard::getPlayerRanking(Card** newHand, Card** newCommunityCards)
{
	int highCardNumber = 0;

	for (int i = 0; i < NUMBER_OF_VALID_COMMUNITY_HAND; i++)
	{
		HandHighCardNumber[i] = getHighNumbers(newCommunityCards, highCardNumber);

		highCardNumber = HandHighCardNumber[i];
	}

	highCardNumber = 0;

	for (int i = 3; i < NUMBER_OF_VALID_PLAYER_HAND+3; i++)
	{
		HandHighCardNumber[i] = getHighNumbers(newHand, highCardNumber);

		highCardNumber = HandHighCardNumber[i];
	}


	return getTheMostHigherNumber();
}

int HighCard::getHighNumbers(Card** newCards, int newHighCardNumber)
{
	int numberCompare = 0;

	for (int i = 0; i < COMMUNITY_CARD_SIZE; i++)
	{
		int compareCard = newCards[i]->getNumber();

		if ((compareCard > numberCompare) && (compareCard != newHighCardNumber))
		{
			numberCompare = compareCard;
		}
	}

	return numberCompare;
}

int HighCard::getTheMostHigherNumber()
{
	int mostHigherNumber = 0;

	for (int i = 0; i < SIZE_OF_HAND_HIGH_CARD; i++)
	{
		if (mostHigherNumber < HandHighCardNumber[i])
		{
			mostHigherNumber = HandHighCardNumber[i];
		}
	}

	return mostHigherNumber;
}

