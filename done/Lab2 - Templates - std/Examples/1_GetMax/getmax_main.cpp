/*
******** Function Template ********
Assume you want to write a function GetMax that returns the maximum of three variables of any type. 
Without templates, you must write an overloaded function with the name GetMax for each type. 
Using templates enables you write the function code once then use it for any type.
*/

#include<iostream>
#include <string>
using namespace std;

//Function Template definition
/* Both the word "class" and "typename" here mean any built-in or user-defined type.
	The compiler will not compile a function template until the generic type T is specified. 
    i.e. until you make a call statement for the function.
	When a template-function-call statement is encountered by the compiler, 
	it generates a version of the function with the type specified by the call statement. 
	Hence each call statement generates an overloaded function with the name GetMax but with different parameter types.

*/
template <typename T> //or template <class T>
T GetMax(T a, T b, T c)
{
	T max = a;
	if (b>max) max = b;
	if (c>max) max = c;
	return max;
}

//Using the Function Template
int main()
{

	//using GetMax with int variables
	int x = 10, y = 20, z = 9;
	int w = GetMax(x, y, z);
	cout << "Maximim integer number is " << w << endl;

	//using GetMax with double variables
	double l = 52.5, m = 34.67, n = 12.4;
	double k = GetMax(l, m, n);
	cout << "Maximim double number is " << k << endl;

	//using GetMax with char variables
	char ch1 = 't', ch2 = 'd', ch3 = 'v';
	char ch4 = GetMax(ch1, ch2, ch3);
	cout << "Maximim character is '" << ch4 << '\'' << endl;

	string S1 = "Ahmed", S2 = "Ali", S3 = "Ayman";
	string S4 = GetMax(S1, S2, S3);
	cout << "Maximim string is '" << S4 << '\'' << endl;


	/* Uncomment the following, what's the problem? How can you fix it so that w = 34.67?
	   Hint: There are two ways, can you think of both of them?
	   Think then see the answer below
	*/
	//w = GetMax(x, y, m);
	//cout << "Maximim double is '" << w << '\'' << endl;

	//Answer:
	//1st way is to cast each parameter. Check next line
	//w = GetMax((double)x,(double) y, m);
	//2nd way is to tell the compiler you want the "double" version of the function
	//Here the compiler performs castig for your parameters. Check next line.
	//w = GetMax<double>(x, y, m); 
	
	return 0;
}
