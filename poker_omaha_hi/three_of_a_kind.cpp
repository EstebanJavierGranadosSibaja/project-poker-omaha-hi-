#include"three_of_a_kind.h"

int ThreeOfAkind::getPlayerHandRankin(Card** newHand, Card** newCommunityCards)
{
	int firstCardUser = 0;
	int secondCardUser = 1;

	Card** combinationOfCards = new Card * [SIZE_OF_COMMUNITY_CARDS];

	while (firstCardUser != NUMBER_OF_VALID_COMMUNITY_HAND)
	{

		combinationOfCards[0] = newHand[firstCardUser];
		combinationOfCards[1] = newHand[secondCardUser];

		if (communityCardCombinations(combinationOfCards, newCommunityCards)) {
			return THREE_OF_A_KIND_VALUE;
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

bool ThreeOfAkind::communityCardCombinations(Card** combinationOfCards, Card** newCommunityCards)
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
//NOTE:Código anidado, muy anidado, función candidato a refactorizar
			if (isAThreeOfAkind(combinationOfCards)) {
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

void ThreeOfAkind::sortTheCards(Card**& vectorOfCombinations)
{
}

bool ThreeOfAkind::isAThreeOfAkind(Card** vectorOfCombinations)
{
	sortTheCards(vectorOfCombinations);

	bool threeCardsToTheLeft = vectorOfCombinations[0] == vectorOfCombinations[1] && vectorOfCombinations[1] == vectorOfCombinations[2]; 
	bool threeCardsToTheRight = vectorOfCombinations[2] == vectorOfCombinations[3] && vectorOfCombinations[3] == vectorOfCombinations[4];
//NOTE: return (threeCardsToTheLeft || threeCardsToTheRight) ;
	if (threeCardsToTheLeft || threeCardsToTheRight) 
	{
		return true; 
	}

	return false;
}
