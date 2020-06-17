// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "math.h"
#include "student.h"
#include <iostream>
#include <string>

using namespace std;

// int (4 bytes), bool, char (byte)
// user defined types

enum class eDegree
{
	CS,
	SE,
	WD
};

eDegree degree = eDegree::CS;

string GetEnumName(eDegree degree)
{
	switch (degree)
	{
	case eDegree::CS:
		return "Computer Science";
		break;
	case eDegree::SE:
		return "Software Engineering";
		break;
	case eDegree::WD:
		return "Web Development";
		break;
	}

	return "";
}

int main()
{
	cout << cube(5) << endl;

	std::string name;
	int releaseYear;
	std::string genre;

	cout << "Enter game name" << endl;
	std::getline(std::cin, name);
	cout << "Enter game release year" << endl;
	cin >> releaseYear;
	cin.ignore(1, '\n');
	cout << "Enter game genre" << endl;
	std::getline(std::cin, genre);

	Student student;

	// enumeration
	cout << "Enter degree (0 - CS, 1 - SE, 2 - WD)" << endl;
	int input;
	cin >> input;
	degree = static_cast<eDegree>(input);

	cout << GetEnumName(degree) << endl;
}

