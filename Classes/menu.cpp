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
