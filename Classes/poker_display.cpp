#include"poker_display.h"

PokerDisplay::PokerDisplay()
{
	rows = 6;
	columns = maxOfUserCard;
	menu = new Menu(); 
	menu->loadMenuWindow(); 

	pokerTable = new PokerTable(); 


}

void PokerDisplay::loadGameWindow()
{
	loadGameImage(); 
	RenderWindow gameWindow(VideoMode(1920, 1080), "Game!!");
	while (gameWindow.isOpen())
	{
		Event event;
		while (gameWindow.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				gameWindow.close();
			}	
		}
		gameWindow.clear();
		
		//se pueden llamar metodos aqui 

		gameWindow.draw(sprite);
		gameWindow.display();
	}
}

void PokerDisplay::loadGameImage()
{
	if (!backGround.loadFromFile("Images/poker_table.png"))
	{
		return;
	}
	sprite = Sprite(backGround);
	sprite.setPosition(0, 0);
	sprite.setScale(1.5f, 1.5f);
}

void PokerDisplay::drawRectangleShape()
{
	
}





