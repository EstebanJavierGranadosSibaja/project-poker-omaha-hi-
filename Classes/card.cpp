#include"Card.h"

Card::Card()
{
	value = 0;
	color = "";
	type = "";
	number = 0;
	url = "";
}

Card::Card(int aValue, string aColor, string aType, int aNumber, string aUrl)
{
	value = aValue;
	color = aColor;
	type = aType;
	number = aNumber;
	url = aUrl;
}

Card::~Card()
{
}

void Card::setValue(int newValue)
{
	value = newValue;
}

void Card::setColor(string newColor)
{
	color = newColor;
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

int Card::getValue()
{
	return value;
}

string Card::getColor()
{
	return color;
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