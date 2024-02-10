#include"poker_display.h"

PokerDisplay::PokerDisplay()
{
	menu = new Menu();
    menu->loadMenuWindow();
	rows = menu->getNumPlayer();
	columns = maxOfUserCard;
	pokerTable = new PokerTable(menu->getBlindPrice(), menu->getNumPlayer());

	backGround = Texture();
	spriteBackGround = Sprite();

	spacesInUserCard = new RectangleShape* [rows];
	for (int i = 0; i < rows; i++)
	{
		spacesInUserCard[i] = new RectangleShape[columns]; 
	}
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

		gameWindow.draw(spriteBackGround);
		gameWindow.display();
	}
}

void PokerDisplay::loadGameImage()
{
	if (!backGround.loadFromFile("Images/poker_table.png"))
	{
		return;
	}
	spriteBackGround = Sprite(backGround);
	spriteBackGround.setPosition(0, 0);
	spriteBackGround.setScale(1.5f, 1.5f);
}

void PokerDisplay::drawRectangleShape()
{
	
}





