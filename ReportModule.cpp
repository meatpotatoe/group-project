#include "ReportModule.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void ReportModule::inventoryList(int num, Book b[]){
	cout << endl;
	int date;
	int year;
	int month;
	int day;
	string m;
	for (int x = 0; x < num; x++){
		date = b[x].dateAdded;
		day = date % 100;
		date -= day;
		month = date % 10000;
		date -= month;
		month = month / 100;
		year = date / 10000;
		switch (month){
		case 1: m = "January";
			break;
		case 2: m = "February";
			break;
		case 3: m = "March";
			break;
		case 4: m = "April";
			break;
		case 5: m = "May";
			break;
		case 6: m = "June";
			break;
		case 7: m = "July";
			break;
		case 8: m = "August";
			break;
		case 9: m = "September";
			break;
		case 10: m = "October";
			break;
		case 11: m = "November";
			break;
		case 12: m = "December";
			break;
		}
		cout << "ISBN: " << b[x].isbn << endl << "Title: " << b[x].title << endl << "Author: " << b[x].author << endl << "Publisher: " <<
			b[x].publisher << endl << "Quantity On Hand: " << b[x].qtyOnHand << endl << "Date Added: " << m << " " << day << " " << year << endl <<
			fixed << setprecision(2) << "Wholesale Cost: " << b[x].wholesaleCost << endl << "Retail Price: " << b[x].retailPrice << endl << endl;
	}
}

void ReportModule::wholesaleValue(int num, Book b[]){
	cout << endl;
	double total = 0;
	for (int x = 0; x < num; x++){
		cout << "ISBN: " << b[x].isbn << endl << "Title: " << b[x].title << endl << "Author: " << b[x].author << endl <<
			"On Hand: " << b[x].qtyOnHand << endl << fixed << setprecision(2) << "Wholesale Cost: " << b[x].wholesaleCost << endl <<
			"Item Inventory Total : " << b[x].qtyOnHand * b[x].wholesaleCost << endl << endl;
		total += b[x].qtyOnHand * b[x].wholesaleCost;
	}
	cout << "Total Inventory Wholesale Cost: " << fixed << setprecision(2) << total << endl;
}

void ReportModule::retailValue(int num, Book b[]){
	cout << endl;
	double total = 0;
	for (int x = 0; x < num; x++){
		cout << "ISBN: " << b[x].isbn << endl << "Title: " << b[x].title << endl << "Author: " << b[x].author << endl <<
			"On Hand: " << b[x].qtyOnHand << endl << fixed << setprecision(2) << "Retail Price: " << b[x].retailPrice << endl <<
			"Item Inventory Total: " << b[x].qtyOnHand * b[x].retailPrice << endl << endl;
		total += b[x].qtyOnHand * b[x].retailPrice;
	}
	cout << "Total Inventory Retail Value: " << fixed << setprecision(2) << total << endl;
}

void ReportModule::quantityList(int num, Book b[]){
	int isbn[250];
	int qtyOnHand[250];
	string title[250];
	string author[250];
	for (int x = 0; x < num; x++){
		isbn[x] = b[x].isbn;
		qtyOnHand[x] = b[x].qtyOnHand;
		title[x] = b[x].title;
		author[x] = b[x].author;
	}
	int i;
	int temp;
	string t;
	string a;
	for (int x = 1; x < num; x++){
		for (int index = 0; index < num; index++){
			if (qtyOnHand[x] > qtyOnHand[index]){
				t = title[x];
				title[x] = title[index];
				title[index] = t;

				a = author[x];
				author[x] = author[index];
				author[index] = a;

				temp = qtyOnHand[x];
				qtyOnHand[x] = qtyOnHand[index];
				qtyOnHand[index] = temp;

				i = isbn[x];
				isbn[x] = isbn[index];
				isbn[index] = i;
			}
		}
	}
	cout << endl;
	for (int x = 0; x < num; x++){
		cout << "ISBN: " << isbn[x] << endl << "Title: " << title[x] << endl << "Author: " << author[x] << endl <<
			"On Hand: " << qtyOnHand[x] << endl << endl;
	}
}

void ReportModule::costList(int num, Book b[]){
	int isbn[250];
	double wholesaleCost[250];
	string title[250];
	string author[250];
	for (int x = 0; x < num; x++){
		isbn[x] = b[x].isbn;
		wholesaleCost[x] = b[x].wholesaleCost;
		title[x] = b[x].title;
		author[x] = b[x].author;
	}
	int i;
	double temp;
	string t;
	string a;
	for (int x = 1; x < num; x++){
		for (int index = 0; index < num; index++){
			if (wholesaleCost[x] > wholesaleCost[index]){
				t = title[x];
				title[x] = title[index];
				title[index] = t;

				a = author[x];
				author[x] = author[index];
				author[index] = a;

				temp = wholesaleCost[x];
				wholesaleCost[x] = wholesaleCost[index];
				wholesaleCost[index] = temp;

				i = isbn[x];
				isbn[x] = isbn[index];
				isbn[index] = i;
			}
		}
	}
	cout << endl;
	for (int x = 0; x < num; x++){
		cout << "ISBN: " << isbn[x] << endl << "Title: " << title[x] << endl << "Author: " << author[x] << endl <<
			fixed << setprecision(2) << "Wholesale Cost: " << wholesaleCost[x] << endl << endl;
	}
}

void ReportModule::ageList(int num, Book b[]){
	int isbn[250];
	int dateAdded[250];
	string title[250];
	string author[250];
	for (int x = 0; x < num; x++){
		isbn[x] = b[x].isbn;
		dateAdded[x] = b[x].dateAdded;
		title[x] = b[x].title;
		author[x] = b[x].author;
	}
	int i;
	int temp;
	string t;
	string a;
	for (int x = 1; x < num; x++){
		for (int index = 0; index < num; index++){
			if (dateAdded[x] < dateAdded[index]){
				t = title[x];
				title[x] = title[index];
				title[index] = t;

				a = author[x];
				author[x] = author[index];
				author[index] = a;

				temp = dateAdded[x];
				dateAdded[x] = dateAdded[index];
				dateAdded[index] = temp;

				i = isbn[x];
				isbn[x] = isbn[index];
				isbn[index] = i;
			}
		}
	}
	int date;
	int year;
	int month;
	int day;
	string m;
	cout << endl;
	for (int x = 0; x < num; x++){
		date = dateAdded[x];
		day = date % 100;
		date -= day;
		month = date % 10000;
		date -= month;
		month = month / 100;
		year = date / 10000;
		switch (month){
		case 1: m = "January";
			break;
		case 2: m = "February";
			break;
		case 3: m = "March";
			break;
		case 4: m = "April";
			break;
		case 5: m = "May";
			break;
		case 6: m = "June";
			break;
		case 7: m = "July";
			break;
		case 8: m = "August";
			break;
		case 9: m = "September";
			break;
		case 10: m = "October";
			break;
		case 11: m = "November";
			break;
		case 12: m = "December";
			break;
		}
		cout << "ISBN: " << endl << "Title: " << title[x] << endl << "Author: " << author[x] << endl <<
			"Date Added: " << m << " " << day << " " << year << endl << endl;
	}
}