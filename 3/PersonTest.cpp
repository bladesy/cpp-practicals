#include <iostream>
#include "Person.h"

using namespace std;

int main(void) {
	Person johnSmith("John", "Smith", "101", 1973);
	johnSmith.setLastName("Smanth");
	cout << "Birth Year: " << johnSmith.getBirthYear() << endl;
	cout << "Person: " << endl << johnSmith << endl;
	
	Person mysterySmith;
	mysterySmith.setLastName("Smith");
	cout << "Person: " << mysterySmith << endl;
	
	Person *newSmith = new Person();
	cout << "ID: " << newSmith->getId() << endl;
	delete newSmith;
	
	Person *newSmith2 = new Person();
	newSmith2->setBirthYear(1987);
	cout << "Birth Year: " << newSmith2->getBirthYear() << endl;
	delete newSmith2;
	
	Person smiths[385];
	smiths[13].setFirstName("John");
	cout << "Given Name: " << smiths[13].getFirstname() << endl;
	
	return 0;
}
