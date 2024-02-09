#pragma once
#include"menu.h";

class PokerDisplay
{
private:
	Texture backGround;
	Texture cardImage;

public:
	PokerDisplay() {}

	void loadGameWindow();
	void loadGameImage(RenderWindow& newWindow);
};