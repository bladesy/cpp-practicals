#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>
#include "ListNode.hpp"

using namespace std;

template <typename T>
class LinkedList {
	public:
		LinkedList();
		~LinkedList();

		int getLength();
		
		void addAtFront(T item);
		void addAtEnd(T item);
		void addAt(int position, T item);

		T* removeAtFront();
		T* removeAtEnd();
		T* removeAt(int position);

		T* getAtFront();
		T* getAtEnd();
		T* getAt(int position);

		void setAtStart();
		void setAtEnd();

		T* getNext();
		T* getPrevious();

	private:
		ListNode<T>* findAt(int p);
		
		int length;
		T tempItem;
		ListNode<T> *firstNode, *currentNode, *lastNode;
};

template <typename T>
LinkedList<T>::LinkedList() : length(0), firstNode(nullptr),
	currentNode(nullptr), lastNode(nullptr) {}

template <typename T>
LinkedList<T>::~LinkedList() {
	ListNode<T> *nodeForDeletion = firstNode;
	while(nodeForDeletion != nullptr) {
		ListNode<T>* nextNode = nodeForDeletion->nextNode;
		delete nodeForDeletion;
		nodeForDeletion = nextNode;
	}
}

template<typename T>
int LinkedList<T>::getLength() {
	return length;
}

template <typename T>
void LinkedList<T>::addAtFront(T item) {
	ListNode<T> *newFirstNode = new ListNode<T>(item, nullptr,
		firstNode);
	
	if(firstNode != nullptr)
		firstNode->prevNode = newFirstNode;
	
	firstNode = newFirstNode;
	
	if(lastNode == nullptr)
		lastNode = newFirstNode;
	
	++length;
}

template <typename T>
void LinkedList<T>::addAtEnd(T item) {
	if(length == 0)
		addAtFront(item);
	else {
		ListNode<T> *newLastNode = new ListNode<T>(item, lastNode,
			nullptr);
		lastNode->nextNode = newLastNode;
		lastNode = newLastNode;
		++length;
	}
}

template <typename T>
void LinkedList<T>::addAt(int position, T item) {
	if(position == 0)
		addAtFront(item);
	else if(position == length)
		addAtEnd(item);
	else {
		ListNode<T> *tempNode = findAt(position);
		if (tempNode != nullptr) {
			ListNode<T>* newNode = new ListNode<T>(item,
				tempNode->prevNode, tempNode);
			tempNode->prevNode->nextNode = newNode;
			tempNode->prevNode = newNode;
			++length;
		}
	}
}

template <typename T>
T* LinkedList<T>::removeAtFront() {
	if(length == 0) {
		cout << "No item to be removed at front of list." << endl;
		return nullptr;
	}
	
	tempItem = firstNode->item;
	ListNode<T> *tempNode = firstNode;
	if(firstNode->nextNode != nullptr)
		firstNode->nextNode->prevNode = nullptr;
	firstNode = firstNode->nextNode;
	--length;
	
	if(length == 0)
		lastNode = nullptr;
	
	delete tempNode;
	return &tempItem;
}

template <typename T>
T* LinkedList<T>::removeAtEnd() {
	if(length == 0) {
		cout << "No item to be removed at end of list." << endl;
		return nullptr;
	}
	
	tempItem = lastNode->item;
	ListNode<T> *tempNode = lastNode;
	if(lastNode->prevNode != nullptr)
		lastNode->prevNode->nextNode = nullptr;
	lastNode = lastNode->prevNode;
	--length;
	
	if (length == 0)
		firstNode = nullptr;
	
	delete tempNode;
	return &tempItem;
}

template <typename T>
T* LinkedList<T>::removeAt(int position) {
	if(position < 0 || position >= length) {
		cout << "No item to be removed at list position " << position
			<< "." << endl;
		return nullptr;
	}
	
	if(position == 0)
		return removeAtFront();
	else if(position == length - 1)
		return removeAtEnd();

	ListNode<T> *tempNode = findAt(position);
	tempItem = tempNode->item;
	tempNode->prevNode->nextNode = tempNode->nextNode;
	tempNode->nextNode->prevNode = tempNode->prevNode;
	--length;

	delete tempNode;
	return &tempItem;
}

template <typename T>
T* LinkedList<T>::getAtFront() {
	if(length > 0) {
		currentNode = firstNode;
		return &(firstNode->item);
	}
	
	return nullptr;
}

template <typename T>
T* LinkedList<T>::getAtEnd() {
	if(length > 0) {
		currentNode = lastNode;
		return &lastNode->item;
	}
	
	return nullptr;
}

template <typename T>
T* LinkedList<T>::getAt(int position) {
	if(position < 0 || position >= length) {
		cout << "No item at list position " << position << "." << endl;
		return nullptr;
	}
	
	if(position == 0)
		return getAtFront();
	else if(position == length - 1)
		return getAtEnd();

	ListNode<T> *tempNode = findAt(position);
	currentNode = tempNode;
	
	return &(currentNode->item);
}

template <typename T>
void LinkedList<T>::setAtStart() {
	currentNode = firstNode;
}

template <typename T>
void LinkedList<T>::setAtEnd() {
	currentNode = lastNode;
}

template <typename T>
T* LinkedList<T>::getNext() {
	if(currentNode != nullptr) {
		ListNode<T> *tempNode = currentNode;
		currentNode = currentNode->nextNode;
		return &tempNode->item;
	}
	
	return nullptr;
}

template <typename T>
T* LinkedList<T>::getPrevious() {
	if(currentNode != nullptr) {
		ListNode<T> *tempNode = currentNode;
		currentNode = currentNode->prevNode;
		return &tempNode->item;
	}
	
	return nullptr;
}

template <typename T>
ListNode<T>* LinkedList<T>::findAt(int position) {
	if(position < 0 || position >= length) {
		cout << "List item does not exist at position " << position
			<< "." << endl;
		return nullptr;
	}
	
	ListNode<T> *node = firstNode;
	for(int i = 0; i < position && node != nullptr; ++i)
		node = node->nextNode;
	
	if(node == nullptr)
		cout << "List item does not exist at position " << position
			<< "." << endl;
	
	return node;
}

#endif
