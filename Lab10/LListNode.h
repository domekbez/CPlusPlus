#ifndef LLIST_NODE_H
#define LLIST_NODE_H
#include <iostream>
using namespace std;
template <class T>
class LList;
template <class T>
class ListNode
{
	template <class T>
	friend class LList;

public:
	ListNode(T);

private:
	T data;
	ListNode<T>* next;
	ListNode<T>* prev;
	template <class T>
	friend ostream& operator<<(ostream& out, const ListNode<T>& ln);
};
template <class T>
ListNode<T>::ListNode(T _data)
{
	data = _data;
	next = nullptr;
	prev = nullptr;
}
template <class T>
ostream& operator<<(ostream& out, const ListNode<T>& ln)
{
	out << ln.data;
	return out;
}

#endif