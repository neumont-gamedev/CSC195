#include "person.h"

#include <iostream>
#include <string>

using namespace std;

string EnumToString(eHairColor color)
{
	switch (color)
	{
	case eHairColor::BROWN:
		return "Brown";
		break;
	case eHairColor::BLONDE:
		return "Blonde";
		break;
	case eHairColor::RED:
		return "Red";
		break;
	default:
		break;
	}

	return "";
}

//void operator << (ostream& stream, Person person)
//{
//	stream << person.name << endl;
//}

Person::Person()
{
	age = 0;
	height = 5.0f;
	hairColor = eHairColor::BROWN;
}

Person::Person(std::string _name, int _age, float _height, eHairColor _hairColor)
{
	name = _name;
	age = _age;
	height = _height;
	hairColor = _hairColor;
}

void Person::Write()
{
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Height: " << height << endl;
	cout << "Hair Color: " << EnumToString(hairColor) << endl;
}

void Person::Read()
{
	cout << "Name: ";
	cin >> name;

	cout << "Age: ";
	cin >> age;
}
