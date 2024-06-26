#include "poker_table.h"

PokerTable::PokerTable(int aBigBlind, int aNumberOfPlayers)
{
	pot = 0;
	bigBlind = aBigBlind;
	smallBlind = aBigBlind / 2;

	numberOfPlayers = aNumberOfPlayers;
	dealer = new Dealer();
	deck = new Deck();
	players = new Player * [numberOfPlayers];

	for (int i = 0; i < numberOfPlayers; i++)
	{
		players[i] = new Player(aBigBlind);
	}


	dealer->shuffleDeck(deck);
	dealer->setCommunityCards(deck);
	dealer->createDealerSprites();
	dealCardsToThePlayers();

}

PokerTable::~PokerTable()
{
}

void PokerTable::setPot(int aPot)
{
	pot = aPot;
}

void PokerTable::setBigBlind(int aBigBlind)
{
	bigBlind = aBigBlind;
}

void PokerTable::setSmallBlind(int aSmallBlind)
{
	smallBlind = aSmallBlind;
}

void PokerTable::setNumberOfPlayers(int newNumberOfPlayers)
{
	numberOfPlayers = newNumberOfPlayers;
}

void PokerTable::setDealer(Dealer* newDealer)
{
	dealer = newDealer;
}

void PokerTable::setDeck(Deck* newDeck)
{
	deck = newDeck;
}

void PokerTable::setPlayer(Player** newPlayers)
{
	players = newPlayers;
}

int PokerTable::getPot()
{
	return pot;
}

int PokerTable::getBigBlind()
{
	return bigBlind;
}

int PokerTable::getSmallBlind()
{
	return smallBlind;
}

int PokerTable::getNumberOfPlayers()
{
	return numberOfPlayers;
}

int PokerTable::getPlayerBlind(int index)
{
	return players[index]->getUserBlind();
}

void PokerTable::setPlayerBlind(int index, int newBlinds)
{
	players[index]->setUserBlind(newBlinds);
}

Dealer* PokerTable::getDealer()
{
	return dealer;
}

Deck* PokerTable::getDeck()
{
	return deck;
}

Player** PokerTable::getPlayers()
{
	return players;
}

void PokerTable::dealCardsToThePlayers()
{
	dealer->getPlayerCards(players, numberOfPlayers, deck);

	for (int i = 0; i < numberOfPlayers; i++)
	{
		players[i]->getUserHand()->createPlayerSprites();
	}
}

bool PokerTable::validationOfThreeBigBlindButton(int& actualUserBlind)
{
	if (actualUserBlind >= bigBlind * 3)
	{
		actualUserBlind -= bigBlind * 3;
		pot += bigBlind * 3;
		return true;
	}
	cout << " Se quedo sin fichas " << endl;
	return false;
}

bool PokerTable::validationOfThreePartsPotButton(int& actualUserBlind)
{
	if (actualUserBlind >= (pot / 2) / 2)
	{
		actualUserBlind -= (pot / 2) / 2;
		pot += (pot / 2) / 2;

		return true;
	}
	cout << " Se quedo sin fichas " << endl;
	return false;
}

bool PokerTable::validationOfTwoPartsPotButton(int& actualUserBlind)
{
	if (actualUserBlind >= pot / 2)
	{
		actualUserBlind -= pot / 2;
		pot += pot / 2;
		return true;
	}
	cout << " Se quedo sin fichas " << endl;
	return false;
}

bool PokerTable::validationOfPotButton(int& actualUserBlind)
{
	if (actualUserBlind >= pot)
	{
		actualUserBlind -= pot;
		pot += pot;
		return true;
	}
	cout << " Se quedo sin fichas " << endl;
	return false;
}

bool PokerTable::validationOfAllInButton(int& actualUserBlind)
{
	if (actualUserBlind != 0)
	{
		pot += actualUserBlind;
		actualUserBlind -= actualUserBlind;

		return true;
	}
	cout << " Se quedo sin fichas " << endl;
	return false;
}

