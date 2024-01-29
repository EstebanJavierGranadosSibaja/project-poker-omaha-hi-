#include "winning_play.h"

WinningPlay::WinningPlay()
{
	for (int i = 0; i < NUMBER_OF_VALUES; i++)
	{
		clubsTypes[i] = new Card(' ', "ANYONE", -1, " ");
		pikesTypes[i] = new Card(' ', "ANYONE", -1, " ");
		heartsTypes[i] = new Card(' ', "ANYONE", -1, " ");
		diamondsTypes[i] = new Card(' ', "ANYONE", -1, " ");
	}

	for (int i = 0; i < NUMBER_OF_CARD_PARAMETERS; i++)
	{
		cardParameters[i] = -1;
	}
}

