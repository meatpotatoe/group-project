#ifndef BOOK_H
#define BOOK_H

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
	void setwholesale(double);
	double getwholesale();
	void setcost(double);
	double getcost();
	book operator+ (const int);
	book operator- (const int);


	book(const book&);
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

#endif