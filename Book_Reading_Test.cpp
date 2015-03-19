#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
#include "book.h"

using namespace std;

int readSize();
void readInventory(book inventory[1024]);
void inventoryMenu(book inventory[1024], int size);
void writeInventory(book inventory[1024], int size);
void addBook(book inventory[1024], int &size);
void removeBook(book inventory[1024], int &size);
void readBook(book inventory[1024], int size);
void modifyData(book inventory[1024], int size);

int main()
{
	book inventory[1024];
	int inventorySize = readSize();
	readInventory(inventory);
	inventoryMenu(inventory, inventorySize);
	return 0;
}

int readSize()
{
	int size;
	ifstream inFile;
	inFile.open("inventory.txt");
	inFile >> size;
	inFile.close();
	return size;
}

void readInventory(book inventory[1024])
{
	int size = 0;
	string placeHolder = " ";
	int isbn = 0;
	string title = " ";
	string author = " ";
	string publisher = " ";
	int dateAdded = 0;
	int onHand = 0;
	double wholesaleCost = 0;
	double retailCost = 0;
	ifstream inFile;
	inFile.open("inventory.txt");
	if (!inFile)
	{
		cout << "OH SHIT" << endl;
	}
	else
	{
		cout << "doing fine - opened" << endl;
		system("pause");
		getline(inFile, placeHolder);
		size = stoi(placeHolder);
		cout << "doing fine - size read" << endl;
		system("pause");
		for (int a = 0; a < size; a++)
		{
			getline(inFile, placeHolder);
			isbn = stoi(placeHolder);
			inventory[a].setISBN(isbn);
			getline(inFile, title);
			inventory[a].setTitle(title);
			getline(inFile, author);
			inventory[a].setAuthor(author);
			getline(inFile, publisher);
			inventory[a].setPublisher(publisher);
			getline(inFile, placeHolder);
			dateAdded = stoi(placeHolder);
			inventory[a].setDateAdded(dateAdded);
			getline(inFile, placeHolder);
			onHand = stoi(placeHolder);
			inventory[a].setOnHand(onHand);
			getline(inFile, placeHolder);
			wholesaleCost = stod(placeHolder);
			inventory[a].setWholesaleCost(wholesaleCost);
			getline(inFile, placeHolder);
			retailCost = stod(placeHolder);
			inventory[a].setRetailCost(retailCost);
		}
		cout << "doing fine - read in." << endl;
	}
	inFile.close();
}

void inventoryMenu(book inventory[1024], int size)
{
	int userInputI = 0;
	do
	{
		cout << "Welcome to the Serendipity Inventory Database!" << endl;
		cout << "==============================================" << endl;
		cout << "(1) Display Full Inventory" << endl;
		cout << "(2) Add a book to the Inventory" << endl;
		cout << "(3) Remove a book from the Inventory" << endl;
		cout << "(4) Retrieve info on a particular book" << endl;
		cout << "(5) Change the details of a particular book" << endl;
		cout << "(0) Return to main menu";
		cout << endl << endl << endl;
		try
		{ 
			cout << "Enter your selection:  ";
			cin >> userInputI;
		}
		catch (...)
		{
			cout << endl << "Please remember to only enter integers.";
			cout << endl << "Returning to main menu.";
			userInputI = 0;
		}
		switch (userInputI)
		{
			case 1: writeInventory(inventory, size); break;
			case 2: addBook(inventory, size); break;
			case 3: removeBook(inventory, size); break;
			case 4:readBook(inventory, size); break;
			case 5:modifyData(inventory, size); break;
			case 0: break;
		}

	} while (userInputI != 0);
}

void writeInventory(book inventory[1024], int size)
{
	ofstream outFile;
	outFile.open("inventory.txt", ios::trunc);
	outFile << size << endl;
	for (int a = 0; a < size; a++)
	{
		outFile << inventory[a].getISBN() << endl;
		outFile << inventory[a].getTitle() << endl;
		outFile << inventory[a].getAuthor() << endl;
		outFile << inventory[a].getPublisher() << endl;
		outFile << inventory[a].getDateAdded() << endl;
		outFile << inventory[a].getOnHand() << endl;
		outFile << inventory[a].getWholesaleCost() << endl;
		outFile << inventory[a].getRetailCost() << endl;
	}
	outFile.close();
} 

