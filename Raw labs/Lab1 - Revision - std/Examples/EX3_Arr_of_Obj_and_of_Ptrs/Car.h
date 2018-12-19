#pragma once
class Car
{
	// the default access specifier in classes is "private"
	// unlike structs which are "public"
	int CarNo;
	int LicenseNo;
public:
	Car(int cno=0, int licNo=0);

	void SetCarNo(int);
	int GetCarNo();

	void SetLicenseNo(int);
	int GetLicenseNo();

	void ReadData();

	void Print();

	~Car();
};