void PokerTable::validationOfGoOut(int& actualUserBlind, int playerIndex)
{
	if (players[playerIndex]->getIsActive())
	{
		players[playerIndex]->setActivePlayer(false);
		cout << "SE SALIO EL JUGADOR NUMERO " + to_string(playerIndex + 1) << endl;
		return;
	}
	else//Note: No tiene sentido el else
	{
		if (actualUserBlind >= bigBlind)
		{
			actualUserBlind -= bigBlind;
			pot += bigBlind;
			players[playerIndex]->setActivePlayer(true);
			cout << "SE VOLVIO A UNIR EL JUGADOR NUMERO " + to_string(playerIndex + 1) << endl;
			return;
		}
		cout << "EL JUGADOR " + to_string(playerIndex + 1) + " NO TIENE DINERO PARA INCORPORARSE A LA MESA " << endl;
	}
}

string* PokerTable::convertHandsToText()
{
	string* newText = new string[numberOfPlayers + 4];
	int lastPosition = 0;

	newText[0] = "    RANKING HISTORIAL DE LAS MANOS DE LOS JUGADORES    \n";

	for (int i = 0; i < numberOfPlayers; i++)
	{
		newText[i + 1] = players[i]->getUserHand()->getHandToText(i + 1);
		lastPosition = i;
	}

	newText[lastPosition + 3] = "  |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| \n";

	return newText;
}

string* PokerTable::convertCommunityCardsToText()
{
	string* newDealerText = new string[COMMUNITY_CARD_SIZE];

	newDealerText[0] = "    RANKING HISTORIAL DE LAS CARTAR COMUNITARIAS DEL DEALER   \n";

	newDealerText[1] = dealer->getCommunityCardsToText();

	return newDealerText;
}

void PokerTable::createAHistoryRanking()
{
	srand(time(NULL));

	int dealerCardsTextSize = numberOfPlayers + 4;
	int playersCardsTextSize = 2;

	int randNumber = rand() % 100000;
	string historyRankingName = "PokerHistory_Code_" + to_string(randNumber) + ".txt";

	file.tryAndCatchOfSaveFile(historyRankingName, convertHandsToText(), dealerCardsTextSize);
	file.tryAndCatchOfLoadAddText(historyRankingName, convertCommunityCardsToText(), dealerCardsTextSize);
}

void PokerTable::preFloatIncreaseThePot(int index, int& actualUserBlind, int actualUser)
{//NOTE: Se puede mejorar con valores en arreglos
	if (index == 0)
	{
		if (players[actualUser]->getIsActive()) {
			validationOfThreeBigBlindButton(actualUserBlind);
			return;
		}
		cout << " Jugador no esta activo para usar el boton 3BB " << endl;

	}

	if (index == 1)
	{
		if (players[actualUser]->getIsActive()) {
			validationOfTwoPartsPotButton(actualUserBlind);
			return;
		}
		cout << " Jugador no esta activo para usar el boton 1/2 Pot " << endl;
	}

	if (index == 2)
	{
		if (players[actualUser]->getIsActive()) {
			validationOfPotButton(actualUserBlind);
			return;
		}
		cout << " Jugador no esta activo para usar el boton 1 Pot " << endl;
	}

	if (index == 3)
	{
		if (players[actualUser]->getIsActive()) {
			validationOfAllInButton(actualUserBlind);
			return;
		}
		cout << " Jugador no esta activo para usar el boton All in " << endl;
	}
	if (index == 4)
	{
		validationOfGoOut(actualUserBlind, actualUser);
		return;
	}
}

void PokerTable::posFloatIncreaseThePot(int index, int& actualUserBlind, int actualUser)
{//NOTE: Se puede mejorar con valores en arreglos
	if (index == 0)
	{
		if (players[actualUser]->getIsActive()) {
			validationOfTwoPartsPotButton(actualUserBlind);
			return;
		}
		cout << " Jugador no esta activo para usar el boton 1/2 Pot " << endl;
	}

	if (index == 1)
	{
		if (players[actualUser]->getIsActive()) {
			validationOfThreePartsPotButton(actualUserBlind);
			return;
		}
		cout << " Jugador no esta activo para usar el boton 3/4 Pot " << endl;
	}

	if (index == 2)
	{
		if (players[actualUser]->getIsActive()) {
			validationOfAllInButton(actualUserBlind);
			return;
		}
		cout << " Jugador no esta activo para usar el boton All in " << endl;
	}
	if (index == 3)
	{
		validationOfGoOut(actualUserBlind, actualUser);
		return;
	}
}

void PokerTable::drawActualPlayerHand(int index, RenderWindow& window)
{
	for (int i = 0; i < SIZE_OF_PLAYER_DECK; i++)
	{
		window.draw(players[index]->getUserHand()->getPlayerSprite()[i]);
	}
}