#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include<string>
using namespace sf;
using namespace std;


class Menu
{
private:
	Font font;
	Event userEvent;
	RectangleShape textBox;
	Texture background;
	Sprite spriteBackground;
	Text text;
	Text userText;
	Vector2i rangeOfTheUserInput;

	bool isEnteringText;
	bool isBlindBeingEntered;

	int numPlayers;
	int blindPrice;
	int amountOfNumbersThatUserCanPress;

public:
	Menu();
	Font getFont();
	int getNumPlayer(); 
	int getBlindPrice(); 
	void loadMenuWindow();
	void loadMenuImage(RenderWindow& window);
	void tryAndCatchOfTheLoadMenu(RenderWindow& window);
	void drawRectangle();
	void addText();
	void blindInput(RenderWindow& window);

	void inputText(bool isEnteringText);
	void checkWhenUserPressEnter(RenderWindow& window);
	void nextUserRequest();
	bool isLenghtOfUserTextCorrect();




};