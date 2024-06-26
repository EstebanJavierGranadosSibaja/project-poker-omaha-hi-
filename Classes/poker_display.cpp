#include"poker_display.h"

PokerDisplay::PokerDisplay()
{
	currentPlayersTurn = 0;
	gameRound = 0;
	postFloatStarts = false;
	showButtonIsBeingPressed = false;
	checkThatUserPressGoOut = false;

	menu = new Menu();
	menu->loadMenuWindow();

	rows = menu->getNumPlayer();
	columns = MAX_OF_USER_CARD;

	pokerTable = new PokerTable(menu->getBlindPrice(), menu->getNumPlayer());

	backGround = Texture();
	spriteBackGround = Sprite();

	clock = Clock();
	time = seconds(0.5f);
	isDealerThrowingCards = true;
	limit = 1;
	soundCard.openFromFile("Images/card_sound.ogg");

	definingTextVariables();

	preFlopButton = new Button[SIZE_PREFLOP_BUTTON];
	postFlopButton = new Button[SIZE_POSFLOP_BUTTON];

	spacesForDealerCard = new RectangleShape[COMMUNITY_CARD_SIZE];

	spacesInUserCard = new RectangleShape * [rows];
	cardDownTexture = new Texture * [rows];
	cardDownSprite = new Sprite * [rows];
	for (int i = 0; i < rows; i++)
	{
		spacesInUserCard[i] = new RectangleShape[columns];
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
	defineBingAndSmallBling();
//NOTE:Eliminar Código comentado
	//pokerTable->createAHistoryRanking();
}

void PokerDisplay::definingTextVariables()
{
	arial.loadFromFile("ARIAL.ttf");

	numberOfPlayer = Text("1", arial, 20);
	numberOfPlayer.setFillColor(Color::White);
	numberOfPlayer.setOutlineThickness(2.5f);
	numberOfPlayer.setOutlineColor(Color::Black);

	potNumber = Text("", arial, 40);
	potNumber.setFillColor(Color::White);
	potNumber.setPosition(850.0f, 68.0f);
	potNumber.setOutlineThickness(2.5f);
	potNumber.setOutlineColor(Color::Black);

	userBlind = Text("", arial, 20);
	userBlind.setFillColor(Color::White);
	userBlind.setOutlineThickness(2.5f);
	userBlind.setOutlineColor(Color::Black);
}

void PokerDisplay::loadGameWindow()
{
	tryAndCatchOfLoadGame();
	definePostflopButtons();
	definePreflopButtons();

	RenderWindow gameWindow(VideoMode(1920, 1080), "Game!!");

	while (gameWindow.isOpen())
	{
		Event event;
		Vector2i mousePosition = sf::Mouse::getPosition(gameWindow);
		Vector2f mousePositionInWindow = gameWindow.mapPixelToCoords(mousePosition);
		//system("cls");//NOTE:Eliminar Código comentado

		if (gameWindow.pollEvent(event))
		{
			highLightingButtons(mousePositionInWindow);
			showButtonPlayerHand(mousePositionInWindow, event);

			if (event.type == Event::MouseButtonPressed)
			{
				betButtonsIntoAction(mousePositionInWindow);
				checkThatUserPressGoOut = false;
			}//NOTE:Eliminar Código comentado
			//cout << " " << mousePosition.x << " , " << mousePosition.y;
			if (event.type == Event::Closed)
			{
				gameWindow.close();
			}
		}

		turnChange();

		gameWindow.clear();
		drawTheMethodsOnTheScreen(gameWindow);
		gameWindow.display();
	}
}

void PokerDisplay::drawTheMethodsOnTheScreen(RenderWindow& gameWindow)
{
	gameWindow.draw(spriteBackGround);
	checkThePlayersBoxes(gameWindow);
	checkTheDealerBoxes(gameWindow);
	drawingPostAndPreFlopButtons(gameWindow);
	drawPotAccumulator(gameWindow);
	dealPreFlopCards(gameWindow);
	drawAllCardsDown(gameWindow);
	drawPot(gameWindow);
	blinkingActualPlayerHand(gameWindow);
	drawUserCards(gameWindow);
	drawCommunityCards(gameWindow);
	gameWindow.draw(bigBlindSprite);
	gameWindow.draw(smallBlindSprite);
}

void PokerDisplay::drawUserCards(RenderWindow& gameWindow)
{
	if (showButtonIsBeingPressed) {
		pokerTable->drawActualPlayerHand(currentPlayersTurn, gameWindow);
	}
}

void PokerDisplay::betButtonsIntoAction(Vector2f& mousePositionInWindow)
{
	if (!postFloatStarts) {
		preFlopActionButtons(mousePositionInWindow);
		return;
	}

	postFlopActionButtons(mousePositionInWindow);

}

void PokerDisplay::drawingPostAndPreFlopButtons(RenderWindow& gameWindow)
{
	if (!postFloatStarts) {
		drawPreFlopButtons(gameWindow);
		return;
	}

	drawPostFlopButtons(gameWindow);
}

void PokerDisplay::highLightingButtons(Vector2f& mousePositionInWindow)
{
	if (!postFloatStarts) {
		highlightButton(mousePositionInWindow, SIZE_PREFLOP_BUTTON, preFlopButton);
		return;
	}
	highlightButton(mousePositionInWindow, SIZE_POSFLOP_BUTTON, postFlopButton);
}

void PokerDisplay::loadGameImage()
{
	if (!backGround.loadFromFile("Images/poker_table.png"))
	{
		throw runtime_error("ERROR AL CARGAR LA IMAGEN EN loadGameImage()");
	}

	spriteBackGround = Sprite(backGround);
	spriteBackGround.setPosition(0, 0);
	spriteBackGround.setScale(1.5f, 1.5f);

}

void PokerDisplay::tryAndCatchOfLoadGame()
{
	try
	{
		loadGameImage();
	}
	catch (const runtime_error& e)
	{
		cerr << "ERROR AL CARGAR LA PANTALLA DEL JUEGO" << e.what() << endl;
	}
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
		numberOfPlayer.setString("Player: " + to_string(i + 1) + "\n");
		// seguir esto
		int playerBlind = pokerTable->getPlayers()[i]->getUserBlind();
		userBlind.setString("\n Blind: " + to_string(playerBlind));

		for (int j = 0; j < columns; j++)
		{
//NOTE:Código anidado, muy anidado, función candidato a refactorizar
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
					numberOfPlayer.setPosition(xRight + 30.f, y);
					userBlind.setPosition(xRight + 30.f, y);

				}

				cardDownSprite[i][j].setPosition(spacesInUserCard[i][j].getPosition());
				cardDownSprite[i][j].setScale(spacesInUserCard[i][j].getSize().x / cardDownTexture[i][j].getSize().x, spacesInUserCard[i][j].getSize().y / cardDownTexture[i][j].getSize().y);

				pokerTable->getPlayers()[i]->getUserHand()->setPositionAndScalesOfPlayerSprites(spacesInUserCard[i][j], j);
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
				numberOfPlayer.setPosition(xLeft + 450.f - incrementPosition, y);
				userBlind.setPosition(xLeft + 410.f - incrementPosition, y);
			}

			cardDownSprite[i][j].setPosition(spacesInUserCard[i][j].getPosition());
			cardDownSprite[i][j].setScale(spacesInUserCard[i][j].getSize().x / cardDownTexture[i][j].getSize().x, spacesInUserCard[i][j].getSize().y / cardDownTexture[i][j].getSize().y);

			pokerTable->getPlayers()[i]->getUserHand()->setPositionAndScalesOfPlayerSprites(spacesInUserCard[i][j], j);

		}
		gameWindow.draw(numberOfPlayer);
		gameWindow.draw(userBlind);

		xRight = 1200.f + incrementPosition;
		xLeft = 20.f;
		y += 110.f;
		incrementPosition += 40.f;
	}

}

