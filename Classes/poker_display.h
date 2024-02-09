#pragma once
#include"menu.h";
#include"poker_table.h"
const int maxOfUserCard = 4; 

class PokerDisplay
{
private:
	PokerTable* pokerTable;
	Menu* menu;
	Texture backGround;
	Sprite spriteBackGround;
	RectangleShape** spacesInUserCard; 

	int rows;
	int columns; 

	

public:

	PokerDisplay();
	void loadGameWindow();
	void loadGameImage();
	void drawRectangleShape(); 
};