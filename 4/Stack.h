#ifndef STACK
#define STACK

class Stack {
	public:
		/* Constructor */
		Stack(int size);
		/* Copy constructor */
		Stack(const Stack &o);
		/* Destructor */
		~Stack();

		void push(int i);
		int pop();

	private:
		int size, *array, top;
};

#endif
