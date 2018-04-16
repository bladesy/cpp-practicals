#ifndef ARRAY_STACK
#define ARRAY_STACK

#include <iostream>

using namespace std;

template<typename T>
class ArrayStack {
	public:
		ArrayStack();
		ArrayStack(int length);
		~ArrayStack();

		int length();
		bool stackEmpty();
		void push(T val);
		T* pop();
		T* top();
		int searchStack(T item);

	private:
		const static int defaultMaxLength = 100;
		int maxLength, topIndex;
		T* stack;
};

template<typename T>
ArrayStack<T>::ArrayStack() : maxLength(defaultMaxLength), topIndex(0),
	stack(new T[maxLength]) {}

template<typename T>
ArrayStack<T>::ArrayStack(int length) : maxLength(length), topIndex(0),
	stack(new T[maxLength]) {}

template<typename T>
ArrayStack<T>::~ArrayStack() {
	delete[] stack;
}

template<typename T>
int ArrayStack<T>::length() {
	return topIndex;
}

template<typename T>
bool ArrayStack<T>::stackEmpty() {
	return topIndex == 0;
}

template<typename T>
void ArrayStack<T>::push(T item) {
	if(topIndex == maxLength) {
		cout << "Stack overflow." << endl;
		return;
	}
	
	stack[topIndex++] = item;
}

template<typename T>
T* ArrayStack<T>::pop() {
	if(topIndex == 0) {
		cout << "Stack underflow." << endl;
		return nullptr;
	}
	
	return &stack[--topIndex];
}

template<typename T>
T* ArrayStack<T>::top() {
	if(topIndex == 0) {
		cout << "Stack empty." << endl;
		return nullptr;
	}
	
	return &stack[topIndex - 1];
}

template<typename T>
int ArrayStack<T>::searchStack(T item) {
	for(int i = topIndex - 1; i >= 0; --i)
		if(stack[i] == item)
			return i;
	
	return -1;
}

#endif
