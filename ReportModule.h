#include <string>

using namespace std;

class ReportModule{
private:
	int num;
	string isbn[250];
	string title[250];
	string author[250];
	string publisher[250];
	int dateAdded[250];
	int qtyOnHand[250];
	double wholesaleCost[250];
	double retailPrice[250];

public:
	ReportModule(int, string[], string[], string[], string[], int[], int[], double[], double[]);
	void inventoryList();
	void wholesaleValue();
	void retailValue();
	void quantityList();
	void costList();
	void ageList();
};