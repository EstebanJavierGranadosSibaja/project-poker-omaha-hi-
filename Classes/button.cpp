#include"button.h"

Button::Button()
{
	buttonFont = Font();
	buttonFont.loadFromFile("ARIAL.ttf");

	buttonShape = RectangleShape(Vector2f(190, 100));
	buttonShape.setFillColor(Color(135, 206, 250, 255));
	buttonShape.setPosition(Vector2f(0, 0)); 

	buttonText = Text("", buttonFont, 35);
	buttonText.setOutlineThickness(2.f);
	buttonText.setFillColor(Color::Black);
	buttonText.setPosition(0, 0);
	
}

Button::Button(float newXPosition, float newYposition, string text)
{
	buttonFont = Font();
	buttonFont.loadFromFile("ARIAL.ttf");

	buttonShape.setFillColor(Color::White);
	buttonShape.setPosition(Vector2f(newXPosition, newYposition)); 

	buttonText = Text(text, buttonFont, 40);
	buttonText.setFillColor(Color::Black);
	buttonText.setPosition(newXPosition +50, newYposition+25);
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
	float xPosition = 100.f;
	float yPosition = 875.f;

	buttonShape.setPosition(Vector2f(xPosition, yPosition));
	buttonText.setPosition(xPosition+50, yPosition+25);
	buttonText.setString(text); 
}

void Button::buttonHalfPot()
{
	string text = "1/2 POT";
	float xPosition = 400.f;
	float yPosition = 875.f;

	buttonShape.setPosition(Vector2f(xPosition, yPosition));
	buttonText.setPosition(xPosition + 90, yPosition +50);
	buttonText.setString(text);
}

void Button::buttonOnePot()
{
	string text = "1 POT";
	float xPosition = 700.f;
	float yPosition = 875.f;

	buttonShape.setPosition(Vector2f(xPosition, yPosition));
	buttonText.setPosition(xPosition + 90, yPosition + 50);
	buttonText.setString(text);
}

void Button::threeQuartersOfPot()
{
	string text = "3/4 POT";
	float xPosition = 700.f;
	float yPosition = 875.f;

	buttonShape.setPosition(Vector2f(xPosition, yPosition));
	buttonText.setPosition(xPosition + 90, yPosition + 50);
	buttonText.setString(text);
}

void Button::buttonAllIn()
{
	string text = "ALL IN";
	float xPosition = 1000.f;
	float yPosition = 875.f;

	buttonShape.setPosition(Vector2f(xPosition, yPosition));
	buttonText.setPosition(xPosition + 90, yPosition + 50);
	buttonText.setString(text);
}

void Button::buttonGoOut()
{
	string text = "GO OUT";
	float xPosition = 1300.f;
	float yPosition = 875.f;

	buttonShape.setPosition(Vector2f(xPosition, yPosition));
	buttonText.setPosition(xPosition + 90, yPosition + 50);
	buttonText.setString(text);

}

void Button::buttonShowCards()
{
	string text = "SHOW";
	float xPosition = 1600.f;
	float yPosition = 875.f;

	buttonShape.setPosition(Vector2f(xPosition, yPosition));
	buttonText.setPosition(xPosition + 90, yPosition + 50);
	buttonText.setString(text);
}

void Button::drawButton(RenderWindow& window)
{
	window.draw(buttonShape);
	window.draw(buttonText);
}
