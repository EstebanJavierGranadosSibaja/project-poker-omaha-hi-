#include"Card.h"

Card::Card()
{
	value = 0;
	type = "";
	number = 0;
	url = "";
}

Card::Card(char aValue, string aType, int aNumber, string aUrl)
{
	value = aValue;
	type = aType;
	number = aNumber;
	url = aUrl;
}

Card::~Card()
{
}

void Card::setValue(char newValue)
{
	value = newValue;
}

void Card::setType(string newType)
{
	type = newType;
}

void Card::setNumber(int newNumber)
{
	number = newNumber;
}

void Card::setUrl(string newUrl)
{
	url = newUrl;
}

char Card::getValue()
{
	return value;
}

string Card::getType()
{
	return type;
}

int Card::getNumber()
{
	return number;
}

string Card::getUrl()
{
	return url;
}