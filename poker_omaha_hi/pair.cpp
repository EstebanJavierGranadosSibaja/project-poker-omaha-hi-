#include"pair.h"

int Pair::getPlayerHandRankin(Card** newHand, Card** newCommunityCards)
{
	int firstCardUser = 0;
	int secondCardUser = 1;

	Card** combinationOfCards = new Card * [SIZE_OF_COMMUNITY_CARDS];

	while (firstCardUser != NUMBER_OF_VALID_COMMUNITY_HAND)
	{
		combinationOfCards[0] = newHand[firstCardUser];
		combinationOfCards[1] = newHand[secondCardUser];

		if (communityCardCombinations(combinationOfCards, newCommunityCards)) {
			return PAIR_VALUE;
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

bool Pair::communityCardCombinations(Card** combinationOfCards, Card** newCommunityCards)
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

			if (isAPair(combinationOfCards)) {
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

void Pair::sortTheCards(Card**& vectorOfCombinations)
{
}

bool Pair::isAPair(Card** vectorOfCombinations)
{
	sortTheCards(vectorOfCombinations);
	bool firstPair = vectorOfCombinations[0] == vectorOfCombinations[1];
	bool secondPair = vectorOfCombinations[1] == vectorOfCombinations[2];
	bool thirdPair = vectorOfCombinations[2] == vectorOfCombinations[3];
	bool fourthPair = vectorOfCombinations[3] == vectorOfCombinations[4];
//NOTE: return   (firstPair || secondPair || thirdPair || fourthPair);
	if (firstPair || secondPair || thirdPair || fourthPair)
	{
		return true; 
	}
	return false;
}
