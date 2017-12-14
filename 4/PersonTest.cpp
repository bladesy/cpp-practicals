#include <iostream>
#include "Person.h"

using namespace std;

int main(void) {
	Person person1("first1", "family1", "1001", 2001),
		person2("first2", "family2", "1002", 2002);
	
	cout << (person1 >= person2) << endl;
	cout << (person1 <= person2) << endl;
	
	return 0;
}
