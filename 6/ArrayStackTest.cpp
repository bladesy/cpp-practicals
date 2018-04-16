#include <iostream>
#include "ArrayStack.hpp"

template<typename T>
void setUpStack(ArrayStack<T>* arrayStack, int length);

template<typename T>
void printStack(ArrayStack<T>& arrayStack);

template<typename T>
void removeAt(ArrayStack<T>& arrayStack, int position);

int main() {
	ArrayStack<string> days(7);
	
	setUpStack(&days, 7);
		
	printStack(days);
	removeAt(days, 3);
	printStack(days);
	
	cout << days.searchStack("mon") << endl;
	cout << days.searchStack("wed") << endl;
	cout << days.searchStack("sun") << endl;
	cout << days.searchStack("thu") << endl;
	
	return 0;
}

template<typename T>
void setUpStack(ArrayStack<T>* arrayStack, int items) {
	if(!arrayStack->stackEmpty()) {
		cout << "Stack is not empty." << endl;
		return;
	}
	
	for(int i = 0; i < items; ++i) {
		cout << "Enter item:" << endl;
		T item;
		cin >> item;
		arrayStack->push(item);
	}
}

template<typename T>
void printStack(ArrayStack<T>& arrayStack) {
	cout << "Stack = { ";
	
	int arrayLength = arrayStack.length();
	ArrayStack<T> tempArrayStack(arrayLength);
	while(!arrayStack.stackEmpty()) {
		T tempItem = *(arrayStack.pop());
		tempArrayStack.push(tempItem);
		cout << tempItem << " ";
	}
	cout << "}" << endl;
	
	while(arrayStack.length() < arrayLength)
		arrayStack.push(*(tempArrayStack.pop()));
}

template<typename T>
void removeAt(ArrayStack<T>& arrayStack, int position) {
	int tempLength = arrayStack.length() - (position + 1);
	ArrayStack<T> tempArrayStack(tempLength);
	
	for(int i = 0; i < tempLength; ++i)
		tempArrayStack.push(*(arrayStack.pop()));
	arrayStack.pop();
	
	for(int i = 0; i < tempLength; ++i)
		arrayStack.push(*(tempArrayStack.pop()));
}
