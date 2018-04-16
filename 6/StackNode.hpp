#ifndef STACK_NODE
#define STACK_NODE

template<typename T>
class StackNode {
	public:
		StackNode(T item, StackNode<T>* nextItem);
		~StackNode() {};

		T item;
		StackNode<T>* nextItem;
};

template<typename T>
StackNode<T>::StackNode(T item, StackNode<T>* nextItem) : item(item),
	nextItem(nextItem) {}

#endif