void addBook(book inventory[1024], int &size)
{
	int userInputI;
	double userInputD;
	string userInputS;
	cout << "Please enter the following for the book you'd like to add to our inventory:" << endl << endl;
	cout << "Enter the ISBN: ";
	cin >> userInputI;
	inventory[size].setISBN(userInputI);
	cin.ignore();
	cout << "Enter the book's title: ";
	getline(cin, userInputS);
	inventory[size].setTitle(userInputS);
	cout << "Enter the author's name:  ";
	getline(cin, userInputS);
	inventory[size].setAuthor(userInputS);
	cout << "Enter the name of the publisher:  ";
	getline(cin, userInputS);
	inventory[size].setPublisher(userInputS);
	cout << "Enter today's date (YYYYMMDD):  ";
	cin >> userInputI;
	inventory[size].setDateAdded(userInputI);
	cout << "Enter the number of copies on hand:  ";
	cin >> userInputI;
	inventory[size].setOnHand(userInputI);
	cout << "Enter the book's wholesale cost:  ";
	cin >> userInputD;
	inventory[size].setWholesaleCost(userInputD);
	cout << "Enter the book's retail cost:  ";
	cin >> userInputD;
	inventory[size].setRetailCost(userInputD);
	cout << endl << endl << inventory[size].getTitle() << " has been added to our inventory!" << endl;
	size++;
	cout << endl << endl << endl << "Returning to the inventory menu...";
	system("pause");
}

void removeBook(book inventory[1024], int &size)
{
	int userInputI;
	char userInputC;
	int index = -1;
	bool found = false;
	string removedTitle;
	cout << "Please enter the ISBN of the book you'd like to remove from our inventory:  ";
	cin >> userInputI;
	for (int a = 0; (a < size && !found); a++)
	{
		if (inventory[a].getISBN() == userInputI)
		{
			found = true;
			index = a;
		}
	}
	if (index >= 0 && found)
	{
		cout << "Are you sure you want to remove " << inventory[index].getTitle() << "from our inventory?" << endl;
		cout << "Enter Y for yes, any other character for no:  ";
		cin >> userInputC;
		if (userInputC == 'y' || userInputC == 'Y')
		{
			for (int b = index; b < (size - 1); b++)
			{
				inventory[b].setISBN(inventory[b + 1].getISBN());
				inventory[b].setTitle(inventory[b + 1].getTitle());
				inventory[b].setAuthor(inventory[b + 1].getAuthor());
				inventory[b].setPublisher(inventory[b + 1].getPublisher());
				inventory[b].setDateAdded(inventory[b + 1].getDateAdded());
				inventory[b].setOnHand(inventory[b + 1].getOnHand());
				inventory[b].setWholesaleCost(inventory[b + 1].getWholesaleCost());
				inventory[b].setRetailCost(inventory[b + 1].getRetailCost());
			}
			removedTitle = inventory[size].getTitle();
			inventory[size].setISBN(0);
			inventory[size].setTitle(" ");
			inventory[size].setAuthor(" ");
			inventory[size].setPublisher(" ");
			inventory[size].setDateAdded(0);
			inventory[size].setWholesaleCost(0);
			inventory[size].setRetailCost(0);
			size--;
			cout << "The book " << removedTitle << " has been removed from our inventory." << endl;
			system("pause");
		}
		else
		{
			cout << "Returning to the inventory menu..." << endl;
			system("pause");
		}
	}
	else
	{
		cout << "ISBN not found, returning to the inventory menu.." << endl;
		system("pause");
	}
}

