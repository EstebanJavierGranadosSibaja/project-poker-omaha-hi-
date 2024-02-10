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
	int incrementPosition = 40;
	int xRight = 1210;
	int xLeft = 20;
	int y = 347;

	for (int i = 0; i < rows; i++)
	{
		numberOfPlayer.setString(to_string(i + 1)); 
		string si = numberOfPlayer.getString(); 
		cout << si; 

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

	/*	numberOfPlayer.setPosition(xRight + 30,y+38); 
		gameWindow.draw(numberOfPlayer); */

		xRight = 1200 + incrementPosition;
		xLeft = 20;
		y += 110;
		incrementPosition += 40;
	}
}

void PokerDisplay::checkTheDealerBoxes(RenderWindow& gameWindow)
{

	int rectWidth = 40;
	int rectHeight = 80;

	int totalWidth = COMMUNITY_CARD_SIZE * rectWidth; 
	int startX = 780;      

	int yCenter = 307;   

	for (int i = 0; i < COMMUNITY_CARD_SIZE; i++)
	{
		spacesForDealerCard[i] = RectangleShape(Vector2f(rectWidth, rectHeight));
		spacesForDealerCard[i].setFillColor(Color::Red);
		spacesForDealerCard[i].setOutlineColor(Color::Red);
		spacesForDealerCard[i].setOutlineThickness(0);
		spacesForDealerCard[i].setPosition(startX + i * rectWidth, yCenter);

		startX += 30; 
		gameWindow.draw(spacesForDealerCard[i]);
		
	}
}






