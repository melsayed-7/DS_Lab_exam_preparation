#pragma once

#include "TreeNode.h"
#include <iostream>
using namespace std;

template <typename T>
class BSTree
{
public:
	TreeNode<T>* root;

	// Given functions
	static void rec_insertBST(TreeNode<T> *& subRoot, T key);
	static void rec_inorder_traverse(TreeNode<T>* subRoot);
	static void rec_preorder_traverse(TreeNode<T>* subRoot);
	static void rec_postorder_traverse(TreeNode<T>* subRoot);	
	static void rec_destroy_tree(TreeNode<T> *& subRoot);
	BSTree();
	~BSTree();
	void insertBST(T key); // not const

	//iterative solution for the in-pre-post order traverse in adam drozdek

	void inorder_traverse() const;
	void preorder_traverse() const;
	void postorder_traverse() const;	
	void destroy_tree(); 

	/*****************************************************************************
	*******************************************************************************
	*********************************************************************************/


	int countNode(TreeNode<T>* x);
	int countLeaf(TreeNode<T>* x);
	int countFull(TreeNode<T>* x); // node is full when there is a left and right children for it

	int sum(TreeNode<T>* x);

	TreeNode<T>*& search(TreeNode<T>* x, T value);
	int height(TreeNode<T> *x);
	int max(TreeNode<T> *x);  //most right
	int min(TreeNode<T> *x); //most left
	void lessthan(TreeNode<T>*x,T value);

	bool pathsum(TreeNode<T>*x, int sum);

};


// Utility Functions - Recursive Functions --------------------------

// Given functions

//* Insert a key in a binary search tree.
// [Note]: subRoot is passed by ref because 
//         the new TreeNode<T> may be inserted in the subRoot (if subRoot is empty NULL)


template <typename T>
int BSTree<T>::countNode(TreeNode<T> *x)
{
	if (x == NULL)
		return 0;
	else
		return 1 + countNode(x->getleft()) + countNode(x->getright());
}
template <typename T>
int BSTree<T>::countLeaf(TreeNode<T> *x)
{
	if (x == NULL)
		return 0;
	if (x->getleft() == NULL && x->getright() == NULL)
		return 1;
	else
		return countLeaf(x->getleft()) + countLeaf(x->getright());
}
template <typename T>
int BSTree<T>::countFull(TreeNode<T> *x)
{
	if (x == NULL)
		return 0;
	int count = 0;
	if (x->getleft() && x->getright())
		count++;
	count = count + countFull(x->getright()) + countFull(x->getleft());
	return count;
}
template<typename T>
int BSTree<T>::sum(TreeNode<T> *x)
{
	if (x == NULL)
		return 0;
	return x->getdata() + sum(x->getleft()) + sum(x->getright());
}
template<typename T>
TreeNode<T>*& BSTree<T>::search(TreeNode<T>* x, T value)
{
	TreeNode<T>* temp = x;
	while (temp != nullptr)
	{
		if (value > temp->getdata())
			temp = temp->getright();
		else if (value < temp->getdata())
			temp = temp->getleft();
	}
	if (temp->getdata() == value)
		return &temp;
	else
		return nullptr;
}
template<typename T>
int BSTree<T>::height(TreeNode<T>*x)
{
	if (x == nullptr)
		return 0;
	else
	{
		int left = height(x->getleft());
		int right = height(x->getright());
		if (left > right)
			return left + 1;
		else
			return right + 1;
	}
}
template <typename T>
int BSTree<T>::max(TreeNode<T> *x)
{
	TreeNode<T>* temp = x;
	while (temp->getright() != nullptr)
	{
		temp = temp->getright();
	}
	return temp->getdata();
}
template <typename T>
int BSTree<T>::min(TreeNode<T> *x)
{
	TreeNode<T>* temp = x;
	while (temp->getleft() != nullptr)
	{
		temp = temp->getleft();
	}
	return temp->getdata();
}
template<typename T>
void BSTree<T>::lessthan(TreeNode<T>*x , T value) 
{
	if (x == nullptr)
		return;
	lessthan(x->getright(), value);
	if (x->getdata() < value)
		cout << x->getdata() << " ";
	lessthan(x->getleft(), value);
}
template<typename T>
bool BSTree<T>::pathsum(TreeNode<T>*x, int sum)
{
	if (x == NULL)
	{
		return (sum == 0);
	}

	else
	{
		bool ans = false;
		int subSum = sum - x->getdata();
		if (subSum == 0 && x->getleft() == NULL && x->getright() == NULL)
			return true;
		if (x->getleft())
			ans = ans || hasPathSum(x->getleft(), subSum);
		if (x->getright())
			ans = ans || hasPathSum(x->getright(), subSum);
		return ans;
	}
}