void readBook(book inventory[1024], int size)
{
	int ISBN;
	bool found = false;
	cout << "Please enter the ISBN of the book in question:  ";
	cin >> ISBN;
	for (int a = 0; a < size && !found; a++)
	{
		if (inventory[a].getISBN() == ISBN)
		{
			cout << "Book Found!" << endl << endl;
			cout << "Title:  " << inventory[a].getTitle() << endl;
			cout << "Author:  " << inventory[a].getAuthor() << endl;
			cout << "Publisher:  " << inventory[a].getPublisher() << endl;
			cout << "# copies on hand:  " << inventory[a].getOnHand() << endl;
			cout << "Wholesale Price:  " << inventory[a].getWholesaleCost() << endl;
			cout << "Retail Price:  " << inventory[a].getRetailCost() << endl;
		}
	}
	if (!found)
	{
		cout << "Sorry, we do not have the requested book in our inventory at this time." << endl << endl;
	}
	cout << endl << endl << endl << "Returning to the inventory menu...";
	system("pause");
}

void modifyData(book inventory[1024], int size)
{
	int ISBN;
	bool found = false;
	int userInputI = 0;
	double userInputD = 0;
	string userInputS = " ";
	int dataChanger = -1;
	cout << "Please enter the ISBN of the book in question:  ";
	cin >> ISBN;
	for (int a = 0; a < size && !found; a++)
	{
		if (inventory[a].getISBN() == ISBN)
		{
			found = true;
			cout << "Book Found!" << endl << endl;
			cout << "Title:  " << inventory[a].getTitle() << endl;
			cout << "Author:  " << inventory[a].getAuthor() << endl;
			cout << "Publisher:  " << inventory[a].getPublisher() << endl;
			cout << "# copies on hand:  " << inventory[a].getOnHand() << endl;
			cout << "Wholesale Price:  " << inventory[a].getWholesaleCost() << endl;
			cout << "Retail Price:  " << inventory[a].getRetailCost() << endl;
			cout << endl << endl << "What data would you like to modify regarding this book?" << endl;
			cout << "(1) Book's ISBN" << endl;
			cout << "(2) Book's Title" << endl;
			cout << "(3) Author's Name" << endl;
			cout << "(4) Book's Publisher" << endl;
			cout << "(5) # copies on hand" << endl;
			cout << "(6) Wholesale Price" << endl;
			cout << "(7) Retail Price" << endl;
			cout << "(0) Return to the Inventory Menu without changing this book." << endl;
			do
			{
				try
				{
					cout << endl << "Enter your selection:  ";
					cin >> dataChanger;
				}
				catch (...)
				{ 
					cout << "Please remember to only enter integers when making menu selections.";
					dataChanger = 0;
				}
			} while (dataChanger < 0 || dataChanger > 7);
			cin.ignore();
			switch (dataChanger)
			{
				case 1:
					cout << endl << "Enter the new ISBN:  ";
					cin >> userInputI;
					inventory[a].setISBN(userInputI); break;
				case 2:
					cout << endl << "Enter the new title:  ";
					getline(cin, userInputS);
					inventory[a].setTitle(userInputS); break;
				case 3:
					cout << endl << "Enter the new author's name:  ";
					getline(cin, userInputS);
					inventory[a].setAuthor(userInputS); break;
				case 4:
					cout << endl << "Enter the name of the new publisher:  ";
					getline(cin, userInputS);
					inventory[a].setPublisher(userInputS); break;
				case 5:
					cout << endl << "Enter how many copies we have on hand:  ";
					cin >> userInputI;
					inventory[a].setOnHand(userInputI); break;
				case 6:
					cout << endl << "Enter the new wholesale price:  ";
					cin >> userInputD;
					inventory[a].setWholesaleCost(userInputI); break;
				case 7:
					cout << endl << "Enter the new retail price:  ";
					cin >> userInputD;
					inventory[a].setRetailCost(userInputI); break;
				case 0: break;
			}
			
		}
	}
	if (!found)
	{
		cout << "Sorry, we do not have the requested book in our inventory at this time." << endl << endl;
	}
	cout << endl << endl << endl << "Returning to the inventory menu...";
	system("pause");
}