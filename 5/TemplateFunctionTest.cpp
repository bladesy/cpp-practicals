#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template<typename T>
int findMax(T* array, int arrayLength);

int main() {
	int arrayLength, *intArray;
	double *doubleArray;
	
	cout << "Enter array length: " << endl;
	cin >> arrayLength;
	cout << endl;
	
	intArray = new int[arrayLength];
	doubleArray = new double[arrayLength];
	
	srand(time(NULL));
	for(int i = 0; i < arrayLength; ++i) {
		intArray[i] = rand();
		cout << "Int \t" << i << ": " << intArray[i] << endl;
		
		doubleArray[i] = rand();
		cout << "Double \t" << i << ": " << doubleArray[i] << endl;
	}
	
	cout << endl;
	cout << "Int " << findMax(intArray, arrayLength)
		<< " is the largest int." << endl;
	cout << "Double " << findMax(doubleArray, arrayLength)
		<< " is the largest double." << endl;
	
	delete[] intArray;
	delete[] doubleArray;
	
	return 0;
}

template<typename T>
int findMax(T* array, int arrayLength) {
	int maxPosition;
	
	if(array == nullptr || arrayLength <= 0)
		return -1;
	
	maxPosition = 0;
	for(int i = 1; i < arrayLength; ++i)
		if(array[i] > array[maxPosition])
			maxPosition = i;
	
	return maxPosition;
}