void PokerDisplay::checkTheDealerBoxes(RenderWindow& gameWindow)
{
	const float rectWidth = 50.f;
	const float rectHeight = 76.f;
	const float startX = 812.f;
	const float yCenter = 320.f;
	const float midCard = 2.f;

	createDealerCardShapes(rectWidth, rectHeight, startX, yCenter, midCard);
	updateDealerPositions(gameWindow);
}

void PokerDisplay::createDealerCardShapes(const float rectWidth, const float rectHeight, const float startX, float yCenter, const float midCard)
{
	for (int i = 0; i < COMMUNITY_CARD_SIZE; i++)
	{
		spacesForDealerCard[i] = RectangleShape(Vector2f(rectWidth, rectHeight));
		spacesForDealerCard[i].setFillColor(Color::Transparent);
		spacesForDealerCard[i].setOutlineColor(Color::Transparent);
		spacesForDealerCard[i].setOutlineThickness(0);
		spacesForDealerCard[i].setPosition(startX + i * rectWidth, yCenter);

		if (i < midCard)
			yCenter += 10.f;
		else
			yCenter -= 10.f;
	}
}

void PokerDisplay::updateDealerPositions(RenderWindow& gameWindow)
{
	for (int i = 0; i < COMMUNITY_CARD_SIZE; i++)
	{
		pokerTable->getDealer()->setPositionAndScalesOfDealerSprites(spacesForDealerCard[i], i);
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
		bool isMouseOverButton = preOfPosButton[i].isTheMouseOverButton(mousePosition);
		if (isMouseOverButton)
		{
			preOfPosButton[i].setButtonColor(Color(49, 59, 90));
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

	string text = "POT ACCUMULATOR";
	float xPosition = 705.f;
	float yPosition = 15.f;

	potAccumulator.setFillColor(Color::Transparent);
	potAccumulator.setPosition(Vector2f(xPosition, yPosition));
	potAccumulator.setOutlineColor(Color::Black);
	potAccumulator.setOutlineThickness(5.0f);

	Text potAccumulatorText(text, arial, 20);
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
			dealCardsInRow(amountOfCardsToDraw, gameWindow, i);
		}
	}
}

