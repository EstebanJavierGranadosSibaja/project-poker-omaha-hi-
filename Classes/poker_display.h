#pragma once
#include"button.h"
#include"poker_table.h"

const int MAX_OF_USER_CARD = 4;
const int BETS_AMOUNT = 4;
const int SIZE_PREFLOP_BUTTON = 6;
const int SIZE_POSFLOP_BUTTON = 5;
const float rectWidth = 50.f;
const float rectHeight = 76.f;
const float startX = 812.f;
const float yCenter = 320.f;
const float midCard = 2.f;

const int LOAD_GAME_ERR = 10;

class PokerDisplay
{
private:
	Text potNumber;
	Text numberOfPlayer;
	Text userBlind; 
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

	Texture bigBlindTexture;
	Texture smallBlindTexture;

	Sprite bigBlindSprite;
	Sprite smallBlindSprite;

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
	void drawTheMethodsOnTheScreen(sf::RenderWindow& gameWindow);
	void drawUserCards(RenderWindow& gameWindow);
	void betButtonsIntoAction(Vector2f& mousePositionInWindow);
	void drawingPostAndPreFlopButtons(RenderWindow& gameWindow);
	void highLightingButtons(sf::Vector2f& mousePositionInWindow);
	void loadGameImage();
	void tryAndCatchOfLoadGame();
	void checkThePlayersBoxes(RenderWindow& gameWindow);
	void checkTheDealerBoxes(RenderWindow& gameWindow);

	void createDealerCardShapes(const float rectWidth, const float rectHeight, const float startX, float yCenter, const float midCard);

	void updateDealerPositions(RenderWindow& gameWindow);

	void definePreflopButtons();
	void definePostflopButtons();

	void drawPreFlopButtons(RenderWindow& gameWindow);
	void drawPostFlopButtons(RenderWindow& gameWindow);

	void highlightButton(Vector2f& mousePosition, int size, Button* preOfPosButton);
	void drawPotAccumulator(RenderWindow& gameWindow);
	void dealPreFlopCards(RenderWindow& gameWindow);
	void dealCardsInRow(int& amountOfCardsToDraw, sf::RenderWindow& gameWindow, int row);
	void drawAllCardsDown(RenderWindow& gameWindow);
	void blinkingActualPlayerHand(RenderWindow& gameWindow);
	void drawBingAndSmallBling(RenderWindow& gameWindow);
	void preFlopActionButtons(Vector2f clickPosition);
	void postFlopActionButtons(Vector2f clickPosition);
	void turnChange();
	void drawPot(RenderWindow& gameWindow);
	void showButtonPlayerHand(Vector2f clickPosition, Event userEvent);
	void drawCommunityCards(RenderWindow& gameWindow); 
};