template <typename T>
void BSTree<T>::rec_insertBST(TreeNode<T> *& subRoot, T key)
{
	if (subRoot == NULL)
		subRoot = new TreeNode<T>(key); // this line is why we sent subRoot by reference (subRoot = something)
	else if (subRoot->getdata() < key)
		rec_insertBST(subRoot->getright(), key);	
		//notic that getright returns an alias. Otherwise, this call will yield a comp. error
	else
		rec_insertBST(subRoot->getleft(), key);

}

//* print the tree with inorder traversal.
template <typename T>
void BSTree<T>::rec_inorder_traverse(TreeNode<T>* subRoot)
{
	if (subRoot == NULL) return;
	rec_inorder_traverse(subRoot->getleft());
	cout << subRoot->getdata() << " ";
	rec_inorder_traverse(subRoot->getright());
}

//* print the tree with preorder traversal.
template <typename T>
void BSTree<T>::rec_preorder_traverse(TreeNode<T>* subRoot)
{
	if (subRoot == NULL) return;
	cout << subRoot->getdata() << "  ";
	rec_preorder_traverse(subRoot->getleft());
	rec_preorder_traverse(subRoot->getright());
}

//* print the tree with postorder traversal.
template <typename T>
void BSTree<T>::rec_postorder_traverse(TreeNode<T>* subRoot)
{
	if (subRoot == NULL) return;
	rec_postorder_traverse(subRoot->getleft());
	rec_postorder_traverse(subRoot->getright());
	cout << subRoot->getdata() << "  ";
}

//* Deletes all the TreeNode<T>s in the tree.
// [Note]: subRoot is passed by ref because 
//         after deleting subRoot TreeNode<T> we will make it point to NULL (change subRoot)
template <typename T>
void BSTree<T>::rec_destroy_tree(TreeNode<T> *& subRoot)
{
	if (subRoot != NULL)
	{
		// recursive call on left
		//TreeNode<T> * sub_left = subRoot->getleft();
		rec_destroy_tree(subRoot->getleft());
		//subRoot->setleft(sub_left);

		// recursive call on right
		//TreeNode<T> * sub_right = subRoot->getright();
		rec_destroy_tree(subRoot->getright());
		//subRoot->setright(sub_right);

		delete subRoot;
		subRoot = NULL; // this line is why we passed subRoot by reference (subRoot = something)
	}
}
//////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
BSTree<T>::BSTree(void)
{
	root = NULL;
}


template <typename T>
BSTree<T>::~BSTree(void)
{
	destroy_tree();
}

// Public Functions ---------------------------------

// Given functions
template <typename T>
void BSTree<T>::insertBST(T key) // not const
{
	// not const because rec_insertBST takes the root by reference, so may change it
	rec_insertBST(root, key);
}
template <typename T>
void BSTree<T>::inorder_traverse() const
{
	rec_inorder_traverse(root);
}
template <typename T>
void BSTree<T>::preorder_traverse() const
{
	rec_preorder_traverse(root);
}
template <typename T>
void BSTree<T>::postorder_traverse() const
{
	rec_postorder_traverse(root);
}
template <typename T>
void BSTree<T>::destroy_tree() // not const
{
	// not const because rec_destroy_tree takes the root by reference, so may change it
	rec_destroy_tree(root); 
}



