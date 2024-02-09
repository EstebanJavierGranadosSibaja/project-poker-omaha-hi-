#pragma once
#include <SFML/Graphics.hpp>
#include"poker_table.h"
using namespace sf;

class Menu
{
private: 
	Font font;
	Event userEvent;
	RectangleShape textBox;
	Texture background;
	Text text;
	Text userText;
	int numPlayers;
	int blindPrice;


public: 

	void loadMenuWindow(); 
	void loadMenuImage(RenderWindow& window);
	void drawRectangle(RenderWindow& window);
	void addText(RenderWindow& window);
	





};
