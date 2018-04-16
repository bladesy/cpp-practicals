#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	set<int> intSet;
	
	intSet.insert(1);
	intSet.insert(2);
	intSet.insert(3);
	
	cout << "intSet = { ";
	set<int>::iterator setIterator;
	for(setIterator = intSet.begin(); setIterator != intSet.end();
		++setIterator)
		cout << *setIterator << " ";
	cout << "}" << endl;
	
	cout << "Enter integer to search for in intSet:" << endl;
	int searchKey;
	cin >> searchKey;
	
	if(binary_search(intSet.begin(), intSet.end(), searchKey))
		cout << searchKey << " found." << endl;
	else
		cout << searchKey << " not found." << endl;
	
	return 0;
}
