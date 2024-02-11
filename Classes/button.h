#pragma once
#include"menu.h";

class Button
{
private: 
	Font buttonFont;
	RectangleShape buttonShape;
	Text buttonText;

	bool isAClick; 


public: 
	Button();
	Button(float newXPosition, float newYposition, string text);
	RectangleShape getButtonShape(); 
	Text getButtonText(); 
	void button3BB();
	void buttonHalfPot();
	void buttonOnePot(); 
	void buttonThreeQuartersOfPot();
	void buttonAllIn();
	void buttonGoOut();
	void buttonShowCards();
	void drawButton(RenderWindow& window); 
	void setButtonColor(Color color);
	bool theButtonWasClicked(Vector2f clickPosition); 
	














};
