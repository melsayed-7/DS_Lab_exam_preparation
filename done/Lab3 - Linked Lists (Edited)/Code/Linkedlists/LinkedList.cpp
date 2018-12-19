#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList()
{
	count = 0;
	Head = NULL;
}

//List is being desturcted ==> delete all items in the list
LinkedList::~LinkedList()
{
	DeleteAll();
}
////////////////////////////////////////////////////////////////////////
/*
* Function: PrintList.
* prints the values of all nodes in a linked list.
*/
void LinkedList::PrintList()
{
	cout<<"\nList has "<<count<<" nodes";
	cout<<"\nprinting list contents:\n\n";
	Node *p = Head;
	
	while(p != NULL)
	{
		cout << "[ " << p->getItem() << " ]";
		cout << "--->";
		p = p->getNext();
	}
	cout << "*\n";
}
////////////////////////////////////////////////////////////////////////
/*
* Function: InsertBeg.
* Creates a new node and adds it to the beginning of a linked list.
* 
* Parameters:
*	- data : The value to be stored in the new node.
*/
void LinkedList::InsertBeg(int data)
{
	Node *R = new Node(data);
	R->setNext(Head);
	Head = R;
	count++;

}
////////////////////////////////////////////////////////////////////////
/*
* Function: DeleteAll.
* Deletes all nodes of the list.
*/
void LinkedList::DeleteAll()
{
	Node *P = Head;
	while (Head != NULL)
	{
		P = Head->getNext();
		delete Head;
		Head = P;
	}
	count = 0;
}
void LinkedList::InsertEnd(int data)
{
	Node *P = Head;
	Node *newnode = new Node(data);
	if (Head != NULL)
	{
		while (P->getNext() != NULL)
		{
			P = P->getNext();
		}
		newnode->setNext(NULL);
		P->setNext(newnode);
	}
	else
	{
		Head = newnode;
		newnode->setNext(NULL);
	}
}
bool LinkedList::Find(int Key)
{
	Node* P = Head;
	while (P)
	{
		if (P->getItem() == Key)
			return true;
		P = P->getNext();
	}
	return false;
}
int LinkedList::CountOccurance(int value)
{
	Node* P = Head;
	int occs = 0;
	while (P)
	{
		if (P->getItem() == value)
			occs++;
		P = P->getNext();
	}
	return occs;
}
void LinkedList::DeleteFirst()
{
	if (!Head)
		return;
	Node* P = Head;
	Head = Head->getNext();
	delete P;
	count--;
}
void LinkedList::DeleteLast()
{
	if (!Head)
		return;
	if (Head->getNext() == NULL)
	{
		Node* R = Head;
		Head = Head->getNext();
		delete R;
		count--;
		return;
	}
	Node* P = Head;
	while (P->getNext()->getNext() != NULL)
	{
		P = P->getNext();
	}
	Node * R = P->getNext();
	P->setNext(NULL);
	delete R;
}
bool LinkedList::DeleteNode(int ID)
{
	if(Head != NULL && Head->getItem() == ID)
	{
		Node * R = Head;
		Head = Head->getNext();
		delete R;
		count--;
		return true;
	}
	Node* P = Head;
	while (P != NULL)
	{
		if (P->getNext()!= NULL && P->getNext()->getItem() == ID)
		{
			Node * R = P->getNext();
			P->setNext(P->getNext()->getNext());
			delete R;
			count--;
			return true;
		}
		P = P->getNext();
	}
	return false;
}

bool LinkedList::DeleteNodes(int value)
{
	if (Find(value))
	{
		while (Find(value))
		{
			DeleteNode(value);
		}
		return true;
	}
	return false;
}


