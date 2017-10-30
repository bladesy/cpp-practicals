#include <iostream>

using namespace std;

int main(void) {
	int array[10], *ap, i;
	
	/* Set the value of the pointer to the address of the first value
	of the array */
	ap = array;
	
	/* Populate the array elements using an integer pointer */
	for(i = 0; i < 10; ++i) {
		*ap = i * 2;
		cout << "array[" << i << "] = " << *(ap++) << endl;
	}
	
	return 0;
}
