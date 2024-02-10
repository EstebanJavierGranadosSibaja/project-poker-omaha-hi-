#pragma once
#include"menu.h";

class Button
{
private: 
	Font buttonFont;
	RectangleShape buttonShape;
	Text buttonText;


public: 
	Button(float newXPosition, float newYposition, string text);
	RectangleShape getButtonShape(); 
	Text getButtonText(); 
	void shapeButton(float xPosition, float yPosition, string& text);
	void button3BB();
	void drawButton(RenderWindow& window); 














};
