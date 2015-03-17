#include <string>

using namespace std;

class ReportModule{
private:
	int num;
	int isbn[250];
	string title[250];
	string author[250];
	string publisher[250];
	int dateAdded[250];
	int qtyOnHand[250];
	double wholesaleCost[250];
	double retailPrice[250];

public:
	ReportModule(int, book[]);
	void inventoryList();
	void wholesaleValue();
	void retailValue();
	void quantityList();
	void costList();
	void ageList();
};