void PokerDisplay::dealCardsInRow(int& amountOfCardsToDraw, RenderWindow& gameWindow, int row)
{
	for (int j = 0; j < columns; j++)
	{
		if (amountOfCardsToDraw == limit && clock.getElapsedTime() > time)
		{
			limit++;
			clock.restart();
//NOTE:Código anidado 
			if (limit == columns * rows)
			{
				isDealerThrowingCards = false;
			}

			soundCard.stop();
			soundCard.play();

		}
		if (amountOfCardsToDraw != limit)
		{
			gameWindow.draw(cardDownSprite[row][j]);
			amountOfCardsToDraw++;
		}
	}
}

void PokerDisplay::drawAllCardsDown(RenderWindow& gameWindow)
{//NOTE:Código anidado, muy anidado, función candidato a refactorizar
	if (!isDealerThrowingCards) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (currentPlayersTurn == i) {
					continue;
				}
				gameWindow.draw(cardDownSprite[i][j]);
			}
		}
	}
}

void PokerDisplay::blinkingActualPlayerHand(RenderWindow& gameWindow)
{

	if (!isDealerThrowingCards && !showButtonIsBeingPressed) {
		bool isWhite = true;
		if (clock.getElapsedTime() > seconds(1.0f)) {
			isWhite = !isWhite;
			clock.restart();
		}
		Color color = isWhite ? Color::White : Color::Transparent;
		for (int j = 0; j < columns; j++) {
			spacesInUserCard[currentPlayersTurn][j].setFillColor(color);
			gameWindow.draw(spacesInUserCard[currentPlayersTurn][j]);
		}
	}

}

