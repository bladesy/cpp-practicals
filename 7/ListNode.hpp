#ifndef LIST_NODE
#define LIST_NODE

template <typename T>
class ListNode {
	public:
		ListNode(T item, ListNode<T>* prevNode, ListNode<T>* nextNode);
		~ListNode() {};

		T item;
		ListNode<T> *prevNode, *nextNode;
};

template <typename T>
ListNode<T>::ListNode(T item, ListNode<T>* prevNode,
	ListNode<T>* nextNode) : item(item), prevNode(prevNode),
	nextNode(nextNode) {}

#endif
