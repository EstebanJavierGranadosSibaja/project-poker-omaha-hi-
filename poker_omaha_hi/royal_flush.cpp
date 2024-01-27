#include "royal_flush.h"

RoyalFlush::RoyalFlush()
{
	for (int i = 0; i < NUMBER_OF_ROYAL_FLUSH_VALUES; i++)
	{
		clubsRoyalFlush[i] = 'X';
		pikesRoyalFlush[i] = 'X';
		heartskRoyalFlush[i] = 'X';
		diamondsRoyalFlush[i] = 'X';
	}
}

int RoyalFlush::getPlayerRanking(Card** newHand, Card** newCommunityCards)
{
	int clubsCounter, pikesCounter, heartsCounter, diamondsCounter;
	bool isRoyalFLush = clubsCounter == 5 || pikesCounter == 5 || heartsCounter == 5 || diamondsCounter == 5;

	for (int i = 0; i < NUMBER_OF_ROYAL_FLUSH_VALUES; i++)
	{
		if (checkRankingRoyalFlush(clubsRoyalFlush[i]))
		{
			clubsCounter += 1;
		}
		if (checkRankingRoyalFlush(pikesRoyalFlush[i]))
		{
			pikesCounter += 1;
		}
		if (checkRankingRoyalFlush(heartskRoyalFlush[i]))
		{
			heartsCounter += 1;
		}
		if (checkRankingRoyalFlush(heartskRoyalFlush[i]))
		{
			diamondsCounter += 1;
		}
	}

	if (isRoyalFLush)
	{
		return 300;
	}

	return 0;
}

void RoyalFlush::getClubsRoyalFlush(Card** newHand, Card** newCommunityCards)
{
	int clubsPosition = 0;
	int numberOfType = 2;

	parameterOfRoyalFlush[0] = numberOfType;
	parameterOfRoyalFlush[1] = clubsPosition;

	for (int i = 0; i < NUMBER_OF_VALID_COMMUNITY_HAND; i++)
	{
		if (checkRoyalFlush(newCommunityCards[i], clubsRoyalFlush, parameterOfRoyalFlush))
		{
			clubsPosition += 1;
			break;
		}
	}

	for (int i = 0; i < NUMBER_OF_VALID_PLAYER_HAND; i++)
	{
		if (checkRoyalFlush(newCommunityCards[i], clubsRoyalFlush, parameterOfRoyalFlush))
		{
			clubsPosition += 1;
			break;
		}
	}
}

void RoyalFlush::getPikesRoyalFlush(Card** newHand, Card** newCommunityCards)
{
	int pikesPosition = 0;
	int numberOfType = 3;

	parameterOfRoyalFlush[0] = numberOfType;
	parameterOfRoyalFlush[1] = pikesPosition;

	for (int i = 0; i < NUMBER_OF_VALID_COMMUNITY_HAND; i++)
	{
		if (checkRoyalFlush(newCommunityCards[i], pikesRoyalFlush, parameterOfRoyalFlush))
		{
			pikesPosition += 1;
			break;
		}
	}

	for (int i = 0; i < NUMBER_OF_VALID_PLAYER_HAND; i++)
	{
		if (checkRoyalFlush(newCommunityCards[i], pikesRoyalFlush, parameterOfRoyalFlush))
		{
			pikesPosition += 1;
			break;
		}
	}
}

void RoyalFlush::getHeartsRoyalFlush(Card** newHand, Card** newCommunityCards)
{
	int heartsPosition = 0;
	int numberOfType = 0;

	parameterOfRoyalFlush[0] = numberOfType;
	parameterOfRoyalFlush[1] = heartsPosition;

	for (int i = 0; i < NUMBER_OF_VALID_COMMUNITY_HAND; i++)
	{
		if (checkRoyalFlush(newCommunityCards[i], heartskRoyalFlush, parameterOfRoyalFlush))
		{
			heartsPosition += 1;
			break;
		}
	}

	for (int i = 0; i < NUMBER_OF_VALID_PLAYER_HAND; i++)
	{
		if (checkRoyalFlush(newCommunityCards[i], heartskRoyalFlush, parameterOfRoyalFlush))
		{
			heartsPosition += 1;
			break;
		}
	}
}

void RoyalFlush::getDiamondsRoyalFlush(Card** newHand, Card** newCommunityCards)
{
	int diamondsPosition = 0;
	int numberOfType = 3;

	parameterOfRoyalFlush[0] = numberOfType;
	parameterOfRoyalFlush[1] = diamondsPosition;

	for (int i = 0; i < NUMBER_OF_VALID_COMMUNITY_HAND; i++)
	{
		if (checkRoyalFlush(newCommunityCards[i], diamondsRoyalFlush, parameterOfRoyalFlush))
		{
			diamondsPosition += 1;
			break;
		}
	}

	for (int i = 0; i < NUMBER_OF_VALID_PLAYER_HAND; i++)
	{
		if (checkRoyalFlush(newCommunityCards[i], heartskRoyalFlush, parameterOfRoyalFlush))
		{
			diamondsPosition += 1;
			break;
		}
	}
}

bool RoyalFlush::checkRoyalFlush(Card* newCard, char* newRoyalFlushVector, int* newParameters)
{
	bool isCorrectValue = newCard->getType() = ARRAY_OF_TYPES[newParameters[0];

	for (int i = 0; i < NUMBER_OF_ROYAL_FLUSH_VALUES; i++)
	{
		bool isSameValue = newCard->getValue() == ROYAL_FLUSH_VALUES[i];

		if (isSameValue && isCorrectValue)
		{
			newRoyalFlushVector[newParameters[1] = ROYAL_FLUSH_VALUES[i];
			return true;
		}
	}

	return false;
}

bool RoyalFlush::checkRankingRoyalFlush(char newRoyalFlushValue)
{
	for (int i = 0; i < NUMBER_OF_ROYAL_FLUSH_VALUES; i++)
	{
		if (newRoyalFlushValue == ROYAL_FLUSH_VALUES[i])
		{
			return true;
		}
	}

	return false;
}



