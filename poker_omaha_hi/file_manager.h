#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class fileManager
{
private:

public:
	void save(string newFileName, string* newText, int newQuantityOfLines);
	string* load(string newFileName);
	void addText(string newFileName, string* newText, int newQuantityOfLines);
	int getQuantityOfLines(string newNameFile);
};
