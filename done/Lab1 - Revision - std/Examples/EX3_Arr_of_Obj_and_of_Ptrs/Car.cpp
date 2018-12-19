#include "Car.h"
#include <iostream> // don't forget to include it in any file that uses: cout, cin
using namespace std;


Car::Car(int cno, int licNo)
{
	SetCarNo(cno);	//better than writing CarNo=cno  why??
	SetLicenseNo(licNo);
	// Note: Setters are used (rather than direct assigement) as they contain validations,
	cout << "Car no. "<<CarNo<<" with Licence "<<LicenseNo<<" is Constructed !!" << endl;

}

void Car::SetCarNo(int cno)
{
	// don't forget any extra needed validations
	CarNo = cno > 0 ? cno : 0; // assume 0 no. indicates of invalid number
}
int Car::GetCarNo()
{
	return CarNo;
}

void Car::SetLicenseNo(int licNo)
{
	LicenseNo = licNo > 0 ? licNo : 0;
}
int Car::GetLicenseNo()
{
	return LicenseNo;
}

void Car::ReadData()
{
	int cno, lno;

	cout<<"Enter Car info:\n";
	cout<<"Car No.:";
	cin>>cno;
	SetCarNo(cno);
	cout<<"License No.:";
	cin>>lno;
	SetLicenseNo(lno);
	
}


void Car::Print()
{
	cout << "\nCar No: " << CarNo << ", ";
	cout << "License No: " << LicenseNo << ", ";
}

Car::~Car()
{
	cout << "\nThe following Car is Destructed !!" << endl;
	Print();
}
