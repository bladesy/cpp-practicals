#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack(int size)
{
	this->size = size;
	/* Dynamic memory allocation - memory must be cleaned up in the
	destructor */
	array = new int[size];
	top = 0;
}

Stack::Stack(const Stack &o) {
	size = o.size;
	array = new int[size];
	top = 0;
}

Stack::~Stack()
{
	delete[] array;
}

void Stack::push(int i)
{
	if (top == size) {
		cout << "Stack overflow" << endl;
		return;
	}
	
	array[top++] = i;
}

int Stack::pop()
{
	if (top == 0) {
		cout << "Stack underflow" << endl;
		return 0;
	}
	
	return array[--top];
}
