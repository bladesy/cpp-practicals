#include <ostream>
#include "Person.h"

using std::ostream;
using std::endl;

int Person::age(int year) const {
	return year - birthYear;
}

bool Person::isVoter(int year) const {
	return age(year) >= VOTER_AGE;
}

bool Person::isSenior(int year) const {
	return age(year) >= SENIOR_AGE;
}

bool Person::operator==(const Person &person) const {
	return id == person.id;
}

bool Person::operator!=(const Person &person) const {
	return !(*this == person);
}

ostream &operator<<(ostream &ostream, const Person &person) {
	ostream << "First Name: " << person.firstName << endl
		<< "Last Name: " << person.lastName << endl
		<< "ID: " << person.id << endl
		<< "Birth Year: " << person.birthYear << endl;
	return ostream;
}
