#include "stack_Node.h"
#include <iostream>

using namespace std;
template <class T>
class LLStack
{
	int	count;
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
LLStack<T> :: LLStack()
{
	head = NULL;
}

template <class T> 
void LLStack<T>::InsertBeg(T data)
{
	Node<T> *R = new Node<T>(data);
	R->setNext(head);
	head = R;
	count++;
}
template <class T> 
bool LLStack<T> :: isEmpty() const
{
	if (head == NULL)
		return true;
	return false;
}
template<class T>
inline LLStack<T>::~LLStack()
{
}
template <class T> 
bool LLStack<T> :: push(T data)
{
	InsertBeg(data);
	count ++;
	return true;
}
template <class T> 
bool LLStack<T> :: pop(T &data)
{
	if (isEmpty())
		return false;
	Node<T> *p = head;
	data = head->getItem();
	head = head->getNext();
	delete p; 
	count --;
	return true;
}

template <class T> 
bool LLStack<T> :: getTopItem(T &x) const
{
	if(isEmpty())
		return false;
	x = head->getItem();
	return true;
}

