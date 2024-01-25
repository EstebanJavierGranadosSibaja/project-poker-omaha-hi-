#include <iostream>
#include "../Classes/poker_table.h"
using namespace std;


int main()
{
	Deck *mazo = new Deck;

	cout << mazo;

	PokerTable* mesa;
	Dealer casos;
	cout << casos.getPlayerCards(mesa);



	return 0;
}

