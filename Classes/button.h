#pragma once
#include"menu.h";

class Button
{
private: 
	Font buttonFont;
	RectangleShape buttonShape;
	Text buttonText;


public: 
	Button();
	Button(float newXPosition, float newYposition, string text);
	RectangleShape getButtonShape(); 
	Text getButtonText(); 
	void button3BB();
	void drawButton(RenderWindow& window); 














};
