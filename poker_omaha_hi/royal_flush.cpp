#include "royal_flush.h"

RoyalFlush::RoyalFlush()
{
	for (int i = 0; i < 2; i++)
	{
		parameterOfRoyalFlush[i] = 0;
	}
}

int RoyalFlush::getPlayerRanking(Card** newHand, Card** newCommunityCards)
{
	int clubsCounter = 0, pikesCounter = 0, heartsCounter = 0, diamondsCounter = 0;
	bool isRoyalFLush = clubsCounter == 5 || pikesCounter == 5 || heartsCounter == 5 || diamondsCounter == 5;

	getClubsRoyalFlush(newHand, newCommunityCards);
	getPikesRoyalFlush(newHand, newCommunityCards);
	getHeartsRoyalFlush(newHand, newCommunityCards);
	getDiamondsRoyalFlush(newHand, newCommunityCards);

	for (int i = 0; i < NUMBER_OF_VALUES; i++)
	{
		if (checkRankingRoyalFlush(clubsTypes[i]))
		{
			clubsCounter += 1;
		}
		if (checkRankingRoyalFlush(pikesTypes[i]))
		{
			pikesCounter += 1;
		}
		if (checkRankingRoyalFlush(heartsTypes[i]))
		{
			heartsCounter += 1;
		}
		if (checkRankingRoyalFlush(heartsTypes[i]))
		{
			diamondsCounter += 1;
		}
	}

	if (isRoyalFLush)
	{
		return 300;
	}

	return -1;
}

void RoyalFlush::getClubsRoyalFlush(Card** newHand, Card** newCommunityCards)
{
	int clubsPosition = 0;
	int numberOfType = 2;

	parameterOfRoyalFlush[0] = numberOfType;

	for (int i = 0; i < NUMBER_OF_VALID_COMMUNITY_HAND; i++)
	{
		parameterOfRoyalFlush[1] = clubsPosition;

		if (checkRoyalFlush(newCommunityCards[i], clubsTypes, parameterOfRoyalFlush))
		{
			clubsPosition += 1;
		}
	}

	for (int i = 0; i < NUMBER_OF_VALID_PLAYER_HAND; i++)
	{
		parameterOfRoyalFlush[1] = clubsPosition;

		if (checkRoyalFlush(newHand[i], clubsTypes, parameterOfRoyalFlush))
		{
			clubsPosition += 1;
		}
	}
}

void RoyalFlush::getPikesRoyalFlush(Card** newHand, Card** newCommunityCards)
{
	int pikesPosition = 0;
	int numberOfType = 3;

	parameterOfRoyalFlush[0] = numberOfType;

	for (int i = 0; i < NUMBER_OF_VALID_COMMUNITY_HAND; i++)
	{
		parameterOfRoyalFlush[1] = pikesPosition;

		if (checkRoyalFlush(newCommunityCards[i], pikesTypes, parameterOfRoyalFlush))
		{
			pikesPosition += 1;
		}
	}

	for (int i = 0; i < NUMBER_OF_VALID_PLAYER_HAND; i++)
	{
		parameterOfRoyalFlush[1] = pikesPosition;

		if (checkRoyalFlush(newHand[i], pikesTypes, parameterOfRoyalFlush))
		{
			pikesPosition += 1;
		}
	}
}

void RoyalFlush::getHeartsRoyalFlush(Card** newHand, Card** newCommunityCards)
{
	int heartsPosition = 0;
	int numberOfType = 0;

	parameterOfRoyalFlush[0] = numberOfType;

	for (int i = 0; i < NUMBER_OF_VALID_COMMUNITY_HAND; i++)
	{
		parameterOfRoyalFlush[1] = heartsPosition;

		if (checkRoyalFlush(newCommunityCards[i], heartsTypes, parameterOfRoyalFlush))
		{
			heartsPosition += 1;
		}
	}

	for (int i = 0; i < NUMBER_OF_VALID_PLAYER_HAND; i++)
	{
		parameterOfRoyalFlush[1] = heartsPosition;

		if (checkRoyalFlush(newHand[i], heartsTypes, parameterOfRoyalFlush))
		{
			heartsPosition += 1;
		}
	}
}

void RoyalFlush::getDiamondsRoyalFlush(Card** newHand, Card** newCommunityCards)
{
	int diamondsPosition = 0;
	int numberOfType = 1;

	parameterOfRoyalFlush[0] = numberOfType;

	for (int i = 0; i < NUMBER_OF_VALID_COMMUNITY_HAND; i++)
	{
		parameterOfRoyalFlush[1] = diamondsPosition;

		if (checkRoyalFlush(newCommunityCards[i], diamondsTypes, parameterOfRoyalFlush))
		{
			diamondsPosition += 1;
		}
	}

	for (int i = 0; i < NUMBER_OF_VALID_PLAYER_HAND; i++)
	{
		parameterOfRoyalFlush[1] = diamondsPosition;

		if (checkRoyalFlush(newHand[i], heartsTypes, parameterOfRoyalFlush))
		{
			diamondsPosition += 1;
		}
	}
}

bool RoyalFlush::checkRoyalFlush(Card* newCard, Card** newRoyalFlushVector, int* newParameters)
{
	bool isCorrectValue = newCard->getType() == ARRAY_OF_TYPES[newParameters[0]];

	for (int i = 0; i < NUMBER_OF_VALUES; i++)
	{
		bool isSameValue = newCard->getValue() == ROYAL_FLUSH_VALUES[i];

		if (isSameValue && isCorrectValue)
		{
			newRoyalFlushVector[newParameters[1]]->setValue(ROYAL_FLUSH_VALUES[i]);
			return true;
		}
	}

	return false;
}

bool RoyalFlush::checkRankingRoyalFlush(Card* newRoyalFlushValue)
{
	for (int i = 0; i < NUMBER_OF_VALUES; i++)
	{
		if (newRoyalFlushValue->getValue() == ROYAL_FLUSH_VALUES[i])
		{
			return true;
		}
	}

	return false;
}


