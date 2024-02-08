#pragma once
#include <SFML/Graphics.hpp>
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
