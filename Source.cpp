//Evan Strom
//CIS 22B
//Group project

#include <iostream>
#include <string>
#include <fstream>
#include "book.h"

using namespace std;
int main()
{
	int choice;
	const int amount = 1024;
	book books[amount] = { book(123,"huck","lick","ass", 3, 123421,12.00, 15.00),
		book(456, "jake", "sucks", "dick", 0, 056273, 10.00, 12.00)
	};
	ifstream inputfile;
	inputfile.open("input.txt");
	ofstream outputfile;
	outputfile.open("output.txt");

	do
	{
		cout << "1) to access the cashier module " << endl;
		cout << "2) to access the inventory " << endl;
		cout << "3) to access the report module " << endl;
		cout << "4) to exit the loop " << endl;
		cout << "enter your choice: ";
		cin >> choice;
		while (choice < 1 || choice > 4)
		{
			cout << "enter  a valid number " << endl;
			cin >> choice;
		}
		if (choice == 1)
		{
			do
			{
				int idnumber, qtyAsked, qtyInstock, i;
				double subtotal, tax,thistotal, total;
				cout << "please enter isbn" << endl;
				cin >> idnumber;
				if (idnumber == books[i].getISBN)
				cout << "date : " << endl;
				cout << "Qty";
				cout << "	" << "ISBN";
				cout << "		" << "Title";
				cout << "			" << "Price" << endl;
				cout << "____________________________________________________________________________";
				cout << endl;
				cout >> books[i].gettitle;
				cout >> books[i].getISBN;
				cout >> books[i].gettitle;
				cout >> books[i].getcost;
				cout << "enter amount you wish to purchase" << endl;
				cin >> qtyAsked;
				qtyInstock = books[i].getqty;
				if (qtyInstock == 0)
					cout << "we are currently out of stock int the requested title" << endl;
				if (qtyAsked > qtyInstock)
					cout << "we regret to inform you that we dont have the quantity in stock to meet your request" << endl;
				else
					subtotal = books[i].getcost * qtyAsked;
				cout << "Serendipity Book Sellers" << endl;
				cout << "date : " << endl;
				cout << "Qty";
				cout << "	" << "ISBN";
				cout << "		" << "Title";
				cout << "			" << "Price" << endl;
				cout << "____________________________________________________________________________";
				cout << endl;
				cout >> books[i].gettitle;
				cout >> books[i].getISBN;
				cout >> books[i].gettitle;
				cout >> books[i].getcost;
				cout << "		" << "subtotal" << subtotal << endl;
				tax = subtotal*.15;
				cout << "		" << "Tax" << tax <<endl;
				total = subtotal + tax;
				cout << "		" << "Total" <<  total << endl;
				cout << "Thank you for shopping at Serendipity!" << endl;
			} while (exit != false);
		}
		else if (choice == 2)
		{

		}
		else if (choice == 3)
		{

		}
		else if (choice == 4)
		{

		}
	} while (choice != 5);
	cout << "program is ending " << endl;
	system("pause");
	return 0;
}
