// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "array.h"
#include "vector.h"
#include "list.h"
#include <iostream>

using namespace std;

void DisplayArray(const nc::array<int, 5>& a)
{
	for (size_t i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void DisplayVector(const nc::vector<int>& v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

int main()
{
	// ARRAY
	cout << "** ARRAY **\n\n";
	nc::array<int, 5> array_numbers{ 7, 10, 65, 23, 14 };
	array_numbers[0] = 23;
	DisplayArray(array_numbers);

	cout << "copy\n";
	nc::array<int, 5> array_copy{ array_numbers };
	array_copy[0] = 56;
	array_copy[4] = 8;
	DisplayArray(array_copy);

	cout << "swap\n";
	array_numbers.swap(array_copy);
	DisplayArray(array_numbers);
	DisplayArray(array_copy);

	cout << "fill\n";
	array_copy.fill(21);
	DisplayArray(array_copy);

	cout << "front: " << array_numbers.front() << endl;
	cout << "back: " << array_numbers.back() << endl;
	cout << "size: " << array_numbers.size() << endl;
	cout << "data: " << array_numbers.data() << endl;

	// VECTOR
	cout << "\n\n** VECTOR **\n\n";
	nc::vector<int> vector_numbers{ 43, 23, 56, 7, 16 };
	vector_numbers[0] = 84;
	vector_numbers.push_back(99);
	DisplayVector(vector_numbers);

	cout << "copy\n";
	nc::vector<int> vector_copy;
	vector_copy = vector_numbers;
	vector_copy.pop_back();
	vector_copy.pop_back();
	DisplayVector(vector_copy);

	cout << "swap\n";
	vector_numbers.swap(vector_copy);
	DisplayVector(vector_numbers);
	DisplayVector(vector_copy);

	cout << "clear\n";
	vector_copy.clear();
	DisplayVector(vector_copy);

	cout << "resize\n";
	vector_numbers.resize(10, 5);
	vector_numbers.reserve(20);
	DisplayVector(vector_numbers);

	cout << "front: " << vector_numbers.front() << endl;
	cout << "back: " << vector_numbers.back() << endl;
	cout << "size: " << vector_numbers.size() << endl;
	cout << "max size: " << vector_numbers.max_size() << endl;
	cout << "capacity: " << vector_numbers.capacity() << endl;
	cout << "empty: " << vector_numbers.empty() << endl;
	cout << "data: " << vector_numbers.data() << endl;

	// LIST
	cout << "\n\n** LIST **\n\n";
	nc::list<int> list_numbers{ 12, 78, 12, 34, 9 };
	list_numbers.push_back(10);
	list_numbers.push_front(8);
	list_numbers.write(cout);

	nc::list<int> list_copy;
	list_copy = list_numbers;
	list_copy.pop_front();
	list_copy.pop_back();
	list_copy.pop_back();
	list_copy.write(cout);

	list_copy.remove(12);
	list_copy.write(cout);

	list_copy.resize(10, 99);
	list_copy.write(cout);

	list_numbers.reverse();
	list_numbers.write(cout);

	cout << "front: " << list_numbers.front() << endl;
	cout << "back: " << list_numbers.back() << endl;
	cout << "size: " << list_numbers.size() << endl;
	cout << "empty: " << list_numbers.empty() << endl;

}

