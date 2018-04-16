#include <iostream>
#include "LinkedStack.hpp"

using namespace std;

template<typename T>
void setUpStack(LinkedStack<T>* linkedStack, int length);

template<typename T>
void printStack(LinkedStack<T>& linkedStack);

template<typename T>
void removeAt(LinkedStack<T>& linkedStack, int position);

int main() {
	LinkedStack<string> days;
	
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
void setUpStack(LinkedStack<T>* linkedStack, int items) {
	if(!linkedStack->stackEmpty()) {
		cout << "Stack is not empty." << endl;
		return;
	}
	
	for(int i = 0; i < items; ++i) {
		cout << "Enter item:" << endl;
		T item;
		cin >> item;
		linkedStack->push(item);
	}
}

template<typename T>
void printStack(LinkedStack<T>& linkedStack) {
	cout << "Stack = { ";
	
	int arrayLength = linkedStack.length();
	LinkedStack<T> tempArrayStack;
	while(!linkedStack.stackEmpty()) {
		T tempItem = *(linkedStack.pop());
		tempArrayStack.push(tempItem);
		cout << tempItem << " ";
	}
	cout << "}" << endl;
	
	while(linkedStack.length() < arrayLength)
		linkedStack.push(*(tempArrayStack.pop()));
}

template<typename T>
void removeAt(LinkedStack<T>& linkedStack, int position) {
	int tempLength = linkedStack.length() - (position + 1);
	LinkedStack<T> tempArrayStack;
	
	for(int i = 0; i < tempLength; ++i)
		tempArrayStack.push(*(linkedStack.pop()));
	linkedStack.pop();
	
	for(int i = 0; i < tempLength; ++i)
		linkedStack.push(*(tempArrayStack.pop()));
}
