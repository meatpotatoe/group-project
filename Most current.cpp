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
	cout << '\t' << '\t' << '\t' << "Price" << endl;
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
	/*		try
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
	}*/
	do
	{
		cout << "1) to access the cashier module " << endl;
		cout << "2) to access the inventory " << endl;
		cout << "3) to access the report module " << endl;
		cout << "4) to exit the program " << endl;
		cout << "enter your choice: ";
		try
		{
			cin >> choice;
		}
		catch (...)
		{
			cout << "enter a valid number " << endl;
			cout << "returning to main menu ";
			choice = 4;
		}
		switch (choice){
		case 1:
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
			cout << inventory[isbnhere].getISBN() << "\t\t";
			cout << inventory[isbnhere].gettitle() << "\t\t\t";
			cout << inventory[isbnhere].getcost() << endl;
			cout << "enter amount you wish to purchase" << endl;
			cin >> qtyAsked;
			qtyInstock = inventory[isbnhere].getqty();
			cout << "\t";
			if (qtyInstock == 0)//		check to make sure we have the book in stock
				cout << "we are currently out of stock int the requested title" << endl;
			if (qtyAsked > qtyInstock)//		check to make sure we have enough in stock
				cout << "we regret to inform you that we dont have the quantity in stock to meet your request" << endl;
			else
			{
				if (qtyAsked > 5)
				{
					inventory[isbnhere] = inventory[isbnhere] - qtyAsked;//		the update of the amount of books instock
					subtotal = inventory[isbnhere].getwholesale() * qtyAsked;
					printheader();
					cout << qtyAsked << "\t";
					cout << inventory[isbnhere].getISBN() << "\t\t";
					cout << inventory[isbnhere].gettitle() << "\t\t\t";
					cout << subtotal << endl;
					cout << "	" << "subtotal " << subtotal << endl;
					tax = subtotal*.15;
					cout << "	" << "Tax " << tax << endl;
					total = subtotal + tax;
					cout << "	" << "Total " << total << endl;
					cout << "Thank you for shopping at Serendipity!" << endl;
				}
				else
				{
					inventory[isbnhere] = inventory[isbnhere] - qtyAsked;//		the update of the amount of books instock
					subtotal = inventory[isbnhere].getcost() * qtyAsked;
					printheader();
					cout << qtyAsked << "\t";
					cout << inventory[isbnhere].getISBN() << "\t\t";
					cout << inventory[isbnhere].gettitle() << "\t\t\t";
					cout << subtotal << endl;
					cout << "	" << "subtotal " << subtotal << endl;
					tax = subtotal*.15;
					cout << "	" << "Tax " << tax << endl;
					total = subtotal + tax;
					cout << "	" << "Total " << total << endl;
					cout << "Thank you for shopping at Serendipity!" << endl;
				}
			}
			break;
		case 2: inventoryMenu(inventory, inventorySize); break;
		case 3:
			ReportModule print(inventorySize, inventory);
			int thischoice;
			cout << "1) inventoryList " << endl;
			cout << "2) wholesaleValue " << endl;
			cout << "3) retailValue " << endl;
			cout << "4) quantityList " << endl;
			cout << "5) costList " << endl;
			cout << "6) age list " << endl;
			cout << "7) to exit the loop" << endl;
			cout << "enter your choice: ";
			try{
				cin >> thischoice;
			}
			catch (...)
			{
				cout << "enter a valid number " << endl;
				thischoice = 7;
			}
			switch (thischoice){
			case 1:print.inventoryList();
			case 2:print.wholesaleValue();
			case 3:print.retailValue();
			case 4:print.quantityList();
			case 5:print.costList();
			case 6:print.ageList();
			case 7:break;
			};
			break;
		case 4:break;
		}
	} while (choice != 4);
	cout << "program is ending " << endl;
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
		cout << "doing fine - read in." << endl;
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
	cout << "Enter today's date (YYYYMMDD): ";
	cin >> userInputI;
	inventory[size].setdate(userInputI);
	cout << "Enter the number of copies on hand: ";
	cin >> userInputI;
	inventory[size].setqty(userInputI);
	cout << "Enter the book's wholesale cost: ";
	cin >> userInputD;
	inventory[size].setwholesale(userInputD);
	cout << "Enter the book's retail cost: ";
	cin >> userInputD;
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
				cout << endl << "Enter how many copies we have on hand: ";
				cin >> userInputI;
				inventory[a].setqty(userInputI); break;
			case 6:
				cout << endl << "Enter the new wholesale price: ";
				cin >> userInputD;
				inventory[a].setwholesale(userInputI); break;
			case 7:
				cout << endl << "Enter the new retail price: ";
				cin >> userInputD;
				inventory[a].setcost(userInputI); break;
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