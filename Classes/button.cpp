#include"button.h"

Button::Button()
{

	buttonFont = Font();
	buttonFont.loadFromFile("ARIAL.ttf");

	buttonShape = RectangleShape(Vector2f(100, 50));
	buttonShape.setFillColor(Color::White);
	buttonShape.setPosition(Vector2f(0, 0)); //

	buttonText = Text("", buttonFont, 20);
	buttonText.setFillColor(Color::Black);
	buttonText.setPosition(0, 0);
}

Button::Button(float newXPosition, float newYposition, string text)
{
	buttonFont = Font();
	buttonFont.loadFromFile("ARIAL.ttf");

	buttonShape = RectangleShape(Vector2f(100, 50));
	buttonShape.setFillColor(Color::White);
	buttonShape.setPosition(Vector2f(newXPosition, newYposition)); //

	buttonText = Text(text, buttonFont, 20);
	buttonText.setFillColor(Color::Black);
	buttonText.setPosition(newXPosition, newYposition);
}

RectangleShape Button::getButtonShape()
{
	return buttonShape;
}

Text Button::getButtonText()
{
	return buttonText;
}


void Button::button3BB()
{
	string text = "3BB";
	float xPosition = 200.f;
	float yPosition = 200.f;

	buttonShape.setPosition(Vector2f(xPosition, yPosition));
	buttonText.setPosition(xPosition, yPosition);
	buttonText.setString(text); 
}

void Button::drawButton(RenderWindow& window)
{
	window.draw(buttonShape);
	window.draw(buttonText);
}
