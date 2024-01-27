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

// terminar el metodo principal de validadcion,
int RoyalFlush::getPlayerRanking(Card** newHand, Card** newCommunityCards)
{
	return 0;
}

void RoyalFlush::getClubsRoyalFlush(Card** newHand, Card** newCommunityCards)
{
	int clubsPosition = 0;
	int numberOfType = 2;

	for (int i = 0; i < NUMBER_OF_VALID_COMMUNITY_HAND; i++)
	{
		if (checkRoyalFlush(newCommunityCards[i], clubsPosition, numberOfType))
		{
			clubsPosition += 1;
			break;
		}
	}

	for (int i = 0; i < NUMBER_OF_VALID_PLAYER_HAND; i++)
	{
		if (checkRoyalFlush(newCommunityCards[i], clubsPosition, numberOfType))
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

	for (int i = 0; i < NUMBER_OF_VALID_COMMUNITY_HAND; i++)
	{
		if (checkRoyalFlush(newCommunityCards[i], pikesPosition, numberOfType))
		{
			pikesPosition += 1;
			break;
		}
	}

	for (int i = 0; i < NUMBER_OF_VALID_PLAYER_HAND; i++)
	{
		if (checkRoyalFlush(newCommunityCards[i], pikesPosition, numberOfType))
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

	for (int i = 0; i < NUMBER_OF_VALID_COMMUNITY_HAND; i++)
	{
		if (checkRoyalFlush(newCommunityCards[i], heartsPosition, numberOfType))
		{
			heartsPosition += 1;
			break;
		}
	}

	for (int i = 0; i < NUMBER_OF_VALID_PLAYER_HAND; i++)
	{
		if (checkRoyalFlush(newCommunityCards[i], heartsPosition, numberOfType))
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

	for (int i = 0; i < NUMBER_OF_VALID_COMMUNITY_HAND; i++)
	{
		if (checkRoyalFlush(newCommunityCards[i], diamondsPosition, numberOfType))
		{
			diamondsPosition += 1;
			break;
		}
	}

	for (int i = 0; i < NUMBER_OF_VALID_PLAYER_HAND; i++)
	{
		if (checkRoyalFlush(newCommunityCards[i], diamondsPosition, numberOfType))
		{
			diamondsPosition += 1;
			break;
		}
	}
}

// ver si se puede hacer con menos parametros
bool RoyalFlush::checkRoyalFlush(Card* newCard, int newPosition, int newNumberOfType)
{
	bool isPikes = newCard->getType() = ARRAY_OF_TYPES[newNumberOfType];

	for (int i = 0; i < NUMBER_OF_ROYAL_FLUSH_VALUES; i++)
	{
		bool isSameValue = newCard->getValue() == ROYAL_FLUSH_VALUES[i];

		if (isSameValue && isPikes)
		{
			//Buscar como refactorizar para que sea un metodo universal
			vectorRoyalFlush[newPosition] = ROYAL_FLUSH_VALUES[i];
			return true;
		}
	}

	return false;
}



