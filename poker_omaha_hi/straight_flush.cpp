#include "straight_flush.h"

int StraightFlush::getPlayerRanking(Card** newHand, Card** newCommunityCards)
{
	int firstCardUser = 0;
	int secondCardUser = 1;

	Card** combinationOfCards = new Card * [SIZE_OF_COMMUNITY_CARDS];

	while (firstCardUser != NUMBER_OF_VALID_COMMUNITY_HAND)
	{
		combinationOfCards[0] = newHand[firstCardUser];
		combinationOfCards[1] = newHand[secondCardUser];

		if (communityCardCombinations(combinationOfCards, newCommunityCards))
		{
			return STRIGHT_FLUSH_VALUE;
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

bool StraightFlush::communityCardCombinations(Card** combinationOfCards, Card** newCommunityCards)
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

			if (isSameColor(combinationOfCards) && isConsecutiveNumber(combinationOfCards))
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

bool StraightFlush::isSameColor(Card** vectorOfCombinations)
{
	sortTheCards(vectorOfCombinations);

	bool isColor = (vectorOfCombinations[0]->getType() == vectorOfCombinations[1]->getType()) &&
		(vectorOfCombinations[1]->getType() == vectorOfCombinations[2]->getType()) &&
		(vectorOfCombinations[2]->getType() == vectorOfCombinations[3]->getType()) &&
		(vectorOfCombinations[3]->getType() == vectorOfCombinations[4]->getType());
//NOTE: return  (isColor);
	if (isColor)
	{
		return true;
	}

	return false;
}

bool StraightFlush::isConsecutiveNumber(Card** vectorOfCombinations)
{
	bool isConsecutiveNumber = (vectorOfCombinations[1]->getNumber() == vectorOfCombinations[0]->getNumber() + 1) &&
		(vectorOfCombinations[2]->getNumber() == vectorOfCombinations[1]->getNumber() + 1) &&
		(vectorOfCombinations[3]->getNumber() == vectorOfCombinations[2]->getNumber() + 1) &&
		(vectorOfCombinations[4]->getNumber() == vectorOfCombinations[3]->getNumber() + 1);
//NOTE: return  (isConsecutiveNumber);
	if (isConsecutiveNumber)
	{
		return true;
	}

	return false;
}


void StraightFlush::sortTheCards(Card**& vectorOfCombinations)
{
}
