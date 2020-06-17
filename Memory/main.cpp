// Memory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

void function(int i)
{
	i = i + 5;

	cout << i << endl;
	cout << &i << endl;
}

void swap(int& i1, int& i2)
{
	int temp = i1;
	i1 = i2;
	i2 = temp;
}

void swap(int* i1, int* i2)
{
	int temp = *i1;
	*i1 = *i2;
	*i2 = temp;
}

int main()
{
	int i = 5;
	int j = 8;
	int& r = i;

	int* p = nullptr;
	p = &i;
	p = &j;

	//overkill();
	swap(&i, &j);

	int* pi = new int(15); // heap -> [0, 0, 0, [int], 0, 0]
	cout << *pi << endl;

	delete pi; // heap -> [0, 0, 0, [int], 0, 0]
	pi = nullptr;

	if (pi != nullptr)
	{
		delete pi;
	}

	cout << i << endl;
	cout << &i << endl;

	cout << p << endl;
	cout << *p << endl;
	cout << &p << endl;
	
	//cout << &r << endl;
	struct peep
	{
		int age;
		float height;

		void print() {}
	};

	// int <---- &
	//
	//
	//
	// float
	//
	//
	//

	peep* pp = new peep;
	(*pp).age = 10;
	pp->age = 10;
	pp->print();
	delete pp;
}

