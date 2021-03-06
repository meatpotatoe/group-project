//Evan Strom
//CIS 22B
//Group project
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "book.h"
#include "reportModule.h"
using namespace std;
void printheader()
{
	cout << "Qty";
	cout << '\t' << "ISBN";
	cout << '\t' << '\t' << "Title";
	cout << '\t' << '\t' << '\t' << '\t' << "Price" << endl;
	cout << "____________________________________________________________________________";
	cout << endl;
}
int searchinv(int *arr, int numElms, int value){
	int index = 0;
	int position = -1;
	bool found = false;
	while (index < numElms && !found){
		if (arr[index] == value){
			found = true;
			position = index;
		}
		index++;
	}
	return position;
}

int readSize();
void readInventory(book inventory[1024]);
void writeInventory(book inventory[1024], int size);
void addBook(book inventory[1024], int &size);
void removeBook(book inventory[1024], int &size);
void readBook(book inventory[1024], int size);
void modifyData(book inventory[1024], int size);
void bookReturn(book inventory[1024], int size);
void inventoryMenu(book inventory[1024], int size);


int main()
{
	ReportModule print;
	int thischoice;
	const int amount = 1024;
	int choice = 4;
	int *I;
	int ISBN[1024];
	I = ISBN;
	ifstream inputfile;
	inputfile.open("input.txt");
	ofstream outputfile;
	outputfile.open("output.txt");
	book inventory[1024];
	int inventorySize = readSize();
	readInventory(inventory);
	const int cashier = 1, inv = 2, report = 3, quit = 4;
	for (int i = 0; i < inventorySize; i++){
		*(I + i) = inventory[i].getISBN();
	}

	do
	{
		system("cls");
		cout << "Welcome to the Serendipity Register Utility!" << endl;
		cout << "============================================" << endl;
		cout << "(1) Access the Register/Make a Sale" << endl;
		cout << "(2) Serendipity Inventory Database" << endl;
		cout << "(3) Retrieve Reports RE: Inventory" << endl;
		cout << "(4) Shut down Register" << endl << endl << endl;
		cout << "Enter your selection: ";
		try
		{
			cin >> choice;
		}
		catch (...)
		{
			cout << "Please enter a valid selection." << endl;
			cout << "Returning you to the main menu...";
			choice = 0;
		}
		switch (choice){
		case 1:
			system("cls");
			int idnumber, qtyAsked, qtyInstock, i, isbnhere, newchoice;
			double subtotal, tax, total;
			cout << "please enter ISBN" << endl;
			cin >> idnumber;
			isbnhere = searchinv(I, 1024, idnumber);//		checks to make sure the isbn exists
			while (isbnhere == -1){
				cout << "the entered ISBN was not found in our inventory" << endl;
				cout << "please try again ";
				cin >> isbnhere;
			}
				printheader();
				cout << inventory[isbnhere].getqty() << "\t";
				cout << inventory[isbnhere].getISBN() << "\t";
				cout << inventory[isbnhere].gettitle() << "\t";
				cout << inventory[isbnhere].getcost() << endl;
				cout << "enter amount you wish to purchase" << endl;
				cin >> qtyAsked;
				qtyInstock = inventory[isbnhere].getqty();
				if (qtyInstock == 0)//		check to make sure we have the book in stock
					cout << "we are currently out of stock in the requested title" << endl;
				if (qtyAsked > qtyInstock)//		check to make sure we have enough in stock
					cout << "we regret to inform you that we dont have the quantity in stock to meet your request" << endl;
				else
				{
					inventory[isbnhere] = inventory[isbnhere] - qtyAsked;//		the update of the amount of books instock
					subtotal = inventory[isbnhere].getcost() * qtyAsked;
					printheader();
					cout << qtyAsked << "\t";
					cout << inventory[isbnhere].getISBN() << "\t";
					cout << inventory[isbnhere].gettitle() << "\t";
					cout << subtotal << endl;
					cout << setprecision(4) << "	" << "subtotal " << subtotal << endl;
					tax = subtotal*.15;
					cout << setprecision(4) << "	" << "Tax " << tax << endl;
					total = subtotal + tax;
					cout << setprecision(4) << "	" << "Total " << total << endl;
					cout << "Thank you for shopping at Serendipity!" << endl;
				}system("pause"); break;
		case 2: system("cls");
			inventoryMenu(inventory, inventorySize); system("pause"); break;
		case 3: 
			system("cls");
				cout << "(1) Display Full Inventory" << endl;
				cout << "(2) Display Wholesale Value of Current Inventory " << endl;
				cout << "(3) Display Retail Value of Current Inventory " << endl;
				cout << "(4) Display Inventory from Highest to Lowest Stock " << endl;
				cout << "(5) Display Inventory from Highest to Lowest Wholesale Cost " << endl;
				cout << "(6) Display Inventory from Least to Most Recently Added " << endl;
				cout << "(7) Return to Main Menu" << endl << endl << endl;
				try{
					cout << "Enter your selection: ";
					cin >> thischoice;
				}
				catch (...)
				{
					cout << "Please enter a valid selection. " << endl;
					thischoice = 7;
				}
				switch (thischoice){
				case 1:print.inventoryList(inventorySize, inventory); system("pause"); break;
				case 2:print.wholesaleValue(inventorySize, inventory); system("pause"); break;
				case 3:print.retailValue(inventorySize, inventory); system("pause"); break;
				case 4:print.quantityList(inventorySize, inventory); system("pause"); break;
				case 5:print.costList(inventorySize, inventory); system("pause"); break;
				case 6:print.ageList(inventorySize, inventory); system("pause"); break;
				case 7: cout << "Returning to main menu..." << endl;
					system("pause"); break;
					};
				break;
		case 4:break;
		default: break;
		}
	} while (choice != 4);
	cout << "Thank you for using the Serendipity Register Utility!" << endl;
	system("pause");
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
	double wholesaleCost = 0.0;
	double retailCost = 0.0;
	ifstream inFile;
	inFile.open("inventory.txt");
	if (!inFile)
	{
		cout << "OH SHIT CALL I.T.!!!" << endl;
	}
	else
	{
		getline(inFile, placeHolder);
		size = stoi(placeHolder);
		for (int a = 0; a < size; a++)
		{
			getline(inFile, placeHolder);
			isbn = stoi(placeHolder);
			inventory[a].setISBN(isbn);
			getline(inFile, title);
			inventory[a].settitle(title);
			getline(inFile, author);
			inventory[a].setauthor(author);
			getline(inFile, publisher);
			inventory[a].setpublisher(publisher);
			getline(inFile, placeHolder);
			dateAdded = stoi(placeHolder);
			inventory[a].setdate(dateAdded);
			getline(inFile, placeHolder);
			onHand = stoi(placeHolder);
			inventory[a].setqty(onHand);
			getline(inFile, placeHolder);
			wholesaleCost = stod(placeHolder);
			inventory[a].setwholesale(wholesaleCost);
			getline(inFile, placeHolder);
			retailCost = stod(placeHolder);
			inventory[a].setcost(retailCost);
		}
	}
	inFile.close();
}
void writeInventory(book inventory[1024], int size)
{
	ofstream outFile;
	outFile.open("inventory.txt", ios::trunc);
	outFile << size << endl;
	for (int a = 0; a < size; a++)
	{
		outFile << inventory[a].getISBN() << endl;
		outFile << inventory[a].gettitle() << endl;
		outFile << inventory[a].getauthor() << endl;
		outFile << inventory[a].getpublisher() << endl;
		outFile << inventory[a].getdate() << endl;
		outFile << inventory[a].getqty() << endl;
		outFile << inventory[a].getwholesale() << endl;
		outFile << inventory[a].getcost() << endl;
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
	inventory[size].settitle(userInputS);
	cout << "Enter the author's name: ";
	getline(cin, userInputS);
	inventory[size].setauthor(userInputS);
	cout << "Enter the name of the publisher: ";
	getline(cin, userInputS);
	inventory[size].setpublisher(userInputS);
	do
	{
		cout << "Enter today's date (YYYYMMDD): ";
		cin >> userInputI;
	}while (userInputI > 20150319 || userInputI < 19001231);
	inventory[size].setdate(userInputI);
	do
	{
		cout << "Enter the number of copies on hand: ";
		cin >> userInputI;
	}while (userInputI <= 0);
	inventory[size].setqty(userInputI);
	do
	{
		cout << "Enter the book's wholesale cost: ";
		cin >> userInputD;
	} while (userInputD <= 0);
	inventory[size].setwholesale(userInputD);
	do
	{
		cout << "Enter the book's retail cost: ";
		cin >> userInputD;
	} while (userInputD <= 0);
	inventory[size].setcost(userInputD);
	cout << endl << endl << inventory[size].gettitle() << " has been added to our inventory!" << endl;
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
	cout << "Please enter the ISBN of the book you'd like to remove from our inventory: ";
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
		cout << "Are you sure you want to remove " << inventory[index].gettitle() << "from our inventory?" << endl;
		cout << "Enter Y for yes, any other character for no: ";
		cin >> userInputC;
		if (userInputC == 'y' || userInputC == 'Y')
		{
			for (int b = index; b < (size - 1); b++)
			{
				inventory[b].setISBN(inventory[b + 1].getISBN());
				inventory[b].settitle(inventory[b + 1].gettitle());
				inventory[b].setauthor(inventory[b + 1].getauthor());
				inventory[b].setpublisher(inventory[b + 1].getpublisher());
				inventory[b].setdate(inventory[b + 1].getdate());
				inventory[b].setqty(inventory[b + 1].getqty());
				inventory[b].setwholesale(inventory[b + 1].getwholesale());
				inventory[b].setcost(inventory[b + 1].getcost());
			}
			removedTitle = inventory[size].gettitle();
			inventory[size].setISBN(0);
			inventory[size].settitle(" ");
			inventory[size].setauthor(" ");
			inventory[size].setpublisher(" ");
			inventory[size].setdate(0);
			inventory[size].setwholesale(0);
			inventory[size].setcost(0);
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
	cout << "Please enter the ISBN of the book in question: ";
	cin >> ISBN;
	for (int a = 0; a < size && !found; a++)
	{
		if (inventory[a].getISBN() == ISBN)
		{
			cout << "Book Found!" << endl << endl;
			cout << "Title: " << inventory[a].gettitle() << endl;
			cout << "Author: " << inventory[a].getauthor() << endl;
			cout << "Publisher: " << inventory[a].getpublisher() << endl;
			cout << "# copies on hand: " << inventory[a].getqty() << endl;
			cout << "Wholesale Price: " << inventory[a].getwholesale() << endl;
			cout << "Retail Price: " << inventory[a].getcost() << endl;
			found = true;
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
	cout << "Please enter the ISBN of the book in question: ";
	cin >> ISBN;
	for (int a = 0; a < size && !found; a++)
	{
		if (inventory[a].getISBN() == ISBN)
		{
			found = true;
			cout << "Book Found!" << endl << endl;
			cout << "Title: " << inventory[a].gettitle() << endl;
			cout << "Author: " << inventory[a].getauthor() << endl;
			cout << "Publisher: " << inventory[a].getpublisher() << endl;
			cout << "# copies on hand: " << inventory[a].getqty() << endl;
			cout << "Wholesale Price: " << inventory[a].getwholesale() << endl;
			cout << "Retail Price: " << inventory[a].getcost() << endl;
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
				cout << endl << "Enter the new ISBN: ";
				cin >> userInputI;
				inventory[a].setISBN(userInputI); break;
			case 2:
				cout << endl << "Enter the new title: ";
				getline(cin, userInputS);
				inventory[a].settitle(userInputS); break;
			case 3:
				cout << endl << "Enter the new author's name: ";
				getline(cin, userInputS);
				inventory[a].setauthor(userInputS); break;
			case 4:
				cout << endl << "Enter the name of the new publisher: ";
				getline(cin, userInputS);
				inventory[a].setpublisher(userInputS); break;
			case 5:
				do
				{
					cout << endl << "Enter the new number of copies on hand: ";
					cin >> userInputI;
				}while (userInputI < 0);
				inventory[a].setqty(userInputI); break;
			case 6:
				do
				{
					cout << endl << "Enter the book's new wholesale cost: ";
					cin >> userInputD;
				} while (userInputD <= 0);
				inventory[a].setwholesale(userInputD); break;
			case 7:
				do
				{
					cout << endl << "Enter the book's new retail cost: ";
					cin >> userInputD;
				} while (userInputD <= 0);
				inventory[a].setcost(userInputD); break;
			case 0: break;
			}
			found = true;
		}
	}
	if (!found)
	{
		cout << "Sorry, we do not have the requested book in our inventory at this time." << endl << endl;
	}
	cout << endl << endl << endl << "Returning to the inventory menu...";
	system("pause");
}
void bookReturn(book inventory[1024], int size)
{
	int ISBN;
	int copiesReturned;
	bool found = false;
	cout << "Enter the ISBN of the book to be returned:  ";
	cin >> ISBN;
	for (int a = 0; a < size && !found; a++)
	{
		if (inventory[a].getISBN() == ISBN)
		{
			cout << inventory[a].gettitle() << " found!" << endl;
			cout << "How many copies is the customer returning?  ";
			cin >> copiesReturned;
			inventory[a] = inventory[a] + copiesReturned;
		}
	}
	if (!found)
	{
		cout << "This book is not in our inventory." << endl;
	}
	cout << "Returning to main menu..." << endl;
	system("pause");
}
void inventoryMenu(book inventory[1024], int size)
{
	int userInputI = 0;
	do
	{
		system("cls");
		cout << "Welcome to the Serendipity Inventory Database!" << endl;
		cout << "==============================================" << endl;
		cout << "(1) Add a book to the Inventory" << endl;
		cout << "(2) Remove a book from the Inventory" << endl;
		cout << "(3) Retrieve info on a particular book" << endl;
		cout << "(4) Change the details of a particular book" << endl;
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
		case 1: addBook(inventory, size); break;
		case 2: removeBook(inventory, size); break;
		case 3:readBook(inventory, size); break;
		case 4:modifyData(inventory, size); break;
		case 0: break;
		}

	} while (userInputI != 0);
}