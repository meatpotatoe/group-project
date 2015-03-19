#include "book.h"

using namespace std;

void book::setISBN(int first){
	ISBN = first;
}
int book::getISBN(){
	return(ISBN);
}
void book::settitle(string second){
	title = second;
}
string book::gettitle(){
	return(title);
}
void book::setauthor(string third){
	author = third;
}
string book::getauthor(){
	return(author);
}
void book::setpublisher(string forth){
	publisher = forth;
}
string book::getpublisher(){
	return(publisher);
}
void book::setdate(int fifth){
	date = fifth;
}
int book::getdate(){
	return(date);
}
void book::setqty(int sixth){
	qty = sixth;
}
int book::getqty(){
	return (qty);
}
void book::setwholesale(double seventh){
	whole = seventh;
}
double book::getwholesale(){
	return(whole);
}
void book::setcost(double eighth){
	cost = eighth;
}
double book::getcost(){
	return(cost);
}
book book::operator+ (const int stocked){
	book temp(*this);
	temp.qty += stocked;
	return temp;
}
book book::operator- (const int bought){
	book temp(*this);
	temp.qty -= bought;
	return temp;
}
book::book(const book& orb) : ISBN(orb.ISBN), title(orb.title), author(orb.author), publisher(orb.publisher), date(orb.date), qty(orb.qty), whole(orb.whole), cost(orb.cost) {}
book::book(int first,
	string second,
	string third,
	string forth,
	int fifth,
	int sixth,
	double seventh,
	double eighth){
	ISBN = first;
	title = second;
	author = third;
	publisher = forth;
	qty = fifth;
	date = sixth;
	whole = seventh;
	cost = eighth;
}
book::book(){
	ISBN = 0;
	title = "no title";
	author = "no author";
	publisher = "no publisher";
	date = 0;
	qty = 0;
	whole = 0.0;
	cost = 0.0;
}