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
void book::setdate(int sixth){
	date = sixth;
}
int book::getdate(){
	return(date);
}
void book::setqty(int third){
	qty = third;
}
int book::getqty(){
	return (qty);
}
void book::setwhole(double eighth){
	whole = eighth;
}
double book::getwhole(){
	return(whole);
}
void book::setcost(double forth){
	cost = forth;
}
double book::getcost(){
	return(cost);
}

book::book(int first,
	string second,
	string third,
	string forth,
	int fifth,
	int sixth,
	double seven,
	double eighth){
	ISBN = first;
	title = second;
	author = third;
	publisher = forth;
	date = fifth;
	qty = sixth;
	whole = seven;
	cost = eighth;
}
book::book(){
	ISBN = 0;
	title = "no title";
	author = "no author";
	publisher = "no publisher";
	date = 0;
	qty = 0;
	whole = 0;
	cost = 0;
}