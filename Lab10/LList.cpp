
/*#include "LList.h"

LList::LList()
{
	head = nullptr;
	tail = nullptr;
}

LList::~LList()
{
	if (!isEmpty())
	{
		ListNode *current = head;
		ListNode *temp;

		while (current != tail)
		{
			temp = current;
			current = current->next;
			delete temp;
		}
		delete current;
	}
}

void LList::insertBegin(int _data)
{
	if(isEmpty()) 
	{
		ListNode *new_node = new ListNode(_data); 
		head = new_node; 
		tail = new_node;
		head->next = head;
		head->prev = head;
	}
	else 
	{
		ListNode *new_node = new ListNode(_data);
		head->prev = new_node;
		new_node->next = head; 
		new_node->prev = tail;
		head = new_node; 
	}
}

bool LList::isEmpty() const
{
	if (head == nullptr)
		return 1;
	else
		return 0;
}

ostream& operator<<(ostream& out, const LList& l)
{
	l.print(out);
	return out;
}

ostream& LList::print(ostream& out) const
{
	if (isEmpty())
	{
		cout << "Lista jest pusta" << endl;

	}
	else
	{
		ListNode *current = head;

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
void LList::insertEnd(int _data)
{
	ListNode* wstaw = new ListNode(_data);
	ListNode * pomoc = new ListNode(0);
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
void LList::insertSorted(int a)
{
	int k = 0;
	ListNode* wstaw = new ListNode(a);
	ListNode* pomoc = new ListNode(0);
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
	while (wstaw->data > pomoc->data)
	{
		if (pomoc == tail)
		{
			k = 1;
			break;
		}
		pomoc = pomoc->next;
	}
	if (k==1)
	{

		insertEnd(a);
		return;
	}
	pomoc->prev->next = wstaw;
	wstaw->prev = pomoc->prev;
	wstaw->next = pomoc;
	pomoc->prev = wstaw;


}
*/
