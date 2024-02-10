#pragma once
#include"button.h"
#include"poker_table.h"
const int maxOfUserCard = 4; 

class PokerDisplay
{
private:
	Text numberOfPlayer; 
	PokerTable* pokerTable;
	Menu* menu;
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
};