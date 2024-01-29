#include "color.h"

Color::Color()
{
	cardType = "";
}

int Color::getPlayerRanking(Card** newHand, Card** newCommunityCards)
{
	int heartsTypesPosition = 0, diamondsTypePosition = 1, clubsTypePosition = 2, pikesTypePosition = 3;
	int clubsCounter = 0, pikesCounter = 0, heartsCounter = 0, diamondsCounter = 0;

	bool isColor = clubsCounter == 5 || pikesCounter == 5 || heartsCounter == 5 || diamondsCounter == 5;

	cardParameters[0] = heartsTypesPosition;
	getTypesColor(heartsTypes, newHand, newCommunityCards);

	cardParameters[0] = diamondsTypePosition;
	getTypesColor(diamondsTypes, newHand, newCommunityCards);

	cardParameters[0] = clubsTypePosition;
	getTypesColor(clubsTypes, newHand, newCommunityCards);

	cardParameters[0] = pikesTypePosition;
	getTypesColor(pikesTypes, newHand, newCommunityCards);

	for (int i = 0; i < NUMBER_OF_VALUES; i++)
	{
		if (isColorHand(clubsTypes[i], "Clubs"))
		{
			clubsCounter += 1;
		}
		if (isColorHand(pikesTypes[i], "Pikes"))
		{
			pikesCounter += 1;
		}
		if (isColorHand(heartsTypes[i], "Hearts"))
		{
			heartsCounter += 1;
		}
		if (isColorHand(heartsTypes[i], "Diamonds"))
		{
			diamondsCounter += 1;
		}
	}
	if (isColor)
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
			newVectorType[actualPosition]->setType(actualType);
			actualPosition += 1;
		}
	}

	for (int i = 0; i < NUMBER_OF_VALID_PLAYER_HAND; i++)
	{
		actualType = newHand[i]->getType();
		cardParameters[1] = actualPosition;

		if (checkColor(actualType, cardParameters))
		{
			newVectorType[actualPosition]->setType(actualType);
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

bool Color::isColorHand(Card* newCardColor, string newActualColor)
{

	if (newCardColor->getType() == newActualColor)
	{
		return true;
	}

	return false;
}
