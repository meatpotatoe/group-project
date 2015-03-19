#include <string>
#include "Book.h"

using namespace std;

class ReportModule{
public:
	ReportModule(){}
	void inventoryList(int, Book[]);
	void wholesaleValue(int, Book[]);
	void retailValue(int, Book[]);
	void quantityList(int, Book[]);
	void costList(int, Book[]);
	void ageList(int, Book[]);
};