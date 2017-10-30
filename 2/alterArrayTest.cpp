#include <iostream>
#include "alterArray.h"

using namespace std;

int main(void) {
	int *array, arrayLength;
	
	/* Prompt the user, then collect their input */
	cout << "Please enter the length of your array:" << endl;
	cin >> arrayLength;
	cout << endl;
	
	/* Assign the integer pointer memory based on the user's input to
	create a dynamic array */
	array = new int[arrayLength];
	
	/* Populate the initial dynamic array, and print its contents */
	for(int i = 0; i < arrayLength; ++i) {
		array[i] = i * 2;
		cout << "array[" << i << "] = " << array[i] << endl;
	}
	
	/* Insert the value 144 at array[6] */
	insert(array, arrayLength, 6, 144);
	cout << endl;
	
	/* Print the contents of the extended array */
	for(int i = 0; i < arrayLength; ++i)
		cout << "array[" << i << "] = " << array[i] << endl;
	
	/* Remove the value at array[10] */
	remove(array, arrayLength, 10);
	cout << endl;
	
	/* Print the contents of the shortened array */
	for(int i = 0; i < arrayLength; ++i)
		cout << "array[" << i << "] = " << array[i] << endl;
	
	/* Delete the array */
	delete[] array;

	return 0;
}
