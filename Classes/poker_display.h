#pragma once
#include"button.h"
#include"poker_table.h"

const int MAX_OF_USER_CARD = 4; 
const int BETS_AMOUNT = 4; 
const int SIZE_PREFLOP_BUTTON = 6; 
const int SIZE_POSFLOP_BUTTON = 5;


class PokerDisplay
{
private:
	Text numberOfPlayer;
	Font arial;
	PokerTable* pokerTable;
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
	int currentPlayersTurn;

	int rows;
	int columns;



public:

	PokerDisplay();
	void loadGameWindow();
	void loadGameImage();
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
	void drawBingAndSmallBling(RenderWindow& gameWindow); 

	void firstRoundOfBetting(Vector2f clickPosition);
	void turnChange();
	
};