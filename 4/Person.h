#ifndef PERSON
#define PERSON

#include <string>
#include <iosfwd>

using std::string;
using std::ostream;

/* Person models the basic state of a person, mainly name and age
related */
class Person {
	public:
		/* Constructors */
		/* Parametised */
		Person(string firstName, string lastName, string id, 
		int birthYear) : firstName(firstName), lastName(lastName),
		id(id), birthYear(birthYear) {}
		/* Default */
		Person() : firstName(""), lastName(""), id(""), birthYear(0) {}

		/* Accessor Functions */
		int getBirthYear() const {
			return birthYear;
		}
		string getFirstname() const { 
			return firstName; 
		}
		string getLastName() const {
			return lastName;
		}
		string getId() const { 
			return id;
		}
		
		/* Modifier Functions */
		void setBirthYear(const int &birthYear) { 
			this->birthYear = birthYear;
		}
		void setFirstName(const string &firstName) { 
			this->firstName = firstName;
		}
		void setLastName(const string &lastName) { 
			this->lastName = lastName;
		}
		void setId(const string &id) { 
			this->id = id;
		}

		/* Member Functions */
		/* Functions base their answer on the year passed in as the
		parameter */
		int age(int year) const;
		bool isVoter(int year) const;
		bool isSenior(int year) const;
		
		/* Operator Overloading */
		bool operator==(const Person &person) const;
		bool operator!=(const Person &person) const;
		bool operator>=(const Person &person) const;
		bool operator<=(const Person &person) const;
		
		/* Friend Functions */
		/* Note that friend functions are not neccessarily member
		functions */
		friend ostream &operator<<(ostream &ostream,
			const Person &person);

	private:
		/* Constants */
		/* Minimum age required to vote */
		static const int VOTER_AGE = 18;
		/* Minimum age required to be considered a senior citizen */
		static const int SENIOR_AGE = 65;
		
		/* State */
		int birthYear;
		string firstName, lastName, id;
};

#endif
