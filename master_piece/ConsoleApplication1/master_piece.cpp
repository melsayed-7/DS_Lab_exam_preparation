// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>

// if you are going to use linked list header file then don't include "stack2.h" and vice versa ,as both have a calss called "Node" and this blows the code up
// alternativly you can use "stack.h" when you include "linkedlist.h" 
//
//#include "linked_list/LinkedList.h"
//#include "stack/Stack.h" // array based implementation
//#include "stack/Stack2.h"//linked list based implementation
//#include "Queue/Queue.h"// this is the generic one sent as downloaded on moodle
//#include "khaled's_Queue/Queue.h"

using namespace std;

//comment this main and activate whatever main from the below mains
int main()
{

}



// copy any code and run it in the main


// linked list main
	/*
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

}
	*/
	//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
//stack main
/*
int main()
{

	//Declare a Stack of integers named "stack1"
	Stack<int,10> stack1;
	LLStack<int> stack2;

	int i,x;

	//Test the 1st stack by pushing 1, 2, 3, 4 and 5 then popping them.
	cout << "Testing stack 2:" << endl;
	cout << "Pushing 5 values into stack 1:" << endl;

	//Reading From the user 5 integer values
	cout<<"Please Enter the 5 values to push in stack1 :";
	for(i = 0; i < 5; i++)
	{
		cin>>x;
		stack2.push(x); //pushing x to stack1
	}

	cout << endl<<"Popping: ";

	while(stack2.pop(x))
		cout << x << " ";

	cout<<endl;

	cout<<"is stack1 Empty??";
	if(stack2.isEmpty())
		cout<<" True";
	else
		cout<<" False";
	cout<<endl;


}
*/

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
	A function the removes and prints the first non-zero items in a queue
	The function stops either because a zero-item is encounted or queue becomes empty
	Note:
	The zero item iteslf should NOT be removed from the queue
*/

/*
template <typename T>
void removeFirstPostitive(Queue<T> & Q)
{
	T x;
	while (Q.peekFront(x))	//Have a look first before dequeuing it
		if (x != 0)
		{
			Q.dequeue(x);
			cout << x << " ";
		}
		else
			return;
}



//This is the program starting point.
int main()
{


	//Declare a queue of integers named "queue1"
	Queue<int> queue1;
	int x;

	//Test the queue by enqueue 6, 7, 8, 9 and 10 then dequeue them.
	cout << "Testing queue 1:" << endl;
	cout << "inserting 5 values into queue 1:" << endl;

	cout << "Please Enter the 5 values to enqueue in queue1 :";
	for (int i = 0; i < 5; i++)
	{
		cin >> x;
		queue1.enqueue(x); //pushing x to stack2
	}

	cout << "\nRemoving first positive items... Removed Items are:";
	removeFirstPostitive(queue1);


	cout << endl;

	//Write code to test empty case and to test peekFront function
	return 0;
}
*/

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
//another queue code
/*
int main()
{
	//Declare a queue of integers named "queue1"
	Queue<int> queue1;
	int x;

	//Test the queue by enqueue 6, 7, 8, 9 and 10 then dequeue them.
	cout << "Testing queue 1:" << endl;
	cout << "inserting 5 values into queue 1:" << endl;

	cout<<"Please Enter the 5 values to enqueue in queue1 :";
	for(int i = 0; i < 5; i++)
	{
		cin>>x;
		queue1.enqueue(x); //pushing x to stack2
	}

	cout << "Testing dequeue operation: ";

	while(queue1.dequeue(x))
		cout << x << " ";

	cout<<endl;

	//Write code to test empty case and to test peekFront function
	return 0;
}

*/