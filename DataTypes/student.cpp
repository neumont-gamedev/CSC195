#include "student.h"
#include <iostream>

using namespace std;

void Student::Write()
{
	cout << name << endl;
	cout << age << endl;
	cout << gpa << endl;
}

void Student::Read()
{
	cout << "Name: ";
	cin >> name;
	cout << "Age: ";
	cin >> age;
	cout << "GPA: ";
	cin >> gpa;
}


