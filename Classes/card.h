#pragma once

#include <iostream>
using namespace std;

class Card
{
private: 
	int number;
	int value;
	string color;
	string type;
	string url;

public: 
	Card();
	Card(int aValue, string aColor, string aType, int aNumber, string aUrl);
	~Card();

	void setValue(int newValue);
	void setColor(string newColor);
	void setType(string newType);
	void setNumber(int newNumber);
	void setUrl(string newUrl);

	int getValue();
	string getColor();
	string getType();
	int getNumber();
	string getUrl();

};