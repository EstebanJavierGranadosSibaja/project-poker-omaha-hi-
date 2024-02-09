#include "high_card.h"

int HighCard::getPlayerRanking(Card** newHand, Card** newCommunityCards)
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
			return highNumber;
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

bool HighCard::communityCardCombinations(Card** combinationOfCards, Card** newCommunityCards)
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

			if (getTheMostHigherCard(combinationOfCards) <= highNumber)
			{
				return true;
			}

			highNumber = getTheMostHigherCard(combinationOfCards);

			thirdCardCommunity++;
			if (thirdCardCommunity == SIZE_OF_COMMUNITY_CARDS)
			{
				secondCardCommunity++;
				thirdCardCommunity = secondCardCommunity + 1;
			}
		}
	}
}

int HighCard::getTheMostHigherCard(Card** vectorOfCombinations)
{
	sortTheCards(vectorOfCombinations);

	bool isAHigherCard = vectorOfCombinations[4]->getNumber() > highNumber;
	bool isAOneAS = vectorOfCombinations[0]->getNumber() == 1;
	int valueOfAsCard = 14;

	if (isAHigherCard && !isAOneAS)
	{
		return vectorOfCombinations[4]->getNumber();
	}
	if (isAOneAS)
	{
		return 14;
	}
	return 0;
}

void HighCard::sortTheCards(Card**& vectorOfCombinations)
{
}
