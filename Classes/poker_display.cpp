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

	spacesInUserCard = new RectangleShape * [rows];
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
		Vector2i mousePosition = Mouse::getPosition(gameWindow);
		Event event;
		while (gameWindow.pollEvent(event))
		{
			system("cls");
			cout << " " << mousePosition.x << " , " << mousePosition.y;

			if (event.type == Event::Closed)
			{
				gameWindow.close();
			}
		}
		gameWindow.clear();

		//se pueden llamar metodos aqui 

		gameWindow.draw(spriteBackGround);

		drawRectangleShape(gameWindow);


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

void PokerDisplay::drawRectangleShape(RenderWindow& gameWindow)
{
	int incrementPosition = 40;
	int xRight = 1210;
	int xLeft = 20;
	int y = 347;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (i < 3)
			{

				spacesInUserCard[i][j] = RectangleShape(Vector2f(50, 76));
				spacesInUserCard[i][j].setFillColor(Color::Red);
				spacesInUserCard[i][j].setOutlineColor(Color::Red);
				spacesInUserCard[i][j].setOutlineThickness(0);
				spacesInUserCard[i][j].setPosition(xRight, y);
				xRight += 55;
				gameWindow.draw(spacesInUserCard[i][j]);
				continue;
			}

			if (i == 3)
			{
				y = 347;
			}

			spacesInUserCard[i][j] = RectangleShape(Vector2f(50, 76));
			spacesInUserCard[i][j].setFillColor(Color::Red);
			spacesInUserCard[i][j].setOutlineColor(Color::Red);
			spacesInUserCard[i][j].setOutlineThickness(0);
			spacesInUserCard[i][j].setPosition(xLeft + 640 - incrementPosition, y);
			xLeft += 55;
			gameWindow.draw(spacesInUserCard[i][j]);

		}

		xRight = 1200 + incrementPosition;
		xLeft = 20;
		y += 110;
		incrementPosition += 40;
	}
}






