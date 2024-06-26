#include"straight.h"

int Straight::getPlayerHandRankin(Card** newHand, Card** newCommunityCards)
{
	int firstCardUser = 0;
	int secondCardUser = 1;

	Card** combinationOfCards = new Card * [SIZE_OF_COMMUNITY_CARDS];

	while (firstCardUser != NUMBER_OF_VALID_COMMUNITY_HAND)
	{

		combinationOfCards[0] = newHand[firstCardUser];
		combinationOfCards[1] = newHand[secondCardUser];

		if (communityCardCombinations(combinationOfCards, newCommunityCards)) {
			return STRAIGHT_VALUE;
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

bool Straight::communityCardCombinations(Card** combinationOfCards, Card** newCommunityCards)
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

			if (isAStraigt(combinationOfCards))
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

void Straight::sortTheCards(Card**& vectorOfCombinations)
{
}

bool Straight::isAStraigt(Card** vectorOfCombinations)
{
	int index = 0;

	sortTheCards(vectorOfCombinations); 

	while (vectorOfCombinations[0]->getValue() != ARRAY_OF_VALUES[index])
	{
		index++;
	}
//NOTE: return  (isACheckStraight(vectorOfCombinations, index));
	if (isACheckStraight(vectorOfCombinations, index))
	{
		return true;
	}


	return false;
}

bool Straight::isACheckStraight(Card** vectorOfCombinations, int startOfTheStaircase)
{
	int straightCounter = 0; 
	for (int i = 0; i < COMMUNITY_CARD_SIZE; i++)
	{
		if (vectorOfCombinations[i]->getValue() == ARRAY_OF_VALUES[startOfTheStaircase])
		{
			straightCounter++; 
		}
		startOfTheStaircase++; 
	}
//NOTE: return (straightCounter == COMMUNITY_CARD_SIZE ||
	//	(straightCounter == COMMUNITY_CARD_SIZE - 1 && ARRAY_OF_VALUES[0] == 'A'))
	if (straightCounter == COMMUNITY_CARD_SIZE ||
		(straightCounter == COMMUNITY_CARD_SIZE - 1 && ARRAY_OF_VALUES[0] == 'A'))
	{
		return true;
	}  
	

	return false; 
}

