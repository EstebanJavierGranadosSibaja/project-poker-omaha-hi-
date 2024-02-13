#include"poker.h"

int Poker::getPlayerHandRankin(Card** newHand, Card** newCommunityCards)
{
	int firstCardUser = 0;
	int secondCardUser = 1;



	Card** combinationOfCards = new Card * [SIZE_OF_COMMUNITY_CARDS];


	while (firstCardUser != NUMBER_OF_VALID_COMMUNITY_HAND)
	{

		combinationOfCards[0] = newHand[firstCardUser];
		combinationOfCards[1] = newHand[secondCardUser];

		if (communityCardCombinations(combinationOfCards,newCommunityCards)) {
			return POKER_VALUE;
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

bool Poker::communityCardCombinations(Card** combinationOfCards, Card** newCommunityCards)
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

			if (isAPoker(combinationOfCards)) {
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

bool Poker::isAPoker(Card** vectorOfCombinations)
{
	int count = 0; 
	int threeCombinations = 3; 
	for (int i = 0; i < 2; i++)
	{
		for (int j = i + 1; j < SIZE_OF_COMMUNITY_CARDS; i++)
		{

			if (vectorOfCombinations[i] == vectorOfCombinations[j])
			{
				count++; 
			}
		}
	}
//NOTE: return  (count == threeCombinations);
	if (count == threeCombinations)
	{

		return true; 
	}

	return false; 
}

void Poker::sortTheCards(Card**& vectorOfCombinations)
{
}
