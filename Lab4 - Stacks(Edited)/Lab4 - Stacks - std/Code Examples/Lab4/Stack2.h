#include "Node.h"
#include <iostream>

using namespace std;
template <class T>
class LLStack
{
	count;
	Node<T>* head; 
public: 
	LLStack();
	bool push(T x);
	bool pop(T &x);
	bool getTopItem(T &x) const;
	void InsertBeg(T data);
	bool isEmpty() const;

	~LLStack();
};

//////////////////////////////////////////////////////////

template <class T> 
LLStack :: LLStack()
{
	head = NULL;
}
template <class T> 
void LLStack::InsertBeg(T data)
{
	Node<T> *R = new Node<T>(data);
	R->setNext(head);
	head = R;
	count++;
}
template <class T> 
bool LLStack :: isEmpty() const
{
	if (head == NULL)
		return true;
	return false;
}
template <class T> 
void LLStack :: push(T data)
{
	InsertBeg(T data);
	count ++;
}
template <class T> 
bool LLStack :: pop(T &data)
{
	Node<T> *p = head;
	data = head->getItem();
	head = head->getNext();
	delete p; 
	count --;
}

template <class T> 
bool LLStack :: getTopItem(T &x) const
{
	if(isEmpty())
		return false;
	x = head->getItem();
	return true;
}

