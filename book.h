#include <iostream>
#include <string>

using namespace std;

class book{
private:
	int ISBN;
	string title;
	string author;
	string publisher;
	int date;
	int qty;
	double whole;
	double cost;
public:
	void setISBN(int);
	int getISBN();
	void settitle(string);
	string gettitle();
	void setauthor(string);
	string getauthor();
	void setpublisher(string);
	string getpublisher();
	void setdate(int);
	int getdate();
	void setqty(int);
	int getqty();
	void setcost(double);
	double getcost();
	void setwhole(double);
	double getwhole();

	book(int, 
		string,
		string,
		string,
		int,
		int,
		double,
		double);
	book();
};