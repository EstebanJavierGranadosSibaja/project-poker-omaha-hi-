#include"button.h"

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

void Button::shapeButton(float xPosition, float yPosition, string& text)
{




	FloatRect textBounds = buttonText.getLocalBounds();
	buttonText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);

}

void Button::button3BB()
{
	string text = "3BB";
	float xPosition = 200.f;
	float yPosition = 200.f;

	shapeButton(xPosition, yPosition, text);
}

void Button::drawButton(RenderWindow& window)
{
	window.draw(buttonShape);
	window.draw(buttonText);
}
