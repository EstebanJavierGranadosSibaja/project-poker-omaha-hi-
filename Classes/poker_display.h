#pragma once
#include"button.h"
#include"poker_table.h"

const int MAX_OF_USER_CARD = 4;
const int BETS_AMOUNT = 4;
const int SIZE_PREFLOP_BUTTON = 6;
const int SIZE_POSFLOP_BUTTON = 5;

const int LOAD_GAME_ERR = 10;

class PokerDisplay
{
private:
	Text potNumber;
	Text numberOfPlayer;
	Font arial;
	PokerTable* pokerTable;
	Player** players;
	Menu* menu;
	Button* preFlopButton;
	Button* postFlopButton;

	Texture backGround;
	Sprite spriteBackGround;
	RectangleShape** spacesInUserCard;
	RectangleShape* spacesForDealerCard;

	Texture** cardDownTexture;
	Sprite** cardDownSprite;

	Music soundCard;
	Clock clock;
	Time time;
	int limit;
	bool isDealerThrowingCards;
	bool postFloatStarts;
	bool showButtonIsBeingPressed;
	int currentPlayersTurn;
	int gameRound;
	int rows;
	int columns;



public:

	PokerDisplay();
	void definingTextVariables();
	void loadGameWindow();
	void drawUserCards(sf::RenderWindow& gameWindow);
	void betButtonsIntoAction(Vector2f& mousePositionInWindow);
	void drawingPostAndPreFlopButtons(sf::RenderWindow& gameWindow);
	void highLightingButtons(sf::Vector2f& mousePositionInWindow);
	void loadGameImage();
	void tryAndCatchOfLoadGame();
	void checkThePlayersBoxes(RenderWindow& gameWindow);
	void checkTheDealerBoxes(RenderWindow& gameWindow);

	void definePreflopButtons();
	void definePostflopButtons();

	void drawPreFlopButtons(RenderWindow& gameWindow);
	void drawPostFlopButtons(RenderWindow& gameWindow);

	void highlightButton(Vector2f& mousePosition, int size, Button* preOfPosButton);
	void drawPotAccumulator(RenderWindow& gameWindow);
	void dealPreFlopCards(RenderWindow& gameWindow);
	void drawAllCardsDown(RenderWindow& gameWindow);
	void blinkingActualPlayerHand(RenderWindow& gameWindow);
	void drawBingAndSmallBling(RenderWindow& gameWindow);
	void preFlopActionButtons(Vector2f clickPosition);
	void postFlopActionButtons(Vector2f clickPosition);
	void turnChange();
	void drawPot(RenderWindow& gameWindow);
	void showButtonPlayerHand(Vector2f clickPosition, Event userEvent);

};