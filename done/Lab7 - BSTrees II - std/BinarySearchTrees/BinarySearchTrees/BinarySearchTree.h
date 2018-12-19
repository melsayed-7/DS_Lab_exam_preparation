#pragma once
#include <iostream>
using namespace std;

//From defiition of a binary tree
//A binary tree is 


template <typename T>
class BinarySearchTree
{
private:
	T Data;
	bool Empty;	//true of tree is empty
	BinarySearchTree<T> *left;
	BinarySearchTree<T> *right;
	
public:
	BinarySearchTree();
	BinarySearchTree(T value);

	bool isEmpty() const;

	void setData(T value);
	T getData() const;

	void setRight(BinarySearchTree<T> *ptr);
	BinarySearchTree<T> *& getRight();


	void setLeft(BinarySearchTree<T> *ptr);
	BinarySearchTree<T> *& getLeft();

	// Given functions
	void insert(T value); // not const

	void preorder_traverse() const;
	void inorder_traverse() const;
	void postorder_traverse() const;


	void destroyTree();

	int countNodes() const;
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	Empty = true;
	//As tree is empty, no need to set its left or right pointer yet
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(T value)
{
	setData(value);
	left= new BinarySearchTree<T>;	//create left empty subtree
	right= new BinarySearchTree<T>;	//create right empty subtree
}

template <typename T>
bool BinarySearchTree<T>::isEmpty() const
{
	return Empty;
}


template <typename T>
void BinarySearchTree<T>::setData(T value)
{
	Data = value;
	Empty = false;
}

template <typename T>
T BinarySearchTree<T>::getData() const
{
	return Data;
}


template <typename T>
void BinarySearchTree<T>::setRight(BinarySearchTree<T> *ptr)
{
	right = ptr;
}

template <typename T>
BinarySearchTree<T> *& BinarySearchTree<T>::getRight()
{
	return right;
}



template <typename T>
void BinarySearchTree<T>::setLeft(BinarySearchTree<T> *ptr)
{
	left = ptr;
}

template <typename T>
BinarySearchTree<T> *& BinarySearchTree<T>::getLeft()
{
	return left;
}


// Insert an value in a binary tree.
//The insertion criterion of Binary Search Tree
// LeftChild < Root < RightChild
template <typename T>
void BinarySearchTree<T>::insert(T value)
{
	if( isEmpty() )	//Empty tree
	{
		setData(value);	//set the value
		left= new BinarySearchTree<T>;	//create left empty subtree
		right= new BinarySearchTree<T>;	//create right empty subtree
		return;
	}
	
	if ( value < Data)
		left->insert(value);
	else
		right->insert(value);
}


// print the tree with preorder traversal.
template <typename T>
void BinarySearchTree<T>::preorder_traverse() const
{
	if( isEmpty() ) return;	//empty tree

	cout<<Data<<" ";
	left->preorder_traverse();
	right->preorder_traverse();
}


// print the tree with inorder traversal.
template <typename T>
void BinarySearchTree<T>::inorder_traverse() const
{
	if( isEmpty() ) return;	//empty tree

	left->inorder_traverse();
	cout<<Data<<" ";
	right->inorder_traverse();
}

// print the tree with postorder traversal.
template <typename T>
void BinarySearchTree<T>::postorder_traverse() const
{
	if( isEmpty() ) return;	//empty tree

	left->postorder_traverse();
	right->postorder_traverse();
	cout<<Data<<" ";
}


template <typename T>
void BinarySearchTree<T>::destroyTree()
{
	if( isEmpty() ) return;
	left->destroyTree();
	delete left;
	right->destroyTree();
	delete right;
	Empty = true;
}


template <typename T>
int BinarySearchTree<T>::countNodes() const
{
	if (isEmpty()) return 0;
	return left->countNodes() + right->countNodes() + 1;
}





