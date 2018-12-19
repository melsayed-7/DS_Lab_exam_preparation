
#include "Queue.h"
#include <iostream>		//To use C++ console I/O functionality
						//, we need to include iostream which contains necessary declarations.

using namespace std;	//This statement enables us to use classes and objects in the standard C++ library
						//without prefixing them with "std::"
//This is the program starting point.
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
  
