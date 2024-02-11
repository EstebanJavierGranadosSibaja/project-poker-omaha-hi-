#include"poker_display.h"

PokerDisplay::PokerDisplay()
{

	menu = new Menu();
	menu->loadMenuWindow();

	rows = menu->getNumPlayer();
	columns = MAX_OF_USER_CARD;

	pokerTable = new PokerTable(menu->getBlindPrice(), menu->getNumPlayer());


	backGround = Texture();
	spriteBackGround = Sprite();
	arial.loadFromFile("ARIAL.ttf");

	numberOfPlayer = Text("1", arial, 35);
	numberOfPlayer.setFillColor(Color::White);
	numberOfPlayer.setOutlineThickness(2.5f);
	numberOfPlayer.setOutlineColor(Color::Black);

	preFlopButton = new Button[SIZE_PREFLOP_BUTTON];
	/*postFlopButton = new Button[SIZE_POSFLOP_BUTTON];*/

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
	definePreflopButtons();

	RenderWindow gameWindow(VideoMode(1920, 1080), "Game!!");


	while (gameWindow.isOpen())
	{
		Event event;

		Vector2i mousePosition = sf::Mouse::getPosition(gameWindow);
		Vector2f mousePositionInWindow = gameWindow.mapPixelToCoords(mousePosition);


		while (gameWindow.pollEvent(event))
		{

			highlightButton(mousePositionInWindow);
			/*system("cls");
			cout << " " << mousePosition.x << " , " << mousePosition.y;*/

			if (event.type == Event::Closed)
			{
				gameWindow.close();
			}
		}
		gameWindow.clear();

		gameWindow.draw(spriteBackGround);
		checkThePlayersBoxes(gameWindow);
		checkTheDealerBoxes(gameWindow);
		drawPreFlopButtons(gameWindow);

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
		numberOfPlayer.setString(to_string(i + 1));

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
				if (j == 3) {
					numberOfPlayer.setPosition(xRight + 40.f, y);
				}
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

			if (j == 0) {
				numberOfPlayer.setPosition(xLeft + 530.f - incrementPosition, y);
			}

		}
		gameWindow.draw(numberOfPlayer);

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

void PokerDisplay::definePreflopButtons()
{
	preFlopButton[0].button3BB();
	preFlopButton[1].buttonHalfPot();
	preFlopButton[2].buttonOnePot();
	preFlopButton[3].buttonAllIn(); 
	preFlopButton[4].buttonGoOut();
	preFlopButton[5].buttonShowCards();
}

//void PokerDisplay::definePostflopButtons()
//{
//	postFlopButton[0].buttonHalfPot();
//	postFlopButton[1].buttonThreeQuartersOfPot();
//	postFlopButton[2].buttonAllIn();
//	postFlopButton[3].buttonGoOut();
//	postFlopButton[4].buttonShowCards();
//}

void PokerDisplay::drawPreFlopButtons(RenderWindow& gameWindow)
{
	for (int i = 0; i < SIZE_PREFLOP_BUTTON; i++)
	{
		preFlopButton[i].drawButton(gameWindow);
	}
}

//void PokerDisplay::drawPostFlopButtons(RenderWindow& gameWindow)
//{
//	for (int i = 0; i < SIZE_POSFLOP_BUTTON; i++)
//	{
//		preFlopButton[i].drawButton(gameWindow);
//	}
//}

void PokerDisplay::highlightButton(Vector2f& mousePosition)
{

	for (int i = 0; i < SIZE_PREFLOP_BUTTON; i++)
	{
		bool isMouseOverButton = preFlopButton[i].getButtonShape().getGlobalBounds().contains(mousePosition);
		if (isMouseOverButton)
		{
			preFlopButton[i].setButtonColor(Color::Red);
			cout << " Si entro " << endl;
		}
		else
		{
			preFlopButton[i].setButtonColor(Color(135, 206, 250, 255));
		}
	}

}








