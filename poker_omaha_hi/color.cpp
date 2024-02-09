#include "color.h"

int Color::getPlayerRanking(Card** newHand, Card** newCommunityCards)
{
	int heartsTypesPosition = 0, diamondsTypePosition = 1, clubsTypePosition = 2, pikesTypePosition = 3;

	cardParameters[0] = heartsTypesPosition;
	getTypesColor(heartsTypes, newHand, newCommunityCards);

	cardParameters[0] = diamondsTypePosition;
	getTypesColor(diamondsTypes, newHand, newCommunityCards);

	cardParameters[0] = clubsTypePosition;
	getTypesColor(clubsTypes, newHand, newCommunityCards);

	cardParameters[0] = pikesTypePosition;
	getTypesColor(pikesTypes, newHand, newCommunityCards);

	if (isColorHand(clubsTypes, "Clubs"))
	{
		return 50;
	}
	if (isColorHand(pikesTypes, "Pikes"))
	{
		return 50;
	}
	if (isColorHand(heartsTypes, "Hearts"))
	{
		return 50;
	}
	if (isColorHand(diamondsTypes, "Diamonds"))
	{
		return 50;
	}

	return -1;
}

void Color::getTypesColor(Card** newVectorType, Card** newHand, Card** newCommunityCards)
{
	int actualPosition = 0;
	string actualType;

	cardType = ARRAY_OF_TYPES[cardParameters[0]];

	for (int i = 0; i < NUMBER_OF_VALID_COMMUNITY_HAND; i++)
	{
		actualType = newCommunityCards[i]->getType();
		cardParameters[1] = actualPosition;

		if (checkColor(actualType, cardParameters))
		{
			newVectorType[actualPosition] = newCommunityCards[i];
			actualPosition += 1;
		}
	}

	for (int i = 0; i < NUMBER_OF_VALID_PLAYER_HAND; i++)
	{
		actualType = newHand[i]->getType();
		cardParameters[1] = actualPosition;

		if (checkColor(actualType, cardParameters))
		{
			newVectorType[actualPosition] = newCommunityCards[i];
			actualPosition += 1;
		}
	}
}



bool Color::checkColor(string newActualType, int* newCardParameters)
{
	if (newActualType == cardType)
	{
		return true;
	}

	return false;
}

bool Color::isColorHand(Card** newCardColor, string newActualColor)
{
	string cardColorType;

	for (int i = 0; i < NUMBER_OF_VECTORS; i++)
	{
		cardColorType = newCardColor[i]->getType();

		if (cardColorType != newActualColor)
		{
			return false;
		}
	}

	return true;
}
