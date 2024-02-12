#include"file_manager.h"

void fileManager::save(string newFileName, string* newText, int newQuantityOfLines)
{
	ofstream myFile(newFileName);

	// se puede cambiar a un try and catch
	if (myFile.fail())
	{
		throw runtime_error("ERROR AL ABRIR EL ARCHIVO EN save()");
	}

	for (int i = 0; i < newQuantityOfLines; i++)
	{
		myFile << newText[i] << "\n";
	}

	myFile.close();
}

void fileManager::tryAndCatchOfSaveFile(string newFileName, string* newText, int newQuantityOfLines)
{
	try
	{
		save(newFileName, newText, newQuantityOfLines);
	}
	catch (const runtime_error& e)
	{
		cerr << "ERROR AL GUARDAR EL ARCHIVO" << e.what() << endl;
	}
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
		throw runtime_error("ERROR AL ABRIR EL ARCHIVO EN load()");
	}

	while (getline(myFile, loadNewLine))
	{
		newText[linesCounter] = loadNewLine;
		linesCounter += 1;
	}

	myFile.close();

	return newText;
}

void fileManager::tryAndCatchOfLoadFile(string newFileName)
{
	try
	{
		load(newFileName);
	}
	catch (const runtime_error& e)
	{
		cerr << "ERROR AL CARGAR EL ARCHIVO" << e.what() << endl;
	}
}

void fileManager::addText(string newFileName, string* newText, int newQuantityOfLines)
{
	ofstream myFile;

	myFile.open(newFileName, ios::app);

	if (myFile.fail())
	{
		throw runtime_error("ERROR AL ABRIR EL ARCHIVO EN AddText()");
	}

	for (int i = 0; i < newQuantityOfLines; i++)
	{
		myFile << newText[i] << "\n";
	}

	myFile.close();
}

void fileManager::tryAndCatchOfLoadAddText(string newFileName, string* newText, int newQuantityOfLines)
{
	try
	{
		addText(newFileName, newText, newQuantityOfLines);
	}
	catch (const runtime_error& e)
	{
		cerr << "ERROR AL AGREGAR TEXTO AL ARCHIVO" << e.what() << endl;
	}
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
