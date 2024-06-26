#include"full_house.h"

int FullHouse::getPlayerHandRankin(Card** newHand, Card** newCommunityCards)
{
	int firstCardUser = 0;
	int secondCardUser = 1;

	Card** combinationOfCards = new Card * [SIZE_OF_COMMUNITY_CARDS];

	while (firstCardUser != NUMBER_OF_VALID_COMMUNITY_HAND)
	{

		combinationOfCards[0] = newHand[firstCardUser];
		combinationOfCards[1] = newHand[secondCardUser];

		if (communityCardCombinations(combinationOfCards, newCommunityCards)) {
			return FULL_HOUSE_VALUE;
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

bool FullHouse::communityCardCombinations(Card** combinationOfCards, Card** newCommunityCards)
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

			if (isAFullHouse(combinationOfCards)) {
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

void FullHouse::sortTheCards(Card**& vectorOfCombinations)
{
}

//void FullHouse::sortTheCards(Card**& vectorOfCombinations)
//{
//	for (int i = 0; i < SIZE_OF_PLAYER_DECK; i++)
//	{
//		for (int j = 0; j < SIZE_OF_PLAYER_DECK - i - 1; j++)
//		{
//			if (vectorOfCombinations[j]->getValue() > vectorOfCombinations[j + 1]->getValue())
//			{
//				Card* temp = vectorOfCombinations[j];
//				vectorOfCombinations[j] = vectorOfCombinations[j + 1];
//				vectorOfCombinations[j + 1] = temp;
//			}
//		}
//	}
//}

bool FullHouse::isAFullHouse(Card** vectorOfCombinations)
{
	sortTheCards(vectorOfCombinations);

	bool isThreeAndTwo = (vectorOfCombinations[0] == vectorOfCombinations[1]  && vectorOfCombinations[1] == vectorOfCombinations[2])
		&& vectorOfCombinations[3] == vectorOfCombinations[4];
	bool isTwoAndThree = vectorOfCombinations[0] == vectorOfCombinations[1] &&
		(vectorOfCombinations[2] == vectorOfCombinations[3] && vectorOfCombinations[3] == vectorOfCombinations[4]);

	if (isThreeAndTwo || isTwoAndThree) {
		return true;
	}

	return false;
}




