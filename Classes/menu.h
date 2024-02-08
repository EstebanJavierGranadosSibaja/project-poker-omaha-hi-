#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Menu
{
private: 
	Texture texture; 
	Sprite sprite; 
	int numPlayers;
	int blindPrice;


public: 

	void loadMenuWindow(); 
	void loadMenuImage(RenderWindow& window);





};
