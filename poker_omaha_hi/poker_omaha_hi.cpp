#include <iostream>
#include"../Classes/menu.h"
#include"../Classes/poker_display.h"
#include"../Classes/poker_table.h"

int main()
{
	Menu menu;
	menu.loadMenuWindow();

	/*Dealer newDealer;
	Deck* newDeck = new Deck();

	bool isPlayerActive = true;
	int numberOfPlayers = 0;
	cout << "Cantidad de jugadores: " << numberOfPlayers;

	Player** newPlayers = new Player*[numberOfPlayers];

	newDealer.shuffleDeck(newDeck);
	newDealer.getPlayerCards(newPlayers, numberOfPlayers, newDeck);

	for (int i = 0; i < numberOfPlayers; i++)
	{
		newPlayers[i] = new Player(i+1, isPlayerActive, 0, newPlayers[i]->getUserHand());
	}

	for (int i = 0; i < numberOfPlayers; i++)
	{
		cout << newPlayers[i]->getUserHand()->getHand()[0]->getNumber() << endl;
	}*/

	return 0;
}

