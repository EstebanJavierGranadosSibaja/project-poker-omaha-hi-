#include"menu.h"

void Menu::loadMenuWindow()
{

	RenderWindow window(VideoMode(1920, 1080), "Game!");

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}


		window.clear();
		loadMenuImage(window);
		//se pueden llamar metodos aqui 


		window.display();
	}
}

void Menu::loadMenuImage(RenderWindow& window)
{
	if (!background.loadFromFile("Images/menu.png"))
	{
		return;
	}

	Sprite sprite(background);

	sprite.setPosition(4.f, 4.f);
	sprite.setScale(static_cast<float>(window.getSize().x) / background.getSize().x,
		static_cast<float>(window.getSize().y) / background.getSize().y);

	window.draw(sprite);
}

void Menu::drawRectangle(RenderWindow& window)
{
	textBox = RectangleShape(Vector2f(200, 30));
	textBox.setFillColor(Color::White);
	textBox.setOutlineColor(Color::Black);
	textBox.setOutlineThickness(2);
	textBox.setPosition(50, 100);
}

void Menu::addText(RenderWindow& window)
{
	if (!font.loadFromFile("C:/Users/Jazmin/source/repos/project-poker-omaha-hi-/poker_omaha_hi/ARIAL.ttf"))
	{
		cerr << "Error al cargar la fuente" << std::endl;
		return;
	}

	text = Text("Ingrese el valor de las ciegas:", font, 24);
	text.setPosition(50, 50);

	userText = Text("", font, 24);
	userText.setFillColor(Color::White);
	userText.setOutlineColor(Color::Black);
	userText.setOutlineThickness(5.f);
	userText.setPosition(55, 105);
}
