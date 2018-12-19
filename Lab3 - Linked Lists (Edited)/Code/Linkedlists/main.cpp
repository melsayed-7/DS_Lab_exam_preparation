#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;

//Function prototypes 

///////////////////////////////////////////////////////////////////////

int main()
{
	LinkedList L;	//create an object of class LinkedList
	int val;

	cout<<"\nPlease enter int values to add to the list (-1 to stop):\n";
	cin>>val;
	while(val != -1)
	{
		L.InsertBeg(val);
		cin>>val;
	}
	L.PrintList();
	cout<<"enter node to delete: ";
	cin >> val;
	L.DeleteNode(val);
	L.PrintList();

	cout << "Deleting nodes: ";
	cin >> val;
	//L.DeleteFirst();
	//L.PrintList();
	L.DeleteNodes(val);
	L.PrintList();

	return 0;
}

