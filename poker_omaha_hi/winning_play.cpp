#include "winning_play.h"

void WinningPlay::sortTheCards(Card** vectorOfCombinations)
{
	for (int i = 0; i < SIZE_OF_PLAYER_DECK; i++)
	{
		for (int j = 0; j < SIZE_OF_PLAYER_DECK - i - 1; j++)
		{
			if (vectorOfCombinations[j]->getValue() > vectorOfCombinations[j + 1]->getValue())
			{
				Card* temp = vectorOfCombinations[j];
				vectorOfCombinations[j] = vectorOfCombinations[j + 1];
				vectorOfCombinations[j + 1] = temp;
			}
		}
	}
}
