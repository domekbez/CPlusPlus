#ifndef LLIST_H
#define LLIST_H

#include <iostream>
#include<fstream>
using namespace std;
#include "LListNode.h"
#include "Buntownik.h"
template<class T>
class LList
{
public:
	LList();
	~LList();
	void insertBegin(T);
	void insertSorted(T);
	void insertEnd(T _data);
	bool isEmpty() const;
	void delete_evry_n(int n);
	void fromFile(string file_name);
	template <class T>
	friend ostream& operator<<(ostream&, const LList<T>&);
protected:
	ListNode<T> *head;
	ListNode<T> *tail;
	ostream& print(ostream&) const;
};
template <class T>
LList<T>::LList()
{
	head = nullptr;
	tail = nullptr;
}
template <class T>
LList<T>::~LList()
{
	if (!isEmpty())
	{
		ListNode<T> *current = head;
		ListNode<T> *temp;

		while (current != tail)
		{
			temp = current;
			current = current->next;
			delete temp;
		}
		delete current;
	}
}
template <class T>
void LList<T>::insertBegin(T _data)
{
	if (isEmpty())
	{
		ListNode<T> *new_node = new ListNode<T>(_data);
		head = new_node;
		tail = new_node;
		head->next = head;
		head->prev = head;
	}
	else
	{
		ListNode<T> *new_node = new ListNode<T>(_data);
		head->prev = new_node;
		new_node->next = head;
		new_node->prev = tail;
		head = new_node;
	}
}
template <class T>
bool LList<T>::isEmpty() const
{
	if (head == nullptr)
		return 1;
	else
		return 0;
}
template <class T>
ostream& operator<<(ostream& out, const LList<T>& l)
{
	l.print(out);
	return out;
}
template <class T>
ostream& LList<T>::print(ostream& out) const
{
	if (isEmpty())
	{
		cout << "Lista jest pusta" << endl;

	}
	else
	{
		ListNode<T> *current = head;

		out << "Zawartosc listy: " << endl;
		while (current != tail)
		{
			out << current->data << ' ';
			current = current->next;
		}
		out << current->data << endl;
	}
	return out;
}
template <class T>
void LList<T>::insertEnd(T _data)
{
	ListNode<T>* wstaw = new ListNode<T>(_data);
	ListNode<T>* pomoc = new ListNode<T>(_data);
	if (!head)
	{
		insertBegin(_data);
		return;
	}
	pomoc = tail;

	tail = wstaw;
	pomoc->next = tail;
	tail->prev = pomoc;
	tail->next = head;
	head->prev = tail;


}
template <class T>
void LList<T>::insertSorted(T a)
{
	int k = 0;
	ListNode<T>* wstaw = new ListNode<T>(a);
	ListNode<T>* pomoc = new ListNode<T>(a);
	if (!head)
	{
		insertBegin(a);
		return;
	}
	pomoc = head;
	if (wstaw->data < head->data)
	{
		insertBegin(a);
		return;
	}
	while (!(wstaw->data < pomoc->data))
	{
		if (pomoc == tail)
		{
			k = 1;
			break;
		}
		pomoc = pomoc->next;
	}
	if (k == 1)
	{

		insertEnd(a);
		return;
	}
	pomoc->prev->next = wstaw;
	wstaw->prev = pomoc->prev;
	wstaw->next = pomoc;
	pomoc->prev = wstaw;


}
template <class T>
void LList<T>::fromFile(string file_name)
{
	fstream plik(file_name, ios::in);
	if(!plik)
	{
		cout << "Nie udalo sie otworzyc pliku" << endl;
	}
	
	T zap;
	while (plik)
	{
		plik >> zap;
		this->insertSorted(zap); 
	}


}
template <class T>
void LList<T>::delete_evry_n(int n)
{
	ListNode<T>* pom = head;
	ListNode<T>* a; 
	ListNode<T>* b;
	if (!head)
	{
		cout << "Lista jest pusta" << endl;
		return;
	}

	while (pom != pom->next)

	{
		for (int i = 0; i < n - 1; i++)
		{
			
			pom = pom->next;
		}
		a = pom->prev;
		b = pom->next;
		a->next = b;
		b->prev = a;
		cout << "Usunieto " << pom->data << endl;
		delete pom;
	}


	
}

#endif