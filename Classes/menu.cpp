#include "menu.h"

Menu::Menu()
{
	isEnteringText = false;

	isBlindBeingEntered = true;
	numPlayers = 0;
	blindPrice = 0;

	drawRectangle();
	addText();

	rangeOfTheUserInput = Vector2i(0, 9);
	amountOfNumbersThatUserCanPress = 6;
}

Font Menu::getFont()
{
	return font;
}

int Menu::getNumPlayer()
{
	return  numPlayers;
}

int Menu::getBlindPrice()
{
	return blindPrice;
}

void Menu::loadMenuWindow()
{
	RenderWindow window(VideoMode(1920, 1080), "Game!");
	loadMenuImage(window);
	while (window.isOpen())
	{

		Vector2i mousePosition = Mouse::getPosition(window);


		while (window.pollEvent(userEvent))
		{

			system("cls");
			cout << " " << mousePosition.x << " , " << mousePosition.y;

			if (userEvent.type == Event::Closed)
			{
				window.close();
			}

			blindInput(window);
		}



		window.clear();

		window.draw(spriteBackground);
		window.draw(text);
		window.draw(textBox);
		window.draw(userText);
		 
		window.display();
	}
}

void Menu::loadMenuImage(RenderWindow& window)
{
	if (!background.loadFromFile("Images/menu2.png"))
	{
		return;
	}

	spriteBackground = Sprite(background);
	spriteBackground.setPosition(0, 0);
	spriteBackground.setScale(static_cast<float>(window.getSize().x) / background.getSize().x,
		static_cast<float>(window.getSize().y) / background.getSize().y);
}

void Menu::drawRectangle()
{
	textBox = RectangleShape(Vector2f(170, 50));
	textBox.setFillColor(Color::White);
	textBox.setOutlineColor(Color::Black);
	textBox.setOutlineThickness(2);
	textBox.setPosition(865, 570);
}

void Menu::addText()
{

	if (!font.loadFromFile("ARIAL.ttf"))
	{
		cerr << "Error al cargar la fuente" << std::endl;
		return;
	}

	text = Text("Ingrese el valor de las ciegas", font, 35);
	text.setFillColor(Color::White);
	text.setOutlineColor(Color::Black);
	text.setOutlineThickness(4.f);
	text.setPosition(740, 500);

	userText = Text("", font, 45);
	userText.setFillColor(Color::Black);
	userText.setOutlineColor(Color::Black);
	userText.setOutlineThickness(2.f);
	userText.setPosition(865, 570);
}

void Menu::blindInput(RenderWindow& window)
{
	bool isLeftButtonPresed = userEvent.type == Event::MouseButtonPressed && userEvent.mouseButton.button == Mouse::Left;

	if (isLeftButtonPresed)
	{

		Vector2i mousePos = Mouse::getPosition(window);
		if (textBox.getGlobalBounds().contains(mousePos.x, mousePos.y))
		{
			isEnteringText = true;

		}
		else
		{
			isEnteringText = false;
		}
	}

	inputText(isEnteringText);
	checkWhenUserPressEnter(window);
}

void Menu::inputText(bool isEnteringText)
{
	char rangeOfNum[2] = { to_string(rangeOfTheUserInput.x)[0] ,
						   to_string(rangeOfTheUserInput.y)[0] };

	bool isAValidRange = userEvent.text.unicode >= rangeOfNum[0] &&
		userEvent.text.unicode <= rangeOfNum[1];

	if (userEvent.type == Event::TextEntered && isEnteringText)
	{
		if (isAValidRange && isLenghtOfUserTextCorrect())
		{ 
			userText.setString(userText.getString() + static_cast<char>(userEvent.text.unicode));
		}
		else if (userEvent.text.unicode == 8 && !userText.getString().isEmpty())
		{
			string str = userText.getString();
			str.erase(str.size() - 1);
			userText.setString(str);
		}
	}
}

void Menu::checkWhenUserPressEnter(RenderWindow& window)
{
	if (userEvent.text.unicode == '\r')
	{
		string textValues = userText.getString();

		if (isBlindBeingEntered) {

			blindPrice = stoi(textValues);
			
			cout << " Precio digitado correctamente : " << blindPrice << endl;

			nextUserRequest();

			isBlindBeingEntered = false;
			return;
		}
		numPlayers = stoi(textValues);
		cout << " Jugadores digitados correctamente : " << numPlayers << endl;
		window.close();
	}
}

void Menu::nextUserRequest()
{
	text.setString("Digite el numero de jugadores de 2 a 6");
	text.setPosition(650, 500);
	userText.setString("");
	rangeOfTheUserInput = Vector2i(2, 6);
	amountOfNumbersThatUserCanPress = 1;
}

bool Menu::isLenghtOfUserTextCorrect()
{
	string textValues = userText.getString();
	if (textValues.length() + 1 <= amountOfNumbersThatUserCanPress) {
		return true;
	}
	return false;
}