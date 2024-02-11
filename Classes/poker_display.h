#pragma once
#include"button.h"
#include"poker_table.h"

const int MAX_OF_USER_CARD = 4; 
const int SIZE_PREFLOP_BUTTON = 6; 

class PokerDisplay
{
private:
	Text numberOfPlayer;
	Font arial;
	PokerTable* pokerTable;
	Menu* menu;
	Button* preFlopButton;

	Texture backGround;
	Sprite spriteBackGround;
	RectangleShape** spacesInUserCard;
	RectangleShape* spacesForDealerCard;

	int rows;
	int columns;



public:

	PokerDisplay();
	void loadGameWindow();
	void loadGameImage();
	void checkThePlayersBoxes(RenderWindow& gameWindow);
	void checkTheDealerBoxes(RenderWindow& gameWindow);
	void definePreflopButtons();
	void drawPreFlopButtons(RenderWindow& gameWindow);
};