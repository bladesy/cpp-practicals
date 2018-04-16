#include <iostream>
#include <cstdlib>
#include "SafeArrayTemplate.hpp"

using namespace std;

template<typename T>
SafeArray<T>::SafeArray(int length) : length(length) {
	if(length > 0)
		array = new T[length];
	else {
		cout << "Invalid array length." << endl;
		exit(1);
	}
}

template<typename T>
SafeArray<T>::~SafeArray() {
	delete[] array;
}

template<typename T>
SafeArray<T>::SafeArray(const SafeArray& safeArray) {
	length = safeArray.length;
	array = new T[length];
}

template<typename T>
SafeArray<T>& SafeArray<T>::operator=(const SafeArray& safeArray) {
	delete[] array;
	
	length = safeArray.length;
	array = new T[length];
}

template<typename T>
SafeArray<T>::SafeArray(const SafeArray&& safeArray)
	: length(safeArray.length), array(safeArray.array) {
	safeArray.length = 0;
	safeArray.array = nullptr;
}

template<typename T>
SafeArray<T>& SafeArray<T>::operator=(const SafeArray&& safeArray) {
	length = safeArray.length;
	array = safeArray.array;
	
	safeArray.length = 0;
	safeArray.array = nullptr;
}

template<typename T>
T& SafeArray<T>::operator[](int index) {
	if(index < 0 || index >= length) {
		cout << "Index out of bounds." << endl;
		exit(1);
	}
	
	return array[index];
}
