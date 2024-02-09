#include "straight_flush.h"

int StraightFlush::getPlayerRanking(Card** newHand, Card** newCommunityCards)
{
	int heartsTypesPosition = 0, diamondsTypePosition = 1, clubsTypePosition = 2, pikesTypePosition = 3;

	cardParameters[0] = heartsTypesPosition;
	cardColor->getTypesColor(heartsTypes, newHand, newCommunityCards);

	cardParameters[0] = diamondsTypePosition;
	cardColor->getTypesColor(diamondsTypes, newHand, newCommunityCards);

	cardParameters[0] = clubsTypePosition;
	cardColor->getTypesColor(clubsTypes, newHand, newCommunityCards);

	cardParameters[0] = pikesTypePosition;
	cardColor->getTypesColor(pikesTypes, newHand, newCommunityCards);


	if ((cardColor->isColorHand(clubsTypes, "Clubs")) && (isConsecutiveNumber(clubsTypes)))
	{
		return 200 + getMosthigherNumber(clubsTypes);
	}
	if ((cardColor->isColorHand(pikesTypes, "Pikes")) && (isConsecutiveNumber(pikesTypes)))
	{
		return 200 + getMosthigherNumber(pikesTypes);
	}
	if ((cardColor->isColorHand(heartsTypes, "Hearts")) && (isConsecutiveNumber(heartsTypes)))
	{
		return 200 + getMosthigherNumber(heartsTypes);
	}
	if ((cardColor->isColorHand(diamondsTypes, "Diamonds")) && (isConsecutiveNumber(heartsTypes)))
	{
		return 200 + getMosthigherNumber(diamondsTypes);
	}

	return -1;
}

int StraightFlush::getMostMinorNumber(Card** newCardColor)
{
	int minorNumber = INT_MAX;
	int compareNumber;

	for (int i = 0; i < NUMBER_OF_VECTORS; i++)
	{
		compareNumber = newCardColor[i]->getNumber();

		if (compareNumber < minorNumber)
		{
			minorNumber = compareNumber;
		}
	}

	return minorNumber;
}

int StraightFlush::getMosthigherNumber(Card** newCardColor)
{
	int higherNumber = 0;
	int compareNumber;

	for (int i = 0; i < NUMBER_OF_VECTORS; i++)
	{
		compareNumber = newCardColor[i]->getNumber();

		if (compareNumber > higherNumber)
		{
			higherNumber = compareNumber;
		}
	}

	return higherNumber;
}

bool StraightFlush::isConsecutiveNumber(Card** newCardColor)
{
	int compareNumber = getMostMinorNumber(newCardColor);
	int consecutiveCounter = 0;

	for (int i = 0; i < NUMBER_OF_VECTORS - 1; i++)
	{
		if (checkConsecutiveNumber(newCardColor, compareNumber))
		{
			consecutiveCounter += 1;
		}
	}

	if (consecutiveCounter == 4)
	{
		return true;
	}

	return false;
}

bool StraightFlush::checkConsecutiveNumber(Card** newCardColor, int& newCompareNumber)
{
	int actualNumber;

	for (int i = 0; i < NUMBER_OF_VECTORS; i++)
	{
		actualNumber = newCardColor[i]->getNumber();

		if (actualNumber == newCompareNumber + 1)
		{
			newCompareNumber = actualNumber;
			return true;
		}
	}

	return false;
}
