#ifndef CYCLIC_QUEUE
#define CYCLIC_QUEUE

class CyclicQueue {
	public:
		CyclicQueue(int maxLength);
		~CyclicQueue();
		
		int length();
		bool isEmpty();
		
		void addAtEnd(int item);
		
		int* getAtFront();
		int* removeAtFront();
		
	private:
		int *buffer, maxLength, firstPosition, lastPosition,
			itemCount;
};

#endif
