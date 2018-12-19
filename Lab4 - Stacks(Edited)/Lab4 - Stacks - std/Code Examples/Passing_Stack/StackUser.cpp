#include "Stack.h"

#include <iostream>
using namespace std;


// A function to print stack contents
//as the function shoud operate on a class template, the function itself should be a function template as well
template <typename T>
void PrintStack(Stack<T> S)
{
	cout << endl<<"Printing stack contents: ";

	T x;
	while(S.pop(x))		
		cout << x << " ";
	
	cout<<endl;
}

//A function that takes a Stack<T> S and returns its reverse (without affecting the orignal stack)
template <typename T>
Stack<T> Reverse(Stack<T> S)
{
	Stack<T> Rev( S.getSize() );	//First creat a stack with same size as S
	T Item;
	while(S.pop(Item))	//pop from S
		Rev.push(Item); //push into Rev

	return Rev;
}
template <typename T>
void ReverseMe(Stack<T> &me)
{
	Stack<T> aux(me.getSize()); 
	Stack<T> aux2(me.getSize());
	T item;
	while(me.pop(item))
		aux.push(item);
	while(aux.pop(item))
		aux2.push(item);
	while(aux2.pop(item))
		me.push(item);
}
template <typename T>
void collapse(Stack<T> &me)
{
	Stack<T> aux(me.getSize()); 
	T item1,item2,sum;
	while(me.pop(item1))
		{
			if(me.pop(item2))
			{
				sum = item1+item2;
			}
			else
				sum = item1;

			aux.push(sum);
	}
	while(aux.pop(item1))
		me.push(item1);
		
}

int main()

{
	Stack<int> stack1(20);

	int i,x;

	//Test the 1st stack by pushing 1, 2, 3, 4 and 5 then popping them.
	cout << "Testing stack 1:" << endl;
	cout << "Pushing 5 values into stack 1:" << endl;

	//Reading From the user 5 integer values
	cout<<"Please Enter the 5 values to push in stack1 :";
	for(i = 0; i < 6; i++)
	{	 
		cin>>x;
		stack1.push(x); //pushing x to stack1
	}
/*
	cout<<"\nstack1 contents\n";
	PrintStack(stack1);

	Stack<int> stack2(20);
	stack2 = Reverse(stack1);

	cout<<"\nstack2 contents\n";
	PrintStack(stack2);
*/
	cout<<"\nstack1 contents\n";
	PrintStack(stack1);
	collapse(stack1);
		cout<<"\nstack1 contents after collapsing\n";
	PrintStack(stack1);
	cout<<endl;
	return 0;


}
