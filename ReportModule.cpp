#include "ReportModule.h"
#include <iostream>
using namespace std;

ReportModule::ReportModule(int n, string i[], string t[], string a[], string p[], int dA[], int qty[],
	double wC[], double rP[]){
	num = n;
	for (int x = 0; x < num; x++)
		isbn[x] = i[x];
	for (int x = 0; x < num; x++)
		title[x] = t[x];
	for (int x = 0; x < num; x++)
		author[x] = a[x];
	for (int x = 0; x < num; x++)
		publisher[x] = p[x];
	for (int x = 0; x < num; x++)
		dateAdded[x] = dA[x];
	for (int x = 0; x < num; x++)
		qtyOnHand[x] = qty[x];
	for (int x = 0; x < num; x++)
		wholesaleCost[x] = wC[x];
	for (int x = 0; x < num; x++)
		retailPrice[x] = rP[x];
}

void ReportModule::inventoryList(){
	cout << endl;
	for (int x = 0; x < num; x++){
		cout << title[x] << endl << "  " << author[x] << endl << "  On Hand: " << qtyOnHand[x] << endl;
	}
}

void ReportModule::wholesaleValue(){
	cout << endl;
	double total = 0;
	for (int x = 0; x < num; x++){
		cout << title[x] << endl << "  " << author[x] << endl << "  Wholesale Cost: " << wholesaleCost[x] << endl << "  Item Inventory Total: " <<
			qtyOnHand[x] * wholesaleCost[x] << endl;
		total += qtyOnHand[x] * wholesaleCost[x];
	}
	cout << "Total Inventory Wholesale Cost: " << total << endl;
}

void ReportModule::retailValue(){
	cout << endl;
	double total = 0;
	for (int x = 0; x < num; x++){
		cout << title[x] << endl << "  " << author[x] << endl << "  Retail Price: " << retailPrice[x] << endl << "  Item Inventory Total: " <<
			qtyOnHand[x] * retailPrice[x] << endl;
		total += qtyOnHand[x]*retailPrice[x];
	}
	cout << "Total Inventory Retail Value: " << total << endl;
}

void ReportModule::quantityList(){
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
			}
		}
	}
	cout << endl;
	for (int x = 0; x < num; x++){
		cout << title[x] << endl << "  " << author[x] << endl << "  On Hand: " << qtyOnHand[x] << endl;
	}
}

void ReportModule::costList(){
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
			}
		}
	}
	cout << endl;
	for (int x = 0; x < num; x++){
		cout << title[x] << endl << "  " << author[x] << endl << "  Wholesale Cost: " << wholesaleCost[x] << endl;
	}
}

void ReportModule::ageList(){
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
		cout << title[x] << endl << "  " << author[x] << endl << "  Date Added: " << m << " " << day << " "  << year << " " << endl;
	}
}