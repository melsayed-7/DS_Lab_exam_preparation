#pragma once

//Class Template
// TemplateArray - a simple templatized array
template <typename T>
class MyArray
{
	enum { size = 100 };	//max 100 items for simplicity
private:
	int count;
	T data[size];

public:
	MyArray();
	int getCount();
	bool addItem(T Item);	//Adds a new Item to the array
	T getItem(int index);	//gets an Item at a given index
	int getIndex(T Item);	//returns the index of a given Item
};

template <typename T>
MyArray<T>::MyArray()
{
	count = 0;
}

template <typename T>
int MyArray<T>::getCount()
{	//Actual number of items stored
	return count;
}


template <typename T>
bool MyArray<T>::addItem(T Item)
{
	if(count < size )
	{
		data[count++] = Item;
		return true;
	}
	return false;
}

template <typename T>
T MyArray<T>::getItem(int index)
{
	return data[index];
}

template <typename T>
int MyArray<T>::getIndex(T Item)	//returns the index of a given Item
{
	for(int i=0; i<count; i++)
		if (data[i] == Item)
			return i;
	return -1;	//Item no found
}

