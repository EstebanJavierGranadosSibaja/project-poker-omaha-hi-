#include"button.h"

Button::Button()
{
	isAClick = false;

	buttonFont = Font();
	buttonFont.loadFromFile("ARIAL.ttf");

	buttonShape = RectangleShape(Vector2f(190, 100));
	
buttonShape.setFillColor(Color(150, 185, 250));
	buttonShape.setPosition(Vector2f(0, 0)); 
	buttonShape.setOutlineColor(Color::Black); 
	buttonShape.setOutlineThickness(3.0f); 
	buttonText = Text("", buttonFont, 35);
	buttonText.setOutlineThickness(2.f);
	buttonText.setFillColor(Color::Black);
	buttonText.setPosition(0, 0);
	
}

Button::Button(float newXPosition, float newYposition, string text)
{
	buttonFont = Font();
	buttonFont.loadFromFile("ARIAL.ttf");

	buttonShape = RectangleShape(Vector2f(190, 100));
	buttonShape.setFillColor(Color::White);
	buttonShape.setPosition(Vector2f(newXPosition, newYposition)); 

	buttonText = Text(text, buttonFont, 40);
	buttonText.setFillColor(Color::Black);
	buttonText.setPosition(newXPosition + 95, newYposition+50);

	
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
	buttonText.setPosition(xPosition+ 30, yPosition+ 30);
	buttonText.setString(text); 


}

void Button::buttonHalfPot()
{
	string text = "1/2 POT";
	float xPosition = 400.f;
	float yPosition = 875.f;

	buttonShape.setPosition(Vector2f(xPosition, yPosition));
	buttonText.setPosition(xPosition + 30, yPosition +30);
	buttonText.setString(text);
}

void Button::buttonOnePot()
{
	string text = "1 POT";
	float xPosition = 700.f;
	float yPosition = 875.f;

	buttonShape.setPosition(Vector2f(xPosition, yPosition));
	buttonText.setPosition(xPosition + 30, yPosition + 30);
	buttonText.setString(text);
}

void Button::buttonThreeQuartersOfPot()
{
	string text = "3/4 POT";
	float xPosition = 700.f;
	float yPosition = 875.f;

	buttonShape.setPosition(Vector2f(xPosition, yPosition));
	buttonText.setPosition(xPosition + 30, yPosition + 30);
	buttonText.setString(text);
}

void Button::buttonAllIn()
{
	string text = "ALL IN";
	float xPosition = 1000.f;
	float yPosition = 875.f;

	buttonShape.setPosition(Vector2f(xPosition, yPosition));
	buttonText.setPosition(xPosition + 30, yPosition + 30);
	buttonText.setString(text);
}

void Button::buttonGoOut()
{
	string text = "GO OUT";
	float xPosition = 1300.f;
	float yPosition = 875.f;

	buttonShape.setPosition(Vector2f(xPosition, yPosition));
	buttonText.setPosition(xPosition + 30, yPosition + 30);
	buttonText.setString(text);

}

void Button::buttonShowCards()
{
	string text = "SHOW";
	float xPosition = 1600.f;
	float yPosition = 875.f;

	buttonShape.setPosition(Vector2f(xPosition, yPosition));
	buttonText.setPosition(xPosition + 30, yPosition + 30);
	buttonText.setString(text);
}

void Button::drawButton(RenderWindow& window)
{
	window.draw(buttonShape);
	window.draw(buttonText);
}

void Button::setButtonColor(Color color)
{
	buttonShape.setFillColor(color);
}

bool Button::isTheMouseOverButton(Vector2f clickPosition)
{
	return buttonShape.getGlobalBounds().contains(clickPosition.x, clickPosition.y); 

}

