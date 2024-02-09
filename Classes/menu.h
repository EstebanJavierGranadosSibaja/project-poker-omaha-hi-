#pragma once
#include <SFML/Graphics.hpp>
#include"poker_table.h"
using namespace sf;

class Menu
{
private: 
	Texture background;
	
	int numPlayers;
	int blindPrice;


public: 

	void loadMenuWindow(); 
	void loadMenuImage(RenderWindow& window);
	





};
