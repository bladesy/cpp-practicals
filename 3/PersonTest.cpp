#include <iostream>
#include "Person.h"

using namespace std;

int main(void) {
	Person johnSmith("John", "Smith", "101", 1973);
	johnSmith.set_family_name("Smanth");
	cout << "Birth Year: " << johnSmith.get_birth_year() << endl;
	cout << "Person: " << johnSmith << endl;
	
	Person mysterySmith;
	mysterySmith.set_family_name("Smith");
	cout << "Person: " << mysterySmith << endl;
	
	Person *newSmith = new Person();
	cout << "ID: " << newSmith->get_ID_number() << endl;
	delete newSmith;
	
	Person *newSmith2 = new Person();
	newSmith2->set_birth_year(1987);
	cout << "Birth Year: " << newSmith2->get_birth_year() << endl;
	delete newSmith2;
	
	Person smiths[385];
	smiths[13].set_given_name("John");
	cout << "Given Name: " << smiths[13].get_given_name() << endl;
	delete[] smiths;
	
	return 0;
}
