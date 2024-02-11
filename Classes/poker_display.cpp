#include"poker_display.h"

PokerDisplay::PokerDisplay()
{
	menu = new Menu();
	menu->loadMenuWindow();

	rows = menu->getNumPlayer();
	columns = MAX_OF_USER_CARD;

	pokerTable = new PokerTable(menu->getBlindPrice(), menu->getNumPlayer());
	pokerTable->dealCardsToThePlayers();

	backGround = Texture();
	spriteBackGround = Sprite();
	arial.loadFromFile("ARIAL.ttf");

	clock = Clock();
	time = seconds(1.f);
	isDealerThrowingCards = true;
	limit = 1;
	soundCard.openFromFile("Images/card_sound.ogg");

	numberOfPlayer = Text("1", arial, 35);
	numberOfPlayer.setFillColor(Color::White);
	numberOfPlayer.setOutlineThickness(2.5f);
	numberOfPlayer.setOutlineColor(Color::Black);

	preFlopButton = new Button[SIZE_PREFLOP_BUTTON];
	postFlopButton = new Button[SIZE_POSFLOP_BUTTON];

	spacesInUserCard = new RectangleShape * [rows];

	for (int i = 0; i < rows; i++)
	{
		spacesInUserCard[i] = new RectangleShape[columns];
	}

	spacesForDealerCard = new RectangleShape[COMMUNITY_CARD_SIZE];

	cardDownTexture = new Texture * [rows];
	cardDownSprite = new Sprite * [rows];
	for (int i = 0; i < rows; i++)
	{
		cardDownTexture[i] = new Texture[columns];
		cardDownSprite[i] = new Sprite[columns];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cardDownTexture[i][j].loadFromFile("Images/cardBack.png");
			cardDownSprite[i][j] = Sprite(cardDownTexture[i][j]);
		}
	}
}

