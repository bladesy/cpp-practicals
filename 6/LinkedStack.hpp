#ifndef LINKED_STACK
#define LINKED_STACK

#include <iostream>
#include "StackNode.hpp"

using namespace std;

template<typename T>
class LinkedStack {
	public:
		LinkedStack();
		~LinkedStack();

		int length();
		bool stackEmpty();
		void push(T val);
		T* pop();
		T* top();
		int searchStack(T item);

	private:
		int stackLength;
		T tempItem;
		StackNode<T>* topItem;
};

template <typename T>
LinkedStack<T>::LinkedStack() : stackLength(0), topItem(nullptr) {}

template<typename T>
LinkedStack<T>::~LinkedStack() {
	while(topItem != nullptr) {
		StackNode<T>* itemForDeletion = topItem;
		topItem = topItem->nextItem;
		delete itemForDeletion;
	}
}

template<typename T>
int LinkedStack<T>::length() {
	return stackLength;
}

template<typename T>
bool LinkedStack<T>::stackEmpty() {
	return stackLength == 0;
}

template<typename T>
void LinkedStack<T>::push(T item) {
	StackNode<T>* newItem = new StackNode<T>(item, topItem);
	topItem = newItem;
	++stackLength;
}

template<typename T>
T* LinkedStack<T>::pop() {
	if(topItem == nullptr) {
		cout << "Stack Underflow" << endl;
		return nullptr;
	}

	tempItem = topItem->item;
	
	StackNode<T>* poppedItem = topItem;
	topItem = topItem->nextItem;
	delete poppedItem;
	--stackLength;
	
	return &tempItem;
}

template<typename T>
T* LinkedStack<T>::top() {
	if(topItem == nullptr) {
		cout << "Stack Underflow" << endl;
		return nullptr;
	}
	
	return &topItem->item;
}

template<typename T>
int LinkedStack<T>::searchStack(T item) {
	StackNode<T>* currentItem = topItem;
	
	for(int i = stackLength - 1; i >= 0; --i) {
		if(currentItem->item == item)
			return i;
		currentItem = currentItem->nextItem;
	}
	
	return -1;
}

#endif
