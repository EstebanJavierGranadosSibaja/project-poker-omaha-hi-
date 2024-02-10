#include"button.h"

Button::Button()
{
	buttonFont= Font();
    buttonShape = RectangleShape();
	buttonText = Text();

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
    Vector2f position(xPosition, yPosition); // Posición predeterminada del botón
    Vector2f size(100.0f, 50.0f); // Tamaño predeterminado del botón

   
    buttonShape.setSize(size);
    buttonShape.setPosition(position);
    buttonShape.setFillColor(Color::White);

    buttonText.setString(text); // Texto predeterminado
    buttonText.setCharacterSize(20);
    buttonText.setFillColor(Color::Black);
    FloatRect textBounds = buttonText.getLocalBounds();
    buttonText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    buttonText.setPosition(xPosition, yPosition); 
}

void Button::button3BB()
{
    string text = "3BB"; 
    float xPosition = 50;
    float yPosition = 500;

    shapeButton(xPosition, yPosition, text); 
}

void Button::drawButton(RenderWindow& window)
{
    window.draw(buttonShape);
    window.draw(buttonText);
}
