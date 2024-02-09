#include"file_manager.h"

void fileManager::save(string newFileName, string* newText, int newQuantityOfLines)
{
	ofstream myFile(newFileName);

	if (myFile.fail())
	{
		cerr << "ERROR AL MOMENTO DE ABRIR EL ARCHIVO " << newFileName << ".txt";
		return;
	}

	for (int i = 0; i < newQuantityOfLines; i++)
	{
		myFile << newText[i] << "\n";
	}

	myFile.close();
}

string* fileManager::load(string newFileName)
{
	string* newText;
	string loadNewLine;
	int linesCounter = 0;
	ifstream myFile;

	newText = new string[getQuantityOfLines(newFileName)];

	myFile.open(newFileName, ios::in);

	if (myFile.fail())
	{
		cerr << "ERROR AL MOMENTO DE ABRIR EL ARCHIVO " << newFileName << ".txt";
		return newText;
	}

	while (getline(myFile, loadNewLine))
	{
		newText[linesCounter] = loadNewLine;
		linesCounter += 1;
	}

	myFile.close();

	return newText;
}

void fileManager::addText(string newFileName, string* newText, int newQuantityOfLines)
{
	ofstream myFile;

	myFile.open(newFileName, ios::app);

	if (myFile.fail())
	{
		cerr << "ERROR AL MOMENTO DE ABRIR EL ARCHIVO " << newFileName << ".txt";
		return;
	}
	for (int i = 0; i < newQuantityOfLines; i++)
	{
		myFile << newText[i] << "\n";
	}

	myFile.close();
}

int fileManager::getQuantityOfLines(string newFileName)
{
	int quantityOfLines = 0;
	string loadNewLine;
	ifstream myFile;

	myFile.open(newFileName, ios::in);

	if (myFile.fail())
	{
		cerr << "ERROR AL MOMENTO DE ABRIR EL ARCHIVO " << newFileName << ".txt";
		return 0;
	}

	while (getline(myFile, loadNewLine))
	{
		quantityOfLines += 1;
	}

	myFile.close();

	return quantityOfLines;
}
