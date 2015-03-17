#include <iostream>
#include <string>

using namespace std;

class book
{
private:
	int isbn;
	string title;
	string author;
	string publisher;
	int dateAdded;
	int onHand;
	double wholesaleCost;
	double retailCost;
public:
	void setISBN(int foobar) { isbn = foobar; }
	int getISBN(){ return isbn; }

	void setTitle(string foobar) { title = foobar; }
	string getTitle() { return title; }

	void setAuthor(string foobar) { author = foobar; }
	string getAuthor() { return author; }

	void setPublisher(string foobar) { publisher = foobar; }
	string getPublisher() { return publisher; }

	void setDateAdded(int foobar) { dateAdded = foobar; }
	int getDateAdded() { return dateAdded; }

	void setOnHand(int foobar){ onHand = foobar; }
	int getOnHand() { return onHand; }

	void setWholesaleCost(double foobar) { wholesaleCost = foobar; }
	double getWholesaleCost() { return wholesaleCost; }

	void setRetailCost(double foobar){ retailCost = foobar; }
	double getRetailCost() { return retailCost; }

	book(int rISBN, string rTitle, string rAuthor, string rPublisher, int rDate, int rOnHand, double wC, double rC);

	book() { isbn = 0; title = " "; author = " "; publisher = " "; dateAdded = 0; onHand = 0; wholesaleCost = 0; retailCost = 0; }
};