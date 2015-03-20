#include <string>
#include "Book.h"

using namespace std;

// This class is a friend class of Book class, because of this it prints and uses books properties directly
class ReportModule{
public:
	ReportModule(){}
	// Functions that print out the selected report
	void inventoryList(int, Book[]);
	void wholesaleValue(int, Book[]);
	void retailValue(int, Book[]);
	void quantityList(int, Book[]);
	void costList(int, Book[]);
	void ageList(int, Book[]);
};