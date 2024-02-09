#include"poker_display.h"

void PokerDisplay::loadGameWindow()
{
	RenderWindow gameWindow(VideoMode(1920, 1080), "Game!!");
	while (gameWindow.isOpen())
	{
		Event event;
		while (gameWindow.pollEvent(event))
		{
			if (event.type == Event::Closed)
				gameWindow.close();
		}


		gameWindow.clear();
		loadGameImage(gameWindow);
		//se pueden llamar metodos aqui 


		gameWindow.display();
	}
}

void PokerDisplay::loadGameImage(RenderWindow& newWindow)
{
	if (!backGround.loadFromFile("Images/poker_table.png"))
	{
		return;
	}

	Sprite sprite(backGround);

	sprite.setPosition(4.f, 4.f);
	sprite.setScale(static_cast<float>(newWindow.getSize().x) / backGround.getSize().x,
		static_cast<float>(newWindow.getSize().y) / backGround.getSize().y);

	newWindow.draw(sprite);
}



