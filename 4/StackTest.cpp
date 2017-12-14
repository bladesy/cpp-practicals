#include <iostream>
#include "Stack.h"

using namespace std;

/* Assigns the location of the Stack a to the Stack b object before
exiting, causing the Stack b to go out of scope and call its destructor.
If Stack did not have a copy constructor, this would destroy the 
internal array of Stack a as a side-effect of destroying Stack b */
void copy(Stack &a);

/* Illustrates the need for copy constructors */
int main(void) {
	Stack s(2);
	
	s.push(4);
	s.push(13);
	copy(s);
	cout << s.pop() << endl;
	
	return 0;
}

void copy(Stack &a) {
	Stack b = a;
}
