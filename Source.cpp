//Evan Strom
//CIS 22B
//Group project

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

struct book
{
	string title;
	string author;
	string publisher;
	int date;
	int quantity;
	int wholesale;
	int retail;
};

int main()
{
	int choice;

	ifstream inputfile;
	inputfile.open("input.txt");
	ofstream outputfile;
	outputfile.open("output.txt");

	book a;
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
			cout << "enter the info the cashier will ask you" << endl;
			cout << "title ";
			cin >> a.title;
			cout << "author ";
			cin >> a.author;
			cout << "publisher ";
			cin >> a.publisher;
			cout << "date added ";
			cin >> a.date;
			cout << "quality on hand ";
			cin >> a.quantity;
			cout << "wholesale cost ";
			cin >> a.wholesale;
			cout << "retail price ";
			cin >> a.retail;
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