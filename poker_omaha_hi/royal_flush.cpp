#include "royal_flush.h"

int RoyalFlush::getPlayerRanking(Card** newHand, Card** newCommunityCards)
{
	int firstCardUser = 0;
	int secondCardUser = 1;

	Card** combinationOfCards = new Card * [SIZE_OF_COMMUNITY_CARDS];

	while (firstCardUser != NUMBER_OF_VALID_COMMUNITY_HAND)
	{

		combinationOfCards[0] = newHand[firstCardUser];
		combinationOfCards[1] = newHand[secondCardUser];

		if (communityCardCombinations(combinationOfCards, newCommunityCards)) {
			return ROYAL_FLUSH_VALUE;
		}

		secondCardUser++;
		if (secondCardUser == SIZE_OF_PLAYER_DECK)
		{
			firstCardUser++;
			secondCardUser = firstCardUser + 1;
		}
	}
	return -1;
}

bool RoyalFlush::communityCardCombinations(Card** combinationOfCards, Card** newCommunityCards)
{
	int firstCardCommunity = 0;
	int secondCardCommunity = 1;
	int thirdCardCommunity = secondCardCommunity + 1;

	for (firstCardCommunity = 0; firstCardCommunity < NUMBER_OF_VALID_COMMUNITY_HAND; firstCardCommunity++)
	{
		secondCardCommunity = firstCardCommunity + 1;

		while (secondCardCommunity != SIZE_OF_PLAYER_DECK)
		{
			combinationOfCards[2] = newCommunityCards[firstCardCommunity];
			combinationOfCards[3] = newCommunityCards[secondCardCommunity];
			combinationOfCards[4] = newCommunityCards[thirdCardCommunity];

			if (isSameColor(combinationOfCards) && isRoyalFlush(combinationOfCards))
			{
				return true;
			}

			thirdCardCommunity++;
			if (thirdCardCommunity == SIZE_OF_COMMUNITY_CARDS)
			{
				secondCardCommunity++;
				thirdCardCommunity = secondCardCommunity + 1;
			}
		}
	}
	return false;
}

bool RoyalFlush::isSameColor(Card** vectorOfCombinations)
{
	sortTheCards(vectorOfCombinations);

	bool isColor = (vectorOfCombinations[0]->getType() == vectorOfCombinations[1]->getType()) &&
		(vectorOfCombinations[1]->getType() == vectorOfCombinations[2]->getType()) &&
		(vectorOfCombinations[2]->getType() == vectorOfCombinations[3]->getType()) &&
		(vectorOfCombinations[3]->getType() == vectorOfCombinations[4]->getType());

	if (isColor)
	{
		return true;
	}

	return false;
}

bool RoyalFlush::isRoyalFlush(Card** vectorOfCombinations)
{
	sortTheCards(vectorOfCombinations);

	bool isRoyalFlush = (vectorOfCombinations[0]->getValue() == ROYAL_FLUSH_VALUES[0]) && (vectorOfCombinations[1]->getValue() == ROYAL_FLUSH_VALUES[1]) &&
		(vectorOfCombinations[2]->getValue() == ROYAL_FLUSH_VALUES[2]) && (vectorOfCombinations[3]->getValue() == ROYAL_FLUSH_VALUES[3]) &&
		(vectorOfCombinations[4]->getValue() == ROYAL_FLUSH_VALUES[4]);

	if (isRoyalFlush)
	{
		return true;
	}

	return false;
}

void RoyalFlush::sortTheCards(Card**& vectorOfCombinations)
{
}


