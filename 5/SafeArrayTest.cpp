#include <iostream>
#include "SafeArray.hpp"

using namespace std;

int main() {
	SafeArray<int> safeIntArray(5);
	SafeArray<char> safeCharArray(5);
	SafeArray<double> safeDoubleArray(5);
	
	safeIntArray[3] = 3;
	cout << safeIntArray[3] << endl;
	
	safeCharArray[0] = 'a';
	cout << safeCharArray[0] << endl;
	
	safeDoubleArray[2] = 2.22;
	cout << safeDoubleArray[2] << endl;
	
	return 0; 
}
