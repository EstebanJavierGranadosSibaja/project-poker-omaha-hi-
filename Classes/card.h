#pragma once
#include <iostream>
using namespace std;



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