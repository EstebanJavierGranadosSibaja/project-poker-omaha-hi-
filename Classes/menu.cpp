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

		//se pueden llamar metodos aqui 


		window.display();
	}
}

void Menu::loadMenuImage(RenderWindow& window)
{
}
