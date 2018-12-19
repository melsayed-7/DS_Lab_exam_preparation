// Lab 1: 
// Example3: Array of Objects and Array of Pointers

//**  THIS File Contains 7 Questions (Q1 to Q7) **//

#include "Car.h" // don't forget to include the .h of the class
                 // in any file that uses the class

#include <iostream>
using namespace std;
#define N 30

int main()
{
	// 1- Array of objects (Automatic & Dynamic)-------------------
	const int K = 4;

	Car A[K];  //Array of 4 Car objects (automatic allocation)

	/// [Q1] What is the type of the variable A? What is the type of item A[0]?
	/// [Q2] What is the size of the variable A? 
	/// [Q3] How many Car objects are allocated after the above line is executed? 

	//Filling array with dummy values
	for(int i=0; i<K; i++)
	{
		A[i].SetCarNo((i+1)*10);	//remember the dot operator
		A[i].SetLicenseNo( (2*i+1) * 10 );
	}

	//Printing array items
	for(int i=0; i<K; i++)
		A[i].Print();


	//Dynamic allocation of array of objects
	Car *B;
	/// [Q4] How many Car objects are allocated after the above line is executed? 

	int n;
	cout<<"\nPlease enter dynamic array size:";
	cin>>n;	//get array size from the user
	
	cout<<"\nAllocating array of "<<n<<" Car objects DYNAMICALLY"<<endl;
	B = new Car[n]; 
	/// [Q5] How many Car objects are allocated after the above line is executed? 

	//Filling array with dummy values
	for(int i=0; i<n; i++)
	{
		B[i].SetCarNo((i+1)*100);	//remember the dot operator
		B[i].SetLicenseNo((2*i+1) * 100);
	}
	

	cout<<"\nPrinting dynamic array items:\n";
	//Printing array items
	for(int i=0; i<n; i++)
		B[i].Print();

	//To delete Array B
	cout<<"\nDeleting the dynamic array";
	delete []B;
	B = NULL; //why? 
	          //Is this line mandatory after the delete?
	          //Does B points to NULL automatically when deleted??

	// 2- Array of pointers to objects -------------------
	// Assume we have a car park and we want to store info of each car in the parking slots
	// Assume the park has N slots. Each slot may be free or has a car occupying it
	// empty slots will be represented as NULL
	Car* ParkSlots[N];  //Array of N pointers to cars.
	/// [Q6] How many Car objects are allocated after the above line is executed? 

	//initialize all slots to "empty"
	for(int i=0; i<N; i++)
		ParkSlots[i] = NULL;
	
	//Adding cars to the parking slots
	cout<<"\n\n======== Array of pointers (to Car) Demo =============\n";
	cout<<"Adding cars to the parking slots\n";
	int m;
	do
	{
		cout<<"\nEnter slot index (-1 to end):";
		cin>>m;
		if(m != -1)  //you should also check that 0<= m <= N-1
		{
			if(ParkSlots[m] == NULL)
			{
				ParkSlots[m] = new Car;  //allocating a new car for pointer at index m
				// read the car info in temp vars
				ParkSlots[m]->ReadData();				
			}
			else
				cout<<"\nSlot is not empty";
		}
	} while( m != -1);

	//Printing the cars
	cout << "\n\nPrinting Cars: " << endl;
	for(int i=0; i<N; i++)
	{
		if(ParkSlots[i])  //if not NULL (what if we forgot to write this condition?)
		{
			cout << "\nCar in Slot no." << i << ": " << endl;
			// see how we access Print() from a pointer to Car, the arrow operator ->
			// ParkSlots array is array of POINTERS
			// ParkSlots[i] is a Pointer to Car (i.e. Car *)
			ParkSlots[i]->Print();
		}
	}

	//De-allocating dynamic memory used by array ParkSlots
	cout<<"\n\nDeallocating memory used by array of pointers";
	for(int i=0; i<N; i++)
		if(ParkSlots[i])  //if not NULL (what if we forgot to write this condition?)
		{
			cout<<"\nDeleting Car no. "<< ParkSlots[i]->GetCarNo() <<" at slot #"<< i << endl; 
			delete ParkSlots[i]; //free memory at this slot
		}

	/// [Q7] In example above, the no. of slots is assumed to be constant (N=30)
	// what if we want to read the no. of slots from the user and allocate it dynamically too
	// Try to make it and ask if there is problem

	cout<<endl;
	return 0;

}
