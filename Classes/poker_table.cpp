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
		players[i] = new Player();
	}

	dealer->shuffleDeck(deck);
	dealer->setCommunityCards(deck);
	dealer->createDealerSprites();
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
}

void PokerTable::startPreFloatRound()
{
	dealer->setCommunityCards(deck);

	/*dealer->getPlayerCards(players, numberOfPlayers, deck);

	for (int i = 0; i < 5; i++)
	{
		cout << dealer->getCommunityCards()[i]->getType() << " - ";
	}
	cout << endl << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << dealer->getCommunityCards()[i]->getNumber() << " - ";
	}
	cout << endl << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << dealer->getCommunityCards()[i]->getValue() << " - ";
	}
//void PokerTable::startPreFloatRound()
//{
//	dealer->setCommunityCards(deck);
//
//
//
//	dealer->getPlayerCards(players, numberOfPlayers, deck);
//
//	for (int i = 0; i < 5; i++)
//	{
//		cout << dealer->getCommunityCards()[i]->getType() << " - ";
//	}
//	cout << endl << endl;
//	for (int i = 0; i < 5; i++)
//	{
//		cout << dealer->getCommunityCards()[i]->getNumber() << " - ";
//	}
//	cout << endl << endl;
//	for (int i = 0; i < 5; i++)
//	{
//		cout << dealer->getCommunityCards()[i]->getValue() << " - ";
//	}
//
//	cout << endl << endl << endl << endl;;
//
//	for (int i = 0; i < numberOfPlayers; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			cout << players[i]->getUserHand()->getHand()[j]->getNumber() << " - ";
//
//		}
//		cout << endl << endl;
//	}
//
//	for (int i = 0; i < numberOfPlayers; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			cout << players[i]->getUserHand()->getHand()[j]->getType() << " - ";
//
//		}
//		cout << endl << endl;
//	}
//}

	cout << endl << endl << endl << endl;;

	for (int i = 0; i < numberOfPlayers; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << players[i]->getUserHand()->getHand()[j]->getNumber() << " - ";

		}
		cout << endl << endl;
	}

	for (int i = 0; i < numberOfPlayers; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << players[i]->getUserHand()->getHand()[j]->getType() << " - ";

		}
		cout << endl << endl;
	}*/
}

bool PokerTable::validationOfThreeBigBlindButton(int &actualUserBlind)
{
	if (actualUserBlind >= bigBlind * 3)
	{
		actualUserBlind -= bigBlind * 3;
		pot += bigBlind * 3;
		return true;
	}

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

	return false;
}

bool PokerTable::validationOfAllInButton(int& actualUserBlind)
{
	if (actualUserBlind != 0)
	{
		actualUserBlind -= actualUserBlind;
		pot += actualUserBlind;
		return true;
	}

	return false;
}

string* PokerTable::convertHandsToText()
{
	string* newText = new string[numberOfPlayers + 4];
	int lastPosition = 0;

	newText[0] = "  ||  RANKING HISTORIAL DE LAS MANOS DE LOS JUGADORES  ||  \n";

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

	newDealerText[0] = "  ||  RANKING HISTORIAL DE LAS CARTAR COMUNITARIAS DEL DEALER  || \n";

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

	cout << dealerCardsTextSize;

	file.save(historyRankingName, convertHandsToText(), dealerCardsTextSize);
	file.addText(historyRankingName, convertCommunityCardsToText(), playersCardsTextSize);
}

void PokerTable::preFloatIncreaseThePot(int index, int& actualUserBlind)
{
	if (index == 0)
	{
		validationOfThreeBigBlindButton(actualUserBlind); 
		return; 
	}

	if (index == 1)
	{
		validationOfTwoPartsPotButton(actualUserBlind); 
		return;
	}

	if (index == 2)
	{
		validationOfPotButton(actualUserBlind); 
		return;
	}

	if (index ==3)
	{
		validationOfAllInButton(actualUserBlind); 
		return;
	}

	




}
