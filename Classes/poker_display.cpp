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
	numberOfPlayer = Text("1", menu->getFont(), 10);
	numberOfPlayer.setFillColor(Color::White); 
	numberOfPlayer.setOutlineThickness(5); 
	numberOfPlayer.setOutlineColor(Color::Black);

	spacesInUserCard = new RectangleShape * [rows];
	for (int i = 0; i < rows; i++)
	{
		spacesInUserCard[i] = new RectangleShape[columns];
	}

	spacesForDealerCard = new RectangleShape[COMMUNITY_CARD_SIZE];
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
			/*system("cls");
			cout << " " << mousePosition.x << " , " << mousePosition.y;*/

			if (event.type == Event::Closed)
			{
				gameWindow.close();
			}
		}
		gameWindow.clear();

		//se pueden llamar metodos aqui 

		gameWindow.draw(spriteBackGround);

		checkThePlayersBoxes(gameWindow);
		checkTheDealerBoxes(gameWindow);
		
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

void PokerDisplay::checkThePlayersBoxes(RenderWindow& gameWindow)
{
	float incrementPosition = 40.f;
	float xRight = 1210.f;
	float xLeft = 20.f;
	float y = 347.f;

	float rectWidth = 50.f;
	float rectHeight = 76.f;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (i < 3)
			{

				spacesInUserCard[i][j] = RectangleShape(Vector2f(rectWidth, rectHeight));
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
				y = 347.f;
			}

			spacesInUserCard[i][j] = RectangleShape(Vector2f(rectWidth, rectHeight));
			spacesInUserCard[i][j].setFillColor(Color::Red);
			spacesInUserCard[i][j].setOutlineColor(Color::Red);
			spacesInUserCard[i][j].setOutlineThickness(0);
			spacesInUserCard[i][j].setPosition(xLeft + 640.f - incrementPosition, y);
			xLeft += 55.f;
			gameWindow.draw(spacesInUserCard[i][j]);

		}

		xRight = 1200.f + incrementPosition;
		xLeft = 20.f;
		y += 110.f;
		incrementPosition += 40.f;
	}
}

void PokerDisplay::checkTheDealerBoxes(RenderWindow& gameWindow)
{
	float rectWidth = 50.f;
	float rectHeight = 76.f;

	float totalWidth = COMMUNITY_CARD_SIZE * rectWidth;
	float startX = 812.f;

	float yCenter = 320.f;

	float midCard = 2.f;

	for (int i = 0; i < COMMUNITY_CARD_SIZE; i++)
	{
		spacesForDealerCard[i] = RectangleShape(Vector2f(rectWidth, rectHeight));
		spacesForDealerCard[i].setFillColor(Color::Red);
		spacesForDealerCard[i].setOutlineColor(Color::Red);
		spacesForDealerCard[i].setOutlineThickness(0);
		spacesForDealerCard[i].setPosition(startX + i * rectWidth, yCenter);


		if (i < midCard)
		{
			yCenter += 10.f;

		}
		else
		{
			yCenter -= 10.f;
		}

		startX += 10.f;
		gameWindow.draw(spacesForDealerCard[i]);
		
	}
}






