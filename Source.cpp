//Evan Strom
//CIS 22B
//Group project
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "book.h"
using namespace std;

void printheader()
{
	cout << "date : " << endl;
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
int main()
{
	const int amount = 1024;
	int choice;
	int *I;
	int ISBN[1024];
	I = ISBN;
	book books[amount] = { book(123, "huck", "lick", "agla", 3, 123421, 12.00, 15.00),
		book(456, "jake", "bleh", "meh", 0, 056273, 10.00, 12.00)
	};

	ifstream inputfile;
	inputfile.open("input.txt");
	ofstream outputfile;
	outputfile.open("output.txt");

	for (int i = 0; i < 3; i++){
		*(I + i) = books[i].getISBN();
	}

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
			int idnumber, qtyAsked, qtyInstock, i, isbnhere;
			double subtotal, tax, thistotal, total;
			cout << "please enter isbn" << endl;
			cin >> idnumber;
			isbnhere = searchinv(I, 1024, idnumber);
			if (isbnhere == -1){
				cout << "the entered ISBN was not found in our inventory" << endl;
				cout << "please try again ";
				cin >> idnumber;
			}
			else
			{
				isbnhere = searchinv(I, 1024, idnumber);
				printheader();
				cout << books[isbnhere].getqty() << "\t";
				cout << books[isbnhere].getISBN() << "\t\t";
				cout << books[isbnhere].gettitle() << "\t\t\t";
				cout << books[isbnhere].getcost() << endl;
				cout << "enter amount you wish to purchase" << endl;
				cin >> qtyAsked;
				qtyInstock = books[isbnhere].getqty();
				cout << "\t";
				if (qtyInstock == 0)
					cout << "we are currently out of stock int the requested title" << endl;
				if (qtyAsked > qtyInstock)
					cout << "we regret to inform you that we dont have the quantity in stock to meet your request" << endl;
				else
				{
					books[isbnhere].setqty(qtyInstock - qtyAsked);
					subtotal = books[isbnhere].getcost() * qtyAsked;
					printheader();
					cout << qtyAsked << "\t";
					cout << books[isbnhere].getISBN() << "\t\t";
					cout << books[isbnhere].gettitle() << "\t\t\t";
					cout << subtotal << endl;
					cout << "		" << "subtotal" << subtotal << endl;
					tax = subtotal*.15;
					cout << "		" << "Tax" << tax << endl;
					total = subtotal + tax;
					cout << "		" << "Total" << total << endl;
					cout << "Thank you for shopping at Serendipity!" << endl;
				}
			}
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