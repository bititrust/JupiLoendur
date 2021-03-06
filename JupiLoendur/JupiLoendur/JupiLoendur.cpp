// JupiLoendur.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class A {
	static int objCount; 
public:
	A()
	{
		++objCount;
	}
	A(const A &a)
	{
		++objCount;
	}
	~A()
	{
		--objCount;
	}
	static int nobjs() {

		return objCount;
	}
};
int A::objCount = 0;

int main()
{
	std::cout << "\nObject counter" << "\n";
	A obj1; // statically created object
	A obj2;
	A *obj3 = new A();	//dynamically created object
	A *obj4 = new A();
	std::cout << "\nNumber of existing objects: " << A::nobjs() << "\n";
	delete obj3;
	delete obj4;

	A obj5 = obj1; // invokes copy constructor
	std::cout << "\nNumber of existing objects: " << A::nobjs() << "\n";

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
