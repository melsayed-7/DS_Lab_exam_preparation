#pragma once
#ifndef NULL
#define NULL 0
#endif

template <typename T>
class TreeNode
{
private:
	T data;
	TreeNode<T> *left;
	TreeNode<T> *right;
public:
	TreeNode<T>();
	TreeNode<T>(T value);
	void setdata(T d);
	T getdata();
	void setleft(TreeNode<T>* p);
	TreeNode<T>*& getleft();
	void setright(TreeNode<T>* p);
	TreeNode<T>*& getright();
};


template <typename T>
TreeNode<T>::TreeNode()
{
	left = right = NULL;
}

template <typename T>
TreeNode<T>::TreeNode(T value)
{
	data = value;
	left = right = NULL;
}

template <typename T>
void TreeNode<T>::setdata(T d)
{
	data = d;
}

template <typename T>
T TreeNode<T>::getdata()
{
	return data;
}

template <typename T>
void TreeNode<T>::setleft(TreeNode<T>* p)
{
	left = p;
}

template <typename T>
TreeNode<T>*& TreeNode<T>::getleft()
{
	return left;
}

template <typename T>
void TreeNode<T>::setright(TreeNode<T>* p)
{
	right = p;
}

template <typename T>
TreeNode<T>*& TreeNode<T>::getright()
{
	return right;
}
