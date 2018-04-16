#include "CyclicQueue.hpp"

CyclicQueue::CyclicQueue(int maxLength) : buffer(new int[maxLength]),
	maxLength(maxLength), firstPosition(0), lastPosition(0),
	itemCount(0) {}

CyclicQueue::~CyclicQueue() {
	delete[] buffer;
}

int CyclicQueue::length() {
	return itemCount;
}

bool CyclicQueue::isEmpty() {
	return itemCount == 0;
}

void CyclicQueue::addAtEnd(int item) {
	if(itemCount != maxLength) {
		lastPosition = (lastPosition + 1) % maxLength;
		buffer[lastPosition] = item;
		++itemCount;
	}
}

int* CyclicQueue::getAtFront() {
	if(itemCount > 0)
		return &buffer[firstPosition];
	
	return nullptr;
}

int* CyclicQueue::removeAtFront() {
	int *firstItem = nullptr;
	
	if(itemCount > 0) {
		firstItem = &buffer[firstPosition];
		firstPosition = (firstPosition + 1) % maxLength;
		--itemCount;
	}
		
	return firstItem;
}
