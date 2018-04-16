#include <iostream>
#include <string>
#include <cctype>
#include "LinkedStack.hpp"

using namespace std;

int main() {
	cout << "Please enter an expression in postfix notation:" << endl;

	char c;
	string num;
	LinkedStack<int> intStack;	
	
	while(c = cin.get()) {
		if(isdigit(c)) {
			num += c;
			while(isdigit(c = cin.get()))
				num += c;
			cin.unget();
			intStack.push(stoi(num));
			num = "";
		}
		else if(c == '+') {
			int x, y;
			
			y = *(intStack.pop());
			x = *(intStack.pop());
			
			intStack.push(x + y);
		}
		else if(c == '-') {
			int x, y;
			
			y = *(intStack.pop());
			x = *(intStack.pop());
			
			intStack.push(x - y);
		}
		else if(c == '*') {
			int x, y;
			
			y = *(intStack.pop());
			x = *(intStack.pop());
			
			intStack.push(x * y);
		}
		else if(c == '/') {
			int x, y;
			
			y = *(intStack.pop());
			x = *(intStack.pop());
			
			intStack.push(x / y);
		}	
		else if(c == '#')
			break;
	}
	
	cout << *(intStack.pop()) << endl;
	
	return 0;
}
