#include <iostream>
#include "area.h"

using namespace std;

int main(void) {
	int length, width;
	
	/* Define measurements by collecting the user's input */
	cout << "Please enter a length:" << endl;
	cin >> length;
	cout << "Please enter a width:" << endl;
	cin >> width;
	
	/* Output the area returned from the area function */
	cout << "The area of the resulting rectangle is " << 
		area(length, width) << "!" << endl;
	
	return 0;
}

int area(int length, int width) {
	return length * width;
}
