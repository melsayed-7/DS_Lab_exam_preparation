
#include "Stack.h"		//include the Stack ADT file
#include <iostream>		//To use C++ console I/O functionality
						//, we need to include iostream which contains necessary declarations.

using namespace std;	//This statement enables us to use classes and objects in the standard C++ library
						//without prefixing them with "std::"
//This is the program starting point.
int main()
{

	//Declare a Stack of integers named "stack1"
	Stack<int,10> stack1;

	int i,x;

	//Test the 1st stack by pushing 1, 2, 3, 4 and 5 then popping them.
	cout << "Testing stack 1:" << endl;
	cout << "Pushing 5 values into stack 1:" << endl;

	//Reading From the user 5 integer values
	cout<<"Please Enter the 5 values to push in stack1 :";
	for(i = 0; i < 5; i++)
	{	 
		cin>>x;
		stack1.push(x); //pushing x to stack1
	}

	cout << endl<<"Popping: ";

	while(stack1.pop(x))		
		cout << x << " ";
	
	cout<<endl;

	cout<<"is stack1 Empty??";
	if(stack1.isEmpty())
		cout<<" True";
	else	
		cout<<" False";
	cout<<endl;


	return 0;
}
  
