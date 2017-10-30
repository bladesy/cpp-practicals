#include <iostream>
#include "arrayCompare.h"

#define ARRAY_SIZE 8

using namespace std;

int main(void) {
	int firstArray[] = {121, 144, 19, 161, 19, 144, 19, 11},
		secondArray[] = {11, 121, 144, 19, 161, 19, 144, 19};
	
	/* Print the arrays */
	for(int i = 0; i < ARRAY_SIZE; ++i)
		cout << "firstArray[" << i << "] = " << firstArray[i] << endl;
	cout << endl;
	
	for(int i = 0; i < ARRAY_SIZE; ++i)
		cout << "secondArray[" << i << "] = " << secondArray[i] << endl;
	cout << endl;
	
	/* Compare the arrays */
	if(sameElements(firstArray, secondArray, ARRAY_SIZE))
		cout << "These arrays have the exact same elements in the same"
			<< " quantities." << endl;
	else
		cout << "These arrays do not have the exact same elements in"
			<< " the same quantities." << endl;

	return 0;
}