void PokerDisplay::defineBingAndSmallBling()
{
	if (!bigBlindTexture.loadFromFile("Images/token.jpg") ||
		!smallBlindTexture.loadFromFile("Images/small_blind.png"))
	{
		cerr << "Error al cargar las im�genes de las blinds." << endl;
		return;
	}

	bigBlindSprite = Sprite(bigBlindTexture);
	smallBlindSprite = Sprite(smallBlindTexture);

	float scale = 0.1f;
	bigBlindSprite.setScale(scale, scale);
	smallBlindSprite.setScale(scale, scale);
	bigBlindSprite.setPosition(1155, 494);
	smallBlindSprite.setPosition(1147, 385);

}

void PokerDisplay::preFlopActionButtons(Vector2f clickPosition)
{
	for (int i = 0; i < BETS_AMOUNT + 1; i++)
	{
		if (preFlopButton[i].isTheMouseOverButton(clickPosition))
		{
			int userBB = pokerTable->getPlayerBlind(currentPlayersTurn);
			pokerTable->preFloatIncreaseThePot(i, userBB, currentPlayersTurn);
			pokerTable->setPlayerBlind(currentPlayersTurn, userBB);
			currentPlayersTurn++;
		}
	}
}

void PokerDisplay::postFlopActionButtons(Vector2f clickPosition)
{
	if (gameRound < 4 && gameRound != 0)
	{
		for (int i = 0; i < BETS_AMOUNT; i++)
		{//NOTE:Código anidado, muy anidado, función candidato a refactorizar
			if (postFlopButton[i].isTheMouseOverButton(clickPosition))
			{
				int userBB = pokerTable->getPlayerBlind(currentPlayersTurn);
				pokerTable->posFloatIncreaseThePot(i, userBB, currentPlayersTurn);
				pokerTable->setPlayerBlind(currentPlayersTurn, userBB);
				currentPlayersTurn++;
			}
		}
	}
}

void PokerDisplay::turnChange()
{
	if (currentPlayersTurn == menu->getNumPlayer())
	{
		if (!postFloatStarts) {
			postFloatStarts = true;
		}
		currentPlayersTurn = 0;
		gameRound++;
	}
}

void PokerDisplay::drawPot(RenderWindow& gameWindow)
{
	string stringPot = to_string(pokerTable->getPot());
	potNumber.setString("POT: " + stringPot);
	gameWindow.draw(potNumber);

}

void PokerDisplay::showButtonPlayerHand(Vector2f clickPosition, Event userEvent)
{
	bool isMouseOverShowButton = preFlopButton[5].isTheMouseOverButton(clickPosition) ||
		postFlopButton[4].isTheMouseOverButton(clickPosition);

	bool hasMouseClickedOnButton = (userEvent.type == Event::MouseButtonPressed) &&
		(userEvent.type == Event::MouseButtonReleased) == false;

	if (isMouseOverShowButton && hasMouseClickedOnButton)
	{
		showButtonIsBeingPressed = true;
	}

	if (userEvent.type == Event::MouseButtonReleased)
	{
		showButtonIsBeingPressed = false;
	}
}

void PokerDisplay::drawCommunityCards(RenderWindow& gameWindow)
{
	if (gameRound >= 1)
	{
		gameWindow.draw(pokerTable->getDealer()->getDealerSprite()[0]);
		gameWindow.draw(pokerTable->getDealer()->getDealerSprite()[1]);
		gameWindow.draw(pokerTable->getDealer()->getDealerSprite()[2]);
	}
	if (gameRound >= 2)
	{
		gameWindow.draw(pokerTable->getDealer()->getDealerSprite()[3]);
	}
	if (gameRound >= 3)
	{
		gameWindow.draw(pokerTable->getDealer()->getDealerSprite()[4]);
	}
}