void PokerDisplay::loadGameWindow()
{
	Player** players = pokerTable->getPlayers();

	loadGameImage();
	//definePreflopButtons();
	definePostflopButtons();

	RenderWindow gameWindow(VideoMode(1920, 1080), "Game!!");


	while (gameWindow.isOpen())
	{
		Event event;

		Vector2i mousePosition = sf::Mouse::getPosition(gameWindow);
		Vector2f mousePositionInWindow = gameWindow.mapPixelToCoords(mousePosition);


		while (gameWindow.pollEvent(event))
		{

			highlightButton(mousePositionInWindow,SIZE_POSFLOP_BUTTON,postFlopButton);
			system("cls");
			cout << " " << mousePosition.x << " , " << mousePosition.y;

			if (event.type == Event::Closed)
			{
				gameWindow.close();
			}
		}
		gameWindow.clear();

		gameWindow.draw(spriteBackGround);
		checkThePlayersBoxes(gameWindow);
		checkTheDealerBoxes(gameWindow);
		drawPostFlopButtons(gameWindow);
		drawPotAccumulator(gameWindow);
		drawBingAndSmallBling(gameWindow);
		dealPreFlopCards(gameWindow);
		drawAllCardsDown(gameWindow); 

		//drawPreFlopButtons(gameWindow);

		//Falla al momento de compilar, no se si se tiene que poner en otro luhar :(
		//setPositionSpritesOfUserCards();

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
				spacesInUserCard[i][j].setFillColor(Color::Transparent);
				spacesInUserCard[i][j].setOutlineColor(Color::Transparent);
				spacesInUserCard[i][j].setOutlineThickness(0);
				spacesInUserCard[i][j].setPosition(xRight, y);
				xRight += 55;
				gameWindow.draw(spacesInUserCard[i][j]);
				if (j == 3) {
					numberOfPlayer.setPosition(xRight + 40.f, y);
				}

				cardDownSprite[i][j].setPosition(spacesInUserCard[i][j].getPosition());
				cardDownSprite[i][j].setScale(spacesInUserCard[i][j].getSize().x / cardDownTexture[i][j].getSize().x, spacesInUserCard[i][j].getSize().y / cardDownTexture[i][j].getSize().y);

				continue;
			}

			if (i == 3)
			{
				y = 347.f;
			}

			spacesInUserCard[i][j] = RectangleShape(Vector2f(rectWidth, rectHeight));
			spacesInUserCard[i][j].setFillColor(Color::Transparent);
			spacesInUserCard[i][j].setOutlineColor(Color::Transparent);
			spacesInUserCard[i][j].setOutlineThickness(0);
			spacesInUserCard[i][j].setPosition(xLeft + 640.f - incrementPosition, y);
			xLeft += 55.f;
			gameWindow.draw(spacesInUserCard[i][j]);

			if (j == 0) {
				numberOfPlayer.setPosition(xLeft + 530.f - incrementPosition, y);
			}

			cardDownSprite[i][j].setPosition(spacesInUserCard[i][j].getPosition());
			cardDownSprite[i][j].setScale(spacesInUserCard[i][j].getSize().x / cardDownTexture[i][j].getSize().x, spacesInUserCard[i][j].getSize().y / cardDownTexture[i][j].getSize().y);

			/*pokerTable->getPlayers()[i]->getUserHand()->getPlayerSprite()[j].setPosition(spacesInUserCard[i][j].getPosition());
			pokerTable->getPlayers()[i]->getUserHand()->getPlayerSprite()[j].setScale(spacesInUserCard[i][j].getSize().x / pokerTable->getPlayers()[i]->getUserHand()->getPlayerTexture()[j].getSize().x,
				spacesInUserCard[i][j].getSize().y / pokerTable->getPlayers()[i]->getUserHand()->getPlayerTexture()[j].getSize().y);*/

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

		/*pokerTable->getDealer()->getDealerSprite()[i].setPosition(spacesForDealerCard[i].getPosition());
		pokerTable->getDealer()->getDealerSprite()[i].setPosition(spacesForDealerCard[i].getSize().x / pokerTable->getDealer()->getDealerTexture()[i].getSize().x,
			spacesForDealerCard[i].getSize().y / pokerTable->getDealer()->getDealerTexture()[i].getSize().y);*/

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

void PokerDisplay::definePostflopButtons()
{
	postFlopButton[0].buttonHalfPot();
	postFlopButton[1].buttonThreeQuartersOfPot();
	postFlopButton[2].buttonAllIn();
	postFlopButton[3].buttonGoOut();
	postFlopButton[4].buttonShowCards();
}

void PokerDisplay::drawPreFlopButtons(RenderWindow& gameWindow)
{
	for (int i = 0; i < SIZE_PREFLOP_BUTTON; i++)
	{
		preFlopButton[i].drawButton(gameWindow);
	}
}

void PokerDisplay::drawPostFlopButtons(RenderWindow& gameWindow)
{
	for (int i = 0; i < SIZE_POSFLOP_BUTTON; i++)
	{
		postFlopButton[i].drawButton(gameWindow);
	}
}

void PokerDisplay::highlightButton(Vector2f& mousePosition, int size, Button* preOfPosButton)
{

	for (int i = 0; i < size; i++)
	{
		bool isMouseOverButton = preOfPosButton[i].getButtonShape().getGlobalBounds().contains(mousePosition);
		if (isMouseOverButton)
		{
			preOfPosButton[i].setButtonColor(Color(173, 216, 230));
			cout << " Si entro " << endl;
		}
		else
		{
			preOfPosButton[i].setButtonColor(Color(135, 206, 250, 255));
		}
	}
}

void PokerDisplay::drawPotAccumulator(RenderWindow& gameWindow)
{
	RectangleShape potAccumulator(Vector2f(500, 120));
	Font potAccumulatorFont;
	string text = "POT ACCUMULATOR";
	float xPosition = 705.f;
	float yPosition = 15.f;

	potAccumulatorFont.loadFromFile("ARIAL.ttf");

	potAccumulator.setFillColor(Color::Transparent);
	potAccumulator.setPosition(Vector2f(xPosition, yPosition));
	potAccumulator.setOutlineColor(Color::Black);
	potAccumulator.setOutlineThickness(5.0f);

	Text potAccumulatorText(text, potAccumulatorFont, 20);
	potAccumulatorText.setOutlineColor(Color::Black);
	potAccumulatorText.setOutlineThickness(1.f);
	potAccumulatorText.setFillColor(Color::Black);
	potAccumulatorText.setPosition(841.0f, 25.0f);

	gameWindow.draw(potAccumulator);
	gameWindow.draw(potAccumulatorText);

}

void PokerDisplay::dealPreFlopCards(RenderWindow& gameWindow)
{
	int amountOfCardsToDraw = 0;
	if (isDealerThrowingCards)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (amountOfCardsToDraw == limit && clock.getElapsedTime() > time)
				{
					limit++;
					clock.restart();

					if (limit == columns * rows)
					{
						isDealerThrowingCards = false;
					}

					soundCard.stop();
					soundCard.play();

				}
				if (amountOfCardsToDraw != limit)
				{
					gameWindow.draw(cardDownSprite[i][j]);
					amountOfCardsToDraw++;
				}
			}
		}
	}
}

void PokerDisplay::drawAllCardsDown(RenderWindow& gameWindow)
{
	if (!isDealerThrowingCards) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				gameWindow.draw(cardDownSprite[i][j]);
			}
		}
	}
}

void PokerDisplay::drawBingAndSmallBling(RenderWindow& gameWindow)
{
	Texture bigBlindTexture;
	Texture smallBlindTexture;

	if (!bigBlindTexture.loadFromFile("Images/token.jpg") ||
		!smallBlindTexture.loadFromFile("Images/small_blind.png"))
	{
		cerr << "Error al cargar las im�genes de las blinds." << endl;
		return;
	}

	Sprite bigBlindSprite(bigBlindTexture);
	Sprite smallBlindSprite(smallBlindTexture);

	float scale =0.1f; 
	bigBlindSprite.setScale(scale, scale);
	smallBlindSprite.setScale(scale, scale);

	
	bigBlindSprite.setPosition(1155, 494);
	smallBlindSprite.setPosition(1147, 385);

	
	gameWindow.draw(bigBlindSprite);
	gameWindow.draw(smallBlindSprite);
}










