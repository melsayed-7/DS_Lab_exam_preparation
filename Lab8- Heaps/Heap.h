#ifndef HEAP_H
#define HEAP_H

#include "HeapItem.h"
template <class T>

class Heap
{
private:
	HeapItem<T> * m_Elements;                 // Pointer to dynamically allocated array
	int          m_iNumElements;              // Number of elements in the heap
	int          m_iHeapLength;               // Size of the array

public:
	Heap(int size = 10);                     // Parameterized constructor
	~Heap();                                 // Destructor
	void ReheapDown(int root, int bottom);   // Reheap after removing item
	void ReheapUp(int root, int bottom);     // Reheap after inserting item
	bool Enqueue(HeapItem<T> *item);            // Add an item to the heap
	bool Enqueue(int key, double data);      // Add an item to the heap
	HeapItem<T> *Dequeue();                     // Get item at the root
	int getNumElements();                    // Return number of elements in the heap
	void printAll();                         // Print all the elements in the heap
};

#endif
//---------------------------------------
// Parameterized default constructor
//---------------------------------------
template <class T>

Heap<T>::Heap(int size)
{
	// Create heap of given size
	m_Elements = new HeapItem<T>[size];
	m_iNumElements = 0;
	m_iHeapLength = size;
}

//---------------------------------------
// Destructor
//---------------------------------------
template <class T>
Heap<T>::~Heap()
{
	delete[] m_Elements;
}

//---------------------------------------
// Reheap after removing item
//---------------------------------------
template <class T>
void Heap<T>::ReheapDown(int root, int bottom)
{
	int maxChild;
	int rightChild;
	int leftChild;
	HeapItem<T> temp;

	leftChild = root * 2 + 1;          // Get index of root's left child
	rightChild = root * 2 + 2;          // Get index of root's right child

										// Check base case in recursive calls.  If leftChild's index is less
										// than or equal to the bottom index we have not finished recursively 
										// reheaping.
	if (leftChild <= bottom)
	{
		if (leftChild == bottom)          // If this root has no right child then 
		{
			maxChild = leftChild;     //     leftChild must hold max key
		}
		else
		{     // Get the one lowest in the tree (highest index in the array)
			if (m_Elements[leftChild].getKey() <= m_Elements[rightChild].getKey())
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}
		if (m_Elements[root].getKey() < m_Elements[maxChild].getKey())
		{
			// Swap these two elements
			temp = m_Elements[root];
			m_Elements[root] = m_Elements[maxChild];
			m_Elements[maxChild] = temp;
			// Make recursive call till reheaping completed
			ReheapDown(maxChild, bottom);
		}
	}
}

//---------------------------------------
// Reheap after inserting item
//---------------------------------------
template <class T>
void Heap<T>::ReheapUp(int root, int bottom)
{
	int parent;
	HeapItem<T> temp;

	// Check base case in recursive calls.  If bottom's index is greater
	// than the root index we have not finished recursively reheaping.
	if (bottom > root)
	{
		parent = (bottom - 1) / 2;
		if (m_Elements[parent].getKey() < m_Elements[bottom].getKey())
		{
			// Swap these two elements
			temp = m_Elements[parent];
			m_Elements[parent] = m_Elements[bottom];
			m_Elements[bottom] = temp;
			// Make recursive call till reheaping completed
			ReheapUp(root, parent);
		}
	}
}

//---------------------------------------
// Add an item to the heap
//---------------------------------------
template <class T>
bool Heap<T>::Enqueue(HeapItem<T> *item)
{
	if (m_iNumElements < m_iHeapLength)
	{
		m_Elements[m_iNumElements] = *item; // Copy item into array
		ReheapUp(0, m_iNumElements);
		m_iNumElements++;
		return true;
	}
	return false;
}

//---------------------------------------
// Add an item to the heap
//---------------------------------------
template <class T>
bool Heap<T>::Enqueue(int key, double data)
{
	bool retVal;
	HeapItem<T> *temp = new HeapItem<T>(key, data);
	retVal = Enqueue(temp);
	delete temp;  // Delete this dynamically created one
	return retVal;
}

//---------------------------------------
// Get item at the root
//---------------------------------------
template <class T>
HeapItem<T> *Heap<T>::Dequeue()
{
	HeapItem<T> *temp = new HeapItem<T>(m_Elements[0].getKey(), m_Elements[0].getData());
	m_iNumElements--;
	// Copy last item into root
	m_Elements[0] = m_Elements[m_iNumElements];
	// Reheap the tree
	ReheapDown(0, m_iNumElements - 1);
	if (m_iNumElements == 0)
		return NULL;
	else
		return temp;
}

//---------------------------------------
// Return number of elements in the heap
//---------------------------------------
template <class T>
int Heap<T>::getNumElements()
{
	return m_iNumElements;
}

//---------------------------------------
// Print all the elements in the heap
//---------------------------------------
template <class T>
void Heap<T>::printAll()
{
	for (int i = 0; i<m_iNumElements; i++)
	{
		cout << "Heap element " << i << ". key=" << m_Elements[i].getKey() << "  data=" <<
			m_Elements[i].getData() << endl;
	}
}
