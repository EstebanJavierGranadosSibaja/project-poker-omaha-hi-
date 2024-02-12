#pragma once
#include <iostream>
#include"string"
#include <stdexcept>
using namespace std;

const int NUMBER_OF_TYPES = 4;
const int NUMBER_OF_VALUES = 13;
const string ARRAY_OF_TYPES[NUMBER_OF_TYPES] = {"Hearts", "Diamonds", "Clubs", "Pikes"};
const char ARRAY_OF_VALUES[NUMBER_OF_VALUES] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'X','J', 'Q', 'K'};
const int COMMUNITY_CARD_SIZE = 5;

class Card
{
private: 
	int number;
	char value;
	string type;
	string url;

public: 
	Card();
	Card(char aValue, string aType, int aNumber, string aUrl);
	~Card();

	void setValue(char newValue);
	void setType(string newType);
	void setNumber(int newNumber);
	void setUrl(string newUrl);

	char getValue();
	string getType();
	int getNumber();
	string getUrl();
};