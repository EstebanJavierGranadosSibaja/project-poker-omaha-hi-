#include "winning_play.h"

void WinningPlay::sortTheCards(Card** vectorOfCombinations)
{
	for (int i = 0; i < SIZE_OF_PLAYER_DECK; i++)
	{
		for (int j = 0; j < SIZE_OF_PLAYER_DECK - i - 1; j++)
		{//NOTE: return
			if (vectorOfCombinations[j]->getNumber() > vectorOfCombinations[j + 1]->getNumber())
			{
				Card* temp = vectorOfCombinations[j];
				vectorOfCombinations[j] = vectorOfCombinations[j + 1];
				vectorOfCombinations[j + 1] = temp;
			}
		}
	}
}
